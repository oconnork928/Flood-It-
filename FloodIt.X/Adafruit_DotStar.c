#include "Adafruit_DotStar.h"

/*!
  @brief   DotStar constructor for hardware SPI. Must be connected to
           MOSI, SCK pins.
  @param   n  Number of DotStars in strand.
  @param   o  Pixel type -- one of the DOTSTAR_* constants defined in
              Adafruit_DotStar.h, for example DOTSTAR_BRG for DotStars
              expecting color bytes expressed in blue, red, green order
              per pixel. Default if unspecified is DOTSTAR_BRG.
  @return  Adafruit_DotStar object. Call the begin() function before use.
*/
void setup1(uint16_t n, uint8_t o){
    numLEDs = n;
    brightness = 0;
    rOffset = o&3;
    gOffset = (o >> 2) & 3;
    bOffset = (o >> 4) & 3;
    RPB13R = 4;               // SDO pin for SPI - goes to MOSI on TFT (pin 24))
    
    SpiChnOpen(2, SPI_OPEN_MSTEN | SPI_OPEN_MODE8 | SPI_OPEN_ON |
        SPI_OPEN_DISSDI | SPI_OPEN_CKE_REV , 8000000);
}

// Pins may be reassigned post-begin(), so a sketch can store hardware
// config in flash, SD card, etc. rather than hardcoded. Also permits
// "recycling" LED ram across multiple strips: set pins to first strip,
// render & write all data, reassign pins to next strip, render & write,
// etc. They won't update simultaneously, but usually unnoticeable.

// SPI STUFF ---------------------------------------------------------------

/* ISSUE DATA TO LED STRIP -------------------------------------------------

  Although the LED driver has an additional per-pixel 5-bit brightness
  setting, it is NOT used or supported here. On APA102, the normally
  very fast PWM is gated through a much slower PWM (about 400 Hz),
  rendering it useless for POV or other high-speed things that are
  probably why one is using DotStars instead of NeoPixels in the first
  place. I'm told that some APA102 clones use current control rather than
  PWM for this, which would be much more worthwhile. Still, no support
  here, no plans for it. If you really can't live without it, you can fork
  the library and add it for your own use, but any pull requests for this
  are unlikely be merged for the foreseeable future.
*/

inline void dsMode16(void){  // configure SPI1 for 16-bit mode
    SPI2CONSET = 0x400;
}

inline void dsMode8(void){  // configure SPI1 for 8-bit mode
    SPI2CONCLR = 0x400;
}

void ds_spiwrite(unsigned char c) {

    while (TxBufFullSPI2());
    WriteSPI2(c);
    while (SPI2STATbits.SPIBUSY); // wait for it to end of transaction

}

void ds_spiwrite8(unsigned char c) {   // Transfer one byte c to SPI
 /* The default mode for me is to transfer 16-bits at once
  * However, it is necessary sometimes to transfer only 8-bits at a time
  * But this is required less often than 16-bits at once
  * So, the default mode is 16-bit mode and is switched to 8-bit mode when
  *     required, and then switched back at the end of the function
  */
    dsMode8(); // switch to 8-bit mode
    while (TxBufFullSPI2());
    WriteSPI2(c);
    while (SPI2STATbits.SPIBUSY); // wait for it to end of transaction
    dsMode16(); // switch back to 16-bit mode
}

void ds_spiwrite16(unsigned short c){  // Transfer two bytes "c" to SPI
    while (TxBufFullSPI2());
    WriteSPI2(c);
    while (SPI2STATbits.SPIBUSY); // wait for it to end of transaction
}

/*!
  @brief   Transmit pixel data in RAM to DotStars.
*/
void show(void) {
  uint8_t i;
  uint16_t n = numLEDs;                // Counter

  // [START FRAME]
    for (i = 0; i < 4; i++){
        ds_spiwrite8(0x00);
    }

  // [Pixel Wite]
    while(n > 0){
        ds_spiwrite8(0xFF); // initial bits

        for (i = 0; i < 3; i++){
            ds_spiwrite8(pixels[n-1][i]); // RGB right 
        }
        n--;
    }

  // [END FRAME]
  // Four end-frame bytes are seemingly indistinguishable from a white
  // pixel, and empirical testing suggests it can be left out...but it's
  // always a good idea to follow the datasheet, in case future hardware
  // revisions are more strict (e.g. might mandate use of end-frame
  // before start-frame marker). i.e. let's not remove this. But after
  // testing a bit more the suggestion is to use at least (numLeds+1)/2
  // high values (1) or (numLeds+15)/16 full bytes as EndFrame. For details
  // see also:
  // https://cpldcpu.wordpress.com/2014/11/30/understanding-the-apa102-superled/
    for (i = 0; i < ((numLEDs + 15) / 16); i++){
        ds_spiwrite8(0xFF);
    }
}

/*!
  @brief   Set a pixel's color using a 32-bit 'packed' RGB value.
  @param   n  Pixel index, starting from 0.
  @param   c  32-bit color value. Most significant byte is 0, second is
              red, then green, and least significant byte is blue.
              e.g. 0x00RRGGBB
*/
void setPixelColor(uint16_t n, uint32_t c) {
  if (n < numLEDs) {
    pixels[n][0] = (uint8_t)(c >> 16);
    pixels[n][1] = (uint8_t)(c >> 8);
    pixels[n][2] = (uint8_t) c;
  }
}

uint16_t numPixels(void){
    return numLEDs;
}
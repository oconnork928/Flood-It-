/* 
 * File:   Adafruit_DotStar.h
 * Author: spfow 
 * 
 * Created on November 24, 2022, 12:20 PM
 */

#ifndef ADAFRUIT_DOTSTAR_H
#define	ADAFRUIT_DOTSTAR_H

#include "plib.h"
#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

// Color-order flag for LED pixels (optional extra parameter to constructor):
// Bits 0,1 = R index (0-2), bits 2,3 = G index, bits 4,5 = B index
#define DOTSTAR_RGB (0 | (1 << 2) | (2 << 4)) ///< Transmit as R,G,B
#define DOTSTAR_RBG (0 | (2 << 2) | (1 << 4)) ///< Transmit as R,B,G
#define DOTSTAR_GRB (1 | (0 << 2) | (2 << 4)) ///< Transmit as G,R,B
#define DOTSTAR_GBR (2 | (0 << 2) | (1 << 4)) ///< Transmit as G,B,R
#define DOTSTAR_BRG (1 | (2 << 2) | (0 << 4)) ///< Transmit as B,R,G
#define DOTSTAR_BGR (2 | (1 << 2) | (0 << 4)) ///< Transmit as B,G,R
#define DOTSTAR_MONO 0 ///< Single-color strip WIP DO NOT USE, use RGB for now

#define PBCLK 40000000 // peripheral bus clock
#define SPI_freq    20000000

/*!
  @brief  Class that stores state and functions for interacting with
          Adafruit DotStars and compatible devices.
*/
  void setup1(uint16_t n, uint8_t o);

  void show(void);
  
  void ds_spiwrite(unsigned char c);
  void ds_spiwrite8(unsigned char c);
  void ds_spiwrite16(unsigned short c);  
  void setPixelColor(uint16_t n, uint32_t c);
  /*!
    @brief   Return the number of pixels in an Adafruit_DotStar strip object.
    @return  Pixel count (0 if not set).
  */
  uint16_t numPixels(void);

  uint16_t numLEDs;                   ///< Number of pixels
  uint8_t brightness;                 ///< Global brightness setting
  uint8_t pixels[5][3];                    ///< LED RGB values (3 bytes ea.)
  uint8_t rOffset;                    ///< Index of red in 3-byte pixel
  uint8_t gOffset;                    ///< Index of green byte
  uint8_t bOffset;                    ///< Index of blue byte



#ifdef	__cplusplus
}
#endif

#endif	/* ADAFRUIT_DOTSTAR_H */


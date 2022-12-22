EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PIC32MX250F128B-V_SP:PIC32MX250F128B-V_SP U1
U 1 1 6398A666
P 5000 2700
F 0 "U1" H 4450 3967 50  0000 C CNN
F 1 "PIC32MX250F128B-V_SP" H 4450 3876 50  0000 C CNN
F 2 "DIP254P762X508-28" H 5000 2700 50  0001 L BNN
F 3 "SPDIP-28 Microchip" H 5000 2700 50  0001 L BNN
F 4 "PIC32MX250F128B-V/SP" H 5000 2700 50  0001 L BNN "Field4"
F 5 "32 Bit MCU, 128KB Flash, 32KB RAM, 40 MHz, 28 Pin, 3 Comp, CTMU, RTCC, 28 SPDIP" H 5000 2700 50  0001 L BNN "Field5"
F 6 "Microchip" H 5000 2700 50  0001 L BNN "Field6"
F 7 "None" H 5000 2700 50  0001 L BNN "Field7"
F 8 "Unavailable" H 5000 2700 50  0001 L BNN "Field8"
	1    5000 2700
	1    0    0    -1  
$EndComp
$Comp
L PIC32MX250F128B-V_SP:LCD_2_4 U2
U 1 1 6398A9DC
P 8200 2600
F 0 "U2" H 8200 3775 50  0000 C CNN
F 1 "LCD_2_4" H 8200 3684 50  0000 C CNN
F 2 "" H 8200 2650 50  0001 C CNN
F 3 "" H 8200 2650 50  0001 C CNN
	1    8200 2600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 6398C2DB
P 3300 6350
F 0 "SW1" V 3346 6302 50  0000 R CNN
F 1 "SW_Push" V 3255 6302 50  0000 R CNN
F 2 "" H 3300 6550 50  0001 C CNN
F 3 "~" H 3300 6550 50  0001 C CNN
	1    3300 6350
	0    -1   -1   0   
$EndComp
$Comp
L Device:Speaker LS1
U 1 1 6398CB75
P 9200 4700
F 0 "LS1" H 9370 4696 50  0000 L CNN
F 1 "Speaker" H 9370 4605 50  0000 L CNN
F 2 "" H 9200 4500 50  0001 C CNN
F 3 "~" H 9190 4650 50  0001 C CNN
	1    9200 4700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 6398D81F
P 4100 6350
F 0 "SW2" V 4146 6302 50  0000 R CNN
F 1 "SW_Push" V 4055 6302 50  0000 R CNN
F 2 "" H 4100 6550 50  0001 C CNN
F 3 "~" H 4100 6550 50  0001 C CNN
	1    4100 6350
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 6398E23C
P 4850 6350
F 0 "SW3" V 4896 6302 50  0000 R CNN
F 1 "SW_Push" V 4805 6302 50  0000 R CNN
F 2 "" H 4850 6550 50  0001 C CNN
F 3 "~" H 4850 6550 50  0001 C CNN
	1    4850 6350
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 6398E242
P 5650 6350
F 0 "SW4" V 5696 6302 50  0000 R CNN
F 1 "SW_Push" V 5605 6302 50  0000 R CNN
F 2 "" H 5650 6550 50  0001 C CNN
F 3 "~" H 5650 6550 50  0001 C CNN
	1    5650 6350
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 6398EA88
P 6400 6350
F 0 "SW5" V 6446 6302 50  0000 R CNN
F 1 "SW_Push" V 6355 6302 50  0000 R CNN
F 2 "" H 6400 6550 50  0001 C CNN
F 3 "~" H 6400 6550 50  0001 C CNN
	1    6400 6350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7450 3350 7400 3350
Wire Wire Line
	7400 3350 7400 3250
Wire Wire Line
	7400 3250 7450 3250
Wire Wire Line
	7400 3250 7400 3150
Wire Wire Line
	7400 3150 7450 3150
Connection ~ 7400 3250
Wire Wire Line
	7400 3150 7400 1850
Wire Wire Line
	7400 1850 7450 1850
Connection ~ 7400 3150
Wire Wire Line
	7450 1950 5800 1950
Wire Wire Line
	5800 1950 5800 2200
Wire Wire Line
	5800 2200 5700 2200
Wire Wire Line
	7450 2150 5900 2150
Wire Wire Line
	5900 2500 5700 2500
Wire Wire Line
	5900 2150 5900 2500
Wire Wire Line
	7450 2450 6000 2450
Wire Wire Line
	6000 2450 6000 4000
Wire Wire Line
	6000 4000 3050 4000
Wire Wire Line
	3050 4000 3050 2800
Wire Wire Line
	3050 2800 3200 2800
Wire Wire Line
	7450 2250 6100 2250
Wire Wire Line
	6100 2250 6100 4100
Wire Wire Line
	6100 4100 2950 4100
Wire Wire Line
	2950 4100 2950 2700
Wire Wire Line
	2950 2700 3200 2700
Wire Wire Line
	7450 2350 6200 2350
Wire Wire Line
	6200 2350 6200 4200
Wire Wire Line
	6200 4200 2850 4200
Wire Wire Line
	2850 4200 2850 2600
Wire Wire Line
	2850 2600 3200 2600
Wire Wire Line
	7450 1650 7400 1650
Wire Wire Line
	7400 1650 7400 1550
Wire Wire Line
	7450 1750 7200 1750
$Comp
L power:GND #PWR?
U 1 1 63998C65
P 7400 1550
F 0 "#PWR?" H 7400 1300 50  0001 C CNN
F 1 "GND" H 7405 1377 50  0000 C CNN
F 2 "" H 7400 1550 50  0001 C CNN
F 3 "" H 7400 1550 50  0001 C CNN
	1    7400 1550
	-1   0    0    1   
$EndComp
Wire Wire Line
	6400 6150 6400 5450
Wire Wire Line
	6400 5450 3150 5450
Wire Wire Line
	3150 5450 3150 3400
Wire Wire Line
	3150 3400 3200 3400
Wire Wire Line
	5650 6150 5650 5550
Wire Wire Line
	5650 5550 2750 5550
Wire Wire Line
	2750 5550 2750 3200
Wire Wire Line
	2750 3200 3200 3200
Wire Wire Line
	4850 6150 4850 5650
Wire Wire Line
	4850 5650 2650 5650
Wire Wire Line
	2650 5650 2650 3100
Wire Wire Line
	2650 3100 3200 3100
Wire Wire Line
	4100 5750 2550 5750
Wire Wire Line
	2550 5750 2550 2500
Wire Wire Line
	2550 2500 3200 2500
Wire Wire Line
	4100 5750 4100 6150
Wire Wire Line
	3300 6150 3300 5850
Wire Wire Line
	3300 5850 2450 5850
Wire Wire Line
	2450 5850 2450 2400
Wire Wire Line
	2450 2400 3200 2400
Wire Wire Line
	3300 6550 3300 6700
Wire Wire Line
	3300 6700 4100 6700
Wire Wire Line
	6400 6700 6400 6550
Wire Wire Line
	5650 6550 5650 6700
Connection ~ 5650 6700
Wire Wire Line
	5650 6700 6400 6700
Wire Wire Line
	4850 6550 4850 6700
Connection ~ 4850 6700
Wire Wire Line
	4850 6700 5650 6700
Wire Wire Line
	4100 6550 4100 6700
Connection ~ 4100 6700
Wire Wire Line
	4100 6700 4850 6700
$Comp
L power:GND #PWR?
U 1 1 639A8CD8
P 4850 6700
F 0 "#PWR?" H 4850 6450 50  0001 C CNN
F 1 "GND" H 4855 6527 50  0000 C CNN
F 2 "" H 4850 6700 50  0001 C CNN
F 3 "" H 4850 6700 50  0001 C CNN
	1    4850 6700
	1    0    0    -1  
$EndComp
$Comp
L PIC32MX250F128B-V_SP:DotStar_LED U3
U 1 1 639B1D9F
P 4450 4600
F 0 "U3" H 4450 4715 50  0000 C CNN
F 1 "DotStar_LED" H 4450 4624 50  0000 C CNN
F 2 "" H 4450 4600 50  0001 C CNN
F 3 "" H 4450 4600 50  0001 C CNN
	1    4450 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4750 6300 4750
Wire Wire Line
	4800 4850 6400 4850
Wire Wire Line
	6300 2900 5700 2900
Wire Wire Line
	6300 2900 6300 4750
Wire Wire Line
	6400 2100 5700 2100
Wire Wire Line
	6400 2100 6400 4850
Wire Wire Line
	4100 4750 4050 4750
Wire Wire Line
	4050 4750 4050 4650
Wire Wire Line
	4050 4650 3850 4650
Wire Wire Line
	4100 4850 4050 4850
Wire Wire Line
	4050 4850 4050 4950
Wire Wire Line
	4050 4950 3850 4950
$Comp
L power:GND #PWR?
U 1 1 639C0796
P 3850 4650
F 0 "#PWR?" H 3850 4400 50  0001 C CNN
F 1 "GND" V 3855 4522 50  0000 R CNN
F 2 "" H 3850 4650 50  0001 C CNN
F 3 "" H 3850 4650 50  0001 C CNN
	1    3850 4650
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 4600 8750 4600
Wire Wire Line
	8750 4600 8750 4700
Wire Wire Line
	8750 4700 9000 4700
Wire Wire Line
	8500 4900 8750 4900
Wire Wire Line
	8750 4900 8750 4800
Wire Wire Line
	8750 4800 9000 4800
Wire Wire Line
	8000 4300 8000 4250
Wire Wire Line
	8000 4250 8400 4250
$Comp
L power:GND #PWR?
U 1 1 639D2870
P 8000 5400
F 0 "#PWR?" H 8000 5150 50  0001 C CNN
F 1 "GND" H 8005 5227 50  0000 C CNN
F 2 "" H 8000 5400 50  0001 C CNN
F 3 "" H 8000 5400 50  0001 C CNN
	1    8000 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 5200 8000 5300
Wire Wire Line
	8000 5300 7350 5300
Wire Wire Line
	7350 5300 7350 4700
Wire Wire Line
	7350 4700 7500 4700
Wire Wire Line
	8000 5300 8000 5400
Connection ~ 8000 5300
Wire Wire Line
	7500 4800 6700 4800
Wire Wire Line
	6700 4800 6700 4400
Wire Wire Line
	6700 4400 2350 4400
Wire Wire Line
	2350 4400 2350 3500
Wire Wire Line
	2350 3500 3200 3500
Wire Wire Line
	7500 4600 6800 4600
Wire Wire Line
	6800 4600 6800 3000
Wire Wire Line
	6800 3000 5700 3000
Wire Wire Line
	7500 4900 6900 4900
Wire Wire Line
	6900 4900 6900 2300
Wire Wire Line
	6900 2300 5700 2300
$Comp
L Device:Battery_Cell BT1
U 1 1 63771ADE
P 9300 6400
F 0 "BT1" H 9418 6496 50  0000 L CNN
F 1 "9V" H 9418 6405 50  0000 L CNN
F 2 "" V 9300 6460 50  0001 C CNN
F 3 "~" V 9300 6460 50  0001 C CNN
	1    9300 6400
	1    0    0    -1  
$EndComp
Text GLabel 3850 4950 0    50   Input ~ 0
BAT5
Text GLabel 5850 1600 1    50   Input ~ 0
BAT3.3
Text GLabel 7200 1600 1    50   Input ~ 0
BAT3.3
Text GLabel 8400 4250 2    50   Input ~ 0
BAT3.3
$Comp
L Analog_DAC:MCP4822 U4
U 1 1 639C5798
P 8000 4700
F 0 "U4" H 8000 5281 50  0000 C CNN
F 1 "MCP4822" H 8000 5190 50  0000 C CNN
F 2 "" H 8800 4400 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20002249B.pdf" H 8800 4400 50  0001 C CNN
	1    8000 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1600 7200 1750
Wire Wire Line
	5850 1600 5850 3400
Wire Wire Line
	5850 3400 5700 3400
Text GLabel 8550 7000 3    50   Input ~ 0
BAT5
Text GLabel 8550 5750 1    50   Input ~ 0
BAT3.3
$Comp
L PIC32MX250F128B-V_SP:V_REG U5
U 1 1 63797932
P 8850 6350
F 0 "U5" H 8875 5785 50  0000 C CNN
F 1 "V_REG" H 8875 5876 50  0000 C CNN
F 2 "" H 8850 6450 50  0001 C CNN
F 3 "" H 8850 6450 50  0001 C CNN
	1    8850 6350
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 5950 8700 5850
Wire Wire Line
	8700 5850 9300 5850
Wire Wire Line
	9300 5850 9300 6200
Wire Wire Line
	9300 6500 9300 6900
Wire Wire Line
	9300 6900 9050 6900
Wire Wire Line
	8700 6900 8700 6800
Wire Wire Line
	8550 5950 8550 5750
Wire Wire Line
	8550 7000 8550 6800
$Comp
L power:GND #PWR?
U 1 1 637B709E
P 9050 6900
F 0 "#PWR?" H 9050 6650 50  0001 C CNN
F 1 "GND" H 9055 6727 50  0000 C CNN
F 2 "" H 9050 6900 50  0001 C CNN
F 3 "" H 9050 6900 50  0001 C CNN
	1    9050 6900
	1    0    0    -1  
$EndComp
Connection ~ 9050 6900
Wire Wire Line
	9050 6900 8700 6900
$EndSCHEMATC
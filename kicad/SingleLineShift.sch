EESchema Schematic File Version 2
LIBS:74xx
LIBS:adc-dac
LIBS:analog_switches
LIBS:atmel
LIBS:audio
LIBS:brooktre
LIBS:cmos4000
LIBS:cmos_ieee
LIBS:conn
LIBS:contrib
LIBS:cypress
LIBS:device
LIBS:digital-audio
LIBS:display
LIBS:dsp
LIBS:elec-unifil
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:intel
LIBS:interface
LIBS:linear
LIBS:memory
LIBS:microchip
LIBS:microchip1
LIBS:microcontrollers
LIBS:motorola
LIBS:opto
LIBS:philips
LIBS:power
LIBS:pspice
LIBS:regul
LIBS:siliconi
LIBS:special
LIBS:texas
LIBS:transistors
LIBS:ttl_ieee
LIBS:valves
LIBS:xilinx
LIBS:MantisLight-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
Title ""
Date "28 dec 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 8250 2650
Wire Wire Line
	8800 2650 8050 2650
Connection ~ 7350 1100
Wire Wire Line
	6900 1100 7850 1100
Wire Wire Line
	7850 1100 7850 2350
Wire Wire Line
	8250 2650 8250 2450
Wire Wire Line
	8750 1100 8250 1100
Wire Wire Line
	8250 1100 8250 1950
Wire Wire Line
	7350 1100 7350 1950
Wire Wire Line
	7350 2650 7350 2450
Wire Wire Line
	6800 2650 7650 2650
Connection ~ 7350 2650
Text HLabel 8800 2650 2    60   BiDi ~ 0
high
Text HLabel 6800 2650 0    60   BiDi ~ 0
low
Text HLabel 8750 1100 2    60   UnSpc ~ 0
Vin_high
$Comp
L MOSFET_N Q8
U 1 1 4E9D5A31
P 7850 2550
F 0 "Q8" H 7860 2720 60  0000 R CNN
F 1 "MOSFET_N" H 7860 2400 60  0000 R CNN
F 2 "" H 7850 2550 60  0001 C CNN
F 3 "" H 7850 2550 60  0001 C CNN
	1    7850 2550
	0    1    1    0   
$EndComp
Text HLabel 6900 1100 0    60   UnSpc ~ 0
VIN_low
$Comp
L R R44
U 1 1 4E9D5A17
P 7350 2200
F 0 "R44" V 7430 2200 50  0000 C CNN
F 1 "10k" V 7350 2200 50  0000 C CNN
F 2 "" H 7350 2200 60  0001 C CNN
F 3 "" H 7350 2200 60  0001 C CNN
	1    7350 2200
	1    0    0    -1  
$EndComp
$Comp
L R R45
U 1 1 4E9D5A11
P 8250 2200
F 0 "R45" V 8330 2200 50  0000 C CNN
F 1 "10k" V 8250 2200 50  0000 C CNN
F 2 "" H 8250 2200 60  0001 C CNN
F 3 "" H 8250 2200 60  0001 C CNN
	1    8250 2200
	1    0    0    -1  
$EndComp
$EndSCHEMATC

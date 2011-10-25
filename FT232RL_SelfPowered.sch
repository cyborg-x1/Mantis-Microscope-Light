EESchema Schematic File Version 2  date Mo 24 Okt 2011 16:23:56 CEST
LIBS:rl_con
LIBS:rl_device
LIBS:rl_mech
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
LIBS:SymbolsSimilarEN60617+oldDIN617
LIBS:texas
LIBS:transistors
LIBS:ttl_ieee
LIBS:valves
LIBS:xilinx
LIBS:MantisLight-cache
EELAYER 24  0
EELAYER END
$Descr A4 11700 8267
Sheet 5 5
Title ""
Date "24 oct 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 4950 2900
Wire Wire Line
	3500 2900 4950 2900
Connection ~ 4400 3100
Wire Wire Line
	4400 3100 4400 2750
Wire Wire Line
	4400 2750 4600 2750
Wire Wire Line
	4850 2600 4950 2600
Wire Wire Line
	4950 2600 4950 3250
Wire Wire Line
	4950 3250 4500 3250
Connection ~ 4500 5400
Wire Wire Line
	4500 3250 4500 5400
Connection ~ 4100 5400
Wire Wire Line
	4100 5400 4100 3550
Wire Wire Line
	4100 3550 3600 3550
Wire Wire Line
	5000 3450 3600 3450
Wire Wire Line
	5000 3350 3600 3350
Connection ~ 5000 5400
Wire Wire Line
	5000 5400 5000 4650
Wire Wire Line
	5000 3750 4600 3750
Wire Wire Line
	4600 3750 4600 4450
Connection ~ 6100 5400
Wire Wire Line
	3900 5400 6250 5400
Wire Wire Line
	6250 5400 6250 4950
Wire Wire Line
	4300 4400 4300 4500
Connection ~ 5800 5400
Wire Wire Line
	5800 5400 5800 4950
Wire Wire Line
	6100 4950 6100 5400
Wire Wire Line
	5000 3000 3100 3000
Wire Wire Line
	6850 3050 7100 3050
Wire Wire Line
	7100 3150 6850 3150
Wire Wire Line
	5000 3100 3700 3100
Wire Wire Line
	3700 3100 3700 3000
Connection ~ 3700 3000
Wire Wire Line
	5650 5400 5650 4950
Connection ~ 5650 5400
Wire Wire Line
	5950 5400 5950 4950
Connection ~ 5950 5400
Wire Wire Line
	4600 4450 4300 4450
Connection ~ 4300 4450
Wire Wire Line
	4300 5400 4300 5000
Connection ~ 4300 5400
Wire Wire Line
	5000 4250 5000 4400
Wire Wire Line
	4800 4700 4800 4300
Wire Wire Line
	4800 4300 5000 4300
Connection ~ 5000 4300
Wire Wire Line
	3600 3250 4300 3250
Wire Wire Line
	4300 3250 4300 3900
Wire Wire Line
	3250 3000 3250 2900
Connection ~ 3250 3000
Wire Wire Line
	4850 2750 4950 2750
Connection ~ 4950 2750
Wire Wire Line
	4600 2600 4300 2600
Wire Wire Line
	4300 2600 4300 3100
Connection ~ 4300 3100
$Comp
L C C5
U 1 1 4E9CC49E
P 4750 2750
F 0 "C5" V 4700 2650 50  0000 C CNN
F 1 "100nF" V 4700 2950 50  0000 C CNN
	1    4750 2750
	0    -1   -1   0   
$EndComp
$Comp
L C C6
U 1 1 4E9CC416
P 5000 4550
F 0 "C6" H 5100 4650 50  0000 C CNN
F 1 "100nF" H 5150 4500 50  0000 C CNN
	1    5000 4550
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 4E9CC415
P 3350 2900
F 0 "C3" V 3300 2750 50  0000 C CNN
F 1 "4.7uF" V 3300 3100 50  0000 C CNN
	1    3350 2900
	0    1    1    0   
$EndComp
$Comp
L C C4
U 1 1 4E9CC414
P 4750 2600
F 0 "C4" V 4700 2500 50  0000 C CNN
F 1 "100nF" V 4700 2800 50  0000 C CNN
	1    4750 2600
	0    -1   -1   0   
$EndComp
$Comp
L CONN_4 P7
U 1 1 4E9CC3D1
P 3250 3400
F 0 "P7" H 3200 3400 50  0000 C CNN
F 1 "USB" V 3300 3400 50  0000 C CNN
	1    3250 3400
	-1   0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 4E9CC378
P 4300 4750
F 0 "R2" V 4380 4750 50  0000 C CNN
F 1 "10k" V 4300 4750 50  0000 C CNN
	1    4300 4750
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 4E9CC374
P 4300 4150
F 0 "R1" V 4380 4150 50  0000 C CNN
F 1 "4k7" V 4300 4150 50  0000 C CNN
	1    4300 4150
	1    0    0    -1  
$EndComp
NoConn ~ 5000 4050
NoConn ~ 5000 3950
NoConn ~ 5000 3650
NoConn ~ 5000 3850
Text HLabel 4800 4700 3    60   UnSpc ~ 0
3V3_FTDI
NoConn ~ 6850 4250
NoConn ~ 6850 4150
NoConn ~ 6850 4050
NoConn ~ 6850 3950
NoConn ~ 6850 3850
NoConn ~ 6850 3750
NoConn ~ 6850 3650
NoConn ~ 6850 3550
NoConn ~ 6850 3450
NoConn ~ 6850 3350
NoConn ~ 6850 3250
Text HLabel 3100 3000 0    60   UnSpc ~ 0
5V
Text HLabel 3900 5400 0    60   UnSpc ~ 0
GND
Text HLabel 7100 3150 2    60   Input ~ 0
RXD
Text HLabel 7100 3050 2    60   Output ~ 0
TXD
$Comp
L FT232RL U3
U 1 1 4E9CB1CE
P 5950 3750
F 0 "U3" H 6350 2800 60  0000 C CNN
F 1 "FT232RL" H 5950 4650 60  0000 C CNN
	1    5950 3750
	1    0    0    -1  
$EndComp
$EndSCHEMATC

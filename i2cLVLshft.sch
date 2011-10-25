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
Sheet 3 5
Title ""
Date "24 oct 2011"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 5800 2950
Wire Wire Line
	6750 2950 5400 2950
Wire Wire Line
	6000 3450 6000 2700
Connection ~ 4250 3450
Wire Wire Line
	4600 3450 3800 3450
Wire Wire Line
	4250 3450 4250 2700
Connection ~ 4250 2050
Wire Wire Line
	4250 2050 4250 2200
Connection ~ 6000 2050
Wire Wire Line
	6000 2200 6000 2050
Connection ~ 4800 2050
Wire Wire Line
	4800 3150 4800 2050
Wire Wire Line
	3800 2050 5200 2050
Wire Wire Line
	5200 2050 5200 2650
Wire Wire Line
	6400 2050 5800 2050
Wire Wire Line
	5800 2050 5800 2200
Wire Wire Line
	4050 2050 4050 2200
Connection ~ 4050 2050
Wire Wire Line
	4050 2950 4050 2700
Wire Wire Line
	5000 2950 3800 2950
Connection ~ 4050 2950
Wire Wire Line
	5800 2950 5800 2700
Wire Wire Line
	6750 3450 5000 3450
Connection ~ 6000 3450
$Comp
L R R?
U 1 1 4E9D54FD
P 6000 2450
AR Path="/4E9D5349/4E9D54F5" Ref="R?"  Part="1" 
AR Path="/4E9D5349/4E9D54FD" Ref="R43"  Part="1" 
F 0 "R43" V 6080 2450 50  0000 C CNN
F 1 "10k" V 6000 2450 50  0000 C CNN
	1    6000 2450
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 4E9D54FC
P 5800 2450
AR Path="/4E9D5349/4E9D54F5" Ref="R?"  Part="1" 
AR Path="/4E9D5349/4E9D54FC" Ref="R42"  Part="1" 
F 0 "R42" V 5880 2450 50  0000 C CNN
F 1 "10k" V 5800 2450 50  0000 C CNN
	1    5800 2450
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 4E9D54FA
P 4250 2450
AR Path="/4E9D5349/4E9D54F5" Ref="R?"  Part="1" 
AR Path="/4E9D5349/4E9D54FA" Ref="R41"  Part="1" 
F 0 "R41" V 4330 2450 50  0000 C CNN
F 1 "10k" V 4250 2450 50  0000 C CNN
	1    4250 2450
	1    0    0    -1  
$EndComp
$Comp
L R R40
U 1 1 4E9D54F5
P 4050 2450
F 0 "R40" V 4130 2450 50  0000 C CNN
F 1 "10k" V 4050 2450 50  0000 C CNN
	1    4050 2450
	1    0    0    -1  
$EndComp
Text Notes 3550 4150 0    60   ~ 0
See NXP application note AN10441
$Comp
L MOSFET_N Q6
U 1 1 4E9D541D
P 4800 3350
F 0 "Q6" H 4810 3520 60  0000 R CNN
F 1 "MOSFET_N" H 4810 3200 60  0000 R CNN
	1    4800 3350
	0    1    1    0   
$EndComp
$Comp
L MOSFET_N Q7
U 1 1 4E9D541A
P 5200 2850
F 0 "Q7" H 5210 3020 60  0000 R CNN
F 1 "MOSFET_N" H 5210 2700 60  0000 R CNN
	1    5200 2850
	0    1    1    0   
$EndComp
Text HLabel 6750 3450 2    60   BiDi ~ 0
SCL_high
Text HLabel 6750 2950 2    60   BiDi ~ 0
SDA_high
Text HLabel 6400 2050 2    60   UnSpc ~ 0
Vin_high
Text HLabel 3800 3450 0    60   BiDi ~ 0
SCL_low
Text HLabel 3800 2950 0    60   BiDi ~ 0
SDA_low
Text HLabel 3800 2050 0    60   UnSpc ~ 0
Vin_low
$EndSCHEMATC

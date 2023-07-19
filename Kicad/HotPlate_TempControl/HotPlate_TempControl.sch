EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "HotPlate"
Date "2021-12-31"
Rev "1.0"
Comp "Amplitud Modulada"
Comment1 "By Cesar Mardueño"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328-PU U1
U 1 1 616BACD3
P 1950 3600
F 0 "U1" H 1306 3646 50  0000 R CNN
F 1 "ATmega328-PU" H 1306 3555 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 1950 3600 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 1950 3600 50  0001 C CNN
	1    1950 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 2400 2900 2400
Wire Wire Line
	2550 2500 2900 2500
Wire Wire Line
	2550 2600 2900 2600
Wire Wire Line
	2550 2700 2900 2700
Wire Wire Line
	2550 2800 2900 2800
Wire Wire Line
	2550 2900 2900 2900
Wire Wire Line
	2550 3000 2900 3000
Wire Wire Line
	2550 3100 2900 3100
Wire Wire Line
	2550 3300 2900 3300
Wire Wire Line
	2550 3400 2900 3400
Wire Wire Line
	2550 3500 2900 3500
Wire Wire Line
	2550 3600 2900 3600
Wire Wire Line
	2550 3700 2900 3700
Wire Wire Line
	2550 3800 2900 3800
Wire Wire Line
	2550 3900 2900 3900
Wire Wire Line
	2550 4100 2900 4100
Wire Wire Line
	2550 4200 2900 4200
Wire Wire Line
	2550 4400 2900 4400
Wire Wire Line
	2550 4500 2900 4500
Wire Wire Line
	2550 4600 2900 4600
Wire Wire Line
	2550 4700 2900 4700
Wire Wire Line
	2550 4800 2900 4800
Wire Wire Line
	1950 5100 1950 5250
Wire Wire Line
	1350 2400 1100 2400
Text Label 3000 4100 0    50   ~ 0
D0
Text Label 3000 4200 0    50   ~ 0
D1
Text Label 3000 4300 0    50   ~ 0
D2
Text Label 3000 4400 0    50   ~ 0
D3
Text Label 3000 4500 0    50   ~ 0
D4
Text Label 3000 4600 0    50   ~ 0
D5
Text Label 3000 4700 0    50   ~ 0
D6
Text Label 3000 4800 0    50   ~ 0
D7
Text Label 2900 4800 2    50   ~ 0
PD7
Text Label 2900 4700 2    50   ~ 0
PD6
Text Label 2900 4600 2    50   ~ 0
PD5
Text Label 2900 4500 2    50   ~ 0
PD4
Text Label 2900 4400 2    50   ~ 0
PD3
Text Label 2900 4300 2    50   ~ 0
PD2
Text Label 2900 4200 2    50   ~ 0
PD1
Text Label 2900 4100 2    50   ~ 0
PD0
Text Label 2900 3900 2    50   ~ 0
PC6
Text Label 2900 3800 2    50   ~ 0
PC5
Text Label 2900 3700 2    50   ~ 0
PC4
Text Label 2900 3600 2    50   ~ 0
PC3
Text Label 2900 3500 2    50   ~ 0
PC2
Text Label 2900 3400 2    50   ~ 0
PC1
Text Label 2900 3300 2    50   ~ 0
PC0
Text Label 2900 3100 2    50   ~ 0
PB7
Text Label 2900 3000 2    50   ~ 0
PB6
Text Label 2900 2900 2    50   ~ 0
PB5
Text Label 2900 2800 2    50   ~ 0
PB4
Text Label 2900 2700 2    50   ~ 0
PB3
Text Label 2900 2600 2    50   ~ 0
PB2
Text Label 2900 2500 2    50   ~ 0
PB1
Text Label 2900 2400 2    50   ~ 0
PB0
Text Label 3000 2400 0    50   ~ 0
D8
Text Label 3000 2500 0    50   ~ 0
D9
Text Label 3000 2600 0    50   ~ 0
D10
Text Label 3000 2700 0    50   ~ 0
D11
Text Label 3000 2800 0    50   ~ 0
D12
Text Label 3000 2900 0    50   ~ 0
D13
$Comp
L power:+5V #PWR0101
U 1 1 61CD0CEF
P 2000 1900
F 0 "#PWR0101" H 2000 1750 50  0001 C CNN
F 1 "+5V" H 2015 2073 50  0000 C CNN
F 2 "" H 2000 1900 50  0001 C CNN
F 3 "" H 2000 1900 50  0001 C CNN
	1    2000 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 61CD1151
P 1950 5250
F 0 "#PWR0102" H 1950 5000 50  0001 C CNN
F 1 "GND" H 1955 5077 50  0000 C CNN
F 2 "" H 1950 5250 50  0001 C CNN
F 3 "" H 1950 5250 50  0001 C CNN
	1    1950 5250
	1    0    0    -1  
$EndComp
$Comp
L MAX6675:MAX6675 U2
U 1 1 61CD2646
P 9350 2150
F 0 "U2" V 9446 1620 50  0000 R CNN
F 1 "MAX6675" V 9355 1620 50  0000 R CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 9350 2150 50  0001 L BNN
F 3 "" H 9350 2150 50  0001 L BNN
	1    9350 2150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9450 2650 9450 2850
Wire Wire Line
	9550 2650 9550 2850
Wire Wire Line
	9750 2650 9750 2850
Wire Wire Line
	9250 2650 9250 2850
Wire Wire Line
	9450 1550 9450 1300
Wire Wire Line
	9550 1300 9550 1550
Wire Wire Line
	9650 1550 9650 1300
Text Label 9550 2850 1    50   ~ 0
T+
Text Label 9450 2850 1    50   ~ 0
T-
$Comp
L power:GND #PWR0103
U 1 1 61CDE133
P 9250 2850
F 0 "#PWR0103" H 9250 2600 50  0001 C CNN
F 1 "GND" H 9255 2677 50  0000 C CNN
F 2 "" H 9250 2850 50  0001 C CNN
F 3 "" H 9250 2850 50  0001 C CNN
	1    9250 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 2850 10050 2850
Wire Wire Line
	10050 2850 10050 2600
$Comp
L power:+5V #PWR0104
U 1 1 61CDEEEE
P 10050 2600
F 0 "#PWR0104" H 10050 2450 50  0001 C CNN
F 1 "+5V" H 10065 2773 50  0000 C CNN
F 2 "" H 10050 2600 50  0001 C CNN
F 3 "" H 10050 2600 50  0001 C CNN
	1    10050 2600
	1    0    0    -1  
$EndComp
Text Label 9450 1300 3    50   ~ 0
PD4
Text Label 9550 1300 3    50   ~ 0
PD5
Text Label 9650 1300 3    50   ~ 0
PD6
$Comp
L Device:Rotary_Encoder_Switch SW2
U 1 1 61CE011E
P 10050 4100
F 0 "SW2" H 10050 4467 50  0000 C CNN
F 1 "ENCODER" H 10050 4376 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 9900 4260 50  0001 C CNN
F 3 "~" H 10050 4360 50  0001 C CNN
	1    10050 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 4000 9400 4000
Wire Wire Line
	9750 4100 9650 4100
Wire Wire Line
	9750 4200 9400 4200
Wire Wire Line
	10350 4200 10500 4200
Wire Wire Line
	10350 4000 10500 4000
$Comp
L Device:R_Small_US R2
U 1 1 61CE3B27
P 9300 4000
F 0 "R2" V 9095 4000 50  0000 C CNN
F 1 "10K" V 9186 4000 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 9300 4000 50  0001 C CNN
F 3 "~" H 9300 4000 50  0001 C CNN
	1    9300 4000
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small_US R3
U 1 1 61CE42D5
P 9300 4200
F 0 "R3" V 9400 4200 50  0000 C CNN
F 1 "10K" V 9500 4200 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 9300 4200 50  0001 C CNN
F 3 "~" H 9300 4200 50  0001 C CNN
	1    9300 4200
	0    1    1    0   
$EndComp
Text Label 9450 4000 0    50   ~ 0
PB1
Text Label 9450 4200 0    50   ~ 0
PB0
$Comp
L power:GND #PWR0105
U 1 1 61CE6FB3
P 9650 4450
F 0 "#PWR0105" H 9650 4200 50  0001 C CNN
F 1 "GND" H 9655 4277 50  0000 C CNN
F 2 "" H 9650 4450 50  0001 C CNN
F 3 "" H 9650 4450 50  0001 C CNN
	1    9650 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 4100 9650 4450
Wire Wire Line
	9100 4200 9100 4000
Wire Wire Line
	9100 4000 9200 4000
Wire Wire Line
	9100 4200 9200 4200
Wire Wire Line
	9100 4000 9100 3900
Connection ~ 9100 4000
$Comp
L power:+5V #PWR0106
U 1 1 61CE9781
P 9100 3900
F 0 "#PWR0106" H 9100 3750 50  0001 C CNN
F 1 "+5V" H 9115 4073 50  0000 C CNN
F 2 "" H 9100 3900 50  0001 C CNN
F 3 "" H 9100 3900 50  0001 C CNN
	1    9100 3900
	1    0    0    -1  
$EndComp
NoConn ~ 10500 4200
NoConn ~ 10500 4000
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 61CF83FA
P 1850 6700
F 0 "J1" H 1930 6692 50  0000 L CNN
F 1 "POWER" H 1930 6601 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-2-5.08_1x02_P5.08mm_Horizontal" H 1850 6700 50  0001 C CNN
F 3 "~" H 1850 6700 50  0001 C CNN
	1    1850 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 6700 1550 6700
Wire Wire Line
	1550 6700 1550 6600
Wire Wire Line
	1650 6800 1550 6800
Wire Wire Line
	1550 6800 1550 6900
$Comp
L power:GND #PWR0108
U 1 1 61CFC149
P 1550 6900
F 0 "#PWR0108" H 1550 6650 50  0001 C CNN
F 1 "GND" H 1555 6727 50  0000 C CNN
F 2 "" H 1550 6900 50  0001 C CNN
F 3 "" H 1550 6900 50  0001 C CNN
	1    1550 6900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 61CFC3FF
P 1550 6600
F 0 "#PWR0109" H 1550 6450 50  0001 C CNN
F 1 "+5V" H 1565 6773 50  0000 C CNN
F 2 "" H 1550 6600 50  0001 C CNN
F 3 "" H 1550 6600 50  0001 C CNN
	1    1550 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 6700 1450 6700
Connection ~ 1550 6700
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 61CFEF66
P 1450 6700
F 0 "#FLG0101" H 1450 6775 50  0001 C CNN
F 1 "PWR_FLAG" V 1450 6827 50  0000 L CNN
F 2 "" H 1450 6700 50  0001 C CNN
F 3 "~" H 1450 6700 50  0001 C CNN
	1    1450 6700
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 61CFF560
P 3000 6950
F 0 "J3" H 3080 6942 50  0000 L CNN
F 1 "RELAY" H 3080 6851 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-2-5.08_1x02_P5.08mm_Horizontal" H 3000 6950 50  0001 C CNN
F 3 "~" H 3000 6950 50  0001 C CNN
	1    3000 6950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 61CFFAE0
P 4600 6700
F 0 "J2" H 4680 6692 50  0000 L CNN
F 1 "DISPLAY" H 4680 6601 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B4B-XH-A_1x04_P2.50mm_Vertical" H 4600 6700 50  0001 C CNN
F 3 "~" H 4600 6700 50  0001 C CNN
	1    4600 6700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 61CFFFC9
P 3000 6600
F 0 "J4" H 3080 6592 50  0000 L CNN
F 1 "TEMP_SENS" H 3080 6501 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-2-5.08_1x02_P5.08mm_Horizontal" H 3000 6600 50  0001 C CNN
F 3 "~" H 3000 6600 50  0001 C CNN
	1    3000 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 6600 4150 6600
Wire Wire Line
	4400 6700 4150 6700
Wire Wire Line
	4400 6800 4300 6800
Wire Wire Line
	4400 6900 4300 6900
Wire Wire Line
	2800 6700 2650 6700
Wire Wire Line
	2800 6600 2650 6600
Wire Wire Line
	2800 6950 2650 6950
Text Label 2650 6600 0    50   ~ 0
T+
Text Label 2650 6700 0    50   ~ 0
T-
Wire Wire Line
	4300 6900 4300 7050
Wire Wire Line
	4300 6800 4300 6450
$Comp
L power:+5V #PWR0110
U 1 1 61D17B26
P 4300 6450
F 0 "#PWR0110" H 4300 6300 50  0001 C CNN
F 1 "+5V" H 4315 6623 50  0000 C CNN
F 2 "" H 4300 6450 50  0001 C CNN
F 3 "" H 4300 6450 50  0001 C CNN
	1    4300 6450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 61D17E39
P 4300 7050
F 0 "#PWR0111" H 4300 6800 50  0001 C CNN
F 1 "GND" H 4305 6877 50  0000 C CNN
F 2 "" H 4300 7050 50  0001 C CNN
F 3 "" H 4300 7050 50  0001 C CNN
	1    4300 7050
	1    0    0    -1  
$EndComp
Text Label 3000 3300 0    50   ~ 0
ADC0
Text Label 3000 3400 0    50   ~ 0
ADC1
Text Label 3000 3500 0    50   ~ 0
ADC2
Text Label 3000 3600 0    50   ~ 0
ADC3
Text Label 3000 3700 0    50   ~ 0
ADC4
Text Label 3000 3800 0    50   ~ 0
ADC5
Text Label 3000 3900 0    50   ~ 0
RESET
Text Label 3350 3800 0    50   ~ 0
SCL
Text Label 3350 3700 0    50   ~ 0
SDA
Text Label 4150 6600 0    50   ~ 0
PC4
Text Label 4150 6700 0    50   ~ 0
PC5
$Comp
L Device:C_Small C4
U 1 1 61CEE4C8
P 5650 4250
F 0 "C4" H 5742 4296 50  0000 L CNN
F 1 "100n" H 5742 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 5650 4250 50  0001 C CNN
F 3 "~" H 5650 4250 50  0001 C CNN
	1    5650 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 61CEEE25
P 5250 4250
F 0 "C3" H 5342 4296 50  0000 L CNN
F 1 "100n" H 5342 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 5250 4250 50  0001 C CNN
F 3 "~" H 5250 4250 50  0001 C CNN
	1    5250 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C5
U 1 1 61CEF744
P 6100 4250
F 0 "C5" H 6192 4296 50  0000 L CNN
F 1 "100n" H 6192 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 6100 4250 50  0001 C CNN
F 3 "~" H 6100 4250 50  0001 C CNN
	1    6100 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 61CF0201
P 6550 4250
F 0 "C6" H 6642 4296 50  0000 L CNN
F 1 "100n" H 6642 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 6550 4250 50  0001 C CNN
F 3 "~" H 6550 4250 50  0001 C CNN
	1    6550 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 61CF0926
P 7000 4250
F 0 "C7" H 7092 4296 50  0000 L CNN
F 1 "100n" H 7092 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 7000 4250 50  0001 C CNN
F 3 "~" H 7000 4250 50  0001 C CNN
	1    7000 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4350 5250 4500
Wire Wire Line
	5250 4500 5650 4500
Wire Wire Line
	5650 4500 5650 4350
Wire Wire Line
	6100 4350 6100 4500
Wire Wire Line
	6100 4500 5900 4500
Connection ~ 5650 4500
Wire Wire Line
	6550 4350 6550 4500
Wire Wire Line
	6550 4500 6100 4500
Connection ~ 6100 4500
Wire Wire Line
	7000 4350 7000 4500
Wire Wire Line
	7000 4500 6550 4500
Connection ~ 6550 4500
Wire Wire Line
	5250 4150 5250 4000
Wire Wire Line
	5250 4000 5650 4000
Wire Wire Line
	5650 4000 5650 4150
Wire Wire Line
	6100 4150 6100 4000
Wire Wire Line
	6100 4000 5850 4000
Connection ~ 5650 4000
Wire Wire Line
	6550 4150 6550 4000
Wire Wire Line
	6550 4000 6100 4000
Connection ~ 6100 4000
Wire Wire Line
	7000 4150 7000 4000
Wire Wire Line
	5850 4000 5850 3850
Connection ~ 5850 4000
Wire Wire Line
	5850 4000 5650 4000
Wire Wire Line
	5900 4500 5900 4650
Connection ~ 5900 4500
Wire Wire Line
	5900 4500 5650 4500
$Comp
L power:+5V #PWR0112
U 1 1 61D0E03D
P 5850 3850
F 0 "#PWR0112" H 5850 3700 50  0001 C CNN
F 1 "+5V" H 5865 4023 50  0000 C CNN
F 2 "" H 5850 3850 50  0001 C CNN
F 3 "" H 5850 3850 50  0001 C CNN
	1    5850 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 61D0E5DC
P 5900 4650
F 0 "#PWR0113" H 5900 4400 50  0001 C CNN
F 1 "GND" H 5905 4477 50  0000 C CNN
F 2 "" H 5900 4650 50  0001 C CNN
F 3 "" H 5900 4650 50  0001 C CNN
	1    5900 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2750 4800 2900
$Comp
L power:GND #PWR0114
U 1 1 61D1216B
P 4800 2900
F 0 "#PWR0114" H 4800 2650 50  0001 C CNN
F 1 "GND" H 4805 2727 50  0000 C CNN
F 2 "" H 4800 2900 50  0001 C CNN
F 3 "" H 4800 2900 50  0001 C CNN
	1    4800 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 61D12488
P 5650 2400
F 0 "R1" V 5445 2400 50  0000 C CNN
F 1 "10K" V 5536 2400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 5650 2400 50  0001 C CNN
F 3 "~" H 5650 2400 50  0001 C CNN
	1    5650 2400
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 2300 5650 2150
$Comp
L power:+5V #PWR0115
U 1 1 61D1A879
P 5650 2150
F 0 "#PWR0115" H 5650 2000 50  0001 C CNN
F 1 "+5V" H 5665 2323 50  0000 C CNN
F 2 "" H 5650 2150 50  0001 C CNN
F 3 "" H 5650 2150 50  0001 C CNN
	1    5650 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 2100 1950 2000
Wire Wire Line
	1950 2000 2000 2000
Wire Wire Line
	2050 2000 2050 2100
Wire Wire Line
	2000 1900 2000 2000
Connection ~ 2000 2000
Wire Wire Line
	2000 2000 2050 2000
Text Label 1100 2400 0    50   ~ 0
AREF
Text Label 7000 4000 3    50   ~ 0
AREF
$Comp
L Device:Crystal_Small Y1
U 1 1 61D27ECB
P 6950 2200
F 0 "Y1" H 6950 2425 50  0000 C CNN
F 1 "16MHZ" H 6950 2334 50  0000 C CNN
F 2 "Crystal:Crystal_HC50_Vertical" H 6950 2200 50  0001 C CNN
F 3 "~" H 6950 2200 50  0001 C CNN
	1    6950 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 61D2844C
P 6700 2500
F 0 "C1" H 6792 2546 50  0000 L CNN
F 1 "22p" H 6792 2455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 6700 2500 50  0001 C CNN
F 3 "~" H 6700 2500 50  0001 C CNN
	1    6700 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C2
U 1 1 61D28913
P 7200 2500
F 0 "C2" H 7292 2546 50  0000 L CNN
F 1 "22p" H 7292 2455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 7200 2500 50  0001 C CNN
F 3 "~" H 7200 2500 50  0001 C CNN
	1    7200 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 2200 6700 2200
Wire Wire Line
	6700 2200 6700 2400
Wire Wire Line
	7050 2200 7200 2200
Wire Wire Line
	7200 2200 7200 2400
Wire Wire Line
	7200 2600 7200 2750
Wire Wire Line
	7200 2750 6950 2750
Wire Wire Line
	6700 2750 6700 2600
Wire Wire Line
	6950 2750 6950 2850
Connection ~ 6950 2750
Wire Wire Line
	6950 2750 6700 2750
$Comp
L power:GND #PWR0116
U 1 1 61D444E0
P 6950 2850
F 0 "#PWR0116" H 6950 2600 50  0001 C CNN
F 1 "GND" H 6955 2677 50  0000 C CNN
F 2 "" H 6950 2850 50  0001 C CNN
F 3 "" H 6950 2850 50  0001 C CNN
	1    6950 2850
	1    0    0    -1  
$EndComp
Text Label 7150 2200 0    50   ~ 0
PB6
Text Label 6750 2200 2    50   ~ 0
PB7
Text Label 2650 6950 0    50   ~ 0
PD3
Wire Wire Line
	2550 7050 2550 7100
Wire Wire Line
	2550 7050 2800 7050
$Comp
L power:GND #PWR0117
U 1 1 61D76E16
P 2550 7100
F 0 "#PWR0117" H 2550 6850 50  0001 C CNN
F 1 "GND" H 2555 6927 50  0000 C CNN
F 2 "" H 2550 7100 50  0001 C CNN
F 3 "" H 2550 7100 50  0001 C CNN
	1    2550 7100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J5
U 1 1 61D9D25D
P 6000 6700
F 0 "J5" H 6080 6692 50  0000 L CNN
F 1 "PROGRAMMER" H 6080 6601 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 6000 6700 50  0001 C CNN
F 3 "~" H 6000 6700 50  0001 C CNN
	1    6000 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 7000 5700 7000
Wire Wire Line
	5700 7000 5700 7100
$Comp
L power:GND #PWR0118
U 1 1 61DA2461
P 5700 7100
F 0 "#PWR0118" H 5700 6850 50  0001 C CNN
F 1 "GND" H 5705 6927 50  0000 C CNN
F 2 "" H 5700 7100 50  0001 C CNN
F 3 "" H 5700 7100 50  0001 C CNN
	1    5700 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 6900 5450 6900
Wire Wire Line
	5800 6800 5700 6800
Wire Wire Line
	5800 6700 5450 6700
Wire Wire Line
	5800 6600 5450 6600
Wire Wire Line
	5800 6500 5450 6500
NoConn ~ 5450 6900
Wire Wire Line
	5700 6800 5700 6400
$Comp
L power:+5V #PWR0119
U 1 1 61DC7DB9
P 5700 6400
F 0 "#PWR0119" H 5700 6250 50  0001 C CNN
F 1 "+5V" H 5715 6573 50  0000 C CNN
F 2 "" H 5700 6400 50  0001 C CNN
F 3 "" H 5700 6400 50  0001 C CNN
	1    5700 6400
	1    0    0    -1  
$EndComp
Text Label 5150 6700 0    50   ~ 0
TX
Text Label 5150 6600 0    50   ~ 0
RX
Text Label 5150 6500 0    50   ~ 0
DTR
Text Label 5450 6500 0    50   ~ 0
PC6
Text Label 5450 6700 0    50   ~ 0
PD0
Text Label 5450 6600 0    50   ~ 0
PD1
Text Label 3350 4100 0    50   ~ 0
TX
Text Label 3350 4200 0    50   ~ 0
RX
Wire Wire Line
	2550 4300 2900 4300
NoConn ~ 2900 4800
NoConn ~ 2900 4300
NoConn ~ 2900 3600
NoConn ~ 2900 3500
NoConn ~ 2900 3400
NoConn ~ 2900 3300
NoConn ~ 2900 2900
NoConn ~ 2900 2800
Wire Wire Line
	1450 6800 1550 6800
Connection ~ 1550 6800
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 61D2C7A5
P 1450 6800
F 0 "#FLG0102" H 1450 6875 50  0001 C CNN
F 1 "PWR_FLAG" V 1450 6927 50  0000 L CNN
F 2 "" H 1450 6800 50  0001 C CNN
F 3 "~" H 1450 6800 50  0001 C CNN
	1    1450 6800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9450 5900 9350 5900
Wire Wire Line
	9350 5900 9350 6000
Wire Wire Line
	9450 5400 9350 5400
Connection ~ 9350 5900
$Comp
L power:GND #PWR0107
U 1 1 61DEDC09
P 9350 6000
F 0 "#PWR0107" H 9350 5750 50  0001 C CNN
F 1 "GND" H 9355 5827 50  0000 C CNN
F 2 "" H 9350 6000 50  0001 C CNN
F 3 "" H 9350 6000 50  0001 C CNN
	1    9350 6000
	1    0    0    -1  
$EndComp
Text Label 10100 5900 2    50   ~ 0
PB3
Wire Wire Line
	5650 2750 5550 2750
Wire Wire Line
	5650 2750 6000 2750
Connection ~ 5650 2750
Text Label 6000 2750 2    50   ~ 0
PC6
Wire Wire Line
	4800 2750 5150 2750
Wire Wire Line
	5650 2500 5650 2750
Wire Wire Line
	9850 5400 10100 5400
Wire Wire Line
	9850 5900 10100 5900
Wire Wire Line
	9350 5400 9350 5900
Text Label 10100 5400 2    50   ~ 0
PB2
$Comp
L Switch:SW_Push SW4
U 1 1 61D66C9E
P 9650 5900
F 0 "SW4" H 9650 6185 50  0000 C CNN
F 1 "SW_Push" H 9650 6094 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 9650 6100 50  0001 C CNN
F 3 "~" H 9650 6100 50  0001 C CNN
	1    9650 5900
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 61D6EC05
P 9650 5400
F 0 "SW3" H 9650 5685 50  0000 C CNN
F 1 "SW_Push" H 9650 5594 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 9650 5600 50  0001 C CNN
F 3 "~" H 9650 5600 50  0001 C CNN
	1    9650 5400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 61D6F0BE
P 5350 2750
F 0 "SW1" H 5350 3035 50  0000 C CNN
F 1 "RESET" H 5350 2944 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5350 2950 50  0001 C CNN
F 3 "~" H 5350 2950 50  0001 C CNN
	1    5350 2750
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 61D815EF
P 7150 6150
F 0 "H1" H 7250 6196 50  0000 L CNN
F 1 "MountingHole" H 7250 6105 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7150 6150 50  0001 C CNN
F 3 "~" H 7150 6150 50  0001 C CNN
	1    7150 6150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 61D81A3D
P 7850 6150
F 0 "H2" H 7950 6196 50  0000 L CNN
F 1 "MountingHole" H 7950 6105 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7850 6150 50  0001 C CNN
F 3 "~" H 7850 6150 50  0001 C CNN
	1    7850 6150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 61D81D64
P 7150 6350
F 0 "H3" H 7250 6396 50  0000 L CNN
F 1 "MountingHole" H 7250 6305 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7150 6350 50  0001 C CNN
F 3 "~" H 7150 6350 50  0001 C CNN
	1    7150 6350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 61D82002
P 7850 6350
F 0 "H4" H 7950 6396 50  0000 L CNN
F 1 "MountingHole" H 7950 6305 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7850 6350 50  0001 C CNN
F 3 "~" H 7850 6350 50  0001 C CNN
	1    7850 6350
	1    0    0    -1  
$EndComp
$EndSCHEMATC

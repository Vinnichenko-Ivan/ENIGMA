EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A2 23386 16535
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
L MCU_Module:Arduino_Nano_v3.x gyroController1
U 1 1 5F0E46C3
P 7350 7100
F 0 "gyroController1" H 7350 6011 50  0000 C CNN
F 1 "gyroController" H 7350 5920 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 7350 7100 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 7350 7100 50  0001 C CNN
	1    7350 7100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male testMotorController1
U 1 1 5E1BC56F
P 4450 5750
F 0 "testMotorController1" V 4512 5894 50  0000 L CNN
F 1 "testMotorController" V 4603 5894 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 4450 5750 50  0001 C CNN
F 3 "~" H 4450 5750 50  0001 C CNN
	1    4450 5750
	0    1    1    0   
$EndComp
$Comp
L Sensor_Temperature:mlx U7
U 1 1 5E4DBB28
P 7850 10700
F 0 "U7" H 8180 10746 50  0000 L CNN
F 1 "mlx" H 8180 10655 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7850 10700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm75b.pdf" H 7850 10700 50  0001 C CNN
	1    7850 10700
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:2N3904 Q2
U 1 1 5E4DBB2E
P 7200 10800
F 0 "Q2" H 7390 10846 50  0000 L CNN
F 1 "2N3904" H 7390 10755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 7400 10725 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 7200 10800 50  0001 L CNN
	1    7200 10800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 10600 7450 10600
Wire Wire Line
	7300 12000 7300 11000
Wire Wire Line
	7450 10700 7450 12100
$Comp
L Sensor_Temperature:mlx U6
U 1 1 5E4DBB37
P 6450 10700
F 0 "U6" H 6780 10746 50  0000 L CNN
F 1 "mlx" H 6780 10655 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6450 10700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm75b.pdf" H 6450 10700 50  0001 C CNN
	1    6450 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 10600 6050 10600
Wire Wire Line
	5900 12000 5900 11000
Wire Wire Line
	6050 10700 6050 12100
Wire Wire Line
	7300 12000 5900 12000
Wire Wire Line
	6050 12100 7450 12100
Wire Wire Line
	6450 11200 7350 11200
Wire Wire Line
	7850 10200 6450 10200
Wire Wire Line
	6450 11200 5950 11200
Connection ~ 6450 11200
$Comp
L Device:R rMLX1
U 1 1 5E4DBB76
P 5750 10400
F 0 "rMLX1" V 5543 10400 50  0000 C CNN
F 1 "10000" V 5634 10400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5680 10400 50  0001 C CNN
F 3 "~" H 5750 10400 50  0001 C CNN
	1    5750 10400
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 10400 5600 10800
Wire Wire Line
	5900 10400 5950 10400
Wire Wire Line
	5950 10400 5950 11200
Connection ~ 5950 11200
Wire Wire Line
	5950 11200 5400 11200
Wire Wire Line
	7300 10400 7350 10400
Wire Wire Line
	7350 10400 7350 11200
Connection ~ 7350 11200
Wire Wire Line
	7350 11200 7850 11200
$Comp
L Transistor_BJT:2N3904 Q1
U 1 1 5E4DBB3D
P 5800 10800
F 0 "Q1" H 5990 10846 50  0000 L CNN
F 1 "2N3904" H 5990 10755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 6000 10725 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 5800 10800 50  0001 L CNN
	1    5800 10800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 10400 7000 10800
$Comp
L Device:R rMLX2
U 1 1 5E4DBB70
P 7150 10400
F 0 "rMLX2" V 6943 10400 50  0000 C CNN
F 1 "10000" V 7034 10400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 7080 10400 50  0001 C CNN
F 3 "~" H 7150 10400 50  0001 C CNN
	1    7150 10400
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push resetButtonGyroArduino1
U 1 1 5E999F57
P 8050 6600
F 0 "resetButtonGyroArduino1" H 8050 6885 50  0000 C CNN
F 1 "resetButtonGyroArduino" H 8050 6794 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 8050 6800 50  0001 C CNN
F 3 "~" H 8050 6800 50  0001 C CNN
	1    8050 6600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push resetButtonMotorArduino1
U 1 1 5E9DE35F
P 5050 6550
F 0 "resetButtonMotorArduino1" H 5050 6835 50  0000 C CNN
F 1 "resetButtonMotorArduino" H 5050 6744 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5050 6750 50  0001 C CNN
F 3 "~" H 5050 6750 50  0001 C CNN
	1    5050 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 8100 8250 6600
Connection ~ 7450 8100
Wire Wire Line
	5250 8050 5250 6550
Connection ~ 7000 10400
Connection ~ 5600 10400
Wire Wire Line
	7000 9850 7000 10400
Wire Wire Line
	7350 8100 7450 8100
Connection ~ 7350 8100
Connection ~ 4350 8050
$Comp
L Sensor_Motion:MPU-6050A U1
U 1 1 608D5ED6
P 9050 7800
F 0 "U1" H 9050 8681 50  0000 C CNN
F 1 "MPU-6050A" H 9050 8590 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Horizontal" H 9050 7000 50  0001 C CNN
F 3 "https://store.invensense.com/datasheets/invensense/MPU-6050_DataSheet_V3%204.pdf" H 9050 7650 50  0001 C CNN
	1    9050 7800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 7600 7850 7600
Wire Wire Line
	8350 7500 7850 7500
Wire Wire Line
	9150 7100 9150 5600
Wire Wire Line
	9150 5600 7450 5600
Wire Wire Line
	9050 8500 8250 8500
Wire Wire Line
	8250 8500 8250 8100
Connection ~ 8250 8100
$Comp
L Device:LED LedArduinoGyro2
U 1 1 60B32A88
P 6750 7750
F 0 "LedArduinoGyro2" H 6743 7966 50  0000 C CNN
F 1 "LedArduinoGyro" H 6743 7875 50  0000 C CNN
F 2 "LED_SMD:LED_PLCC_2835" H 6750 7750 50  0001 C CNN
F 3 "~" H 6750 7750 50  0001 C CNN
	1    6750 7750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 60B32A8E
P 6750 8050
F 0 "R4" H 6820 8096 50  0000 L CNN
F 1 "220" H 6820 8005 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 6680 8050 50  0001 C CNN
F 3 "~" H 6750 8050 50  0001 C CNN
	1    6750 8050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 7600 6750 7600
Wire Wire Line
	7350 8200 6750 8200
$Comp
L Device:R R5
U 1 1 60C66FA2
P 7700 8650
F 0 "R5" V 7493 8650 50  0000 C CNN
F 1 "10000" V 7584 8650 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 7630 8650 50  0001 C CNN
F 3 "~" H 7700 8650 50  0001 C CNN
	1    7700 8650
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push calibrateButtonGyroArduino2
U 1 1 60C66FA8
P 7250 8650
F 0 "calibrateButtonGyroArduino2" H 7250 8935 50  0000 C CNN
F 1 "calibrateButtonGyroArduino" H 7250 8844 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 7250 8850 50  0001 C CNN
F 3 "~" H 7250 8850 50  0001 C CNN
	1    7250 8650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 8650 7500 8650
Wire Wire Line
	7850 8650 7850 8100
Wire Wire Line
	7450 8100 7850 8100
Connection ~ 7850 8100
Wire Wire Line
	7850 8100 8250 8100
Wire Wire Line
	7050 8650 7050 6300
Wire Wire Line
	7050 6300 7550 6300
Wire Wire Line
	7550 6300 7550 6100
Connection ~ 7550 6100
Wire Wire Line
	7350 8200 7350 8100
Wire Wire Line
	7500 8650 7500 8750
Wire Wire Line
	7500 8750 6600 8750
Wire Wire Line
	6600 8750 6600 7500
Wire Wire Line
	6600 7500 6850 7500
Connection ~ 7500 8650
Wire Wire Line
	7500 8650 7550 8650
$Comp
L Connector:Conn_01x02_Male RX/TXgyroArduino1
U 1 1 60F275F9
P 6600 6500
F 0 "RX/TXgyroArduino1" H 6708 6681 50  0000 C CNN
F 1 "RX/TXgyroArduino" H 6708 6590 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6600 6500 50  0001 C CNN
F 3 "~" H 6600 6500 50  0001 C CNN
	1    6600 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 6500 6800 6500
Wire Wire Line
	6850 6600 6800 6600
$Comp
L Connector:Conn_01x08_Male 3.3V1
U 1 1 6106EB3D
P 3700 5750
F 0 "3.3V1" H 3808 6231 50  0000 C CNN
F 1 "3.3V" H 3808 6140 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 3700 5750 50  0001 C CNN
F 3 "~" H 3700 5750 50  0001 C CNN
	1    3700 5750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Male 5V1
U 1 1 6106EB43
P 3700 4800
F 0 "5V1" H 3808 5281 50  0000 C CNN
F 1 "5V" H 3808 5190 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 3700 4800 50  0001 C CNN
F 3 "~" H 3700 4800 50  0001 C CNN
	1    3700 4800
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Male GND1
U 1 1 6106EB49
P 3700 3850
F 0 "GND1" H 3808 4331 50  0000 C CNN
F 1 "GND" H 3808 4240 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 3700 3850 50  0001 C CNN
F 3 "~" H 3700 3850 50  0001 C CNN
	1    3700 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 5950 4450 5450
Wire Wire Line
	4450 5450 3900 5450
Connection ~ 4450 5950
Wire Wire Line
	3900 6150 3900 6050
Connection ~ 3900 5450
Connection ~ 3900 5550
Wire Wire Line
	3900 5550 3900 5450
Connection ~ 3900 5650
Wire Wire Line
	3900 5650 3900 5550
Connection ~ 3900 5750
Wire Wire Line
	3900 5750 3900 5650
Connection ~ 3900 5850
Wire Wire Line
	3900 5850 3900 5750
Connection ~ 3900 5950
Wire Wire Line
	3900 5950 3900 5850
Connection ~ 3900 6050
Wire Wire Line
	3900 6050 3900 5950
Wire Wire Line
	3900 5200 3900 5100
Connection ~ 3900 4600
Wire Wire Line
	3900 4600 3900 4500
Connection ~ 3900 4700
Wire Wire Line
	3900 4700 3900 4600
Connection ~ 3900 4800
Wire Wire Line
	3900 4800 3900 4700
Connection ~ 3900 4900
Wire Wire Line
	3900 4900 3900 4800
Connection ~ 3900 5000
Wire Wire Line
	3900 5000 3900 4900
Connection ~ 3900 5100
Wire Wire Line
	3900 5100 3900 5000
Wire Wire Line
	3900 4500 4550 4500
Wire Wire Line
	4550 4500 4550 5950
Connection ~ 3900 4500
Connection ~ 4550 5950
Connection ~ 3900 3650
Wire Wire Line
	3900 3650 3900 3550
Connection ~ 3900 3750
Wire Wire Line
	3900 3750 3900 3650
Connection ~ 3900 3850
Wire Wire Line
	3900 3850 3900 3750
Connection ~ 3900 3950
Wire Wire Line
	3900 3950 3900 3850
Connection ~ 3900 4050
Wire Wire Line
	3900 4050 3900 3950
Connection ~ 3900 4150
Wire Wire Line
	3900 4150 3900 4050
Wire Wire Line
	3900 3550 4350 3550
Wire Wire Line
	4350 3550 4350 5950
Connection ~ 3900 3550
Connection ~ 4350 5950
$Comp
L Device:R R3
U 1 1 615D7344
P 4700 8600
F 0 "R3" V 4493 8600 50  0000 C CNN
F 1 "10000" V 4584 8600 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4630 8600 50  0001 C CNN
F 3 "~" H 4700 8600 50  0001 C CNN
	1    4700 8600
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push calibrateButtonGyroArduino1
U 1 1 615D734A
P 4250 8600
F 0 "calibrateButtonGyroArduino1" H 4250 8885 50  0000 C CNN
F 1 "calibrateButtonGyroArduino" H 4250 8794 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4250 8800 50  0001 C CNN
F 3 "~" H 4250 8800 50  0001 C CNN
	1    4250 8600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 8600 4500 8600
Wire Wire Line
	4850 8600 4850 8050
Wire Wire Line
	4500 8600 4500 8700
Connection ~ 4500 8600
Wire Wire Line
	4500 8600 4550 8600
Connection ~ 4850 8050
Wire Wire Line
	4850 8050 4950 8050
Wire Wire Line
	3350 8700 4500 8700
Wire Wire Line
	4050 8600 4050 6300
Wire Wire Line
	4050 6300 4550 6300
$Comp
L Connector:Conn_01x02_Male RX/TXmotorArduino1
U 1 1 61A10862
P 3600 6450
F 0 "RX/TXmotorArduino1" H 3708 6631 50  0000 C CNN
F 1 "RX/TXmotorArduino" H 3708 6540 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3600 6450 50  0001 C CNN
F 3 "~" H 3600 6450 50  0001 C CNN
	1    3600 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 6450 3800 6450
Wire Wire Line
	3850 6550 3800 6550
$Comp
L Switch:SW_DPST_x2 powerGyroController1
U 1 1 61F1BC4C
P 7050 5450
F 0 "powerGyroController1" H 7050 5593 50  0000 C CNN
F 1 "powerGyroController" H 7050 5593 50  0001 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 7050 5450 50  0001 C CNN
F 3 "~" H 7050 5450 50  0001 C CNN
	1    7050 5450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPST_x2 powerMotorController1
U 1 1 61F9DD32
P 4450 5300
F 0 "powerMotorController1" H 4450 5443 50  0000 C CNN
F 1 "powerGyroController" H 4450 5443 50  0001 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 4450 5300 50  0001 C CNN
F 3 "~" H 4450 5300 50  0001 C CNN
	1    4450 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 5450 6200 5450
Wire Wire Line
	6200 5450 6200 9150
Wire Wire Line
	4250 5300 4250 5950
Connection ~ 4250 5950
Wire Wire Line
	4650 5300 6200 5300
Wire Wire Line
	6200 5300 6200 5450
Connection ~ 6200 5450
Wire Wire Line
	6200 9150 9700 9150
Wire Wire Line
	6450 8050 6450 8200
Wire Wire Line
	6450 8200 6750 8200
Connection ~ 5250 8050
Connection ~ 6750 8200
Wire Wire Line
	9050 8500 10250 8500
Connection ~ 9050 8500
$Comp
L Connector:Conn_01x02_Male PowerPlateConn1
U 1 1 62540A9C
P 10000 10850
F 0 "PowerPlateConn1" H 10108 11031 50  0000 C CNN
F 1 "PowerPlateConn" H 10108 10940 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 10000 10850 50  0001 C CNN
F 3 "~" H 10000 10850 50  0001 C CNN
	1    10000 10850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9700 9500 10100 9500
Wire Wire Line
	10100 9500 10100 10650
Wire Wire Line
	9700 9500 9700 9150
Wire Wire Line
	10000 9600 10250 9600
$Comp
L Device:Buzzer BZ1
U 1 1 5E036409
P 2900 7650
F 0 "BZ1" H 2905 7325 50  0000 C CNN
F 1 "Buzzer" H 2905 7416 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" V 2875 7750 50  0001 C CNN
F 3 "~" V 2875 7750 50  0001 C CNN
	1    2900 7650
	-1   0    0    1   
$EndComp
$Comp
L Motor:Motor_Servo M1
U 1 1 5E03944E
P 2650 7150
F 0 "M1" H 2644 6843 50  0000 C CNN
F 1 "Motor_Servo" H 2644 6934 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2650 6960 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 2650 6960 50  0001 C CNN
	1    2650 7150
	-1   0    0    1   
$EndComp
$Comp
L Device:LED Ledsignal1
U 1 1 5E03ADEB
P 2800 8100
F 0 "Ledsignal1" H 2793 8316 50  0000 C CNN
F 1 "Ledsignal" H 2793 8225 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 2800 8100 50  0001 C CNN
F 3 "~" H 2800 8100 50  0001 C CNN
	1    2800 8100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5E03ADF1
P 2500 8100
F 0 "R1" H 2570 8146 50  0000 L CNN
F 1 "220" H 2570 8055 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 2430 8100 50  0001 C CNN
F 3 "~" H 2500 8100 50  0001 C CNN
	1    2500 8100
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 8100 2350 7450
Wire Wire Line
	2350 6700 2950 6700
Wire Wire Line
	2950 6700 2950 7050
Wire Wire Line
	3000 7550 3000 7450
Wire Wire Line
	3000 7450 2350 7450
Connection ~ 2350 7450
Wire Wire Line
	2350 7450 2350 6700
Wire Wire Line
	2350 6700 2350 4200
Wire Wire Line
	2350 4200 3900 4200
Wire Wire Line
	3900 4150 3900 4200
Connection ~ 2350 6700
Connection ~ 3900 4200
Wire Wire Line
	3900 4200 3900 4250
Wire Wire Line
	2950 7150 3100 7150
Wire Wire Line
	3200 7150 3200 5200
Wire Wire Line
	3200 5200 3900 5200
Connection ~ 3900 5200
Wire Wire Line
	2950 7250 3250 7250
Wire Wire Line
	3250 7250 3250 6750
Wire Wire Line
	3250 6750 3850 6750
Wire Wire Line
	3000 7750 3500 7750
Wire Wire Line
	3500 7750 3500 6950
Wire Wire Line
	3500 6950 3850 6950
Connection ~ 7250 6000
Wire Wire Line
	7250 6000 7250 5450
Connection ~ 7450 6000
Wire Wire Line
	7450 5600 7450 6000
Wire Wire Line
	7550 6100 7550 6000
Wire Wire Line
	7450 6000 7450 6100
Wire Wire Line
	7350 8100 7350 6000
Wire Wire Line
	7250 6100 7250 6000
$Comp
L Connector:Conn_01x04_Male testGyroController1
U 1 1 5E2F5D55
P 7450 5800
F 0 "testGyroController1" V 7512 5944 50  0000 L CNN
F 1 "testGyroController" V 7603 5944 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7450 5800 50  0001 C CNN
F 3 "~" H 7450 5800 50  0001 C CNN
	1    7450 5800
	0    1    1    0   
$EndComp
Connection ~ 10000 9600
Connection ~ 9700 9500
Wire Wire Line
	10000 10650 10000 9600
Wire Wire Line
	10000 9600 9300 9600
$Comp
L Switch:SW_DPST_x2 powerRaspb1
U 1 1 62608983
P 9500 9500
F 0 "powerRaspb1" H 9500 9643 50  0000 C CNN
F 1 "powerGyroController" H 9500 9643 50  0001 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 9500 9500 50  0001 C CNN
F 3 "~" H 9500 9500 50  0001 C CNN
	1    9500 9500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male PowerRaspbConn1
U 1 1 62518135
P 9100 9500
F 0 "PowerRaspbConn1" H 9208 9681 50  0000 C CNN
F 1 "PowerRaspbConn" H 9208 9590 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9100 9500 50  0001 C CNN
F 3 "~" H 9100 9500 50  0001 C CNN
	1    9100 9500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6650 3350 8700
Wire Wire Line
	3350 6650 3850 6650
Wire Wire Line
	4450 5950 4450 6050
Wire Wire Line
	4350 8050 4350 5950
Wire Wire Line
	4250 6050 4250 5950
Wire Wire Line
	4450 8050 4850 8050
Wire Wire Line
	4350 8050 4450 8050
Connection ~ 4450 8050
Wire Wire Line
	4550 6050 4550 5950
Wire Wire Line
	4550 6300 4550 6050
Connection ~ 4550 6050
$Comp
L MCU_Module:Arduino_Nano_v3.x motorController1
U 1 1 5E05AF20
P 4350 7050
F 0 "motorController1" H 4350 5961 50  0000 C CNN
F 1 "motorController" H 4350 5870 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 4350 7050 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 4350 7050 50  0001 C CNN
	1    4350 7050
	1    0    0    -1  
$EndComp
Connection ~ 6800 6600
$Comp
L HC-SR04:HC-SR04 U4
U 1 1 5E0607DD
P 2500 10250
F 0 "U4" H 2930 10246 50  0000 L CNN
F 1 "HC-SR04" H 2930 10155 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Horizontal" H 2500 10250 50  0001 L BNN
F 3 "Unavailable" H 2500 10250 50  0001 L BNN
F 4 "None" H 2500 10250 50  0001 L BNN "Field4"
F 5 "OSEPP Electronics" H 2500 10250 50  0001 L BNN "Field5"
F 6 "HC-SR04 Ultrasonic Sensor Platform Evaluation Expansion Board" H 2500 10250 50  0001 L BNN "Field6"
F 7 "None" H 2500 10250 50  0001 L BNN "Field7"
F 8 "HC-SR04" H 2500 10250 50  0001 L BNN "Field8"
	1    2500 10250
	-1   0    0    1   
$EndComp
$Comp
L HC-SR04:HC-SR04 U3
U 1 1 5E0607E8
P 2500 9700
F 0 "U3" H 2930 9696 50  0000 L CNN
F 1 "HC-SR04" H 2930 9605 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Horizontal" H 2500 9700 50  0001 L BNN
F 3 "Unavailable" H 2500 9700 50  0001 L BNN
F 4 "None" H 2500 9700 50  0001 L BNN "Field4"
F 5 "OSEPP Electronics" H 2500 9700 50  0001 L BNN "Field5"
F 6 "HC-SR04 Ultrasonic Sensor Platform Evaluation Expansion Board" H 2500 9700 50  0001 L BNN "Field6"
F 7 "None" H 2500 9700 50  0001 L BNN "Field7"
F 8 "HC-SR04" H 2500 9700 50  0001 L BNN "Field8"
	1    2500 9700
	-1   0    0    1   
$EndComp
$Comp
L HC-SR04:HC-SR04 U2
U 1 1 5E0607F3
P 2500 9150
F 0 "U2" H 2930 9146 50  0000 L CNN
F 1 "HC-SR04" H 2930 9055 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Horizontal" H 2500 9150 50  0001 L BNN
F 3 "Unavailable" H 2500 9150 50  0001 L BNN
F 4 "None" H 2500 9150 50  0001 L BNN "Field4"
F 5 "OSEPP Electronics" H 2500 9150 50  0001 L BNN "Field5"
F 6 "HC-SR04 Ultrasonic Sensor Platform Evaluation Expansion Board" H 2500 9150 50  0001 L BNN "Field6"
F 7 "None" H 2500 9150 50  0001 L BNN "Field7"
F 8 "HC-SR04" H 2500 9150 50  0001 L BNN "Field8"
	1    2500 9150
	-1   0    0    1   
$EndComp
$Comp
L HC-SR04:HC-SR04 U5
U 1 1 5E0607FE
P 2500 10800
F 0 "U5" H 2930 10796 50  0000 L CNN
F 1 "HC-SR04" H 2930 10705 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Horizontal" H 2500 10800 50  0001 L BNN
F 3 "Unavailable" H 2500 10800 50  0001 L BNN
F 4 "None" H 2500 10800 50  0001 L BNN "Field4"
F 5 "OSEPP Electronics" H 2500 10800 50  0001 L BNN "Field5"
F 6 "HC-SR04 Ultrasonic Sensor Platform Evaluation Expansion Board" H 2500 10800 50  0001 L BNN "Field6"
F 7 "None" H 2500 10800 50  0001 L BNN "Field7"
F 8 "HC-SR04" H 2500 10800 50  0001 L BNN "Field8"
	1    2500 10800
	-1   0    0    1   
$EndComp
Wire Wire Line
	10250 8500 10250 9600
Wire Wire Line
	5400 11200 5400 8050
Wire Wire Line
	5250 8050 5400 8050
Connection ~ 5400 8050
Wire Wire Line
	5400 8050 6450 8050
Wire Wire Line
	6450 10200 6450 9350
Wire Wire Line
	6450 9350 3200 9350
Wire Wire Line
	3200 9350 3200 8400
Wire Wire Line
	3200 8400 1850 8400
Wire Wire Line
	1850 8400 1850 3350
Wire Wire Line
	1850 3350 4950 3350
Wire Wire Line
	4950 3350 4950 6050
Wire Wire Line
	4950 6050 4550 6050
Connection ~ 6450 10200
Wire Wire Line
	5600 7750 4850 7750
Wire Wire Line
	5600 7750 5600 10400
Wire Wire Line
	7000 9850 5700 9850
Wire Wire Line
	5700 9850 5700 7650
Wire Wire Line
	5700 7650 4850 7650
Wire Wire Line
	6050 12100 5100 12100
Wire Wire Line
	5100 12100 5100 7550
Wire Wire Line
	5100 7550 4850 7550
Connection ~ 6050 12100
Wire Wire Line
	4850 7450 5150 7450
Wire Wire Line
	5150 7450 5150 12000
Wire Wire Line
	5150 12000 5900 12000
Connection ~ 5900 12000
Wire Wire Line
	2700 10900 2800 10900
Wire Wire Line
	2800 10900 2800 10350
Wire Wire Line
	2800 10350 2700 10350
Wire Wire Line
	2800 9800 2700 9800
Wire Wire Line
	2800 9800 2800 10350
Connection ~ 2800 10350
Wire Wire Line
	2800 9800 2800 9250
Wire Wire Line
	2800 9250 2700 9250
Connection ~ 2800 9800
Wire Wire Line
	2700 8950 2750 8950
Wire Wire Line
	2750 8950 2750 9500
Wire Wire Line
	2750 9500 2700 9500
Wire Wire Line
	2750 9500 2750 10050
Wire Wire Line
	2750 10050 2700 10050
Connection ~ 2750 9500
Wire Wire Line
	2750 10050 2750 10600
Wire Wire Line
	2750 10600 2700 10600
Connection ~ 2750 10050
Wire Wire Line
	2750 8950 4950 8950
Wire Wire Line
	4950 8950 4950 8050
Connection ~ 2750 8950
Connection ~ 4950 8050
Wire Wire Line
	4950 8050 5250 8050
Wire Wire Line
	2800 9250 3100 9250
Wire Wire Line
	3100 9250 3100 7150
Connection ~ 2800 9250
Connection ~ 3100 7150
Wire Wire Line
	3100 7150 3200 7150
Wire Wire Line
	2700 9700 2700 9650
Wire Wire Line
	2700 9150 2700 9100
Wire Wire Line
	2700 9100 5300 9100
Wire Wire Line
	5300 9100 5300 7350
Wire Wire Line
	5300 7350 4850 7350
Connection ~ 2700 9100
Wire Wire Line
	2700 9100 2700 9050
Wire Wire Line
	2700 9650 5350 9650
Wire Wire Line
	5350 9650 5350 7250
Wire Wire Line
	5350 7250 4850 7250
Connection ~ 2700 9650
Wire Wire Line
	2700 9650 2700 9600
Wire Wire Line
	2700 10250 2700 10200
Wire Wire Line
	2700 10200 5450 10200
Wire Wire Line
	5450 10200 5450 7150
Wire Wire Line
	5450 7150 4850 7150
Connection ~ 2700 10200
Wire Wire Line
	2700 10200 2700 10150
Wire Wire Line
	4850 7050 5500 7050
Wire Wire Line
	5500 7050 5500 10750
Wire Wire Line
	5500 10750 2700 10750
Wire Wire Line
	2700 10700 2700 10750
Connection ~ 2700 10750
Wire Wire Line
	2700 10750 2700 10800
$Comp
L Connector:Conn_01x06_Male motorShildConn1
U 1 1 615CDB1D
P 3650 7250
F 0 "motorShildConn1" H 3758 7631 50  0000 C CNN
F 1 "motorShildConn" H 3758 7540 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 3650 7250 50  0001 C CNN
F 3 "~" H 3650 7250 50  0001 C CNN
	1    3650 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 8250 4350 8050
$Comp
L Device:LED LedArduinoGyro1
U 1 1 61896891
P 3700 7800
F 0 "LedArduinoGyro1" H 3693 8016 50  0000 C CNN
F 1 "LedArduinoGyro" H 3693 7925 50  0000 C CNN
F 2 "LED_SMD:LED_PLCC_2835" H 3700 7800 50  0001 C CNN
F 3 "~" H 3700 7800 50  0001 C CNN
	1    3700 7800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R2
U 1 1 61896897
P 3700 8100
F 0 "R2" H 3770 8146 50  0000 L CNN
F 1 "220" H 3770 8055 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 3630 8100 50  0001 C CNN
F 3 "~" H 3700 8100 50  0001 C CNN
	1    3700 8100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 8250 4350 8250
Wire Wire Line
	2950 8100 3000 8100
Wire Wire Line
	3000 8100 3000 7750
Connection ~ 3000 7750
Wire Wire Line
	3700 7650 3700 7750
Wire Wire Line
	3700 7750 3850 7750
Wire Wire Line
	3850 7650 4550 7650
Wire Wire Line
	4550 7650 4550 6950
Wire Wire Line
	4550 6950 6800 6950
Wire Wire Line
	6800 6600 6800 6950
Wire Wire Line
	3850 6850 4600 6850
Wire Wire Line
	4600 6850 4600 6700
Wire Wire Line
	4600 6700 6600 6700
Wire Wire Line
	6600 6700 6600 6350
Wire Wire Line
	6600 6350 6800 6350
Wire Wire Line
	6800 6350 6800 6500
Connection ~ 6800 6500
$EndSCHEMATC

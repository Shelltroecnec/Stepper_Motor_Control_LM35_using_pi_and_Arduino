#Pheripheral Intialization
bulb=3
SWT=5

#Motor Intialization
dirPin = 7
stepPin = 11
StepsPerRevol = 200

#Sensor Intialization
LM35 = 13
IR = 15

import smbus
import os 
import serial
import time
import RPi.GPIO as ss
ss.setwarnings(False)
ss.setmode(ss.BOARD)

ss.setup(bulb,ss.OUT)
ss.setup(SWT,ss.IN)
ss.setup(stepPin,ss.OUT)
ss.setup(dirPin,ss.OUT)
ss.setup(LM35,ss.IN)
ss.setup(IR,ss.IN)

ss.output(bulb,True)
sr=serial.Serial(port="/dev/ttyS0",baudrate=9600)
sm=smbus.SMBus(1)
sm.write_byte(0x48,0)
time.sleep(0.2)

def blue():
	a=sr.read()
	if(a=='1'):
		sr.write("Light-ON")
		ss.output(bulb,False)
	if(a=='0'):
		sr.write("Light-OFF")
		ss.output(bulb,True)
def LM35():
	ss.output(dirPin,True)
	for i in stepPerRevol(1,201,1):
		ss.output(stepPin,True)
		time.sleep(1)
		ss.output(stepPin,False)
		time.sleep(1)

while True:
	if (ss.input(SWT)==0):
		ss.output(red,False)
	temp = sm.read_byte(0x48)
	 milivolt = ((temp*4.88)/1024)
	lm_read = (milivolt / 10)
	if(lm_read > 28):
		LM35()
ss.clear()


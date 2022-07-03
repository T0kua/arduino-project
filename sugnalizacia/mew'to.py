import serial
import time
import pyautogui

ArduinoSerial = serial.Serial('COM4',9600)
time.sleep(2)

while 1 :
	incoming = str(ArduinoSerial.readline())
	print(incoming)

	if "warn" in incoming :
		pyautogui.hotkey('Win',"d")
		#pyautogui.typewrite(['s'],0.2)
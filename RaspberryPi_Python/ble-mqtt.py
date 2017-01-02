#!/usr/bin/python
# read BGM111 uart output as <topic payload>, and publish on MQTT
import serial
import time
import paho.mqtt.publish as publish


port = serial.Serial("/dev/ttyAMA0", baudrate=115200, timeout=3.0)

while True:
    rcv = port.readline()
    print(rcv)
    if len(rcv) > 4:
         mytopic, mypayload = rcv.split(" ")
         mypayload =  mypayload.rstrip()
         publish.single(mytopic, mypayload, hostname="localhost")

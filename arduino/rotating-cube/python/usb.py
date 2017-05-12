#!/usr/bin/python
import warnings
import serial
import serial.tools.list_ports
import sys
import glob

class Communications:
    conn = False
    baudRate = None

    def __init__(self, baudRate = 9600):
        self.baudRate = baudRate
        self.setup()
        if not self.conn:
            raise IOError("Connection is not setup")

    def setup(self):
        # self.conn = serial.Serial("/dev/ttyS0", 9600)
        self.conn = serial.Serial("/dev/ttyUSB0", self.baudRate)

    def read(self):
        return self.conn.read()

    def readLine(self):
        return self.conn.readline()

    def write(self, data):
        self.conn.write(data)

    def displayDevices(self):
        for pinfo in serial.tools.list_ports.comports():
            print "{} => {} ::: {}".format(pinfo.serial_number, pinfo.device, pinfo.description)
            for p in pinfo:
                print p

    """ DOESN"T WORK
    def setupBySerialNumber(serialNumber):
        for pinfo in serial.tools.list_ports.comports():
            print "{} => {} ::: {}".format(pinfo.serial_number, pinfo.device, pinfo.description)
            for p in pinfo:
                print p
            if pinfo.serial_number == serialNumber:
                self.conn = serial.Serial(pinfo.device)
                break

    def setupByScanning():
        #scan first arduino found
        for pinfo in serial.tools.list_ports.comports():
            print "{} => {} ::: {}".format(pinfo.serial_number, pinfo.device, pinfo.description)
            for p in pinfo:
                print p
            if 'Arduino' in pinfo.description:
                conn = serial.Serial(pinfo.device)
    """

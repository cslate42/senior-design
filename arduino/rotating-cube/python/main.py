#!/usr/bin/python
import pygame, sys, string, time, signal
import numpy as np

import graphic3d
import usb
import simulator
import json

def main():
    x = 0.0
    y = 0.0
    z = 0.0

    i = 0
    avgs = {'x': [], 'y': [], 'z': []}

    comm = usb.Communications(38400)
    sim = simulator.Simulator()
    vertices = getObjectVertices()
    sim.setup(vertices)

    while( True ):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                deconstruct()

        try:
            line = comm.readLine().strip()
        except:
            continue

        # angles = getAnglesFromADXL345(line)
        angles = getAnglesFromGY512(line)
        # print angles
        # time.sleep(1)
        if not angles:
            continue

        x += angles[0]
        y += angles[1]
        z += angles[2]
        sim.updateDisplay(x, y, z)

        # if angles:
        #     avgs['x'].append(angles[0])
        #     avgs['y'].append(angles[1])
        #     avgs['z'].append(angles[2])
        #
        # if i > 50:
        #     # print avgs
        #     x = np.mean(avgs['x'])
        #     y = np.mean(avgs['y'])
        #     z = np.mean(avgs['z'])
        #     print "X:{:f} Y:{:f} Z:{:f}".format(x,y,z)
        #     sim.updateDisplay(x, y, z)
        #     avgs = {'x': [], 'y': [], 'z': []}
        #     i = 0
        # i += 1

def deconstruct():
    pygame.quit()
    sys.exit()

def getAnglesFromADXL345(line):
    # print "RAW", line
    # print "STARTS WITH", line.startswith("<{")
    # print "ENDS WITH", line.endswith("}>")
    if line.startswith("<{") and line.endswith("}>"):
        line = line.replace("<{", "")
        line = line.replace("}>", "")
        useLine = True
    else:
        useLine = False

    # print "--------------------LINE START---------------------"
    # print line
    # print useLine
    # print "--------------------LINE END---------------------"
    if useLine:
        angles = map(getAngles, line.split("|"))
        if len(angles) == 3 :
            return angles
        else :
            return False
    else :
        return False

def getAnglesFromGY512(line):
    try:
        decoded = json.loads(line)
    except:
        decoded = dict()

    if 'gyro' in decoded and 'accl' in decoded:
        angles = []
        for angle in [ decoded['gyro']['x'], decoded['gyro']['y'], decoded['gyro']['z'] ]:
            angles.append( angle / 2000.0 )
        return angles
    else:
        return False

def getFloat(str):
    try:
        x = float(str)
    except:
        x = 0.00
    return x

def getAngles(str):
    f = getFloat(str)
    print "ORIG: {} F: {}".format(str, f)
    # acceleration to degrees
    return f * 1.95

def getObjectVertices():
    # use a cube
    return [
        graphic3d.Point3D(-1,1,-1),
        graphic3d.Point3D(1,1,-1),
        graphic3d.Point3D(1,-1,-1),
        graphic3d.Point3D(-1,-1,-1),
        graphic3d.Point3D(-1,1,1),
        graphic3d.Point3D(1,1,1),
        graphic3d.Point3D(1,-1,1),
        graphic3d.Point3D(-1,-1,1)
    ]



def signal_handler(signal, frame):
    # global interrupt
    print 'You pressed Ctrl+C!'
    deconstruct()

if __name__ == "__main__":
    signal.signal(signal.SIGINT, signal_handler)
    main()

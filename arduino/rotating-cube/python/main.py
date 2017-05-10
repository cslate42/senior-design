#!/usr/bin/python
import pygame, sys, string

import graphic3d
import usb
import simulator

def main():
    comm = usb.Communications()
    sim = simulator.Simulator()
    vertices = getObjectVertices()
    sim.setup(vertices)
    while( True ):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
        try:
            line = comm.readLine().strip()
            # print "RAW", line
            # print "STARTS WITH", line.startswith("<{")
            # print "ENDS WITH", line.endswith("}>")
            if line.startswith("<{") and line.endswith("}>"):
                line = line.replace("<{", "")
                line = line.replace("}>", "")
                useLine = True
            else:
                useLine = False
        except:
            useLine = False

        # print "--------------------LINE START---------------------"
        # print line
        # print useLine
        # print "--------------------LINE END---------------------"
        if not useLine:
            continue

        angles = map(getAngles, line.split("|"))
        # print angles
        # print "--------------------------"

        if len(angles) == 3 :
            sim.updateDisplay(angles[0], angles[1], angles[2])

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

if __name__ == "__main__":
    main()

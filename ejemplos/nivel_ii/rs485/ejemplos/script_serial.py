#!/bin/env python
#Python Serial Communications Script
#from earl@microcontrollerelectronics.com

import serial,sys,glob,select

def scan_ports(pat):
  scan = glob.glob(pat)
  if (len(scan) == 0): return("")
  else:                return(scan[0])

serport = ""
rate    = "115200"

if (len(sys.argv) > 1):
 l = len(sys.argv) - 1
 while(l>0):
   if (sys.argv[l][0] == '/'): serport = sys.argv[l]
   else:                       rate    = sys.argv[l]
   l = l - 1

if (serport == ""): serport = scan_ports("/dev/ttyACM*")
if (serport == ""): serport = scan_ports("/dev/ttyUSB*")
if (serport == ""):
  print("Unable to find any ports scanning for /dev/[ttyACM*|ttyUSB*]") 
  sys.exit()

ser = serial.Serial(port=serport,baudrate=rate,parity=serial.PARITY_NONE,stopbits=serial.STOPBITS_ONE,bytesize=serial.EIGHTBITS,timeout=1)

print("connected to: ",ser.portstr," ",ser)

while True:
  try:
    tr = ser.inWaiting()
    if tr > 0:
      print(ser.read(tr).decode("utf-8"),end='')
#     for x in line: print (x.encode('hex'),end='')
      sys.stdout.flush()
  except KeyboardInterrupt:
    sys.exit()
  except:
    pass
  while sys.stdin in select.select([sys.stdin], [], [], 0)[0]:
#   line = sys.stdin.readline()
#   for x in line: print (x.encode('hex'),end='')
#   print
    ser.write(sys.stdin.readline().encode("utf-8"))

ser.close()
sys.exit()
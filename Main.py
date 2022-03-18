import serial
import time
import matplotlib.pyplot as plt
import csv

ser = serial.Serial(port='COM8', baudrate=115200, timeout=.1)
sensor_value = []
temperature = []
distance = []
data = []

for i in range(200):
    b = ser.readline()         # read a byte string
    string_n = b.decode()  # decode byte string into Unicode  
    string = string_n.rstrip() # remove \n and \r
    if string != '' and string != 'Gas sensor warming up!':
        s, t, d = string.split(' ')
        sensor_value.append(float(s))
        temperature.append(float(t))
        distance.append(float(d))
        data.append([float(s), float(t), float(d)])
    time.sleep(0.1)            # wait (sleep) 0.1 seconds

ser.close()

import csv  

header = ['Gas sensor reading', 'Temperature', 'Distance']

with open('readings.csv', 'a+', encoding='UTF8') as f:
    writer = csv.writer(f)

    # write the header
    if f.read(1): writer.writerow(header)

    # write the data
    for x in data:
        writer.writerow(x)

fig, axs = plt.subplots(3)

axs[0].plot(sensor_value, '-r')
axs[1].plot(temperature, '-g')
axs[2].plot(distance, '-b')

axs[0].set_title('Gas Sensor Readings')
axs[1].set_title('Temperature')
axs[2].set_title('Distance')

plt.xlabel('Time (seconds)')
plt.title('Distance')
plt.show()


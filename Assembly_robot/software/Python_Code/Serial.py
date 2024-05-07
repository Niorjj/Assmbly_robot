import serial
import time
ser = serial.Serial('/dev/ttyAMA0',115200)
if not ser.is_open:
    ser.open()
print(ser.write(b"serial is ready"))
if __name__ == '__main__':
    try:
        while True:
            size = ser.in_waiting
            if size != 0:
                ret = ser.read(size)
                print(ret)
                ser.flush()
                time.sleep(0.5)
    except KeyboardInterrupt:
        ser.close()


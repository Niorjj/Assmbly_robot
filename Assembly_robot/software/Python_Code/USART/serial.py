import serial
import struct
from time import sleep

def recv(serial):
    while True:
        data = serial.read_all().hex()
        if data == '':
            continue
        else:
            break
        sleep(0.02)
    return data

def send(send_data):
    send_data_hex = bytes.fromhex(send_data)
    if (serial.isOpen()):
        serial.write(send_data_hex)  # 编码
        print("发送成功", send_data)
    else:
        print("发送失败！")

if __name__ == '__main__':
    serial = serial.Serial('COM5', 9600, timeout=0.5)
    if serial.isOpen() :
        print("open success")
    else :
        print("open failed")

    a = ['01','02','03','04','05','06','07','08','09']
    for i in range(0, len(a), 1):

      send(str (a[i]))
      sleep(0.5)  # 起到一个延时的效果
      data =recv(serial)
      if data != '' :
            print("receive : ",data)
            '''if data == 'x':
                print("exit")
                break'''


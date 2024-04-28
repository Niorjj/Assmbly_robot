import serial
import time

# 串口配置
ser = serial.Serial(
    port='/dev/ttyS0',
    baudrate=115200,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    timeout=1  # 超时设置
)
ser.open()
# 检查串口是否打开
if ser.is_open:
    ser.write(b'hello')

time.sleep(2)
ser.close()


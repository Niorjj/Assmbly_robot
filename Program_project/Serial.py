import serial
import time

# 设置串口参数
SERIAL_PORT = '/dev/ttyS0'  # 根据你的配置修改串口号
BAUD_RATE = 115200

# 打开串口
try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
    print("串口已打开")
except serial.SerialException:
    print("无法打开串口，请检查连接")
    exit()

try:
    while True:
        # 从串口接收数据
        if ser.in_waiting > 0:
            received_data = ser.readline().decode().strip()
            print("收到的数据：", received_data)

        # 发送数据到串口
        data_to_send = "Hello STM32!\n"
        ser.write(data_to_send.encode())
        print("已发送数据：", data_to_send.strip())

        # 等待一段时间
        time.sleep(1)

except KeyboardInterrupt:
    # 捕获 Ctrl+C 信号，关闭串口并退出程序
    print("退出程序")
    ser.close()


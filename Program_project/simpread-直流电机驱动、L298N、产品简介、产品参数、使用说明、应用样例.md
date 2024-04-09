> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [wiki.dfrobot.com.cn](https://wiki.dfrobot.com.cn/_SKU_DRI0002_L298N%E5%8F%8C%E8%B7%AFH%E6%A1%A5%E7%94%B5%E6%9C%BA%E9%A9%B1%E5%8A%A8)

> DF-MD V1.3 大功率直流电机驱动器采用 LGS 公司优秀大功率电机专用驱动芯片 L298N，可直接驱动直流电机，驱动电流达 2A。

*   [1. 产品简介](#target_0)
*   [2. 产品参数](#target_1)
*   [3. 尺寸图](#target_2)
*   [4. 接口指示图](#target_3)
*   [5. 使用教程](#target_4)
*   [5.1VD 供电](#target_5)
*   [5.2PWM 控制](#target_6)
*   [5.3 Mind + 图形化编程](#target_7)
*   [更多资料下载](#target_8)
*   [修改历史](#target_9)
*   [疑难解答](#target_10)
*   [更多](#target_11)

[![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/397529fbb47eb02a81d4094cd22c3862.png)](https://www.dfrobot.com.cn/goods-208.html "L298N直流电机驱动模块DF-MD V1.3(SKU:DRI00025)")

1. 产品简介
-------

DF-MD V1.4 是续 DF-MD V1.0 之后的第 4 次改版，每一次改版其性能方面有很大的提升，DF-MDV1.4 在 V1.3 的基础上增加了 5V 电平口；控制端口由原来的 6 个改为 4 个，不但可以节约控制器端口，而且控制方式也更为简单。DF-MD V1.4 大功率直流电机驱动器采用 LGS 公司优秀大功率电机专用驱动芯片 L298N，可直接驱动直流电机，驱动电流达 2A。该电路线路布线合理、均采用贴元件片、体积小、方便安装，输出端采用高速肖特基二极管作为保护。

2. 产品参数
-------

*   逻辑部分输入电压 VD：DC 6.5～12 V
*   驱动部分输入电压 VS：DC 4.8～35V
*   逻辑部分工作电流 Iss：≤36mA
*   驱动部分工作电流 Io：≤2A
*   最大耗散功率：25W（T=75℃）
*   控制信号输入电平：
*   高电平：2.3V≤Vin≤5V
*   低电平：-0.3V≤Vin≤1.5V
*   工作温度：-25℃～＋130℃
*   驱动形式：双路大功率 H 桥驱动
*   模块尺寸：47 mm × 53mm
*   模块重量：约 29g

3. 尺寸图
------

![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/e4232c46b72f3814e5be6ee0fec7de29.png)

4. 接口指示图
--------

![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/3c88ef8ad5d23f37553daaa34cecd26e.png)

<table><thead><tr><th>符号</th><th>意义</th><th>说明</th></tr></thead><tbody><tr><td>PWR</td><td>指示灯</td><td>电源正常供电时，PWR 亮红光</td></tr><tr><td>VD</td><td>逻辑电源输入</td><td>输入电压范围建议为 6.5V～12V</td></tr><tr><td>GND</td><td>公共地</td><td>逻辑电源和电机驱动电源的公共地</td></tr><tr><td>VS</td><td>电机驱动电源输入</td><td>输入电压范围建议为 4.8V～46V</td></tr><tr><td>VD=VS</td><td>电源切换</td><td>当跳冒插上时逻辑电源和电机驱动电源相通 (<strong>如果电机驱动电源输入大于 12V 时，不可将此跳冒短接</strong>)</td></tr><tr><td>5V</td><td>5V 高电平信号</td><td>无</td></tr><tr><td></td><td>电机指示灯</td><td>电机正常工作，电机指示灯会亮起，正转为红灯，反转为绿灯</td></tr></tbody></table>

**电机控制端口**

E1,E2: 分别为两个电机控制的使能端 (可使用 PWM 调速)。 M1,M2: 正反转控制信号输入端。比如，M1=0，M1 电机正转; M1=1，M1 电机反转。

<table><thead><tr><th>E1/E2</th><th>M1/M2</th><th>执行结果</th></tr></thead><tbody><tr><td>LOW</td><td>LOW/HIGH</td><td>电机禁止</td></tr><tr><td>HIGH</td><td>HIGH</td><td>电机反转</td></tr><tr><td>HIGH</td><td>LOW</td><td>电机正转</td></tr><tr><td>PWM</td><td>LOW/HIGH</td><td>电机调速</td></tr></tbody></table>

**注: LOW = 0; HIGH = 1; PWM = 0~255**

5. 使用教程
-------

5.1VD 供电
--------

这个例子为仅用一个外部供电，使得电机全部反转

**硬件连线图**

![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/bbe07104ffebdc50f547edcf25447f95.png)

![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/02fde2d1453bf9807a658cd30620cd9f.png)![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/3d33db1998be1176223b41886dc02baa.png)![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/9892af08b78a4988e7f1be026454dc2f.png)

**注意**：

需要将 VD=VS 通过跳帽连接在一起

E1、E2、M1、M2 分别与 5V 相连

5.2PWM 控制
---------

这个例子，使得电机转速从低到高，正向变速运转

**注：PWM 调速是通过调整空占比来模拟不同电压值，从而控制加到电机两端的电压高低来实现调速。**

**硬件准备：**

*   [DFRduino UNO](https://www.dfrobot.com.cn/goods-521.html)×1（SKU：DFR0216）
*   [L298N 直流电机驱动模块](https://www.dfrobot.com.cn/goods-208.html) ×1（SKU：DRI0002）
*   [7.4V 2500mAh 锂电池](https://www.dfrobot.com.cn/goods-434.html) ×1（SKU：FIT0137）
*   [SJ01 - 带编码器直流减速电机](https://www.dfrobot.com.cn/goods-1270.html) ×2（SKU：FIT0450）

**软件准备**

*   下载 Arduino IDE： [点击下载 Arduino IDE](https://www.arduino.cc/en/software)

**硬件连线图**

![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/85535f61461350befb55d3b7e58654ff.png)

![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/4094736ed572dcbbae94bdefd909f287.png)

**注意**：

将 VD=VS 通过跳帽连接在一起

E1-- 连接 --DFRduino UNO 6 号引脚

E2-- 连接 --DFRduino UNO 5 号引脚

VD-- 连接 --DFRduino UNO VIN

GND-- 连接 --DFRduino UNO GND

**示例代码**

5.3 Mind + 图形化编程
----------------

**关于 Mind+**

1、下载及安装软件。下载地址：[http://mindplus.cc](http://mindplus.cc/) 详细教程：[安装教程](https://mindplus.dfrobot.com.cn/zhunbei)

2、切换到 “上传模式”。 详细教程：[Mind + 基础 wiki 教程 - 上传模式编程流程](https://wiki.dfrobot.com.cn/Mindplus_%E5%9F%BA%E7%A1%80wiki%E6%95%99%E7%A8%8B-%E4%B8%8A%E4%BC%A0%E6%A8%A1%E5%BC%8F%E7%BC%96%E7%A8%8B%E6%B5%81%E7%A8%8B)

3、“扩展”中选择 “主控板” 中的“Arduino Uno”。 详细教程：[Mind + 基础 wiki 教程 - 加载扩展库流程](https://wiki.dfrobot.com.cn/Mindplus_%E5%9F%BA%E7%A1%80wiki%E6%95%99%E7%A8%8B-%E5%8A%A0%E8%BD%BD%E6%89%A9%E5%B1%95%E5%BA%93%E6%B5%81%E7%A8%8B)

4、进行编程，程序如下图：

5、菜单 “连接设备”，“上传到设备”

6、程序上传完毕后，即可看到效果。

![](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/50074a0494f6474b3fd77e440e7996fc.png)

更多资料下载
------

[DRI0002_3D_STP.rar](https://img.dfrobot.com.cn/wiki/60c1e008bddfc41c3293de80/97d61119d7555643c1dd196368b8d628.rar "DRI0002_3D_STP.rar")

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADIAAAAyCAYAAAAeP4ixAAACbklEQVRoQ+2aMU4dMRCGZw6RC1CSSyQdLZJtKQ2REgoiRIpQkCYClCYpkgIESQFIpIlkW+IIcIC0gUNwiEFGz+hlmbG9b1nesvGW++zxfP7H4/H6IYzkwZFwQAUZmpJVkSeniFJKA8ASIi7MyfkrRPxjrT1JjZ8MLaXUDiJuzwngn2GJaNd7vyP5IoIYY94Q0fEQIKIPRGS8947zSQTRWh8CwLuBgZx479+2BTkHgBdDAgGAC+fcywoyIFWqInWN9BSONbTmFVp/AeA5o+rjKRJ2XwBYRsRXM4ZXgAg2LAPzOCDTJYQx5pSIVlrC3EI45y611osMTHuQUPUiYpiVooerg7TWRwDAlhSM0TuI+BsD0x4kGCuFSRVzSqkfiLiWmY17EALMbCAlMCmI6IwxZo+INgQYEYKBuW5da00PKikjhNNiiPGm01rrbwDwofGehQjjNcv1SZgddALhlJEgwgJFxDNr7acmjFLqCyJuTd6LEGFttpmkYC91Hrk3s1GZFERMmUT01Xv/sQljjPlMRMsxO6WULwnb2D8FEs4j680wScjO5f3vzrlNJszESWq2LYXJgTzjZm56MCHf3zVBxH1r7ftU1splxxKYHEgoUUpTo+grEf303rPH5hxENJqDKQEJtko2q9zGeeycWy3JhpKhWT8+NM/sufIhBwKI+Mta+7pkfxKMtd8Qtdbcx4dUQZcFCQ2I6DcAnLUpf6YMPxhIDDOuxC4C6djoQUE6+tKpewWZ1wlRkq0qUhXptKTlzv93aI3jWmE0Fz2TeujpX73F9TaKy9CeMk8vZusfBnqZ1g5GqyIdJq+XrqNR5AahKr9CCcxGSwAAAABJRU5ErkJggg==)

[L298 数据手册](https://www.dfrobot.com.cn/image/data/DRI0002/CN/L298%20datasheet.pdf "L298数据手册")

修改历史
----

### 文档修改历史

<table><thead><tr><th>文档版本号</th><th>修改时间</th><th>修改人</th><th>修改内容</th></tr></thead><tbody><tr><td>V1.0</td><td>2022.12.28</td><td>康啸</td><td>第一版发布</td></tr></tbody></table>

### 产品修改历史

<table><thead><tr><th>产品版本号</th><th>修改时间</th><th>修改人</th><th>产品修改内容</th></tr></thead><tbody><tr><td>V1.0</td><td>2022.12.28</td><td>刘礼华</td><td>第一版发布</td></tr></tbody></table>

疑难解答
----

更多问题及有趣的应用，请访问[论坛](http://www.dfrobot.com.cn/community/forum.php)

更多
--

![](http://imgtest.dfrobot.com.cn/DFRobotCnWikiImage/Nextredirectltr.png)购买 [DFRobot 商城购买链接](http://www.dfrobot.com.cn/goods-208.html)
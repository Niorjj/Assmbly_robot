import math as m

d1 = 8
a2 = 12
a3 = 11


def fkinematics(theta1, theta2, theta3):
    px = m.cos(theta1) * (a3 * m.cos(theta2 + theta3) + a2 * m.cos(theta2))
    py = m.sin(theta1) * (a3 * m.cos(theta2 + theta3) + a2 * m.cos(theta2))
    pz = d1 - (a2 * m.sin(theta2)) - (a3 * m.sin(theta2 + theta3))
    return [px, py, pz]


def ikinematics(px_value, py_value, pz_value):
    theta1 = m.atan2(py_value, px_value)

    costheta3 = ((px_value * m.cos(theta1) + py_value * m.sin(theta1)) ** 2 + (
                d1 - pz_value) ** 2 - a2 ** 2 - a3 ** 2) / (2 * a2 * a3)
    sintheta3 = m.sqrt(1 - (costheta3 ** 2))
    theta3 = m.atan2(sintheta3, costheta3)

    costheta2 = (
            ((d1 - pz_value) * a3 * m.sin(theta3) + (px_value * m.cos(theta1) + py_value * m.sin(theta1)) * (
                        a3 * m.cos(theta3) + a2))
            / ((a3 * m.cos(theta3) + a2) ** 2 + (a2 * m.sin(theta3)) ** 2))
    sintheta2 = m.sqrt(1 - (costheta2 ** 2))
    theta2 = m.atan(sintheta2 / costheta2)
    return [theta1, theta2, theta3]


result_fkinematics = fkinematics(20, 30, 50)
px_array = []
py_array = []
pz_array = []

px_array.append(result_fkinematics[0])
py_array.append(result_fkinematics[1])
pz_array.append(result_fkinematics[2])
print(px_array, py_array, pz_array)

result_ikinematics = ikinematics(px_array[0], py_array[0], pz_array[0])
theta1_array = []
theta2_value = []
theta3_value = []
theta1_array.append(result_ikinematics[0])
theta2_value.append(result_ikinematics[1])
theta3_value.append(result_ikinematics[2])
print(theta1_array, theta2_value, theta3_value)

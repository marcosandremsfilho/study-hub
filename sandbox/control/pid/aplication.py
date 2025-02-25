#!/usr/bin/env python

import time

from pid import pidController
from graphic import graphInterface
from water_boiler import waterBoiler

simulation_time = 60

boiler = waterBoiler(1)
water_temp = boiler.initial_temperature

pid = pidController(1, 0.01, 0.01)
pid.set_setpoint(100)

graph = graphInterface()
graph.set_x_label("Time (s)")
graph.set_y_label("Temperature °C")

setpoint, x, y = [], [], []

start_time = time.time()
last_time = start_time

max_temp = 0

pid = pidController(1, 0.01, 0.01)
pid.set_setpoint(50)

while time.time() - start_time < simulation_time:
    current_time = time.time()
    dt = current_time - last_time

    power = pid.system_output(water_temp)
    water_temp = boiler.update_temperature(power, dt)

    x.append(current_time - start_time)
    y.append(water_temp)
    setpoint.append(pid.setpoint)

    last_time = current_time
    max_temp = water_temp if max_temp < water_temp else max_temp

    time.sleep(0.1)

print("First part results")
print(f"Water temperature: {water_temp}")
print(f"Max temperature: {max_temp}")

"""
pid.set_setpoint(100)

second_start_time = current_time - start_time
start_time = time.time()

while time.time() - start_time < simulation_time:
    current_time = time.time()
    dt = current_time - last_time

    power = pid.system_output(water_temp)
    water_temp = boiler.update_temperature(power, dt)

    x.append(current_time - second_start_time)
    y.append(water_temp)
    setpoint.append(pid.setpoint)

    last_time = current_time
    max_temp = water_temp if max_temp < water_temp else max_temp

    time.sleep(0.1)

print("Second part results")
print(f"Water temperature: {water_temp}")
print(f"Max temperature: {max_temp}")
"""

graph.plot(x, setpoint)
graph.plot(x, y)
graph.show()

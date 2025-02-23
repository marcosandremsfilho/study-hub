#!/usr/bin/env python

import time

from pid import pidController
from graphic import graphInterface
from water_boiler import waterBoiler

boiler = waterBoiler(1)
water_temp = boiler.initial_temperature

pid = pidController(0.5, 1, 1)
pid.set_setpoint(50)

graph = graphInterface()

setpoint, x, y = [], [], []

start_time = time.time()
last_time = start_time

while time.time() - start_time < 5:
    current_time = time.time()
    dt = current_time - last_time

    power = pid.system_output(water_temp)
    water_temp = boiler.update_temperature(power)

    x.append(current_time - start_time)
    y.append(water_temp)
    setpoint.append(pid.setpoint)

    print(f"PID output: {power} Water temperature: {water_temp} dt: {dt}")

    time.sleep(1)

graph.plot(x, y)
# graph.show()

#!/usr/bin/env python

import time


class pidController:
    def __init__(self, kp, ki, kd) -> None:
        self.kp = kp
        self.ki = ki
        self.kd = kd

        self.setpoint = None
        self._last_time = time.time()
        self._last_error = None

        self._proportional = None
        self._integrative = None
        self._derivative = None

        self._integrative_limit = 800

    def set_setpoint(self, setpoint):
        self.setpoint = setpoint

    def _clamp(self, value, limits):
        lower, upper = limits
        if value is None:
            return None
        elif (upper is not None) and (value > upper):
            return upper
        elif (lower is not None) and (value < lower):
            return lower
        return value

    def system_output(self, system_input):
        error = self.setpoint - system_input
        derivative_error = error - (self._last_error if self._last_error is not None else error)

        now = time.time()

        dt = now - self._last_time

        if dt < 1e-6:
            dt = 1e-6

        print(f"Error: {error} dt: {dt}")
        self._proportional = self.kp * error
        self._integrative = self.ki * error * dt
        self._derivative = (self.kd * derivative_error) / dt

        self._integrative = self._clamp(self._integrative, [0.1, 100])
        self._derivative = self._clamp(self._derivative, [0.1, 100])
        self._last_error = error
        self._last_time = now

        print(f"P: {self._proportional} I: {self._integrative} D: {self._derivative}")
        return self._proportional + self._integrative + self._derivative

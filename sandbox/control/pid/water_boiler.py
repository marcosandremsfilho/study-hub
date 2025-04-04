#!/usr/bin/env python


class waterBoiler:
    def __init__(self, initial_temperature) -> None:
        self.initial_temperature = initial_temperature

        self.current_temperature = None

    def update_temperature(self, boiler_power, dt):
        if self.current_temperature is None:
            self.current_temperature = self.initial_temperature

        if boiler_power > 0:
            self.current_temperature += 1 * boiler_power * dt

        self.current_temperature -=  0.5*dt
        return self.current_temperature

#!/usr/bin/env python

import matplotlib.pyplot as plt

class graphInterface:
    def __init__(self, backend_plot = "TkAgg") -> None:
        plt.switch_backend(backend_plot)

    def plot(self, x : list, y : list, label = ""):
        plt.plot(x, y, label = label)

    def set_x_label(self,label : str):
        plt.xlabel(label)

    def set_y_label(self,label : str):
        plt.ylabel(label)

    def show(self):
        plt.show()


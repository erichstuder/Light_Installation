import numpy as np
import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as p3
import matplotlib.animation as animation
from stl import mesh
import random


def update_led_colors(num, leds):
	for led in leds:
		red = random.random()
		green = random.random()
		blue = random.random()
		led.set_color([red, green, blue])
	return leds


def start_simulator():
	figure = plt.figure()
	ax = p3.Axes3D(figure)
	ax.set_facecolor('#000000')
	figure.set_facecolor('#000000')

	coordinates = []
	for x in range(5):
		for y in range(5):
			for z in range(15):
				coordinates.append((100*x, 100*y, 33.25*z))
	leds = [ax.plot(p[0], p[1], p[2], marker='o')[0] for p in coordinates]

	ax.set_xlim3d([0, 400])
	ax.set_xlabel('X')

	ax.set_ylim3d([0, 400])
	ax.set_ylabel('Y')

	ax.set_zlim3d([0, 500])
	ax.set_zlabel('Z')

	ax.set_title('3D Test')

	line_ani = animation.FuncAnimation(figure, update_led_colors, 1, fargs=(leds,), interval=1000, blit=False)

	plt.show()


if __name__ == "__main__":
	start_simulator()

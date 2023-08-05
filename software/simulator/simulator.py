import numpy as np
import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as p3
import matplotlib.animation as animation
from stl import mesh
import random

# Fixing random state for reproducibility
np.random.seed(19680801)


def Gen_RandLine(length, dims=2):
	"""
	Create a line using a random walk algorithm

	length is the number of points for the line.
	dims is the number of dimensions the line has.
	"""
	lineData = np.empty((dims, length))
	lineData[:, 0] = np.random.rand(dims)
	for index in range(1, length):
		# scaling the random numbers by 0.1 so
		# movement is small compared to position.
		# subtraction by 0.5 is to change the range to [-0.5, 0.5]
		# to allow a line to move backwards.
		step = ((np.random.rand(dims) - 0.5) * 0.1)
		lineData[:, index] = lineData[:, index - 1] + step

	return lineData


def update_lines(num, dataLines, lines):
	for line, data in zip(lines, dataLines):
		# NOTE: there is no .set_data() for 3 dim data...
		line.set_data(data[0:2, :num])
		line.set_3d_properties(data[2, :num])
	return lines


def update_led_colors():
		pass


def start_simulator():
	figure = plt.figure()
	ax = p3.Axes3D(figure)
	ax.set_facecolor('#000000')
	figure.set_facecolor('#000000')

	# Fifty lines of random 3-D lines
	data = [Gen_RandLine(25, 3) for index in range(50)]

	# Creating fifty line objects.
	# NOTE: Can't pass empty arrays into 3d version of plot()
	lines = [ax.plot(dat[0, 0:1], dat[1, 0:1], dat[2, 0:1])[0] for dat in data]

	# Setting the axes properties
	ax.set_xlim3d([-300, 300])
	ax.set_xlabel('X')

	ax.set_ylim3d([-300, 300])
	ax.set_ylabel('Y')

	ax.set_zlim3d([-300, 300])
	ax.set_zlabel('Z')

	ax.set_title('3D Test')

	# Creating the Animation object
	#line_ani = animation.FuncAnimation(figure, update_lines, 25, fargs=(data, lines),
	#								interval=50, blit=False)

	a = random.random()
	plt.plot(0, 0, color=(a, 0, 0), marker='o')
	#plt.plot(10, 0, 'go')
	#plt.plot(20, 0, 'ro')
        

	plt.show()
        

def _start_simulator():
	from mpl_toolkits import mplot3d

	figure = plt.figure()
	axes = mplot3d.Axes3D(figure)

	your_mesh = mesh.Mesh.from_file('clamp.stl')
	axes.add_collection3d(mplot3d.art3d.Poly3DCollection(your_mesh.vectors))

	# Auto scale to the mesh size
	# scale = your_mesh.points.flatten(-1)
	#scale = 100
	#axes.auto_scale_xyz(scale, scale, scale)

	# Show the plot to the screen
	plt.show()


if __name__ == "__main__":
	start_simulator()

# language: en
Feature: Led Simulation
	The simulator makes it possible to simulate the leds.
	The simulator shows a 3D model of the cube.
	Led animation patterns are programable via python code.
	The animation runs as soon as the simulator is started.
	During the animation the model can be rotated with the mouse.

	Scenario: Start the simulator
		When I start the simulator
		Then a model of the cube is shown
		And the leds are shown
		And the led animation starts rightaway

	Scenario: Rotating the cube
		Given the simulator is running
		And the animation is running
		Then the cube can be rotated with the mouse

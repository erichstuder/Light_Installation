# language: en
Feature: Start Simulator

    Scenario: Start the simulator
        When I start the simulator
        Then a 3D model of the Light Installation is shown

    Scenario: Start the simulator and begin animation
        When I start the simulator
        Then the led animation starts rightaway

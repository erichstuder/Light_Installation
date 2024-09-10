# language: en
Feature: Start Simulator

    Scenario: Start the simulator
        When I start the simulator
        Then a 3D model of the Light Installation is shown

    Scenario: Start the simulator and begin animation
        When I start the simulator
        Then the led animation starts rightaway

    Scenario: Start the simulator with no last pattern
        When I start the simulator
        Given there is no last pattern
        Then an empty pattern is loaded by default

    Scenario: Start the simulator with a last pattern
        When I start the simulator
        Given there is a last pattern
        Then the last pattern is loaded

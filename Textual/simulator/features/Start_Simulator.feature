# language: en
Feature: Start Simulator

    # This is hard to test, because the simulator is a GUI application -> manual test?
    # Scenario: Start the simulator and show 3D model
    #     When I start the simulator
    #     Then a 3D model of the Light Installation is shown

    Scenario: Start the simulator and begin animation
        When I start the simulator
        Then the led animation starts rightaway

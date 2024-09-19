# language: en
Feature: Start Simulator

%.. feature:: Start Simulator
%    :id: F_001
%    :links: UC_001, UC_002, UC_005, UC_006

    # This is hard to test, because the simulator is a GUI application -> manual test?
    # Scenario: Start the simulator and show 3D model
    #     When I start the simulator
    #     Then a 3D model of the Light Installation is shown

    Scenario: Start the simulator and begin animation
        When I start the simulator
        Then the led animation starts rightaway

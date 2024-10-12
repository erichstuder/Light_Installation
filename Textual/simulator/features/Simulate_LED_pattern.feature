# language: en
Feature: Simulate LED pattern

%.. feature:: Simulate LED pattern
%    :id: F_002
%    :links: UC_001, UC_002, UC_005, UC_006

    Scenario: Start the simulator and begin simulation
        When I start the simulator
        Then the led simulation starts rightaway

# language: en
Feature: Load LED pattern

%.. feature:: Load LED pattern
%    :id: F_001
%    :links: UC_002

    Scenario: Start the simulator without an LED pattern
        When I start the simulator without an LED pattern
        Then an error happens

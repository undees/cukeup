Feature: Gray Code
  Scenario Outline: Counter
    When I press the button
    Then the LEDs should read "<leds>"

  Examples:
    | leds |
    | ..O  |
    | .OO  |
    | .O.  |
    | OO.  |
    | OOO  |
    | O.O  |
    | O..  |
    | ...  |

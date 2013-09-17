Feature: Gray Code
  Scenario: Reset
    Given the LEDs read "OOO"
    When I reset the counter
    Then the LEDs should read "..."

  Scenario Outline: Counter
    Given the LEDs read "<n>"
    When I press the button
    Then the LEDs should read "<nplus1>"
    Examples:
      | n   | nplus1 |
      | ... | ..O    |
      | ..O | .OO    |
      | .OO | .O.    |
      | .O. | OO.    |
      | OO. | OOO    |
      | OOO | O.O    |
      | O.O | O..    |
      | O.. | ...    |

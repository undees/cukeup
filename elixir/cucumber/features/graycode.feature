Feature: Gray Code
  Scenario: Reset
    Given the LEDs read "ooo"
    When I reset the counter
    Then the LEDs should read "..."

  Scenario Outline: Counter
    Given the LEDs read "<n>"
    When I press the button
    Then the LEDs should read "<nplus1>"
    Examples:
      | n   | nplus1 |
      | ... | ..o    |
      | ..o | .oo    |
      | .oo | .o.    |
      | .o. | oo.    |
      | oo. | ooo    |
      | ooo | o.o    |
      | o.o | o..    |
      | o.. | ...    |

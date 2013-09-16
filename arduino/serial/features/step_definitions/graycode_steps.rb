When /^I press the button$/ do
  Arduino.press
end

Then /^the LEDs should read "(.*?)"$/ do |leds|
  expect(Arduino.leds).to eq(leds)
end

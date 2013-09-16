When(/^I multiply (\d+) and (\d+)$/) do |a, b|
  Calculator.multiply a, b
end

Then(/^I should get (\d+)$/) do |expected|
  expect(Calculator.result).to eq(expected.to_i)
end

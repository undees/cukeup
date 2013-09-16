require 'httparty'

class Calculator
  include HTTParty
  base_uri 'localhost:33333'

  def self.multiply(a, b)
    get "/multiply?multiplier=#{a}&multiplicand=#{b}"
  end

  def self.result
    get("/result").to_i
  end
end

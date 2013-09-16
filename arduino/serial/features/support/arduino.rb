require 'serialport'

module Arduino
  @@port = SerialPort.open 2, 9600
  at_exit { @@port.close }

  def self.press
    @@port.write '+'
  end

  def self.leds
    @@port.write '?'
    @@port.read.strip
  end
end

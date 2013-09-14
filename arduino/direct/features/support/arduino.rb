require 'ffi'

module Arduino
  extend FFI::Library
  ffi_lib 'graycode'

  attach_function :press, [], :void
  attach_function :leds,  [], :string

  attach_function :setup, [], :void
  attach_function :loop,  [], :void
end

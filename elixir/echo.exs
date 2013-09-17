defmodule ShoutyEcho do
  def echo_loop do
    receive do
      {sender, msg} ->
        sender <- {:ok, String.upcase(msg)}
        echo_loop
    end
  end
end

pid = spawn(ShoutyEcho, :echo_loop, [])
pid <- {self, "Your name here"}

receive do
  {:ok, response} ->
    IO.puts response
    after 500 ->
      IO.puts "Done"
end

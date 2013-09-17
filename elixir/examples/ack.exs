defmodule Ackermann do
  def ack(m, n) when m == 0, do: n + 1
  def ack(m, n) when n == 0, do: ack(m - 1, 1)
  def ack(m, n), do: ack(m - 1, ack(m, n - 1))
end

IO.puts Ackermann.ack(3, 9)

defmodule :graycode do
  def given([:the, :leds, :read, input], _state, _) do
    {:ok, input}
  end

  def when_([:i, :reset, :the, :counter], _state, _) do
    {:ok, '...'}
  end

  def when_([:i, :press, :the, :button], state, _) do
    {:ok, _next(state)}
  end

  def then([:the, :leds, :should, :read, expected], state, _) do
    {expected === state, state}
  end

  defp _next(leds) do
    case leds do
      '...' -> '..o'
      '..o' -> '.oo'
      '.oo' -> '.o.'
      '.o.' -> 'oo.'
      'oo.' -> 'ooo'
      'ooo' -> 'o.o'
      'o.o' -> 'o..'
      'o..' -> '...'
    end
  end

  def main() do
    :cucumberl.run("./features/graycode.feature")
  end
end

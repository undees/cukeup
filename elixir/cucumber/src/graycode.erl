-module(graycode).

-export([given/3, 'when'/3, then/3, main/0]).

given([the, leds, read, _Input], State, _) ->
    {ok, State}.

'when'([i, reset, the, counter], State, _) ->
    {ok, State};
'when'([i, press, the, button], State, _) ->
    {ok, State}.

then([the, leds, should, read, _Expected], State, _) ->
    {ok, State}.

main() ->
    cucumberl:run("./features/graycode.feature").

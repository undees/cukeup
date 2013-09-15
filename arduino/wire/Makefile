default: server

server: listener.o graycode.o graycode_steps.o
	g++ -o server listener.o graycode.o graycode_steps.o json_spirit/build/json_spirit/libjson_spirit.a

graycode.o: graycode.cpp Bounce.h
	g++ -I . -c graycode.cpp

graycode_steps.o: graycode_steps.cpp
	g++ -I . -I json_spirit/json_spirit -c graycode_steps.cpp

listener.o: listener.c
	gcc -c listener.c

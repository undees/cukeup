default: server

server: graycode_steps.o graycode.o
	g++ -lboost_unit_test_framework-mt -lboost_system-mt -lboost_regex-mt -o server graycode_steps.o graycode.o cucumber-cpp/build/src/libcucumber-cpp.a cucumber-cpp/build/src/libCukeBins.a

graycode.o: graycode.cpp Bounce.h
	g++ -I . -c graycode.cpp

graycode_steps.o: graycode_steps.cpp
	g++ -I cucumber-cpp/include -c graycode_steps.cpp

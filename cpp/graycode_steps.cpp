#define BOOST_TEST_MODULE GrayCode
#include <boost/test/unit_test.hpp>
#include <cukebins/wireserver.hpp>
#include <string>
using std::string;

extern "C" void press();
extern "C" const char* leds();
extern "C" void loop();

WHEN("^I press the button$") {
    press();
    loop();
}

THEN("^the LEDs should read \"(.*?)\"$") {
    REGEX_PARAM(string, expected);
    BOOST_CHECK_EQUAL(leds(), expected);
}

#include <json_spirit.h>
#include <string>
using std::string;
using json_spirit::Value;
using json_spirit::Object;
using json_spirit::Array;
using json_spirit::read;
using json_spirit::write;

extern "C" void press();
extern "C" const char* leds();
extern "C" void loop();

// ZOMG AWFUL DO NOT PUT ALL YOUR CODE IN ONE FUNCTION LIKE THIS
//
// ALSO, WAITING FOR SIGSEGV IS NOT ERROR CHECKING

extern "C" void respond_to_cucumber(FILE* stream, const char* message)
{
    string s = message;
    Value v;
    read(s, v);

    Array& a = v.get_array();
    string type = a[0].get_str();
    if (type == "step_matches") {
        string name = a[1].get_obj()[0].value_.get_str();
        if (name == "I press the button") {
            fputs("[\"success\", [{\"id\":\"0\", \"args\":[]}]]\n", stream);
            return;
        } else if (name.find("the LEDs should read \"") == 0) {
            const int start_leds = 22;
            string leds = name.substr(start_leds, 3);
            fputs("[\"success\", [{\"id\":\"1\", \"args\":[{\"val\":\"", stream);
            fputs(leds.c_str(), stream);
            fputs("\", \"pos\":\"22\"}]}]]\n", stream);
            return;
        }
    } else if (type == "invoke") {
        Object& step = a[1].get_obj();
        string id = step[0].value_.get_str();

        if (id == "0") {
            press();
            loop();
        } else if (id == "1") {
            string expected = step[1].value_.get_array()[0].get_str();
            if (expected != leds()) {
                fputs("[\"fail\",{\"message\":\"LEDs did not match\"}]\n", stream);
                return;
            }
        }
    }

    fputs("[\"success\",[]]\n", stream);
}

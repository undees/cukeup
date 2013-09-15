#define LOW  0
#define HIGH 1

#define INPUT  0
#define OUTPUT 1

void pinMode(int, int) {}
void digitalWrite(int, int) {}
void delay(int) {}

class SerialPort {
public:
    void begin(int) {}
    int available() { return -1; }
    int read() { return -1; }
    void write(int) {}
};

SerialPort Serial;

bool isFakeButtonPressed;

class Bounce {
public:
    Bounce(int, int) {}
    void update() {}
    bool risingEdge() {
        bool result = isFakeButtonPressed;
        isFakeButtonPressed = false;
        return result;
    }

};

extern int counter;

extern "C" void press() {
    isFakeButtonPressed = true;
}

extern "C" const char* leds();

extern "C" void setup();
extern "C" void loop();

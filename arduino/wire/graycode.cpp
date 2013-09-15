#include <Bounce.h>

const int BUTTON        = 2;
const int LEDS          = 3;
const int LEDPINS[LEDS] = {9, 10, 11};

Bounce button(BUTTON, 100);

const int QUERY     = '?';
const int INCREMENT = '+';

int counter = 0;

const int ENTRIES = 8;
const bool STATES[ENTRIES][LEDS] = {
    LOW,  LOW,  LOW,
    LOW,  LOW,  HIGH,
    LOW,  HIGH, HIGH,
    LOW,  HIGH, LOW,
    HIGH, HIGH, LOW,
    HIGH, HIGH, HIGH,
    HIGH, LOW,  HIGH,
    HIGH, LOW,  LOW
};

void setup() {
    pinMode(BUTTON, INPUT);

    for (int i = 0; i < LEDS; ++i) {
        pinMode(LEDPINS[i], OUTPUT);
    }

    Serial.begin(9600);
}

bool isIncrement(bool buttonPressed, int command) {
    return buttonPressed || (INCREMENT == command);
}

bool isQuery(int command) {
    return QUERY == command;
}

int newCounter(int command) {
    int index = command - '0';

    if (index < 0 || index >= ENTRIES) {
        return counter;
    }

    return index;
}

void updateLeds() {
    for (int i = 0; i < LEDS; ++i) {
        digitalWrite(LEDPINS[i], STATES[counter][i]);
    }
}

const char* leds() {
    static char buf[LEDS + 1] = {0};

    for (int i = 0; i < LEDS; ++i) {
        buf[i] = STATES[counter][i] == HIGH ? 'O' : '.';
    }

    return buf;
}

void loop() {
    button.update();
    bool buttonPressed = button.risingEdge();

    int command = (Serial.available() > 0 ? Serial.read() : -1);

    if (isIncrement(buttonPressed, command)) {
        counter = (counter + 1) % ENTRIES;
        updateLeds();
    } else if (isQuery(command)) {
        Serial.write(counter);
    } else {
        counter = newCounter(command);
        updateLeds();
    }

    delay(50);
}

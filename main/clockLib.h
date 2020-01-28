#ifndef _CLOCK_LIB_H
#define _CLOCK_LIB_H

#define BLUETOOTH_TX 3
#define BLUETOOTH_RX 4

const uint8_t DIGIT_HOURS_HIGH = 0;
const uint8_t DIGIT_HOURS_LOW = 1;
const uint8_t DIGIT_MINUTES_HIGH = 2;
const uint8_t DIGIT_MINUTES_LOW = 3;
const uint8_t DIGIT_SECONDS_HIGH = 4;
const uint8_t DIGIT_SECONDS_LOW = 5;

enum ClockMode {
    CLOCK_MODE_TIME,
    CLOCK_MODE_TEMPERATURE,
    CLOCK_MODE_HUMIDITY
};

enum OperationMode {
    CLOCK_OP_MODE_CLOCK,    //Clock mode
    CLOCK_OP_MODE_TIMER,    //timer mode
    CLOCK_OP_MODE_SCORE     //Score mode
};


class DigitalClock {
    public:
        void begin();
        void setDigit(uint8_t digit, signed char digitValue, bool lastBit);
        void clearDigitsLast();
        void displayDigit(uint8_t digit);
        int getSegmentHex(uint8_t number);
        ClockMode getClockMode(uint8_t t_seconds);
        OperationMode getOperationMode();
        void setOperationMode(String ck__cmd);
    private:
        void setupIOPort(uint8_t digit, uint8_t port, uint8_t portDir);
        int getDigitAddress(uint8_t digit);
        void writeDigit(uint8_t digit, signed char digitHex);
        signed char digits_current[4] = { 0 }; //[6]; if seconds included
        signed char digits_last[4] = { -1 }; //[6]; if seconds included
        OperationMode operationMode = CLOCK_OP_MODE_CLOCK;
};

#endif // _CLOCK_LIB_H


#ifndef MURACH_TEMP_H
#define MURACH_TEMP_H
#include <string>

class Temp {
private:
    double celsius;
    double fahrenheit;

public:
    Temp() {
        celsius = 0;
        fahrenheit = 32;
    }
    
    double getCelsius() const {
        return round(celsius * 10) / 10;
    }

    double getFahrenheit() const {
        return round(fahrenheit * 10) / 10;
    }

    void setCelsius(double celsius) {
        double f = celsius * 9.0 / 5.0 + 32.0;
        fahrenheit = f;
    }

    void setFahrenheit(double fahrenheit) {
        double c = (fahrenheit - 32.0) * 5.0 / 9.0;
        celsius = c;
    }
};

#endif // MURACH_DIE_H
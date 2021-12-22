#include <iostream>
#include <string>
#include <limits>
#include "console.h"

    // declare helper functions
    void discard_remaining_chars();
    void handle_invalid_number();
    bool check_range(double num, double min, double max);

    // define general-purpose functions
    double Console::get_double(std::string prompt, double min, double max) {
        double num = 0.0;
        bool is_valid = false;
        while (!is_valid) {
            std::cout << prompt;
            if (!(std::cin >> num)) {
                handle_invalid_number();
            }
            else {
                discard_remaining_chars();
                is_valid = check_range(num, min, max);
            }
        }
        return num;
    }

    int Console::get_int(std::string prompt, int min, int max) {
        int num = 0;
        bool is_valid = false;
        while (!is_valid) {
            std::cout << prompt;
            if (!(std::cin >> num)) {
                handle_invalid_number();
            }
            else {
                discard_remaining_chars();
                is_valid = check_range(num, min, max);
            }
        }
        return num;
    }

    char Console::get_char(std::string prompt, bool add_blank_line) {
        char choice = 'n';
        std::cout << prompt;
        std::cin >> choice;
        if (add_blank_line)
            std::cout << std::endl;

        discard_remaining_chars();
        return choice;
    }

    //for string with space
    std::string Console::get_string(std::string prompt)
    {
        std::string result;
        std::cout << prompt;
        discard_remaining_chars();
        getline(std::cin, result);
        return std::string();
    }

    // define helper functions
    void discard_remaining_chars() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void handle_invalid_number() {
        std::cout << "Error! Invalid number. Try again.\n";
        std::cin.clear();              // clear the failure flag
        discard_remaining_chars();
    }

    bool check_range(double num, double min, double max) {
        if (num < min) {
            std::cout << "Error! Number must be greater than "
                << min << ". Try again.\n";
            return false;
        }
        else if (num > max) {
            std::cout << "Error! Number must be less than "
                << max << ". Try again.\n";
            return false;
        }
        else {
            return true;
        }
    }

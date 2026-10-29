#include <iostream>
#include <string>
#include <charconv>

using namespace std;


void calculate() {
    string text_input; 
    int number;

    while (true) {
        cout << "Please input a number: ";
        cin >> text_input;

        
        if (text_input == "end") {
            cout << "Operation cancelled by user.\n";
            return;
        }


        auto [ptr, ec] = std::from_chars(text_input.data(), text_input.data() + text_input.size(), number);

        if (ec != std::errc{}) {
            cout << "MISTAKE: Please input a valid integer.\n";
            continue;
        }

       
        break;
    }

   
    if ((number & 1) == 0) {
        cout << "Analysis: Your number is EVEN.\n";
    } else {
        cout << "Analysis: Your number is ODD.\n";
    }


    int multiplied = number << 1; 
    int divided = number >> 1;    

    cout << "Your number * 2 is: " << multiplied << "\n";
    cout << "Your number / 2 is: " << divided << "\n";
}


bool askAgain() {
    char choice;
    cout << "Wanna try again?: ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        return true;
    }
    return false;
}

int main() {
    do {
        calculate();
    } while (askAgain());

    cout << "Program terminated successfully.\n";
    return 0;
}
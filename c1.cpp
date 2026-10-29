#include <iostream>
#include <string>
#include <charconv>
using namespace std;

struct strucle {
    int add = 0;
    int i = 0;
};

strucle sub() {  
    strucle strucles;
    string text_input; 
    int number;        

    while (true) {
        cout << "Please input a number or type 'end' to quit: ";
        cin >> text_input;

        if (text_input == "end") {
            break; 
        }


        auto [ptr, ec] = std::from_chars(text_input.data(), text_input.data() + text_input.size(), number);

        if (ec != std::errc{}) {
            cout << "MISTAKE: Please input a valid number." << "\n";
            continue; 
        }


        if ((number < 0) && (number % 2 != 0)) {
            strucles.i++;
        }
        else if ((number % 2 == 0) && (number > 0)) {
            strucles.add += number; 
        }
    }
    
    return strucles;
}

void out(int add, int i) {
    cout << "Even positive numbers sum is: " << add << "\n";
    cout << "Odd negative numbers count is: " << i << "\n";
}

int main() { 
    strucle mystrucles = sub();
    out(mystrucles.add, mystrucles.i);
    return 0;
}
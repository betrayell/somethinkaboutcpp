#include <iostream>
#include <limits>
#include <string>
using namespace std;

int takeData(){
    int x;
    while (true) {
        cout << "Enter a number: ";
        cin >> x;
        if (cin.fail()) {
            cout << "MİSTAKE:Please input a valid number." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
       else{
        return x;
       }
    }
}
string conditions(int x){
    if(x == 0){
     return "Your number is even and equels 0";
    }
    if (x>0){
        if (x % 2 == 0){
            return  "Your number is even and greater than 0";
        } 
        else{
            return "Your number is odd and greater than 0";
        }
    }

   else {
        if (x % 2 == 0){
            return "Your number is even and less than 0";
            
        }
        else {
            return "Your number is odd and less than 0";
            
        }

    }
}
void out(string y){
    cout << y << "\n";
}
int main(){
    int x;
    string y;
    x = takeData(); 
    y = conditions(x);
    out(y);
    return 0;
} 




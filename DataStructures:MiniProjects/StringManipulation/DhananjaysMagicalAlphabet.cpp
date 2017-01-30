#include <iostream>
using namespace std; 

/* 
An alphabet is Dhananjay's Magical alphabet if its ASCII value is prime.

Rules for converting:

1.Each character should be replaced by the nearest Dhananjay's Magical alphabet.

2.If the character is equidistant with 2 Magical alphabets. 
The one with lower ASCII value will be considered as its replacement.

*/



void convert(string input) {
    int x = input.length();
    for (int i = 0; i < x; i++) {
        int value = int(input[i]);
        if (value <= 93) {
            if (value <= 76) {
                if (value <= 72) {
                    if (value <= 69) {
                        input[i] = 'C';
                        cout << input[i];
                    }
                    else {
                        input[i] = 'G';
                        cout << input[i];
                    }
                }
                else {
                    input[i] = 'I';
                    cout << input[i];
                }
            }
            else {
                if (value <= 81) {
                    input[i] = 'O';
                    cout << input[i];
                }
                else if (value <= 86) {
                    input[i] = 'S';
                    cout << input[i];
                }
                else {
                    input[i] = 'Y';
                    cout << input[i];
                }
            }
        }
        else {
            if (value <= 105) {
                if (value <= 102) {
                    if (value <= 99 ) {
                        input[i] = 'a';
                        cout << input[i];
                    }
                    else {
                        input[i] = 'e';
                        cout << input[i];
                    }
                }
                else {
                    input[i] = 'g';
                    cout << input[i];
                }
            }
            else {
                if (value <= 108) {
                    input[i] = 'k';
                    cout << input[i];
                }
                else if (value <= 111) {
                    input[i] = 'm';
                    cout << input[i];
                }
                else {
                    input[i] = 'q';
                    cout << input[i];
                }
            }
            
        }
    }
    cout << endl;
}



int main()
{
    int testcase, num_Char;
    string x;
    cout << "How many test cases would you like?" << endl;
    cin >> testcase;
    
    for (int i = 0; i < testcase; i++) {
        cout << "Please enter the number of characters in your string: " << endl;
        cin >> num_Char;
        cout << "Please enter your string: " << endl;
        cin >> x;
        if(x.length() != num_Char) {
            cout << "You did not enter the right number of characters. Please try again." << endl;
            break;
        }
        convert(x);
    }
    


    return 0;
}

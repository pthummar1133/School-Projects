//  StringCaseChanger
//
//  Created by Parth Thummar on 1/29/17.
//  Copyright © 2017 Parth Thummar. All rights reserved.
//

#include <iostream>
using namespace std;

//Change the case of each alphabet in string input.


int main()
{
    cout << "Please input your string: ";
    string input;
    cin >> input;
    
    for(int i = 0; i < input.length(); i++) {
        if (int(input[i]) > 64 && int(input[i]) < 91) {
            input[i] = char(int(input[i]+32));
        }
        else if (int(input[i]) > 96 && int(input[i]) < 123) {
            input[i] = char(int(input[i]-32));

        }
    }
    
    cout << "The converted string is: " << input << endl << endl;
    
    return 0;
}

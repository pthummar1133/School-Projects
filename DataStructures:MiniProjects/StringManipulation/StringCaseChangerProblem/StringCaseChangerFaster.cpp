//  StringCaseChangerFaster.cpp
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
        if (islower(input[i])
            input[i] = isupper(input[i]);
        else if(isupper(input[i]))
            input[i] = islower(input[i]);
    }
    
    cout << "The converted string is: " << input << endl << endl;
    
    return 0;
}

#include <iostream>
using namespace std;

//PalindromicString

int main()
{
    string input;
    cin >> input;
    
    int length = input.length();
    
    for (int i = 0; i < length; i++) {
        int x = length-i-1;
        if (i == x || i>x) {
            cout << "YES";
            break;
        }
        else if (input[i] == input[x]) {
            continue;
        }
        else {
            cout << "NO";
            break;
        }
            
    }
    
    return 0;
}

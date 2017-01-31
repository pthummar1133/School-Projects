#include <iostream>
using namespace std;

/*
[1] If any of the width or height is less than L, user is prompted to upload another one. 
Print "UPLOAD ANOTHER" in this case.
[2] If width and height, both are large enough and 
(a) if the photo is already square then it is accepted. Print "ACCEPTED" in this case.
(b) else user is prompted to crop it. Print "CROP IT" in this case.
*/


int main()
{
    int length, num_Photos, width, height;
    //L
    cout << "Print the length: " << endl;
    cin >> length;
    cout << "Print the number of photos to upload: " << endl;
    cin >> num_Photos;
    
    for (int i = 0; i < num_Photos; i++) {
        cout << "Print the width: " << endl;
        cin >> width;
        cout << "Print the height: " << endl;
        cin >> height;
        
        if (width < length || height < length) {
            cout << "UPLOAD ANOTHER" << endl;
        }
        else if (width == height) {
            cout << "ACCEPTED" << endl;
        }
        else {
            cout << "CROP IT" << endl;
        }
        
    }
    
    return 0;
}

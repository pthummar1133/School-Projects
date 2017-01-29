#include <iostream>
using namespace std;

/*
Suppose we have a sequence of non-negative integers, Namely a_1, a_2, ... ,a_n. 
At each time we can choose one term a_i with 0 < i < n and we subtract 1 from both a_i 
and a_i+1. We wonder whether we can get a sequence of all zeros after several operations.
*/


bool modify_sequence (int a[], int num) {
    int elements;
    cout << "Please input " << num << " numbers." << endl;
    for (int i = 0; i < num; i++) {
        cin >> elements;
        a[i] = elements;
    }
    
    for (int i = 0; i < num-1; i++) {
        while (a[i] && a[i+1]) {
            a[i]-=1;
            a[i+1]-=1;
        }
    }
    
    for (int i = 0; i < num; i++) {
        if (a[i] != 0)
            return false;
    }
    return true;
}

void execute () {
    int num; 
    cout << "Please input the amount of numbers you would like to input." << endl;
    cin >> num;
    
    int a[num];
    
    if (modify_sequence(a,num))
        cout << "YES. The sequence was able to be modified to all zeros.";
    else
        cout << "NO. The sequence failed to be modified to all zeros.";
}


int main()
{
    execute();

    return 0;
}

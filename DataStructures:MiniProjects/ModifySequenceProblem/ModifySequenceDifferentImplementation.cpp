#include <iostream>
using namespace std;

/*
//Suppose we have a sequence of non-negative integers, Namely a_1, a_2, ... ,a_n. 
//At each time we can choose one term a_i with 0 < i < n and we subtract 1 from both a_i 
//and a_i+1. We wonder whether we can get a sequence of all zeros after several operations.
*/

bool modify_sequence (int *a, int num) {
    int elements;
    
    //checks first condition
    if (num == 1) {
        int a;
        cin >> a;
        if (a == 0)
            return true;
        else 
            return false;
    }
    //checks second condition
    else if (num == 2) {
        int a, b;
        cin >> a;
        cin >> b;
        if (a == b)
            return true;
        else
            return false;
    }
    cin >> elements;
    a[0] = elements;
    cin >> elements;
    a[1] = elements;
    
    //checks the rest of conditions
    while (a[0] && a[1]) {
            a[0]-=1;
            a[1]-=1;
        }
    //check for: x 0 of first two numbers (a[0] & a[1]) in sequence
    if (a[0] != 0 && a[1] == 0) 
        return false;
    
    for (int i = 2; i < num; i++) {
        cin >> elements;
        a[i] = elements;  
        
        //checks for prev number to not be 0 and current number to be 0
        if (a[i-1] != 0 && a[i] == 0)
            return false;
        
        //checks if prev number and current number are both zero;
        else if (a[i-1] == 0 && a[i] == 0)
            continue;
            
        //computes previous number being larger than current number
        else if (a[i-1] != 0 && a[i-1]>a[i]){
            return false;
        }   
        
        //computes previous number being smaller than current number
        else if (a[i-1] != 0 && a[i-1]<=a[i]) {
            a[i]-= a[i-1];
            a[i-1] = 0;
        }
    }
    
    if (a[num-1])
        return false;
    return true;
}

void execute () {
    int num;
    cin >> num;
    
    int a[num];
    
    if (modify_sequence(a,num))
        cout << "YES";
    else
        cout << "NO";
    
}


int main()
{
    execute();

    return 0;
}

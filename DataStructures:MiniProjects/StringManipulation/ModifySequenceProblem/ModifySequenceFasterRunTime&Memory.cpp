#include <iostream>
using namespace std;

/*
//Suppose we have a sequence of non-negative integers, Namely a_1, a_2, ... ,a_n. 
//At each time we can choose one term a_i with 0 < i < n and we subtract 1 from both a_i 
//and a_i+1. We wonder whether we can get a sequence of all zeros after several operations.
*/


//shift function of array
void shift(int * a) {
    a[0] = a[1];
    a[1] = a[2];
    a[2] = 0;
    
}

bool modify_sequence (int *a, int num) {
    int elements;
    
    cout << "Please input " << num << " numbers." << endl;
    
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
    
    //checks rest of conditions
    else if (num > 2) 
    {
        //assigns first two values
        cin >> elements;
        a[0] = elements;
        cin >> elements;
        a[1] = elements;
        while (a[0] && a[1]) 
        {
                a[0]-=1;
                a[1]-=1;
        }
        
        //check for: x 0 of first two numbers (a[0] & a[1]) in sequence
        if (a[0] != 0 && a[1] == 0) 
            return false;
        
        int i = 0;
        while(i < num) 
        {
            ++i;
            cin >> elements;
            a[2] = elements;  
            
            //checks for prev number to not be 0 and current number to be 0
            if (a[1] != 0 && a[2] == 0)
                return false;
            
            //checks if prev number and current number are both zero;
            else if (a[1] == 0 && a[2] == 0)
                continue;
                
            //computes previous number being larger than current number
            else if (a[1] != 0 && a[1]>a[2]){
                return false;
            }   
            
            //computes previous number being smaller than current number
            else if (a[1] != 0 && a[1]<=a[2]) {
                a[2]-= a[1];
                a[1] = 0;
            }
        }
        
        if (a[2])
            return false;
        return true;
    }
    
}

void execute () {
    cout << "Please input the amount of numbers you would like to input." << endl;
    
    int num;
    cin >> num;
    
    int a[3];
    
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

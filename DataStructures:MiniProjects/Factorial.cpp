#include <iostream>
using namespace std;

//Finding the Factorial of a Number

int factorial(int n) {
    if (n <= 1) 
        return 1;
    return n*factorial(n-1);
}

int main()
{
    cout << "Please enter a number you would like to factorial: " << endl;
    int num, result;
    cin >> num;
    
    result = factorial(num);
    
    cout << result;


    return 0;
}

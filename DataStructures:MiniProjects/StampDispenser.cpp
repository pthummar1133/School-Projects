#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <assert.h>

///
///Stamp Dispenser program to give minimum number of stamps needed for a given request
///
class StampDispenser
{
public:
    
    //Checks to see if stampdenominations are valid
    StampDispenser(const int* stampDenominations, size_t numStampDenominations);
    
    //Takes in the request and calculates the least number of stamps needed
    int CalcNumStampsToFillRequest(int request);
    
    //Destructor
    ~StampDispenser() {
        
        delete[] stampDenominations;
        std::cout << "Destructor executed" << std::endl;
    }
    
private:
    
    size_t numStampDenominations;
    int *stampDenominations;
    
};

StampDispenser::StampDispenser(const int *stampDenominations, size_t numStampDenominations) {
    
    //checks to see if denominations are present
    if (numStampDenominations>0) {
        
        StampDispenser::stampDenominations = new int[numStampDenominations];
        
        //Copies made to member variables
        StampDispenser::numStampDenominations = numStampDenominations;
        
        for(int i = 0; i < numStampDenominations; i++) {
            
            StampDispenser::stampDenominations[i] = stampDenominations[i];
            
        }
        
        //sort array descending from greatest to least
        sort(StampDispenser::stampDenominations, StampDispenser::stampDenominations + StampDispenser::numStampDenominations, std::greater<int>());
        
        //Check to see if lowest stampDenomination is 1
        if (StampDispenser::stampDenominations[numStampDenominations-1] != 1) {
            
            std::cout << StampDispenser::stampDenominations[numStampDenominations-1] <<
            " is the minimum denomination, but is not equal to 1. Program will now Terminate." << std::endl;
            exit(1);
            
        }
    }
    
    else {
        
        std::cout << "Nothing Initialized. Please initialize stamp denominations." << std::endl;
        exit(1);
        
    }
}

int StampDispenser::CalcNumStampsToFillRequest(int request) {
    
    //check for special cases
    if(request < 0) {
        
        return -1;
        
    }
    else if(request == 0){
        
        return 0;
    
    }
    
    int *minStampsMin = new int [request + 1];
    
    minStampsMin[0] = 0;
    
    //iterates request number of times
    for (int i = 1; i <= request; i++) {
        
        std::vector<int> numOfStampsTracker;
        
        //iterates number of elements in stampDenominations number of times for stamp
        for (int j = 0; j < numStampDenominations; j++) {
            
            if (i >= stampDenominations[j]) {
                
                int valueRemaining = i - stampDenominations[j];
                numOfStampsTracker.push_back(minStampsMin[valueRemaining] + 1);
                
            }
        }
        
        int min = numOfStampsTracker[0];
        
        //Checks to make sure there's a possible value for min num of stamps
        if(numOfStampsTracker.size() == 0) {
            
            std::cout << std::endl << "Error";
            return -1;
            
        }
        
        //computes minimum number of stamps
        else {
            
            for (int i = 1; i < numOfStampsTracker.size(); i++) {
                
                if (numOfStampsTracker[i] < min) {
                    
                    min = numOfStampsTracker[i];
                    
                }
                
            }
            
        }
    
        minStampsMin[i] = min;
        
    }
    
    return minStampsMin[request];
    
}

void Execute() {
    int num = 0, elements = 0, request = 0;
    
    std::cout << "Enter in how many stampDenominations you would want: ";
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cin >> num;
    
    int stampDenominations[num];
    
    std::cout << "Enter which stampdenominations you want (no more or less than number of stampDenominations): ";
    std::cout << std::endl;
    std::cout << std::endl;
    
    for (int i = 0; i < num; i++) {
        std::cin >> elements;
        stampDenominations[i] = elements;
    }
    
    std::cout << "Please enter the request for which you want stamps for: ";
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cin >> request;
    
    StampDispenser stampDispenser(stampDenominations, num);
    int min_Stamps = stampDispenser.CalcNumStampsToFillRequest(request);
    
    if (min_Stamps >= 0) {
        std::cout << "Minimum Number of Stamps needed: " << min_Stamps << std::endl;
    }
    else {
        std::cout << "Request is Invalid. Please enter valid request." << std::endl;
    }
    
}




int main()
{
    Execute();
    
    return 0;
}

#include <iostream>
using namespace std;

bool is_Safe(int board[], int row, int col, int n)
{	
    int i, j, colptr;

    for (i = 0; i < n; i++) {
    	
    	//calculate/convert two-dimensional array pos. to one-dimensional
    	colptr = row*n + i; 
    	
    	//check row
        if (board[colptr])		
            return false;
            
    	for (j = 0; j < n; j++) {
    		
    		//checks diagonal
    		if ((i + j) == (row + col) && board[i*n+j] == 1) 
    			return false;
    			
    		//checks diagonal
    		else if ((i - j) == (row - col) && board[i*n+j] == 1) 
    			return false;
    	}
    }
   
    return true;
}
 
bool n_Queens(int board[], int col, int n)
{
	//base case prevents recursion from looping forever. All queens are placed
    if (col >= n)
        return true;
        
    //place queen in rows one at a time
    for (int i = 0; i < n; i++)
    {
    	//checks if board[i][col] = board[i*n + col] is safe
        if ( is_Safe(board, i, col, n) )
        {
            //if safe then place queen on board[i][col] = board[i*n + col]
            board[i*n + col] = 1;
 
            //recursion used to calculate rest of queens in each column
            if ( n_Queens(board, col + 1, n) )
                return true;
 
            //backtrack queen if board[i][col] = board[i*n + col] is not a safe place
            board[i*n + col] = 0;
        }
    }
    
    return false;
}

//Print whether there is a solution and the board result
void printSolution(int board[], int size, int n)
{
	if (n_Queens(board, 0, n))
    	cout << "YES";
    else
		cout << "NO";
		
    for (int x = 0; x<size; x++){
		if(x % n == 0) {
			cout << endl;
			cout << board[x] << " ";
		}
		else {
			cout << board[x] << " ";
		}
	}
}

int main()
{
    int n;
	cin >> n;
	
	int size = n*n;
    int board[size];
    
    for(int x = 0; x < size; x++) {
    	board[x] = 0;
    }
    
    printSolution(board, size, n);
    
    return 0;
}
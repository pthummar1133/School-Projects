#include <iostream>
#include <string>
using namespace std;
int Frequency[26];

int hashFunc(char c) {
    return (c - 'a');
}

void countFre(string s) {
    
	for(int i = 0; i < 26; i++) {
	    Frequency[i] = 0;
	}
	
    for (int i = 0; i < s.length(); i++) {
        int index = hashFunc(s[i]);
        Frequency[index]++;
    }
    for (int i = 0; i < 26; i++){
        cout << (char)(i + 'a') << ' ' << Frequency[i] << endl;
    }
}


int main() {
    string s;
	cin >> s;
	
	countFre(s);
	return 0;
}

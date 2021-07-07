// Q2. Possible Words from Phone Digits

#include <bits/stdc++.h>
#include <string>

using namespace std;

void possibleWords(int a[],int n);


int main() {
  
	int T;
	
	cin >> T; 
	
	while(T--)
	{
	   int N;
	    
	   cin >> N;
	   
	   int a[N]; 
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; 
	   }
	   
	  possibleWords(a,N);
	   cout << endl;
	}
	
	return 0;
}


string hashTable[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void pW(int a[], int N, string output){
    if(N==0){
        cout<<output<<" ";
        return;
    }
    string str = hashTable[a[0]];
    for(int i=0;i<str.length();i++){
        pW(a+1,N-1,output+str[i]);
    }
    return;
}
void possibleWords(int a[],int N)
{
    return pW(a,N,"");
}

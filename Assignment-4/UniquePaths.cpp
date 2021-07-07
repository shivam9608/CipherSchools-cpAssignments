// Q17. Unique Paths

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    if(n==1 || m==1)return 1;
    return uniquePaths(m-1, n) + uniquePaths(m, n-1);
}
int main(){
    cout<<uniquePaths(2, 2);
}

//Ques.18) Excel Sheet Column Title.
//Sol.
#include <bits/stdc++.h>
using namespace std;
string convertToTitle(int n) 
{        
    string ans;
    while(n>0)
    {
        --n;
        int d= n%26;
        n/=26;
        ans+= 'A'+d;            
    }
   reverse(ans.begin(),ans.end());
   return ans; 
}

int main() 
{
   cout<<convertToTitle(28) <<endl;
   return 0; 
}

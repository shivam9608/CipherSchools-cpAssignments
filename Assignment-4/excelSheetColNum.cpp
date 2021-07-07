// Q19. Excel Sheet Coloumn Number

#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string s)
{        
        int ans=0;        
        for(auto c:s)
        {
          ans= ans*26 + (c-'A'+1);    
        }
            return ans;
}
int main() 
{
   cout<<titleToNumber("AB") <<endl;
   return 0; 
}

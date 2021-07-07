#include<bits/stdc++.h>

int Solution::numDecodings(string A) {
    if(A[0] == '0')return 0;
   vector<int> count(A.length(),1);
   if(A.length() == 1){
       if(A[0] == '0')return 0;
       return 1;
   }
   for(int i=1 ; i<A.length() ; i++){
       if(A[i] == '0' && (A[i-1] > '2' || A[i-1] == '0'))return 0;
       else if(A[i] == '0'){
           if(i == 1)count[i] = count[i-1];
           else count[i] = count[i-2];}
       else if(A[i-1] == '0'){
           count[i] = count[i-1];
       }
       else if(A[i-1] < '2' || A[i-1] == '2' && A[i] <'7'){
           if(i==1)count[i] = count[i-1] + 1;
           else count[i] = count[i-1] + count[i-2];
       }
       else{
           count[i] = count[i-1];
       }
   }
   return count[A.length()-1];
}

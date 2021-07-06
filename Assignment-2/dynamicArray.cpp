//Question 19. Create a dynamic array.

#include<iostream>
using namespace std;

int main() 
{
   int i,n;
   cout<<"Enter total number of elements:"<<"\n";
   cin>>n;
   int *a = new int(n);
   cout<<"Enter "<<n<<" elements"<<endl;
   for(i = 0;i<n;i++) 
   {
      cin>>a[i];
   }
   
   cout<<"Entered elements are: ";
   for(i = 0;i<n;i++)
   {
      cout<<a[i]<<" ";
   }
   
   cout<<endl;
   delete (a);
   return 0;
   
}

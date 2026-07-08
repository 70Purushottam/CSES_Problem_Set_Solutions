// C++ Solution

// Topics: Simulation 

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
  int n;
  cin>>n;
  if(n==2||n==3) cout<<"NO SOLUTION"<<"\n";

  else {
      if(n%2==0){
         int i=1,j=(n+1)/2 + 1;
         for(int x=1;x<=n;x++){
          if(x%2!=0){
              cout<<j++<<" ";
          }
          else{
              cout<<i++<<" ";
          }
          
      }
  }
  else{
      int i=1,j=(n+1)/2 + 1;
      for(int x=1;x<=n;x++){
          if(x%2!=0){
              cout<<i++<<" ";
          }
          else{
              cout<<j++<<" ";
          }
          
      }
   }
 }
}

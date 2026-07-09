// C++ Solution

// Topics: BackTracking


# include <bits/stdc++.h>
using namespace std;
int ans=0,n=8;
bool is_safe(char b[8][8],int r,int c){
  if(b[r][c]=='*') return false;
  
  // top left
  int i=r-1,j=c-1;
  while(i>=0&&j>=0){
      if(b[i][j]=='q') return false;
      i--;j--;
  }
  
  // left
   j=c-1;
  while(j>=0){
      if(b[r][j]=='q') return false;
      j--;
  }
  
  // bottom left
   i=r+1,j=c-1;
  while(i<8&&j>=0){
      if(b[i][j]=='q') return false;
      i++;j--;
  }
  
  return true;
}
 
void func(char b[8][8],int c){
    if(c==n) {ans++;return;}
    
    for(int r=0;r<n;r++){
        if(is_safe(b,r,c)){
            b[r][c]='q';
            func(b,c+1);
            b[r][c]='.';
        }
    }
}
 
int main() {
	// your code goes here
//int n=8;
char b[8][8];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>b[i][j];
    }
}
func(b,0);
cout<<ans;
}
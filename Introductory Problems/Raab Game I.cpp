// C++ Solution

// Topics: Game 


# include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n,a,b;
    cin>>n>>a>>b;
    if(a+b>n||(a<1&&b>0)||(b<1&&a>0)) cout<<"NO"<<"\n";
else{   
    cout<<"YES"<<"\n";
    vector<int> v1,v2;
    int i=1;
    int same=n-a-b;
    while(same>0){
        v1.push_back(i);
        v2.push_back(i);
        i++;
        same--;
    }
    int k=i,j=i;
    i=n-a+1;
    while(a>0){
        v1.push_back(i++);
        v2.push_back(j++);
       // i++;
        a--;
    }
   while(b>0){
        v1.push_back(k++);
        v2.push_back(j++);
        i++;
        b--;
    }
    for(int i=0;i<n;i++){
        cout<<v1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<v2[i]<<" ";
    }
    cout<<"\n";}
}
}

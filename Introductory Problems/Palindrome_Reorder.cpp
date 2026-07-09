// C++ Solution

// Topics : hashmap, string

# include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
string s;
cin>>s;
unordered_map<char,int> mp;
int n=s.size();
for(int i=0;i<n;i++){
    mp[s[i]]++;
}
int f=0,cnt=0;
for(auto it:mp){
    if(it.second%2!=0) cnt++;
    if(cnt>=2) {cout<<"NO SOLUTION";f=1;break;}
}
int i=0,j=n-1;
if(f!=1){
    for(auto it:mp){
        int k=it.second;
        if(k%2!=0){//  odd
            s[n/2]=it.first;
        }
        k--;
        while(k>0){
            s[i++]=it.first;
            s[j--]=it.first;
            k-=2;
        }
    }
    cout<<s;
}
}
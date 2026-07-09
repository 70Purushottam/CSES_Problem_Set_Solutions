// C++ Solution

// Topics: String , Recursion

#include <bits/stdc++.h>
using namespace std;
map<char,int> mpf;
vector<string> ans;
void generate(string aux,int n){
    if(aux.length()==n) {ans.push_back(aux);return;}
    for(auto it:mpf){
        if(it.second>0){
            mpf[it.first]--;
            generate(aux+it.first,n);
             mpf[it.first]++;
        }
    }
}
int main() {
	// your code goes here
string s;
cin>>s;
int n=s.size();
// map<char,int> mpf;
for(int i=0;i<n;i++){
    mpf[s[i]]++;
}
 generate("",n);
 cout<<ans.size()<<"\n";
 for(int i=0;i<ans.size();i++) cout<<ans[i]<<"\n";
}

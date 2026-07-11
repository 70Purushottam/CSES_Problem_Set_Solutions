// C++ Solution

// Topics: String, hashmap


#include <bits/stdc++.h>
using namespace std;
 
bool is_possible(map<char,int>& mp, char curr){
    int total_left_to_fill=0;
    char mode=curr;
    for(auto it:mp){

        if(it.second>mp[mode]) mode=it.first;
        
        total_left_to_fill += it.second;
    }
    
    return (mp[mode]<=(total_left_to_fill + 1)/2) && (mp[curr]<=total_left_to_fill/2);
} 
int main() {
	// your code goes here
 string s;
 cin>>s;
 int n=s.size();
 
 map<char,int> mp;
 for(char ch:s) mp[ch]++;
 
 string ans="";
 char last='\0';
 
 for(int i=0;i<n;i++){
     
     for(int j=0;j<26;j++){
         char ch='A'+j;
         if(mp[ch]==0||ch==last) continue;
         
         mp[ch]--;
         if(is_possible(mp,ch)){
             ans.push_back(ch);
             last=ch;
             break;
         }
         else mp[ch]++;
     }
 }
 if(ans.size()==n) cout<<ans;
 else cout<<-1;
 
}
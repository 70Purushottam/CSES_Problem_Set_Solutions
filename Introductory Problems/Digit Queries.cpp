// C++ Solution

// Topics: Queries, counting

#include <bits/stdc++.h>
# define ll long long
using namespace std;
 
int main() {
	// your code goes here
 int q;
 cin>>q;
 while(q--){
 
 ll k;
 cin>>k;
 
 ll start=1,digit_len=1,count=9;
 
 while(k> start + digit_len*count){
     start += digit_len*count;
     digit_len++;
     count *= 10;
 }
 
 ll first_num= pow(10,digit_len-1);
 
 ll offset_num=(k-start)/digit_len;
 ll target_num=first_num+offset_num;
 
 string str= to_string(target_num);
 ll digit_offset = k-start;
 ll pos_in_num=digit_offset%digit_len;
 cout<<str[pos_in_num]<<"\n";
 }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
  string st;
  cout<<"Enter data:";
  cin>>st;
  int cnt=0;
  
  for(auto it : st){
  	if(it == '1') cnt++;
  }
  
  if(cnt % 2 == 0) st+='0';
  else st+='1';
  
  cout<< "String with Parity bit is "<< st<<endl;
  return 0;
}

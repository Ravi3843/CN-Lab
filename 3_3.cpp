#include <bits/stdc++.h>
using namespace std;

int main(){

  string st;
  cout<<"Enter bit string:";
  cin>>st;
  int ami=0;
  
  for(int i=1; i<st.size(); i++){
      if((st[i] == '1' && st[i-1] == '0') || (st[i] == '0' && st[i-1] == '1') || 
      (st[i] == '1' && st[i-1] == '1'))  ami++;
  }
  
  cout<<"The no of transitions is "<< ami<<endl;
  
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){

  string st;
  cout<<"Enter bit string:";
  cin>>st;
  int n=st.size();
  int dman=n;
  
  for(int i=1; i<st.size(); i++){
      if(st[i] == '0') dman++;
  }
  
  cout<<"The no of transitions is "<< dman<<endl;
  
  return 0;
}

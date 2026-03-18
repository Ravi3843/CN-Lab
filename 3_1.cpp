#include <bits/stdc++.h>
using namespace std;

int main(){

  string st;
  cout<<"Enter bit string:";
  cin>>st;
  int n=st.size(), nrzl=0;
  
  for(int i=1; i<n; i++){
      if(st[i] != st[i-1]) nrzl++;
  }
  
  cout<<"The no of transitions is "<< nrzl<<endl;
  
  return 0;
}

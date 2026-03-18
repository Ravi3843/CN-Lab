#include <bits/stdc++.h>
using namespace std;

int main(){

  string st;
  cout<<"Enter bit string:";
  cin>>st;
  int n=st.size(), man=n;
  
  for(int i=1; i<n; i++){
      if(st[i] == st[i-1]) man++;
  }
  
  cout<<"The no of transitions is "<< man<<endl;
  
  return 0;
}

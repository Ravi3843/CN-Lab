#include <bits/stdc++.h>
using namespace std;

int main(){

  string st;
  cout<<"Enter bit string:";
  cin>>st;
  int nrzi=0;
  
  for(int i=0; i<st.size(); i++){
      if(st[i] == '1') nrzi++;
  }
  
  cout<<"The no of transitions is "<< nrzi<<endl;
  
  return 0;
}

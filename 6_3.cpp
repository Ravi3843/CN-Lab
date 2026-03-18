#include <bits/stdc++.h>
using namespace std;

int main(){
  string st;
  cout<<"Enter string:";
  cin>>st;
  int cnt=0;
  string ans="";
  
  for(int i=0; i<st.size(); i++){
    if(st[i]=='1') cnt++;
    else if(st[i]=='0') cnt=0;
    ans += st[i];
    
      if(cnt==5) {
       ans+='0';
       cnt=0;
      }
  }
  
    cout<<"String after bit stuffing: "<<ans<<endl;
  
return 0;
}

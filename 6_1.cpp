#include <bits/stdc++.h>
using namespace std;

void leftshift(vector<int> buff){
 for(int i=0; i<buff.size()-1; i++){
   buff[i]=buff[i+1];
 }
}

void xorsum(vector<int>& buff, vector<int>& div){
  for(int i=0; i<buff.size(); i++){
     buff[i]^=div[i];
  }
}


int main(){
 string stream, genpol;
 cout<<"Enter data stream:";
 cin>>stream;
 cout<<"Enter generating polynomial:";
 cin>>genpol;
 int n=stream.size();
 int m=genpol.size();
 stream+=string(m-1, '0');
 
 vector<int> div(m), buff(m);
 for(int i=0; i<m; i++){
  div[i]=genpol[i]-'0';
  buff[i]=stream[i]-'0';
 }
 
 for(int i=m; i<=n+m-1; i++){
   if(buff[0] == 1) xorsum(buff, div);
   leftshift(buff);
   if(i<stream.size()) buff[m-1]=stream[i]-'0';
 }
   cout<<"CRC Remainder:";
   for(int i=0; i<m-1; i++){
     cout<<buff[i]<<endl;
   }
 
return 0;
}

#include <bits/stdc++.h>
using namespace std;

string binarySum(string a, string b){
   int c=0;
   string result="";
   int n=a.size();
   
   for(int i=n-1; i>=0; i--){
      int sum = (a[i]-'0') + (b[i]-'0') + c;
      result=char(sum%2 + '0') + result;
      c = sum/2;
   }
    if(c==1){
    result=binarySum(result, string(a.size()-1, '0') + '1');
    c=0;
    }
    return result;
}


string complement(string s){
    for(int i=0; i<s.size(); i++){
       if(s[i]=='1') s[i]='0';
       else s[i]='1';
    }
  return s;
}


int main(){
  int n;
  cout<<"Enter no of segments:";
  cin>>n;
  string sum;
  cout<<"Enter 1st segment:";
  cin>>sum;
  cout<<"Enter other segment:";
  
  for(int i=1; i<n; i++){
    string tem;
    cin>>tem;
    sum=binarySum(sum, tem);
  }
  
  string cs = complement(sum);
  cout<<"Checksum:"<<cs;
  
return 0;
}

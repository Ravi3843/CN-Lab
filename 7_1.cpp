#include<bits/stdc++.h>
using namespace std;
int dec(string s){
		int d=0;
		for(int i=0;i<s.size();i++){
		d+=pow(2,i)*(s[i]-'0');
		}
		return d;
}
void genhamming(string s){
	string ans="";
	int d=s.size();
	int r=0;
	while(pow(2,r)<d+r+1) r++;
	cout<<"number of parity bit to be added"<<r;
	reverse(s.begin(),s.end());
	int c=0,i=0,j=0;
	while(j<r+d){
	if(pow(2,c)==j+1&&c!=r) {
	ans+='h';
	c++;
	}
	else ans+=s[i++];
	j++;
	}
	for(int i=0;i<ans.size();i++){
	if(ans[i]=='h'){
	int c=0;
	int j=i;
	int a=i+1;
	while(j<ans.size()){
	if(ans[j]=='1') c++;
	j++;
	if(j+1%a==0) j=j+a;
	}
	if(c%2==0) {
	ans[i]='0';
	}
	else {
	ans[i]='1';
	}
	}
	}
	reverse(ans.begin(),ans.end());
	cout<<endl;
	cout<<"hamming code"<<ans;
}
void correcterror(string ans){
	int d=ans.size();
	int r=0;
	string par="";
	while(pow(2,r)<d+r+1) r++;
	reverse(ans.begin(),ans.end());
	int c1=0;
	for(int i=0;i<ans.size();i++){
	if(i+1==pow(2,c1)&&c1!=r){
	c1++;
	int c=0;
	int j=i;
	int a=i+1;
	while(j<ans.size()){
	if(ans[j]=='1') c++;
	j++;
	if(j+1%a==0) j=j+a;
	}
	if(c%2==0) {
	ans[i]='0';
	par+='0';
	}
	else {
	ans[i]='1';
	par+='1';
	}
	}
	}
	int a=dec(par);
	if(a!=0) {
        cout<<"error is present at:"<<a;
        if(ans[a-1]=='0') ans[a-1]='1';
        else ans[a-1]='0';
        }
	 
	
	
}
int main(){
	string s;
        cout<<"enter the frame which should be convert to hamming";
        cin>>s;
        cout<<"hamming code:";
        genhamming(s);
        cout<<"enter the receiving string";
        string rec;
        cin>>rec;
        correcterror(rec);

	return 0;
}

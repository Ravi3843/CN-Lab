#include <bits/stdc++.h>
using namespace std;

int main(){
  float bw;
  cout<<"Enter Bandwidth:";
  cin>>bw;
  
  float snr;
  cout<<"Enter SNR Value:";
  cin>>snr;
  
  double capacity = bw * (log(1+snr)/log (2));
  
  cout<<"Capacity is "<<capacity<<endl;
  return 0;
}

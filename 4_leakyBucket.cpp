#include <bits/stdc++.h>
using namespace std;

void leakyBucket(vector<int> packets, int leakRate, int bucketSize) {
    queue<int> bucket; int content=0;
    cout << "\n--- Leaky Bucket ---\n";
    for(int p: packets){
        cout << "Packet " << p << " arrives\n";
        if(content + p > bucketSize) cout << "Bucket overflow! Packet dropped\n";
        else { bucket.push(p); content += p; }
        int leak=leakRate;
        while(!bucket.empty() && leak>0){
            int f=bucket.front();
            if(f<=leak){ cout << "Sent " << f << endl; leak-=f; content-=f; bucket.pop(); }
            else{ cout << "Sent " << leak << endl; bucket.front()-=leak; content-=leak; leak=0; }
        }
    }
    while(!bucket.empty()){ cout << "Sent remaining " << bucket.front() << endl; bucket.pop(); }
}

void tokenBucket(vector<int> packets, int tokenRate, int bucketSize) {
    int tokens=0;
    cout << "\n--- Token Bucket ---\n";
    for(int p: packets){
        tokens=min(bucketSize, tokens+tokenRate);
        cout << "Packet " << p << ", tokens: " << tokens << endl;
        if(tokens>=p){ cout << "Packet sent\n"; tokens-=p; }
        else cout << "Not enough tokens. Packet waits\n";
    }
}

int main(){
    int choice,n,bucket,rate; vector<int> packets;
    do{
        cout << "\n1.Leaky Bucket 2.Token Bucket 3.Exit\nChoice: "; cin>>choice;
        if(choice==3) break;
        cout << "Number of packets: "; cin>>n; packets.resize(n);
        cout << "Packet sizes: "; for(int i=0;i<n;i++) cin>>packets[i];
        cout << "Bucket size: "; cin>>bucket;
        cout << "Leak/Token rate: "; cin>>rate;
        if(choice==1) leakyBucket(packets, rate, bucket);
        else if(choice==2) tokenBucket(packets, rate, bucket);
        else cout << "Invalid choice!\n";
    } while(choice!=3);
}

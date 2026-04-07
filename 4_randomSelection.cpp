#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));  

    int maxTake = 5;
    vector<int> buffer;
    int packets = 10;

    for(int i = 0; i < packets; i++) {
        if(buffer.size() < maxTake) {
            cout << "Packet accepted: " << i << '\n';
            buffer.push_back(i);
        } 
        else {
            int ind = rand() % buffer.size();

            cout << "Randomly removed packet: " << buffer[ind] << '\n';
            buffer.erase(buffer.begin() + ind);

            cout << "Packet accepted: " << i << '\n';
            buffer.push_back(i);
        }
    }

    return 0;
}
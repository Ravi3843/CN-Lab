#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxTake = 5;

    // Higher value = higher priority
    vector<int> requests = {10, 0, 1, 2, 4, 3, 2, 9, 8, 5};

    vector<int> buffer;

    for(int i = 0; i < requests.size(); i++) {

        if(buffer.size() < maxTake) {
            cout << "Packet accepted: " << requests[i] << '\n';
            buffer.push_back(requests[i]);
        } 
        else {
            // find lowest priority in buffer
            int ind = min_element(buffer.begin(), buffer.end()) - buffer.begin();

            if(buffer[ind] < requests[i]) {
                cout << "Removed packet (low priority): " 
                     << buffer[ind] << '\n';

                buffer.erase(buffer.begin() + ind);

                cout << "Packet accepted: " << requests[i] << '\n';
                buffer.push_back(requests[i]);
            } 
            else {
                cout << "Packet dropped: " << requests[i] << '\n';
            }
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxTake = 5;

    vector<string> requests = {
        "ftp", "multi", "multi", "ftp", "ftp",
        "multi", "ftp", "ftp", "multi", "multi"
    };

    vector<int> buffer;

    for(int i = 0; i < requests.size(); i++) {

        if(buffer.size() < maxTake) {
            cout << "Packet accepted: " << i 
                 << " (" << requests[i] << ")\n";
            buffer.push_back(i);
        } 
        else {
            if(requests[i] == "ftp") {
                // remove oldest packet (FIFO)
                cout << "Removed packet: " << buffer.front() << '\n';
                buffer.erase(buffer.begin());

                cout << "Packet accepted: " << i 
                     << " (ftp)\n";
                buffer.push_back(i);
            } 
            else {
                cout << "Packet dropped: " << i 
                     << " (multi)\n";
            }
        }
    }

    return 0;
}
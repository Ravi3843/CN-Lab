#include<bits/stdc++.h>
using namespace std;

void tokenBucket(vector<int> packets, int tokenRate, int bucketSize, int tc) {
    int tokens = 0;
    int n = packets.size();
    for(int i=0; i<n; i++) {
        // Add tokens per iteration (time unit)
        tokens = min(bucketSize, tokens + tokenRate);

        cout << "\nPacket " << i << '(' << packets[i] << ')' << " arrives | Tokens available: " << tokens << endl;

        // Each packet needs only 1 token (assumed)
        if (tokens >= tc) {
            cout << "Packet SENT\n";
            tokens -= tc;
        } 
        else {
            cout << "Packet WAITING (No tokens)\n";
        }
    }
}

int main() {
    vector<int> packets = {1, 1, 1, 1, 1, 1, 1, 1}; // 8 packets
    int tokenRate = 2;     // tokens added per iteration
    int bucketSize = 5;    // max tokens
    int tc = 1;           // token consumptions

    tokenBucket(packets, tokenRate, bucketSize, tc);

    return 0;
}

// 2nd
#include <bits/stdc++.h>
using namespace std;

void tokenBucket(vector<int> &packets, int tokenRate, int bucketSize) {
    int tokens = 0;
    queue<int> q;

    cout << "\n--- Token Bucket with Queue ---\n";

    for (int i = 0; i < packets.size(); i++) {

        // Add tokens each time unit
        tokens = min(bucketSize, tokens + tokenRate);

        cout << "\nTime " << i + 1;
        cout << "\nTokens available: " << tokens << endl;

        // First, try to send queued packets
        while (!q.empty() && tokens >= q.front()) {
            cout << "Queued packet of size " << q.front() << " SENT ✅\n";
            tokens -= q.front();
            q.pop();
        }

        // Now handle current packet
        cout << "Incoming packet size: " << packets[i] << endl;

        if (tokens >= packets[i]) {
            cout << "Packet SENT ✅\n";
            tokens -= packets[i];
        } else {
            cout << "Packet WAITING ⏳ (Added to queue)\n";
            q.push(packets[i]);
        }

        cout << "Tokens left: " << tokens << endl;
        cout << "Queue size: " << q.size() << endl;
    }

    // Process remaining queued packets after all arrivals
    cout << "\n--- Processing Remaining Queue ---\n";

    int time = packets.size();

    while (!q.empty()) {
        time++;

        tokens = min(bucketSize, tokens + tokenRate);

        cout << "\nTime " << time;
        cout << "\nTokens available: " << tokens << endl;

        if (tokens >= q.front()) {
            cout << "Queued packet of size " << q.front() << " SENT ✅\n";
            tokens -= q.front();
            q.pop();
        } else {
            cout << "Still waiting...\n";
        }
    }

    cout << "\n--- Simulation Complete ---\n";
}

int main() {
    int n, tokenRate, bucketSize;

    cout << "Enter number of packets: ";
    cin >> n;

    vector<int> packets(n);

    cout << "Enter packet sizes:\n";
    for (int i = 0; i < n; i++) {
        cout << "Packet " << i + 1 << ": ";
        cin >> packets[i];
    }

    cout << "Enter token generation rate: ";
    cin >> tokenRate;

    cout << "Enter bucket size: ";
    cin >> bucketSize;

    tokenBucket(packets, tokenRate, bucketSize);

    return 0;
}
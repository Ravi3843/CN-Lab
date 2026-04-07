#include<bits/stdc++.h>
using namespace std;

int main() {
    int d, r = 0;
    cout << "Enter number of data bits: ";
    cin >> d;
    
    vector<int> data(d);
    cout << "Enter data bits: ";
    for(int i=0; i<d; i++) {
        cin >> data[i];
    }

    // Calculate number of parity bits
    while(pow(2, r) < (d + r + 1)) {
        r++;
    }

    int n = d + r;
    vector<int> hamming(n + 1);

    // Place data bits and parity bits
    int j = 0;
    for(int i=1; i<=n; i++) {
        if((i & (i - 1)) == 0) {
            hamming[i] = 0; // parity bit
        }
        else {
            hamming[i] = data[j++]; // shift j
        }
    }

    // Calculate parity bits
    for(int i=0; i<r; i++) {
        int pos = pow(2, i);
        int parity = 0;

        for(int j=1; j<=n; j++) {
            if(j & pos) {
                parity ^= hamming[j];
            }
        }

        hamming[pos] = parity;
    }

    // Display sender data
    cout << "\nSender code: ";
    for(int i=1; i<=n; i++) {
        cout << hamming[i] << " ";
    }

    // Receiver
    cout << "\n\nEnter received code: ";
    for (int i = 1; i <= n; i++) {
        cin >> hamming[i];
    }

    // Check error
    int error = 0;
    for(int i=0; i<r; i++) {
        int pos = pow(2, i);
        int parity = 0;

        for(int j=1; j<=n; j++) {
            if(j & pos) {
                parity ^= hamming[j];
            }
        }

        if(parity != 0) {
            error += pos;
        }
    }

    if(error == 0) {
        cout << "No error detected\n";
    } 
    else {
        cout << "Error at position: " << error << endl;

        // Correct error
        hamming[error] ^= 1;
    }

    // Extract original data
    cout << "Corrected data: ";
    for(int i=1; i<=n; i++) {
        if((i & (i - 1)) != 0) {
            cout << hamming[i] << " ";
        }
    }

    return 0;
}
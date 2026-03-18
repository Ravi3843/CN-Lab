#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;


bool isLost() {
    return rand() % 5 < 1;
}

void stopAndWaitARQ(int frames) {
    cout << "\n--- Stop-and-Wait ARQ ---\n";

    for (int i = 0; i < frames; i++) {
        cout << "Sending frame " << i << "...\n";

        if (isLost()) {
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Frame lost! Retransmitting frame " << i << "\n";
            i--;
        } else {
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "Acknowledgement received for frame " << i << "\n";
        }
    }
}

// Go-Back-N ARQ
void goBackNARQ(int frames, int windowSize) {
    cout << "\n--- Go-Back-N ARQ ---\n";

    int base = 0;

    while (base < frames) {
        cout << "Sending frames: ";

        int i;
        for (i = base; i < min(base + windowSize, frames); i++) {
            cout << i << " ";
        }
        cout << "\n";

        this_thread::sleep_for(chrono::seconds(2));

        if (isLost()) {
            cout << "Frame lost! Go back to frame " << base << "\n";
        } else {
            cout << "All frames acknowledged from " << base << " to " << i - 1 << "\n";
            base = i;
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

// Selective Repeat ARQ
void selectiveRepeatARQ(int frames, int windowSize) {
    cout << "\n--- Selective Repeat ARQ ---\n";

    vector<bool> ack(frames, false);
    int base = 0;

    while (base < frames) {
        for (int i = base; i < min(base + windowSize, frames); i++) {
            if (!ack[i]) {
                cout << "Sending frame " << i << "...\n";

                if (isLost()) {
                    cout << "Frame " << i << " lost!\n";
                } else {
                    cout << "Ack received for frame " << i << "\n";
                    ack[i] = true;
                }
            }
        }

        // Slide window
        while (base < frames && ack[base]) {
            base++;
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}


int main() {
    srand(time(0));

    int totalFrames, windowSize;

    cout << "Enter number of total frames: ";
    cin >> totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    stopAndWaitARQ(totalFrames);
    goBackNARQ(totalFrames, windowSize);
    selectiveRepeatARQ(totalFrames, windowSize);

    return 0;
}

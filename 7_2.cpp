#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

bool sendFrame(int frameNumber, bool &ackReceived) {
    cout << "Sending frame " << frameNumber << "...\n";
    this_thread::sleep_for(chrono::seconds(2));
    ackReceived = (rand() % 2 == 0);
    if (ackReceived) {
        cout << "ACK for frame " << frameNumber << " received.\n";
    } else {
        cout << "No ACK for frame " << frameNumber << " (Packet loss).\n";
    }
    return ackReceived;
}

int main() {
    const int totalFrames = 2;
    int currentFrame = 1;
    bool ackReceived = false;

    while (currentFrame <= totalFrames) {
        cout << "\nAttempting to send frame " << currentFrame << "...\n";
        while (!sendFrame(currentFrame, ackReceived)) {
            cout << "Retrying to send frame " << currentFrame << "...\n";
        }
        currentFrame++;
    }

    cout << "\nAll frames sent successfully!\n";
    return 0;
}

#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

bool isLost()
{
    return ((double)rand()) / RAND_MAX < 0.5;
}

void selectiveRepeatARQ(int frames, int window)
{
    vector<bool> ack(frames, false);
    int base = 0;

    while(base < frames)
    {
        for(int i = base; i < min(base + window, frames); i++)
        {
            if(!ack[i]){
                cout << "Sending frame " << i << "...";
                if (isLost())
                {
                    cout << "Frame lost! Resending later\n";
                    this_thread::sleep_for(chrono::seconds(2));
                }
                else
                {
                    cout << "Ack received\n";
                    ack[i] = true;
                    this_thread::sleep_for(chrono::milliseconds(500));
                }
            }
        }

        while (base < frames && ack[base])
            base += 1;
    }
}

int main()
{
    srand(time(0)); 
    int frames, window;
    cin >> frames >> window;
    selectiveRepeatARQ(frames, window);
}
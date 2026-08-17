#include <iostream>
using namespace std;

void sender(int frame);
void receiver(int frame);

void sender(int frame)
{
    cout << "\nSending Frame " << frame << "..." << endl;

    // Frame 2 is intentionally lost
    if (frame == 2)
    {
        cout << "Frame " << frame << " lost!" << endl;
        cout << "Timeout occurred." << endl;

        cout << "Retransmitting Frame " << frame << "..." << endl;
        receiver(frame);
    }
    else
    {
        receiver(frame);
    }
}

void receiver(int frame)
{
    cout << "Frame " << frame << " received successfully." << endl;
    cout << "ACK " << frame << " received." << endl;
}

int main()
{
    cout << "Stop and Wait ARQ" << endl;

    // Frame 1
    sender(1);

    // Frame 2
    sender(2);

    // Frame 3
    sender(3);

    cout << "\nTransmission completed successfully." << endl;

    return 0;
}
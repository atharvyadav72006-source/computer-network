#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int n, error = 0;

    cout << "Enter received codeword: ";
    cin >> s;

    n = s.length();

    for(int p = 1; p <= n; p = p * 2)
    {
        int parity = 0;

        for(int i = 1; i <= n; i++)
        {
            if(i & p)
            {
                parity = parity ^ (s[n-i] - '0');
            }
        }

        if(parity != 0)
        {
            error = error + p;
        }
    }

    if(error == 0)
    {
        cout << "Received codeword is correct." << endl;
    }
    else
    {
        cout << "Received codeword is wrong." << endl;
        cout << "Error is at position: " << error << endl;
    }

    return 0;
}
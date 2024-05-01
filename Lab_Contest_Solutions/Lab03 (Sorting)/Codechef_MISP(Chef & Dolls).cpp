#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        unordered_map<int, int> dollCounts;

        // Count occurrences of each doll type
        for (int i = 0; i < N; ++i) {
            int type;
            cin >> type;
            dollCounts[type]++;
        }

        // Find the doll type with odd count
        for (auto& pair : dollCounts)
        {
            if (pair.second % 2 != 0)
            {
                cout << pair.first << endl;
                break;
            }
        }
    }

    return 0;
}


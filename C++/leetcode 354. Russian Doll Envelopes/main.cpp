#include <iostream>
#include <vector>

using namespace std;

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    if (envelopes.size() == 1)
    {
        return 1;
    }

    vector<int> lastEnvelope;
    int count = 0;

    sort(envelopes.begin(), envelopes.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
             if (a[0] != b[0])
                 return a[0] < b[0];
             else
                 return a[1] < b[1];
         });

    for (int i = 0; i < envelopes.size(); i++)
    {
        vector<int> current = envelopes[i];

        if (!lastEnvelope.empty())
        {
            if (current[0] < lastEnvelope[0] ||
                current[1] < lastEnvelope[1])
            {
                cout << "不能塞進去！" << "\n";
                return 0;
            }
            else if (current == lastEnvelope)
            {
                return 1;
            }
            else
            {
                count++;
            }
        }

        lastEnvelope = current;
    }

    return count;
}
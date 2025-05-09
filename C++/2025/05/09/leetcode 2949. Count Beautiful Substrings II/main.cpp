#include <iostream>

using namespace std;

long long beautifulSubstrings(string s, int k)
{
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            int vowels = 0;
            int consonants = 0;

            for (int index = i; index <= j; index++)
            {
                if (s[index] == 'a' || s[index] == 'e' || s[index] == 'i' || s[index] == 'o' || s[index] == 'u')
                    vowels++;
                else
                    consonants++;
            }

            if (vowels != consonants)
                continue;

            if ((vowels * consonants) % k == 0)
                count++;
        }
    }
    return count;
}
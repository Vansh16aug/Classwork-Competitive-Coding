#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.size(); i++)
        {
            mpp[s[i]]++;
        }
        vector<pair<int, char>> freqVec;
        for (auto &it : mpp)
        {
            freqVec.push_back({it.second, it.first});
        }
        sort(freqVec.begin(), freqVec.end(), greater<pair<int, char>>()); // sort in descending order
        string result;
        for (auto &it : freqVec)
        {
            result.append(it.first, it.second); // (no of times want to append, char to append)
        }
        return result;
    }
};

int main()
{
    Solution obj;
    string input = "example";
    string sortedString = obj.frequencySort(input);
    cout << "Sorted string: " << sortedString << endl;
    return 0;
}
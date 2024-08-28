#include <bits/stdc++.h>

using namespace std;

bool isAnagram(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    unordered_map<char, int> mpp;
    for (int i = 0; i < str1.length(); i++) {
        mpp[str1[i]]++;
        mpp[str2[i]]--;
    }    
    for (auto &it : mpp) {
        if (it.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string str1="listen";
    string str2="silent";

    if (isAnagram(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
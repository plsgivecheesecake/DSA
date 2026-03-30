class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> oddmap;
        unordered_map<char, int> evenmap;

        for (int i = 0; i < s1.size(); i++) {
            if (i & 1) {
                oddmap[s1[i]]++;
                oddmap[s2[i]]--;
            }
            else {
                evenmap[s1[i]]++;
                evenmap[s2[i]]--;
            }
        }
        for (auto& [key, value] : oddmap) if (value != 0) return false;
        for (auto& [key, value] : evenmap) if (value != 0) return false;
        return true;
    }
};
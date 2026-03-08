class Solution {
public:
    
    void findPermutations(int index, int n, vector<char>& buffer, vector<string>& result) {
        if (index >= n) {
            // build the string, add to result, and return
            string permutation = "";
            for (char c : buffer) permutation += c;
            result.push_back(permutation);
            return;
        }
        buffer.push_back('0');
        findPermutations(index + 1, n, buffer, result);
        buffer.pop_back();
        buffer.push_back('1');
        findPermutations(index + 1, n, buffer, result);
        buffer.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<char> buffer;
        vector<string> result;
        // Find all permutations of length n
        findPermutations(0, n, buffer, result);
        // for (string& permutation : result) cout << permutation << " ";

        // Turn nums into a set and check if anything from result isn't present in nums_set
        unordered_set<string> nums_set(nums.begin(), nums.end());
        for (string& candidate : result) {
            if (!nums_set.count(candidate)) return candidate;
        }
        return "Failsafe";
    }
};
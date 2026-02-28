class Solution {
public:
    int concatenatedBinary(int n) {
        queue<string> q({"1"});
        string result = "";
        while (n--) {
            result += q.front();
            q.push(q.front() + "0");
            q.push(q.front() + "1");
            q.pop();
        }
        int decimal_result = 0;
        for (int i = 0; i <= result.size() - 1; i++) {
            decimal_result = (decimal_result * 2 + (result[i] - '0')) % 1000000007;
        }
        return decimal_result;
    }
};
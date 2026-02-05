class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> index;
        unordered_set<char> order_chars;
        for (int i = 0; i < order.size(); i++) {
            index[order[i]] = i;
            order_chars.insert(order[i]);
        }
        vector<char> in_order;
        vector<char> not_in_order;
        for (int i = 0; i < s.size(); i++) {
            if (order_chars.count(s[i])) in_order.push_back(s[i]);
            else not_in_order.push_back(s[i]);
        }
        std::sort(in_order.begin(), in_order.end(), [&index](char a, char b) {
            return index[a] < index[b];
        });
        in_order.insert(in_order.end(), not_in_order.begin(), not_in_order.end());
        string result(in_order.begin(), in_order.end());
        return result;
    }
};
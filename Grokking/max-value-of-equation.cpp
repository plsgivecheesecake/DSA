#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<vector<int>> deque;
        int maxValue = INT_MIN;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];

            // Remove points that are out of the x range (xi - xj > k)
            while (!deque.empty() && x - deque.front()[0] > k) {
                deque.pop_front();
            }

            // Calculate the equation value with the front of the deque
            if (!deque.empty()) {
                maxValue = max(maxValue, y + x + deque.front()[1] - deque.front()[0]);
            }

            // Remove points from the back of the deque that are less efficient
            while (!deque.empty() && y - x >= deque.back()[1] - deque.back()[0]) {
                deque.pop_back();
            }

            // Add the current point to the deque
            deque.push_back({x, y});
        }

        return maxValue;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> points1 = {{0, 0}, {2, 1}, {3, 3}, {7, 10}};
    int k1 = 4;
    cout << "Example 1: " << solution.findMaxValueOfEquation(points1, k1) << endl; // Expected output: 17

    // Example 2
    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}};
    int k2 = 3;
    cout << "Example 2: " << solution.findMaxValueOfEquation(points2, k2) << endl; // Expected output: 12

    // Example 3
    vector<vector<int>> points3 = {{2, 4}, {5, 1}, {8, 7}, {10, 3}};
    int k3 = 5;
    cout << "Example 3: " << solution.findMaxValueOfEquation(points3, k3) << endl; // Expected output: 12

    return 0;
}

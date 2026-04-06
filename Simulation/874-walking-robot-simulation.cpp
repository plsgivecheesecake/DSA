class Solution {
public:
    int computeSquaredEuclideanDistance(pair<int, int>& currPos) {
        return (currPos.first * currPos.first) + (currPos.second * currPos.second);
    }

    void computeFinalDestination(
        pair<int, int>& currPos, 
        int distance, 
        pair<int, int>& forward_vector,
        set<pair<int, int>>& obstacle_set
    ) {
        for (int i = 1; i <= distance; i++) {
            int expected_x = currPos.first + forward_vector.first;
            int expected_y = currPos.second + forward_vector.second;
            if (obstacle_set.count({expected_x, expected_y})) {
                break;
            }
            currPos.first = expected_x;
            currPos.second = expected_y;
        }

    }

    void rotateLeft(pair<int, int>& forward_vector) {
        std::swap(forward_vector.first, forward_vector.second);
        forward_vector.first = -1 * forward_vector.first;
    }

    void rotateRight(pair<int, int>& forward_vector) {
        std::swap(forward_vector.first, forward_vector.second);
        forward_vector.second = -1 * forward_vector.second;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Initialize current position to (0, 0)
        pair<int, int> currPos = {0, 0};
        // and forward_vector to north (0, 1)
        pair<int, int> forward_vector = {0, 1};

        // Convert the obstacles vector into a set 
        set<pair<int, int>> obstacle_set;
        for (vector<int>& obstacle_index : obstacles) {
            obstacle_set.insert({obstacle_index[0], obstacle_index[1]});
        }

        // Now, iterate over the commands
        int maxEuclideanDistance = 0;
        for (int command : commands) {
            if (command == -1) {
                rotateRight(forward_vector);
            }
            else if (command == -2) {
                rotateLeft(forward_vector);
            }
            else {
                computeFinalDestination(currPos, command, forward_vector, obstacle_set);
                maxEuclideanDistance = std::max(
                    maxEuclideanDistance,
                    computeSquaredEuclideanDistance(currPos)
                );
            }
        }

        return maxEuclideanDistance;
    }


};
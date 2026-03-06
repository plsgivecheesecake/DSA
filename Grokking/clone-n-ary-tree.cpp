#include <iostream>
#include <vector>
using namespace std;

// class NAryNode {
// public:
//     int val; // Value of the current node
//     vector<NAryNode*> children; // List of children for the current node

//     // Constructor to initialize a node with a value
//     NAryNode(int val) {
//         this->val = val;
//     }
// };

class Solution {
public:
    // Method to clone the N-ary tree
    NAryNode* cloneTree(NAryNode* root) {
        // Base case: if the current node is null, return null
        if (root == nullptr) return nullptr;

        // Create a new node with the same value as the root node
        NAryNode* newNode = new NAryNode(root->val);

        // Recursively clone all the children of the current node
        for (NAryNode* child : root->children) {
            newNode->children.push_back(cloneTree(child));
        }

        // Return the new node, which represents the root of the cloned subtree
        return newNode;
    }

    // Helper method to print the N-ary tree in level order
    void printTree(NAryNode* root) {
        // Base case: if the tree is empty, return
        if (root == nullptr) return;

        // Initialize a list to store nodes at the current level
        vector<NAryNode*> currentLevel;
        currentLevel.push_back(root);

        // Process all levels of the tree
        while (!currentLevel.empty()) {
            vector<NAryNode*> nextLevel;

            // Print all nodes at the current level
            for (NAryNode* node : currentLevel) {
                cout << node->val << " "; // Print the value of the current node

                // Add children of the current node to the next level list
                for (NAryNode* child : node->children) {
                    nextLevel.push_back(child);
                }
            }

            cout << endl; // Move to the next line for the next level

            // Move to the next level
            currentLevel = nextLevel;
        }
    }
};

int main() {
    // Create the original N-ary tree for Example 1
    NAryNode* root1 = new NAryNode(1);
    root1->children.push_back(new NAryNode(2));
    root1->children.push_back(new NAryNode(3));
    root1->children.push_back(new NAryNode(4));
    root1->children[1]->children.push_back(new NAryNode(5));
    root1->children[1]->children.push_back(new NAryNode(6));

    Solution solution;

    // Clone the tree using the cloneTree method
    NAryNode* clonedRoot1 = solution.cloneTree(root1);

    // Print the original tree
    cout << "Original Tree:" << endl;
    solution.printTree(root1);

    // Print the cloned tree
    cout << "\nCloned Tree:" << endl;
    solution.printTree(clonedRoot1);

    return 0;
}

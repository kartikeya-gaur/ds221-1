#ifndef USER_CODE_H
#define USER_CODE_H

// Standard library header files
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// --- Question 1 ---
long long question_one(const std::vector<int>& X) {
    if (X.empty()) return 0;
    long long sum = 0;
    long long max_sum = X[0];

    for (int val : X) {
        sum += val;
        if (sum > max_sum) {
            max_sum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return max_sum;
}

// --- Question 2 ---
#ifndef BIN_TREE_NODE_DEF
#define BIN_TREE_NODE_DEF
class BinTreeNode {
public:
    int value;
    BinTreeNode *left;
    BinTreeNode *right;
};
#endif

BinTreeNode* build_tree(const vector<int>& values, const vector<bool>& present) {
    if (values.empty() || !present[0]) return nullptr;

    queue<pair<BinTreeNode*, int>> q;

    BinTreeNode* root = new BinTreeNode;
    root->value = values[0];
    root->left = nullptr;
    root->right = nullptr;

    q.push({root, 0});
    size_t i = 1;

    while (!q.empty() && i < values.size()) {
        auto current = q.front();
        q.pop();
        BinTreeNode* node = current.first;
        int depth = current.second;

        // Left child
        if (i < values.size() && present[i]) {
            BinTreeNode* child = new BinTreeNode;
            child->value = values[i];
            child->left = nullptr;
            child->right = nullptr;
            node->left = child;
            q.push({child, depth + 1});
        }
        i++;

        // Right child
        if (i < values.size() && present[i]) {
            BinTreeNode* child = new BinTreeNode;
            child->value = values[i];
            child->left = nullptr;
            child->right = nullptr;
            node->right = child;
            q.push({child, depth + 1});
        }
        i++;
    }

    return root;
}

void traverse(BinTreeNode* node, 
              vector<int>& path, 
              int depth, 
              map<pair<int, vector<int>>, vector<vector<int>>>& buckets, 
              int& answer) {
    if (!node) return;

    path.push_back(node->value);

    // Leaf node
    if (node->left == nullptr && node->right == nullptr) {
        vector<int> sorted_path = path;
        sort(sorted_path.begin(), sorted_path.end());

        pair<int, vector<int>> keys = {depth, sorted_path};

        for (const vector<int>& previous_path : buckets[keys]) {
            if (previous_path != path) {
                answer = max(answer, depth);
                break;
            }
        }
        buckets[keys].push_back(path);
    }

    if (node->left != nullptr) {
        traverse(node->left, path, depth + 1, buckets, answer);
    }

    if (node->right != nullptr) {
        traverse(node->right, path, depth + 1, buckets, answer);
    }

    path.pop_back();
}

int question_two(const vector<int>& values, const vector<bool>& present) {
    if (values.empty() || !present[0]) return -1;

    BinTreeNode* root = build_tree(values, present);
    vector<int> path;
    map<pair<int, vector<int>>, vector<vector<int>>> buckets;
    int answer = -1;

    traverse(root, path, 0, buckets, answer);
    return answer;
}

// --- Question 3 ---
int question_three(
    int N,
    const vector<vector<int>>& edges,
    int S,
    int K,
    const vector<int>& destinations
) {
    // TODO: Implement function
    return 0;
}

#endif // USER_CODE_H
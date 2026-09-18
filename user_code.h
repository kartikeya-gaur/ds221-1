#ifndef USER_CODE_H
#define USER_CODE_H

// Feel free to include more standard library header files
// based on your requirements
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

// Feel free to introduce more helper functions

long long question1(const std::vector<int>& X) {
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

int question_two(const vector<int>& values, const vector<bool>& present) {
    // TODO: Implement function
    return 0;
}

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

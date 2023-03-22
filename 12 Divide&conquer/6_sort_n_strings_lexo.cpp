#include<bits/stdc++.h>
using namespace std;

// Merge two sorted sublists into one sorted list
vector<string> merge(vector<string>& left, vector<string>& right) {
    vector<string> result;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }
    return result;
}

// Sort a list of strings using divide and conquer
vector<string> merge_sort(vector<string>& strings) {
    if (strings.size() <= 1) {
        return strings;
    }
    int mid = strings.size() / 2;
    vector<string> left(strings.begin(), strings.begin() + mid);
    vector<string> right(strings.begin() + mid, strings.end());
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
}

int main() {
    vector<string> strings = {"banana", "apple", "pear", "orange", "kiwi"};
    vector<string> sorted_strings = merge_sort(strings);
    for (string s : sorted_strings) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}

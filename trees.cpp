#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && q || p && !q)
            return false;
        return (!p && !q || p->val == q->val && isSameTree(p->left, q->left) &&
                                isSameTree(p->right, q->right));
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        if (!(root->left && root->right))
            return root->val == targetSum;
        return (hasPathSum(root->left, targetSum - root->val) ||
                hasPathSum(root->right, targetSum - root->val));
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        TreeNode* t = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = t;
        return root;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root)
            return ans;
        if (root->left)
            for (auto i : binaryTreePaths(root->left))
                ans.push_back(to_string(root->val) + "->" + i);
        if (root->right)
            for (auto i : binaryTreePaths(root->right))
                ans.push_back(to_string(root->val) + "->" + i);
        if (!root->left && !root->right)
            ans.push_back(to_string(root->val));
        return ans;
    }
};

int main() {
    TreeNode tree(1, new TreeNode(2), nullptr);
    Solution s;
    s.invertTree(&tree);
}
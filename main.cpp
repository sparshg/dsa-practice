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

using namespace std;

// leetcode
class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        int ans = 0;
        for (int j = 0; j < strs[0].size(); j++, ans++) {
            char common = strs[0][ans];
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i][ans] != common)
                    return strs[0].substr(0, ans);
            }
        }
        return "";
    }

    // noice
    int removeDuplicates(vector<int> &nums) {
        int at = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[at] != nums[i]) {
                nums[++at] = nums[i];
            }
        }
        return at + 1;
    }

    // wtf I could use the above directly
    int removeElement(vector<int> &nums, int val) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            while (nums[i] != val && i < nums.size() - 1)
                i++;
            while (nums[j] == val && j > 0)
                j--;
            if (i >= j)
                return nums[i] == val ? i : i + 1;

            swap(nums[i], nums[j]);
        }
        return 0;
    }

    // What a terrible solution I just wrote ewwwwww
    int searchInsert(vector<int> &nums, int target) {
        int incr = nums.size() / 2, i = 0;
        while (incr != 0) {
            if (nums[i] == target)
                return i;
            while (incr != 0 &&
                   (i + incr >= nums.size() || nums[i + incr] > target))
                incr /= 2;
            i += incr;
        }
        return target > nums[i] ? i + 1 : i;
    }

    // acceptable
    int lengthOfLastWord(string s) {
        int a = s.size() - 1;
        while (a > 0 && s[a] == ' ')
            a--;
        int b = a;
        while (b >= 0 && s[b] != ' ')
            b--;
        return a - b;
    }

    // me after studying dd
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + carry == 10) {
                carry = 1;
                digits[i] = 0;
            } else {
                digits[i] += carry;
                carry = 0;
            }
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    vector<int> v = {9, 9, 9, 9};
    Solution s;
    auto output = s.plusOne(v);
    for (auto &&i : output) {
        cout << i << "\n";
    }
}
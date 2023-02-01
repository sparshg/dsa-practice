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
    string longestCommonPrefix(vector<string>& strs) {
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
    int removeDuplicates(vector<int>& nums) {
        int at = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[at] != nums[i]) {
                nums[++at] = nums[i];
            }
        }
        return at + 1;
    }

    // wtf I could use the above directly
    int removeElement(vector<int>& nums, int val) {
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
    int searchInsert(vector<int>& nums, int target) {
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
    vector<int> plusOne(vector<int>& digits) {
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

    // noicee
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string ans = "";
        while (carry != 0 || i >= 0 || j >= 0) {
            int first = i < 0 || a[i] == '0' ? 0 : 1;
            int second = j < 0 || b[j] == '0' ? 0 : 1;
            int t = first + second + carry;
            carry = (t > 1) ? 1 : 0;
            ans.insert(ans.begin(), t % 2 + 48);
            i--;
            j--;
        }
        return ans;
    }

    // brrrr usee newton's methood
    int mySqrt(int x) {
        int h = min(x / 2, 46340), l = 1, m = 1;
        while (l <= h) {
            m = (l + h) / 2;
            if (m * m > x)
                h = m - 1;
            else if (m * m < x)
                l = m + 1;
            else
                return m;
        }
        return (m * m > x) ? m - 1 : m;
    }

    // nice
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i]))
                i++;
            while (j > 0 && !isalnum(s[j]))
                j--;
            if (isalnum(s[i]) && isalnum(s[j]) &&
                tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }

    // old...
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
            ans ^= nums[i];
        return ans;
    }

    // should be count += ((n << 1) & 1)..
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            count += n % 2;
            n /= 2;
        }
        return count;
    }

    // pascal's triangle
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        if (numRows > 1)
            res.push_back({1, 1});
        for (int i = 1; i < numRows - 1; i++) {
            vector<int> t = {1};
            for (int j = 0; j < i; j++) {
                t.push_back(res[i][j] + res[i][j + 1]);
            }
            t.push_back(1);
            res.push_back(t);
        }

        return res;
    }

    // pascal's triangle
    vector<int> getRow(int rowIndex) {
        vector<int> t = {1};
        for (int i = 1; i <= rowIndex / 2; i++) {
            long int temp = 1;
            for (int k = rowIndex; k > rowIndex - i; k--)
                temp *= k;
            for (int k = 2; k <= i; k++)
                temp /= k;
            t.push_back(temp);
        }
        for (int i = t.size() - ((rowIndex & 1) ? 1 : 2); i >= 0; i--) {
            t.push_back(t[i]);
        }
        return t;
    }

    // parentheses
    bool isValid(string s) {
        stack<char> mem;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                mem.push(s[i]);
            else {
                if (mem.empty() || s[i] == ')' && mem.top() != '(' ||
                    s[i] == ']' && mem.top() != '[' ||
                    s[i] == '}' && mem.top() != '{')
                    return false;
                mem.pop();
            }
        }
        return mem.empty();
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        int a = m - 1, b = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (b < 0 || a >= 0 && (nums1[a] > nums2[b])) {
                nums1[i] = nums1[a--];
            } else {
                nums1[i] = nums2[b--];
            }
        }
    }

    int findDuplicate(vector<int>& nums) {
        int i = 0, mem = 0;
        while (nums[i] != 0) {
            mem = nums[i];
            nums[i] = 0;
            i = mem;
        }
        return mem;
    }

    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] > 1)
                return true;
            m[nums[i]]++;
        }
        return false;
    }

    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1, m2;
        for (int i = 0; i < s.size(); i++) {
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        for (int i = 0; i < s.size(); i++) {
            if (m1[s[i]] != t[i] || m2[t[i]] != s[i])
                return false;
        }
        return true;
    }

    // can be done just with bit manipulation...
    uint32_t reverseBits(uint32_t n) {
        uint32_t t = 0, c = 0;
        while (n != 0) {
            t = (t * 2) + (n % 2);
            n /= 2;
            c++;
        }
        for (int i = 0; i < 32 - c; i++)
            t <<= 1;
        return t;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int start = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] - i != nums[start] - start) {
                (start == i - 1) ? ans.push_back(to_string(nums[start]))
                                 : ans.push_back(to_string(nums[start]) + "->" +
                                                 to_string(nums[i - 1]));
                start = i;
            }
        }
        return ans;
    }

    // copied...
    bool isPowerOfTwo(int n) { return (n > 0 && !(n & (n - 1))); }

    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int count[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 97]++;
            count[t[i] - 97]--;
        }
        for (int i = 0; i < 26; i++)
            if (count[i])
                return false;
        return true;
    }

    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i <= nums.size(); i++) {
            ans ^= nums[i - 1] ^ i;
        }
        return ans;
    }

    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++)
            swap(s[i], s[s.size() - i - 1]);
    }

    // woow.. n & (n - 1) : first set bit turned off
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++)
            ans[i] = ans[i & (i - 1)] + 1;
        return ans;
    }
};

int main() {
    vector<int> v = {0, 1, 2, 4, 5, 7};
    vector<int> v2 = {1};
    Solution s;
    auto output = s.addDigits(38);
    cout << output << endl;
    // for (auto&& i : output)
    //     cout << i << endl;
    // for (auto&& j : i) {
    //     cout << j << " ";
    // }
    // cout << i << "\n";
    // }
}

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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        while (ptr != nullptr && ptr->next != nullptr) {
            if (ptr->val == ptr->next->val)
                ptr->next = ptr->next->next;
            else
                ptr = ptr->next;
        }
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* p1 = nullptr;
        while (head) {
            ListNode* p3 = head->next;
            head->next = p1;
            p1 = head;
            head = p3;
        }
        return p1;
    }

    // bad O(n^2)
    bool _hasCycle(ListNode* head) {
        unordered_set<ListNode*> addresses;
        ListNode* ptr = head;
        while (ptr) {
            if (addresses.find(ptr) != addresses.end())
                return true;
            addresses.insert(ptr);
            ptr = ptr->next;
        }
        return false;
    }

    // Floyd's cycle algorithm
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val)
            head = head->next;
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        while (ptr) {
            if (prev && ptr->val == val)
                prev->next = ptr->next;
            else
                prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        for (int i = 0; i < 2; i++) {
            while (ptr1 && ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            if (!ptr1)
                ptr1 = headB;
            else
                ptr2 = headA;
        }
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};

int main() {
    Solution s;
    ListNode l(3, new ListNode(2, &l));
    cout << s.hasCycle(&l) << endl;
}
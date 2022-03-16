#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode * n): val(x), next(n) {};
};


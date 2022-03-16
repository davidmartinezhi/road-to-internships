#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode * n): val(x), next(n) {};
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
        1. listen
            input: head of a singly-linked-list
            reverse the list
            output: reversed linked-list
            
            nodes in the list range from 0 to 5000
            nodes val range from -5000 to 5000
            
        2. example
            [1,2,3,4,5] -> [5,4,3,2,1]
            [1,2] -> [2,1]
            
        3. brute force
        4. optimize
            BCR: O(n)
            3 pointers. previous head and next
            head points to previous and next keeps track of the rest of the list
            O(n) runtime
            O(1) memory
            
        5. walkthrough
            3 pointers
            prev is nullptr
            curr points to head
            next points to the second node
            
            while next is diff from nullptr, head points to prev and traverse
        6. implement
        7. test
            empty head
            just one node exists
        */
        
        //check for list with size 0 and 1
        if(head == nullptr || head->next == nullptr) return head;
        
        //Start traversal
        ListNode * prevNode = nullptr;
        ListNode * nextNode;
        
        while(head != nullptr){
            nextNode = head->next;
            head->next = prevNode;
            
            prevNode = head;
            head = nextNode;
        }
        
        return prevNode;  
    }
};
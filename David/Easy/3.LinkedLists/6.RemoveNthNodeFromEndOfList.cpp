#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;

    ListNode(): val(0), next(nullptr){};
    ListNode(int x): val(x), next(nullptr){};
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        1. listen
            input: given the head of the linked list remove the Nth node from end of list
            output: head of the list without that node in the list
            
            
            The number of nodes in the list is sz
            1 <= sz <= 30
            0 <= Node.val <= 100
            1 <= n <= sz
            
        2. example
            head = [1,2,3,4,5], n = 2 -> [1,2,3,5]
            head = [1,2,3,4,5], n = 5 -> [2,3,4,5]
            head = [1,2,3,4,5], n = 1 -> [1,2,3,4]
            
        3. brute force
            traverse the entire list to know the size
            if n is equal to size, remove head
            if n is equal to 1, remove tail
            else traverse until that element and remove it as in the delete node problem
            
        4. optimize
            traverse a pointer, n spaces
            then traverse the entire list
            
            when the fisrt pointer becomes nullptr, remove the last one
            
            BCR: O(n)
            in both approaches we get O(n).
                I'll do the brute force approach first, since it's easiear to understand the code 
                behind it
            
        5. walkthrough
        
            
        6. implement
        
            
        7. test
            remove first element
            remove last element
            remove element in the body
            
            todo:
                check logic sz == n

            
        */
        
        //traverse to get the size
        int sz = 0;
        
        //Runtime: O(n)
        ListNode * aux = head;
        while(aux != nullptr){
            sz++;
            aux = aux->next;
        }
        
        //check if n is the beginning of the list
        if(n == sz){
            aux = head;
            head = head->next;
            delete aux;
            return head;
        }
        
        //Runtime: O(n)
        //check if n is the end of the list
        if(n == 1){
            aux = head;
            int count = 0;
            while(count != sz - 2){
                count++;
                aux = aux->next;
            }
            ListNode * aux2 = aux;
            aux = aux->next;
            aux2->next = nullptr;
            delete aux;
            return head;
        }
        
     //check if it is in the body
        aux = head;
        int count = 0;
        while(count != sz - n){
            count++;
            aux = aux->next; 
        }
        
        ListNode * aux2 = aux->next;
        aux->val = aux->next->val;
        aux->next = aux->next->next;
        delete aux2;
        
        return head;
    }
};

/*
Nota: 
    20-25 minutos
    Runtime: O(2n) = O(n)
    memory: O(1)
*/
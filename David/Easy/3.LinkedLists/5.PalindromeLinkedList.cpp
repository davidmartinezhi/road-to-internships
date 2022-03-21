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
    bool isPalindrome(ListNode* head) {
        /*
        1. listen
            input: head of a singly linked list
            output: true if it's a palindrome, else false
            
            the number of nodes in the list is in the range 1 and 10000
            nodes val ranges from 0 to 9
            
            Can it be done in O(n) time and O(1) memory
            
            palindrome means it is read the same way fowards and backwards
            
        2. example
            cuaderno
        
        3. brute force
            Use an auxiliary vector to save all values
            create a pointer at start and another at end
            while(start < end) if they are different, return false, else true
            
            runtime: O(n)
            memory: O(n)
        
        4. optimize
            BCR: O(n)
            reverse half the list
            

        
        5. walkthrough
            Traverse the list to get the size
 
            Move an auxiliary pointer to size/2, that's the prev
        
                
            if size is non, move the aux + 1 after reversing
                
            reverse the half of the list

            traverse them both until size/2 
            if they are of diff value, return false
            
            else return true
            
        6. implement
        
        7. test
            palindrome list
                pair and non
            non-palindrome list
                pair and non
            
            special case: 
                List with one node
        
        */
        

        //Create auxiliary pointer and traverse the linked list to find the size
        ListNode * aux = head; 
        int n = 0;
        
        while(aux){
            aux = aux->next;
            n++;
        }
        
        //Check if there is one or two elements
        if(n == 1) return true;
        
        if(n == 2){
            if(head->val == head->next->val) return true;
            else return false;
        }
        
        // If there are more than two elements, move to the middle of the list
        aux = head;
        
        int count = 0;  
        while(count < n / 2-1){
            //Move aux to the middle of the list
            aux = aux->next;
            count++;
        }
        
        //Reverse the second half of the list
        ListNode * prevNode = nullptr;
        aux = aux->next;
        ListNode * nextNode = aux->next;
            
        while(aux != nullptr && nextNode != nullptr){
            nextNode = aux->next;
            aux->next = prevNode;
            
            prevNode = aux;
            aux = nextNode;
        }


        //Check if they are palindromes
        while(prevNode && head){
            if(prevNode->val != head->val) return false;
            prevNode = prevNode->next;
            head = head->next;
        }
        
        return true;
    }
};
/*
Nota: 
time: 40-45 minutes
runtime: O(n)
memory: O(1)

*/
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
    void deleteNode(ListNode* node) {
        /*
        1. listen
            input: node to be deleted directly
            I won't hace access to the head
            Node to be deleted is not a tail node
            
            The number of the nodes in the given list is in the range [2, 1000].
            -1000 <= Node.val <= 1000
            The value of each node in the list is unique.
            The node to be deleted is in the list and is not a tail node
            
        2. example
            [4,5,1,9], node = 1 -> [4,1,9]
            head = [4,5,1,9], node = 5 -> [4,1,9]
            
        3. brute force
        4. optimize
            copy the info of the next node
            delete the next node
            
            runtime: O(1)
            memory: O(1)
            
        5. walkthrough
            copy the info of the next node and delete the next node
        
        6.implement
        
        7. test
            head to be removed

        */
        
        ListNode * aux = node->next;    //Creo apuntador al siguiente nodo
        node->val = aux->val;   //Nodo por eliminar clona los valores
        node->next = aux->next; 
        delete aux; //Elimino el nodo siguiente
    }
};
/*
Notas:
    runtime: O(1)
    memory: O(1)
*/

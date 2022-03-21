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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
        1. listen
        
            input: head of two sorted linked lists
                merge both linked lists in one single linked list
                list should be made by joining the nodes of both linked lists
            output: head of resulting linked list
            
            number of nodes in each list in between 0 and 50
            
            node val is between -100 and 100
            both lists are sorted in non decreasing order
            
        2. example
        
            list1: [1, 5, 6, 8], list2: [2,3,7,9]
            -> [1,2,3,4,5,7,9]
            
        3. brute force
            functioning like a zipper
            pointer to new head
            pointer to new connection
            previous heads serve to compare next values and connect
        
            O(n) runtime
            memory: O(1)
        4. optimize
            BCR O(n)
            Brute force is an optimal solution
        
        5. walkthrough
            create pointer to new head and point it to smallest value head
            create aux pointer that joins the new head to the rest of the body
            each connection, the previous head moves to the next node
        
        6. implement
        
        7. test
            
            -one kist is larger than the other
            -both lists are of the same size
            
            special case:
                -both heads are nullptr
                -one head is nullptr
            
        */
        
    //Check if both heads are nullptr
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        
    //Check if one head is nullptr
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
   
        
    //If both lists have nodes      
        //Initialize new head pointer to the smallest head value
        ListNode * newHead;  
        
        if(list1->val < list2->val){
            newHead = list1;
            list1 = list1->next;
        } 
        else{
           newHead = list2; 
            list2 = list2->next;
        } 
        
        //Create node that connects both lists according to the node's value
        ListNode * aux = newHead;
        
        while(list1 && list2){  //While both nodes aren't nullptr
            
            //If list1 node is smaller than list2 node
            if(list1->val < list2->val){
                aux->next = list1;  //We point to that node
                list1 = list1->next;    //We move the node to it's next value
            }
            else{   //Else we do the same with the other list
                aux->next = list2;
                list2 = list2->next;
            }
            
            //We move aux to his next node
            aux = aux->next;
        }
        
        //If any list rans out of nodes, we check to add the nodes from the other list
        while(list1){
            aux->next = list1;
            list1 = list1->next;
            aux = aux->next;
        }

        while(list2){
            aux->next = list2;
            list2 = list2->next;
            aux = aux->next;
        }
        
        return newHead;
    }
};
/*
    Nota: 
        time: 22 minutes
        runtime: O( n )
        memory: O(1)
*/
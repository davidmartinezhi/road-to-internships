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
        
       //runtime: O(2n) -> O(n)

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
            head = head->next;  //Head is the second element now
            delete aux; //Delete previous head
            return head;
        }
        
        //Runtime: O(n)

        //check if n is the end of the list
        if(n == 1){
            aux = head;
            int count = 0;
            while(count != sz - 2){ //Get to the previous to last element
                count++;
                aux = aux->next;
            }
            ListNode * aux2 = aux;  //Auxiliary pointer to the prev pointer where we are going to delete
            aux = aux->next;    //Aux moves to the node we'll remove
            aux2->next = nullptr;   //Prev now points to nullptr
            delete aux; //We delete aux
            return head;
        }
        
     //check if it is in the body
        aux = head;
        int count = 0;
        while(count != sz - n){ //We move to the element we are going to remove
            count++;
            aux = aux->next; 
        }
        
        ListNode * aux2 = aux->next;    //Aux node to the next node, from the one we are going to delete
        aux->val = aux->next->val;  //We copy all data
        aux->next = aux->next->next;
        delete aux2;    //We delete the next node
        
        return head;
    }
};

/*
Nota:
    Terminado en 20-25 minutos
    Para los 17 minutos que tenía para terminarlo,lo hice bastante bien
    Comence a programarlo cuando quedaban 7 minutos, entonces no estuvo mal
        En lo que más tiempo tarde fue en el testing de logica, para saber que nodo iba a eliminar

*/
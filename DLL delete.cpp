/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

void deleteNode(Node** head_ref,Node* del){
    
    if(*head_ref == NULL || del == NULL){
        return;
    }
    
    //if node to be deleted is head node
    if(*head_ref==del){
        *head_ref=del->next;
    }
    
    //change next only if node to be deleted is not last node
    if(del->next != NULL){
        del->next->prev=del->prev;
    }
    
    //change prev only if node to be deleted is NOT the first node
    if(del->prev != NULL){
        del->prev->next=del->next;
    }
        
    free(del);
    return;
    
}

void push(Node** head_ref,int new_data){
    
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->prev=NULL;
    new_node->next=(*head_ref);
    
    if((*head_ref)!=NULL)
        (*head_ref)->prev=new_node;
    
    (*head_ref)=new_node;
}

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
}

int main()
{
    Node* head=NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head,8);
    push(&head,10);
    
    cout<<"Original Linked List: ";
    printList(head);
    deleteNode(&head, head);
    deleteNode(&head, head->next);
    deleteNode(&head, head->next);
    
    cout<<"\nModified Linked List:";
    printList(head);

    return 0;
}
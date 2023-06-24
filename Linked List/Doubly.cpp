#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    // Destructor
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void InsertAtHead(Node* &head,Node* &tail,int d){
    // empty list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void InsertAtTail(Node* &head,Node* &tail,int d){
    // empty list
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void InsertAtPosition(Node* &head,Node* &tail,int position,int d){
    // insert at start
    if(position == 1){
        InsertAtHead(head,tail,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    // insertion at last position
    if(temp->next == NULL){
        InsertAtTail(head,tail,d);
        return ;
    }
    // creating a node for d;
    Node* newone = new Node(d);
    newone->next = temp->next;
    temp->next->prev = newone;
    temp->next = newone;
    newone->prev = temp;
}
int getlength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void deleteNode(int position, Node* &head,Node* &tail){
    // deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        // memory free start node
        delete temp;
    }
    else{
        // deleting any middle or last node
        Node* curr = head;
        Node* previous = NULL;
        int cnt = 1;
        while(cnt < position){
            previous = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        previous->next = curr->next;
        if(curr->next == NULL){
            tail = previous;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    cout<<getlength(head)<<endl;
    // Insertion from head
    InsertAtHead(head,tail,11);
    print(head);
    InsertAtHead(head,tail,12);
    print(head);
    InsertAtHead(head,tail,13);
    print(head);
    // Insertion from tail
    InsertAtTail(head,tail,9);
    print(head);
    InsertAtTail(head,tail,8);
    print(head);
    // Insertion at position
    InsertAtPosition(head,tail,1,100);
    print(head);
    InsertAtPosition(head,tail,2,95);
    print(head);
    InsertAtPosition(head,tail,8,7);
    print(head);
    // deleting Node
    deleteNode(1,head,tail);
    print(head);
    deleteNode(2,head,tail);
    print(head);
    deleteNode(6,head,tail);
    print(head);
    return 0;
}
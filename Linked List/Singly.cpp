#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node(){
        int value = this->data;
        // memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};
void InsertionAtHead(Node* &head,Node* &tail,int d){
    // new node create
    Node* temp = new Node(d);
    // empty list
    if(head == NULL){
        head = temp;
        tail = temp;
    }else{
        temp->next = head;
        head = temp;
    }
}
void InsertAtTail(Node* &head,Node* &tail,int d){
    Node* temp = new Node(d);
    if(tail == NULL){
        tail = temp;
        head = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}
void InsertAtPosition(Node* &tail,Node* &head, int position, int d){
    if(position == 1){
        InsertionAtHead(head,tail,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    // Inserting at last position
    if(temp->next == NULL){
        InsertAtTail(head,tail,d);
        return;
    }
    // creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void deleteNode(int position, Node* &head,Node* &tail){
    // deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        // memory free start node
        delete temp;
    }
    else{
        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        if(curr->next == NULL){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
void print(Node* &tail){
    Node* temp = tail;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    // created a new node
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    
    // head pointed to node1


    // tail pointed to node1
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    InsertionAtHead(head,tail,9);
    print(head);
    InsertAtTail(head,tail,12);
    print(head);
    InsertAtTail(head,tail,15);
    print(head);
    InsertAtPosition(tail,head,1,22);
    print(head);
    // To check position of head and tail
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

    deleteNode(4,head,tail);
    print(head);
    // To check position of head and tail
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    return 0;
}
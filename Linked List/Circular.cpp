#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    // constrtuctor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    // destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
void insertNode(Node* &tail,int element,int d){
    // assuming that the element is present in the list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }else{
        // non-empty list
        // assuming that the element is present in the list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        // element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node* tail){
    Node* temp = tail;
    // empty list
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return ;
    }
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}
// to check it is circular or not
bool isCircular(Node* head){
    // empty list
    if(head == NULL){
        return true;
    }
    Node* temp = head->next;
    while(1){
        if(temp == head){
            return true;
        }
        else if(temp == NULL){
            return false;
        }
        temp = temp->next;
    }
}
void deleteNode(Node* &tail,int value){
    // empty list
    if(tail == NULL){
        cout<<"List is empty, please check again"<<endl;
        return ;
    }else{
        // non-empty
        // assuming that value is present in the Linked List
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // 1 Node Linked list
        if(curr == prev){
            tail = NULL;
        }
        // >=2 Node Linked List
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node* tail = NULL;
    // empty list me insert krte hai
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,7);
    print(tail);
    insertNode(tail,7,9);
    print(tail);
    insertNode(tail,5,6);
    print(tail);
    // to check it is circular or not
    cout<<"iscircular = "<<isCircular(tail)<<endl;;
    // deleting element
    deleteNode(tail,3);
    print(tail);
    deleteNode(tail,9);
    print(tail);
    return 0;
}
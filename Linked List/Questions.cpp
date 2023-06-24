#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    // constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};
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
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}
// find the reverse of linked list
Node* reverse(Node* head,Node* &tail){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    tail = head;
    return prev;
}
// using recursion
void solve(Node* &head,Node* curr,Node* prev){
    // base case
    if(curr == NULL){
        head = prev;
        return ;
    }
    Node* forward = curr->next;
    solve(head,forward,curr);
    curr->next = prev;
}

// another solution using recursion
Node* reverse1(Node* head ){
    // base case
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* chotaHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}
Node* reverseLL(Node* head,Node* &tail){
    // Node* curr = head;
    // Node* prev = NULL;
    tail = head;
    // solve(head,curr,prev);
    // return head;

    return reverse1(head);
}

// find the middle of LInked List
Node* findMiddle(Node* head){
    int len = getLength(head);
    int ans = (len/2) + 1;
    Node* temp = head;
    int cnt = 1;
    while(cnt < ans){
        temp = temp->next;
        cnt++;
    }
    return temp;
}
// another method
Node* Getmiddle(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    // 2 nodes - not needed
    // if(head->next->next == NULL){
    //     return head->next;
    // }
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(head,tail,11);
    print(head);
    InsertAtTail(head,tail,12);
    print(head);
    InsertAtTail(head,tail,13);
    print(head);
    InsertAtTail(head,tail,14);
    print(head);
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data<<endl;
    head = reverse(head,tail);
    print(head);
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data<<endl;
    head = reverseLL(head,tail);
    print(head);
    cout<<"head = "<<head->data<<endl;
    cout<<"tail = "<<tail->data<<endl;

    Node* middle = findMiddle(head);
    cout<<"Middle = "<<middle->data<<endl;

    Node* middle1 = Getmiddle(head);
    cout<<"Middle = "<<middle1->data<<endl;
}
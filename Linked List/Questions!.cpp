#include<iostream>
#include<map>
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
void print(Node* &tail){
    Node* temp = tail;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// reverse LL in K groups 
Node* kreverse(Node* head,int k){
    // base case
    if(head == NULL){
        return NULL;
    }
    // step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // step2 : recursion
    if(next != NULL){
        head->next = kreverse(next,k);
    }
    // step3: return head of reversed list
    return prev;
}
// to check that LL is circular or not
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
// to detect the loop in LL
bool detectCycle(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*,bool> visited;
    Node* temp = head;
    while(temp != NULL){
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
// using floyd's cycle detection method
Node* floydDetect(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}
// to get starting node of loop
Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydDetect(head);
    Node* slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
// to remove loop
void removeLoop(Node* head){
    if(head == NULL){
        return;
    }
    Node* startofLoop = getStartingNode(head);
    Node* temp = startofLoop;
    while(temp->next != startofLoop){
        temp = temp->next;
    }
    temp->next = NULL;
}
// to remove duplicates from a sorted LL.
Node* removeDuplicate(Node* head){
    // empty list
    if(head == NULL){
        return NULL;
    }
    // for non-empty list
    Node* curr = head;
    while(curr != NULL){
        if(curr->next != NULL && curr->data == curr->next->data){
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = next_next;
        }else{
            curr = curr->next;
        }
    }
    return head;
}
// remove duplicates from unsorted LL.

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    InsertAtTail(head,tail,12);
    print(head);
    InsertAtTail(head,tail,15);
    print(head);
    InsertAtTail(head,tail,17);
    print(head);
    InsertAtTail(head,tail,19);
    print(head);
    // head = kreverse(head,2);
    // print(head);
    // cout<<"Head = "<<head->data<<endl;
    // cout<<"Tail = "<<tail->data<<endl;
    cout<<"is circular = "<<isCircular(head)<<endl;
    cout<<"detection of cycle = "<<detectCycle(head)<<endl;
    cout<<tail->data<<endl;
    tail->next = head->next;
    cout<<tail->next->data<<endl;
    cout<<"detection of cycle = "<<detectCycle(head)<<endl;   
}
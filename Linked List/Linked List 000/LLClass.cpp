#include <iostream>
using namespace std;
class Node{ // user defined datatype
public:
    int val;
    Node* next;
    Node(int val){
        this -> val = val;
        this -> next = NULL;
    }
};

class LinkedList{// user defined datastructure
public:
    Node* head; 
    Node* tail;
    int size;
    LinkedList(){
        head = tail = NULL; //No val or next of NULL
        size = 0;
    }
    void insertAtEnd(int val){
        Node* temp = new Node(val);
        if(size == 0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void inserAtHead(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            temp -> next = head;
            head = temp;
        }
        size++;
    }

    void insertAtIndex(int idx, int val){
        if(idx == 0){
            inserAtHead(val);
            return;
        } 
        else if(idx == size){
            insertAtEnd(val);
            return;
        }
        else{
            Node* t = new Node(val);
            Node* temp = head;
            for(int i=1; i<idx-1; i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
        
    }

    void display(){
        Node* temp = head;
        while(temp!= NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteAtHead(){
        if(size == 0){
            cout << "List is Empty!" << endl;
            return;
        } 
        else if (size == 1) {
            head = tail = NULL;
            return;
        }
        else{
            head = head->next;
            size--;
        }
    }

    void deleteAtTail(){
        if(size == 0){
            cout << "List is Empty!" << endl;
            return;
        } 
        Node* temp = head;
        while(temp->next != tail){
            temp->next = temp;
        }
        temp->next = NULL;
        tail = temp;
        size--;
        
       
    }

    void deleteAtIndex(int idx){
        if(idx<0 || idx>=size) cout <<"Invalid Index";
        else if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtTail();
        else{
            Node* temp = head;
            for(int i=1; i<idx-1; i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }

};


int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.display();
    ll.insertAtIndex(1,69);
    ll.display();
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtIndex(0);
    ll.display();

}
#include <iostream>

using namespace std;

//Making class to create nodes
class Node {
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value){
            //Creating a new node
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList(){
            Node* temp = head;
            while(head != nullptr){
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList(){
            Node* temp = head;
            if(temp == nullptr){
                cout << "Empty Linked List" << endl;
            }
            while (temp != nullptr){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead(){
            cout << "Head:" << head->value << endl;
        }

        void getTail(){
            cout << "Tail:" << tail->value << endl;
        }

        void append(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void deleteLast(){
            Node* temp = head;
            Node* pre = head;
            if(length == 0){
                cout << "The Linked List is empty" << endl;
            }else if(length == 1){
                head = nullptr;
                tail = nullptr;
                delete temp;
                length--;
            }else{
                while(temp->next != nullptr){
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
                delete temp;
                length--;
            }
        }
};

int main(){

    LinkedList* firstLinkedList = new LinkedList(4);
    cout << firstLinkedList << endl;
    firstLinkedList->append(5);
    firstLinkedList->printList();
    firstLinkedList->deleteLast();
    firstLinkedList->printList();
    firstLinkedList->deleteLast();
    firstLinkedList->printList();
    firstLinkedList->deleteLast();
    delete firstLinkedList;
}
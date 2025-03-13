#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* head;     // Points to top element of stack.
    int num;        // Number of elements (index-style tracking).
    int capacity;   // Fixed size limit (resized when full).

public:
    Stack(int initialCapacity) {  // You can set any initial size.
        head = nullptr;
        num = -1;
        capacity = initialCapacity;
    }
    void push(int x) {
        if (num == capacity - 1) increaseCapacity();
        if (num == -1) {
            head = new Node();
            head->next = nullptr;
            head->data = x;
            num++;
            return;
        }
        Node* tmp = new Node();
        tmp->data = x;
        tmp->next = head;
        head = tmp;
        num++;

    }

    int pop() {
        if (num == -1) {
            cout << "your stack is already empty" << endl;
            return 0;
        }
        if (num == 0) {
            int val = head->data;
            Node* tmps = head;
            head = nullptr;
            delete tmps;
            num--;
            return val;
        }
        Node* tmp = head;
        int tmpVal = tmp->data;
        head = head->next;
        delete tmp;
        num--;
        return tmpVal;
    }
    int peek() {
        if (num == -1) {
            cout << "Your stack is empty" << endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty() {
        return num < 0;
    }

    void increaseCapacity() {
        capacity *= 2;
    }

    bool deleteElement(int val) {
        if (head == nullptr) {
            cout << "your stack is already empty" << endl;
            return false;
        }
        Node* tmp = new Node();
        tmp = head;
        if (head->data == val) {
            pop();
            return true;
        }

        while (tmp->next != nullptr) {
            if (tmp->next->data == val) {
                Node* tmpNext = tmp->next;
                tmp->next = tmpNext->next;
                delete tmpNext;
                num--;
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }
};

int main() {
    Stack* s = new Stack(10);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    s->push(6);
    s->push(7);
    s->push(8);


    s->pop();
    s->deleteElement(3);
    s->deleteElement(1);
    

    cout << "Traverse: " << endl;
    while (int x = s->pop()) {
        cout << x << endl;
    }
    

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyCircularList {
private:
    Node* head;

public:
    SinglyCircularList() : head(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr};

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        head = newNode;
        temp->next = head;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfterValue(int existingValue, int newValue) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert after value " << existingValue << ".\n";
            return;
        }

        Node* temp = head;
        do {
            if (temp->data == existingValue) {
                Node* newNode = new Node{newValue, temp->next};
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Value " << existingValue << " not found. Insertion cancelled.\n";
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "Circle is empty. Cannot remove a student.\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        Node* removeNode = head;
        head = head->next;
        last->next = head;
        delete removeNode;
    }

    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "Circle is empty.\n";
            return;
        }

        if (head->data == value && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* prev = nullptr;
        Node* current = head;

        do {
            if (current->data == value) {
                if (current == head) {
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                    delete current;
                    return;
                }

                prev->next = current->next;
                delete current;
                return;
            }

            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Value " << value << " not found.\n";
    }

    void display() const {
        if (head == nullptr) {
            cout << "[empty circle]";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data;
            if (temp->next != head) {
                cout << " -> ";
            }
            temp = temp->next;
        } while (temp != head);
    }
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyCircularList {
private:
    DNode* head;

public:
    DoublyCircularList() : head(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    void insertAtBeginning(int value) {
        DNode* newNode = new DNode{value, nullptr, nullptr};

        if (head == nullptr) {
            head = newNode;
            newNode->prev = newNode;
            newNode->next = newNode;
            return;
        }

        DNode* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int value) {
        DNode* newNode = new DNode{value, nullptr, nullptr};

        if (head == nullptr) {
            head = newNode;
            newNode->prev = newNode;
            newNode->next = newNode;
            return;
        }

        DNode* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }

    void insertAfterValue(int existingValue, int newValue) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert after value " << existingValue << ".\n";
            return;
        }

        DNode* temp = head;
        do {
            if (temp->data == existingValue) {
                DNode* newNode = new DNode{newValue, temp, temp->next};
                temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Value " << existingValue << " not found. Insertion cancelled.\n";
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "Circle is empty. Cannot remove a student.\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        DNode* last = head->prev;
        DNode* removeNode = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        delete removeNode;
    }

    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "Circle is empty.\n";
            return;
        }

        DNode* temp = head;
        do {
            if (temp->data == value) {
                if (temp == head && head->next == head) {
                    delete head;
                    head = nullptr;
                    return;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head) {
                    head = temp->next;
                }

                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Value " << value << " not found.\n";
    }

    void display() const {
        if (head == nullptr) {
            cout << "[empty circle]";
            return;
        }

        DNode* temp = head;
        do {
            cout << temp->data;
            if (temp->next != head) {
                cout << " <-> ";
            }
            temp = temp->next;
        } while (temp != head);
    }
};

void printSinglyOperation(const string& label, SinglyCircularList& list) {
    cout << "\n" << label << " => ";
    list.display();
    cout << endl;
}

void printDoublyOperation(const string& label, DoublyCircularList& list) {
    cout << "\n" << label << " => ";
    list.display();
    cout << endl;
}

int main() {
    SinglyCircularList singly;
    DoublyCircularList doubly;

    cout << "--- Singly Circular Linked List ---";
    singly.insertAtEnd(10);
    printSinglyOperation("After join 10 at end", singly);

    singly.insertAtEnd(20);
    printSinglyOperation("After join 20 at end", singly);

    singly.insertAtBeginning(5);
    printSinglyOperation("After join 5 at beginning", singly);

    singly.insertAfterValue(10, 15);
    printSinglyOperation("After join 15 after 10", singly);

    singly.deleteFirst();
    printSinglyOperation("After leave first student", singly);

    singly.deleteByValue(15);
    printSinglyOperation("After leave student 15", singly);

    cout << "\n--- Doubly Circular Linked List ---";
    doubly.insertAtEnd(30);
    printDoublyOperation("After join 30 at end", doubly);

    doubly.insertAtEnd(40);
    printDoublyOperation("After join 40 at end", doubly);

    doubly.insertAtBeginning(25);
    printDoublyOperation("After join 25 at beginning", doubly);

    doubly.insertAfterValue(30, 35);
    printDoublyOperation("After join 35 after 30", doubly);

    doubly.deleteFirst();
    printDoublyOperation("After leave first student", doubly);

    doubly.deleteByValue(35);
    printDoublyOperation("After leave student 35", doubly);

    return 0;
}

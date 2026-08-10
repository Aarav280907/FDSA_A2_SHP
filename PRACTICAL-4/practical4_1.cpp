/*A hospital manages a queue of patient tokens. New critical patients must be added to the front, routine patients are added to the end, 
and occasionally a patient with a priority number must be inserted at a specific position in the queue. Given a sequence of such operations,
 implement all three insertion types and print the final queue after each operation.*/

 #include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

void printQueue(Node* head) {
    cout << "Queue: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;
}

void addCritical(Node*& head, const string& patient) {
    Node* newNode = new Node{patient, head};
    head = newNode;
    printQueue(head);
}

void addRoutine(Node*& head, const string& patient) {
    Node* newNode = new Node{patient, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printQueue(head);
}

void addPriority(Node*& head, const string& patient, int position) {
    Node* newNode = new Node{patient, nullptr};
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        printQueue(head);
        return;
    }
    Node* temp = head;
    int index = 0;
    while (temp != nullptr && index < position - 1) {
        temp = temp->next;
        index++;
    }
    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printQueue(head);
}

int main() {
    Node* head = nullptr;
    int choice, pos;
    string name;
    do {
        cout << "\n--- Hospital Queue Menu ---\n";
        cout << "1. Add Critical Patient (front)\n";
        cout << "2. Add Routine Patient (end)\n";
        cout << "3. Add Priority Patient (specific position)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
            cin.ignore();
                cout << "Enter patient name: ";
                getline(cin,name);
                addCritical(head, name);
                break;
            case 2:
            cin.ignore();
                cout << "Enter patient name: ";
                getline(cin,name);
                addRoutine(head, name);
                
                break;
            case 3:
            cin.ignore();
                cout << "Enter patient name: ";
                getline(cin,name);
                cout << "Enter position (0 = front): ";
                cin >> pos;
                addPriority(head, name, pos);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);
    return 0;
}


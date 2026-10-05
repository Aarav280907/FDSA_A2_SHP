/*A hospital emergency ward receives patients continuously and attends to them strictly in the order they arrived, 
with no upper limit on how many can be waiting at once. New patients are added at the back and the doctor always 
attends to the patient at the front. Given a sequence of arrive and attend operations, implement this unlimited 
patient queue and print the current front patient after each operation.*/

#include <iostream>
using namespace std;

class PatientQueue {
private:
    struct Node {
        int patientID;
        Node* next;
        Node(int id) : patientID(id), next(nullptr) {}
    };
    Node* front; // Pointer to the front patient
    Node* rear; // Pointer to the rear patient
public:
    PatientQueue() : front(nullptr), rear(nullptr) {}
    PatientQueue(const PatientQueue&) = delete; // Disable copy constructor
    PatientQueue& operator=(const PatientQueue&) = delete; // Disable copy assignment   
    
    
    void arrive(int patientID) {
        Node* newNode = new Node(patientID);
        if (!rear) { // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        printFront();
    }
    
    void attend() {
        if (!front) { // If the queue is empty
            cout << "Error: No patients to attend." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) { // If the queue becomes empty
            rear = nullptr;
        }
        delete temp;
        printFront();
    }

    void printFront() {
        if (!front) {
            cout << "No patients in the queue." << endl;
        } else {
            cout << "Current front patient ID: " << front->patientID << endl;
        }
    }

    void display() {
        if (!front) {
            cout << "No patients in the queue." << endl;
            return;
        }
        cout << "Patients in queue: ";
        Node* current = front;
        while (current) {
            cout << current->patientID << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    PatientQueue pq;
    int choice, patientID;

    while (true) {
        cout << "\n1. Arrive\n2. Attend\n3. Display Queue\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient ID to arrive: ";
                cin >> patientID;
                pq.arrive(patientID);
                break;
            case 2:
                pq.attend();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node* next;
};

void printQueue(Node* head)
{
    cout << "Queue (Front to Back): ";

    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->name << " ";
        temp = temp->next;
    }

    cout << endl;
}

void addCritical(Node*& head, const string& patient)
{
    Node* newNode = new Node{patient, head};

    head = newNode;

    printQueue(head);
}

void addRoutine(Node*& head, const string& patient)
{
    Node* newNode = new Node{patient, nullptr};

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printQueue(head);
}

void addPriority(Node*& head, const string& patient, int position)
{
    Node* newNode = new Node{patient, nullptr};

    if (position == 0)
    {
        newNode->next = head;
        head = newNode;

        printQueue(head);
        return;
    }

    Node* temp = head;
    int index = 0;

    while (temp != nullptr && index < position - 1)
    {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr)
    {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printQueue(head);
}

void deleteByValue(Node*& head, const string& patient)
{
    if (head == nullptr)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    if (head->name == patient)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        cout << patient << " deleted." << endl;
        printQueue(head);

        return;
    }

    Node* temp = head;

    while (temp->next != nullptr &&
           temp->next->name != patient)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        cout << "Patient not found!" << endl;
        return;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;

    cout << patient << " deleted." << endl;

    printQueue(head);
}

void reversePrint(Node* head)
{
    if (head == nullptr)
    {
        return;
    }

    reversePrint(head->next);

    cout << head->name << " ";
}

void printReverse(Node* head)
{
    cout << "Queue (Back to Front): ";

    reversePrint(head);

    cout << endl;
}


int main()
{
    Node* head = nullptr;

    int choice, pos;
    string name;

    do
    {
        cout << "\n--- Hospital Queue Menu ---\n";

        cout << "1. Add Critical Patient (Front)\n";
        cout << "2. Add Routine Patient (End)\n";
        cout << "3. Add Priority Patient (Specific Position)\n";
        cout << "4. Delete Patient by Name\n";
        cout << "5. Display Queue (Front to Back)\n";
        cout << "6. Display Queue (Back to Front)\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:

                cin.ignore();

                cout << "Enter patient name: ";
                getline(cin, name);

                addCritical(head, name);

                break;


            case 2:

                cin.ignore();

                cout << "Enter patient name: ";
                getline(cin, name);

                addRoutine(head, name);

                break;


            case 3:

                cin.ignore();

                cout << "Enter patient name: ";
                getline(cin, name);

                cout << "Enter position (0 = front): ";
                cin >> pos;

                addPriority(head, name, pos);

                break;


            case 4:

                cin.ignore();

                cout << "Enter patient name to delete: ";
                getline(cin, name);

                deleteByValue(head, name);

                break;


            case 5:

                printQueue(head);

                break;


            case 6:

                printReverse(head);

                break;


            case 7:

                cout << "Exiting program..." << endl;

                break;


            default:

                cout << "Invalid choice!" << endl;
        }

    }
    while (choice != 7);

    return 0;
}

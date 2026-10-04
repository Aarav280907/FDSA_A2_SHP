/*A cafeteria stacks clean trays on a fixed-size counter. New trays are always placed on top, and customers always take from the top. 
The counter can hold at most n trays at a time — if it is full, no more trays can be added, and if it is empty, no tray can be taken. 
Given a sequence of place and take operations, implement this fixed-capacity tray stack and print the current top tray after each operation.
 Report an error if a place or take operation cannot be performed.*/

 #include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrayStack {
private:
    int capacity;
    vector<string> stack;

public:
    TrayStack(int n) : capacity(n) {}

    void place(const string& tray) {
        if ((int)stack.size() >= capacity) {
            cout << "Error: Cannot place tray, stack is full" << endl;
        } else {
            stack.push_back(tray);
            cout << "Top tray: " << stack.back() << endl;
        }
    }

    void take() {
        if (stack.empty()) {
            cout << "Error: Cannot take tray, stack is empty" << endl;
        } else {
            stack.pop_back();
            if (!stack.empty()) {
                cout << "Top tray: " << stack.back() << endl;
            } else {
                cout << "Stack is empty" << endl;
            }
        }
    }
};

int main() {
    int n = 3; // maximum capacity
    TrayStack ts(n);

    // Example sequence of operations
    ts.place("Tray1");
    ts.place("Tray2");
    ts.take();
    ts.place("Tray3");
    ts.place("Tray4");
    ts.place("Tray5"); // should error
    ts.take();
    ts.take();
    ts.take();
    ts.take();         // should error

    return 0;
}


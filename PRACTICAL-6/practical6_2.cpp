/*A web browser keeps track of pages visited so that the back button always returns to the most recently visited page.
Unlike a fixed counter, the browser has no hard limit on how many pages it can remember — it grows as the user visits
more pages and shrinks as they press back. Given a sequence of visit and back operations, implement this unlimited page
history and print the current page after each operation.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BrowserHistory {
private:
    vector<string> history;

public:
    void visit(const string& page) {
        history.push_back(page);
        cout << "Current page: " << history.back() << endl;
    }

    void back() {
        if (history.empty()) {
            cout << "Error: No pages in history" << endl;
        } else {
            history.pop_back();
            if (!history.empty()) {
                cout << "Current page: " << history.back() << endl;
            } else {
                cout << "No pages left in history" << endl;
            }
        }
    }
};

int main() {
    BrowserHistory bh;

    // Example sequence of operations
    bh.visit("google.com");
    bh.visit("wikipedia.org");
    bh.visit("stackoverflow.com");
    bh.back();
    bh.back();
    bh.back();
    bh.back(); // should error

    return 0;
}

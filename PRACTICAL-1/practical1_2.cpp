/*A library issues books to students and records each book's ID every time it is borrowed. At the
end of the month, the librarian wants to find all books that were borrowed more than once, as
those need priority restocking. Given the borrowing log, print all such book IDs.
Describe the approach you used. How many times does your solution scan the data? If the
library had 100,000 borrow records, would your approach still be practical? Can you think of a
way that requires fewer passes?*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of borrow records: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the book IDs in the borrowing log: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> count;
    for (int id : arr) {
        count[id]++;
    }

    cout << "Books borrowed more than once: ";
    for (auto &entry : count) {
        if (entry.second > 1) {
            cout << entry.first << " ";
        }
    }

    return 0;
}

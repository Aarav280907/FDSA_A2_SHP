/*A security guard at a parking lot checks vehicles one by one from the entrance to find a car with
a specific license plate. Sometimes he starts from the entrance, sometimes he calls a helper
who starts from where the guard left off. Given a list of license plates and a target plate,
implement both approaches — one that checks plates one by one from the start, and one where
the function calls itself to continue checking — and report the position of the target plate if
found.
Describe the approach you used. What happens in your solution if the target plate appears
more than once in the list? Does it find the first occurrence, the last, or just any one?*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
//iterative
int findPlateIterative(const vector<string>& plates, const string& target) {
    for (int i = 0; i < plates.size(); i++) {
        if (plates[i] == target) {
            return i;
        }
    }
    return -1;
}

// Recurssive
int findPlateRecursive(const vector<string>& plates, const string& target, int index = 0) {
   if (index >= plates.size()) {
     return -1;
   }
   if (plates[index] == target) {
       return index; 
   }
   return findPlateRecursive(plates, target, index + 1); 
}

int main() 
{
    vector<string> plates = {"GJ01AB1234", "MH02XY5678", "DL03PQ9999", "GJ01AB1234"};
    string target = "GJ01AB1234";

    int posIter = findPlateIterative(plates, target);
    int posRec = findPlateRecursive(plates, target);

    cout << "Iterative found at position: " << posIter << endl;
    cout << "Recursive found at position: " << posRec << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct SongNode {
    string songName;
    SongNode* prev;
    SongNode* next;
};

class Playlist {
private:
    SongNode* head;
    SongNode* tail;
    int count;

public:
    Playlist() : head(nullptr), tail(nullptr), count(0) {}

    void addAtBeginning(const string& song) {
        SongNode* newNode = new SongNode{song, nullptr, nullptr};

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        count++;
        printState("Add to beginning: " + song);
    }

    void addAtEnd(const string& song) {
        SongNode* newNode = new SongNode{song, nullptr, nullptr};

        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
        printState("Add to end: " + song);
    }

    void insertAfterSong(const string& currentSong, const string& newSong) {
        SongNode* temp = head;

        while (temp != nullptr && temp->songName != currentSong) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Song '" << currentSong << "' not found. Insertion cancelled.\n";
            return;
        }

        SongNode* newNode = new SongNode{newSong, nullptr, nullptr};

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;
        count++;

        printState("Insert after '" + currentSong + "': " + newSong);
    }

    void removeFirstSong() {
        if (head == nullptr) {
            cout << "Playlist is empty. Cannot remove a song.\n";
            return;
        }

        SongNode* temp = head;
        string removedSong = head->songName;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        count--;
        printState("Remove first song: " + removedSong);
    }

    int getCount() const {
        return count;
    }

    void displayFromFirstToLast() const {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        SongNode* temp = head;
        cout << "Playlist from first to last: ";

        while (temp != nullptr) {
            cout << temp->songName;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }

        cout << "\n";
    }

    void printState(const string& action) const {
        cout << "\n" << action << "\n";
        cout << "Total songs: " << count << "\n";
        displayFromFirstToLast();
    }
};

int main() {
    Playlist playlist;
    int choice;
    string song;
    string currentSong;
    string newSong;

    cout << "--- Music Playlist Simulation ---\n";

    do {
        cout << "\n1. Add song at beginning\n";
        cout << "2. Add song at end\n";
        cout << "3. Insert song after another song\n";
        cout << "4. Remove first song\n";
        cout << "5. Display playlist\n";
        cout << "6. Show song count\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, song);
                playlist.addAtBeginning(song);
                break;

            case 2:
                cout << "Enter song name: ";
                getline(cin, song);
                playlist.addAtEnd(song);
                break;

            case 3:
                cout << "Enter the existing song name: ";
                getline(cin, currentSong);
                cout << "Enter the new song name: ";
                getline(cin, newSong);
                playlist.insertAfterSong(currentSong, newSong);
                break;

            case 4:
                playlist.removeFirstSong();
                break;

            case 5:
                playlist.displayFromFirstToLast();
                break;

            case 6:
                cout << "Total songs: " << playlist.getCount() << "\n";
                break;

            case 0:
                cout << "Exiting playlist.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

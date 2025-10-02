#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string payload;
    Node* next;
};

/**
* constructing a new load with the parameter as a the payload
*/
Node* newNode(string payload) {
    Node* node = new Node();
    node->payload = payload;
    node->next = nullptr;
    return node;
}

/**
* loadGame takes an int and a string vector of names and loads a circular 
* linked list (of n size), with the names from the vector
*/
Node* loadGame(int n, vector<string> names) {
    if(n == 0) {
        return nullptr;
    }

    if(n != names.size()) {
        throw runtime_error("Mismatch: n does not match number of names provided");
    }
    
    Node* head = nullptr;
    Node* prev = nullptr;
    string name;

    for (int i = 0; i < n; ++i) {
        name = names.at(i);
        Node* newNodePtr = newNode(name);
        if (head == nullptr) {
            head = newNodePtr; // initialize head specially
        } else {
            prev->next = newNodePtr;
        }
        prev = newNodePtr;
    }
    prev->next = head; //make circular

    return head;
}

/**
* prints out the data of each node in the linked list
*/
void print(Node* start) { // prints list
    Node* curr = start;
    while (curr != nullptr) {
        cout << curr->payload << endl;
        curr = curr->next;
        if (curr == start) {
            break; // exit circular list
        }
    }
}

/**
*  Runs the Josephus algorithm on a circular linked list. This algorithm simulates 
* a game where every k-th person is eliminated until only one person remains.
* The function takes two parameters, start, which is a node*, pointing to the start, and an integer
* which is how many nodes to iterate past
*/
Node* runGame(Node* start, int k) { // josephus w circular list, k = num skips
    if(start == nullptr) {
        return nullptr;
    }

    if(k <= 0) {
        throw runtime_error("k must be positive");
    }
    
    Node* curr = start;
    Node* prev = curr;
    while (curr->next != curr) { // exit condition, last person standing
        for (int i = 0; i < k; ++i) { // find kth node
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    return curr; // last person standing
}

/* Driver program to test above functions */
int main() {
    int n=1, k=1, max; // n = num names; k = num skips (minus 1)
    string name;
    vector<string> names;

    // get inputs and check if cin is in a valid state
    cin >> n >> k;
    if(!cin) { throw runtime_error("Faulty input"); }
    if(n <= 0 || k < 0) { throw runtime_error("n must be positive, k must be non-negative"); }

    while (cin >> name && name != ".") { names.push_back(name); } // EOF or . ends input

    // initialize and run game
    Node* startPerson = loadGame(n, names);
    cout << endl;
    print(startPerson);
    cout << endl;
    Node* lastPerson = runGame(startPerson, k);

    if (lastPerson != nullptr) {
        cout << lastPerson->payload << " wins!" << endl;
    } else {
        cout << "error: null game" << endl;
    }
    
    delete lastPerson; // delete the last node remaining in the heap

    return 0;
}

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

// Use standard namespace for brevity in small projects
using namespace std;

// Structure representing a node in the Binary Search Tree
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Class implementing a Hash Table where collisions are resolved 
// by storing elements in Binary Search Trees
class HashTable {
private:
    static const int TABLE_SIZE = 10;
    Node* table[TABLE_SIZE];

    // Helper recursive function to insert a key into BST
    void insertIntoTree(Node*& root, int key) {
        if (root == nullptr) {
            root = new Node(key);
        }
        else if (key < root->key) {
            insertIntoTree(root->left, key);
        }
        else if (key > root->key) {
            insertIntoTree(root->right, key);
        }
    }

    // Helper recursive function to print BST visually
    void printTreeStructure(Node* root, int level) {
        if (root != nullptr) {
            printTreeStructure(root->right, level + 1);
            cout << setw(level * 5) << " " << root->key << endl;
            printTreeStructure(root->left, level + 1);
        }
    }

    // Helper function to delete all nodes in a tree (prevent leaks)
    void clearTree(Node* root) {
        if (root != nullptr) {
            clearTree(root->left);
            clearTree(root->right);
            delete root;
        }
    }

    // Hash function to determine the index
    int getHash(int key) const {
        return abs(key) % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            clearTree(table[i]);
        }
    }

    // High-level method to fill the table with random data
    void fillWithRandomData(int count) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 99); // Random values between 1 and 99

        cout << "Generating keys: ";
        for (int i = 0; i < count; ++i) {
            int key = dis(gen);
            cout << key << " ";
            insertIntoTree(table[getHash(key)], key);
        }
        cout << endl;
    }

    // Displays the content of the entire hash table
    void display() {
        cout << "\n--- Hash Table Content (Collisions handled by BST) ---" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "Bucket [" << i << "]:" << endl;
            if (table[i] == nullptr) {
                cout << "  (empty)" << endl;
            }
            else {
                printTreeStructure(table[i], 1);
            }
            cout << "------------------------------------------------------" << endl;
        }
    }
};

int main() {
    HashTable myTable;

    // Build the structure
    myTable.fillWithRandomData(15);

    // Show the result
    myTable.display();

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
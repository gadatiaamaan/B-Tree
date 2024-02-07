#include <iostream>
#include <cstdlib>

using namespace std;

// Constants for B-tree properties
const int MAX_KEYS = 5;  // Maximum number of keys in a node
const int MIN_KEYS = 3;  // Minimum number of keys in a node

// Structure for a B-tree node
struct TreeNode {
    int keys[MAX_KEYS + 1];       // Array to store keys
    int numKeys;                  // Number of keys currently in the node
    TreeNode* children[MAX_KEYS + 2];  // Array of child pointers
};

// Global variable to store the root of the B-tree
TreeNode* root = nullptr;

// Function prototypes
TreeNode* createNode(int key, TreeNode* child);
void insertInNode(int key, int location, TreeNode* node, TreeNode* child);
void transferNode(int key, int* ptrKey, int location, TreeNode* node, TreeNode* child, TreeNode** newNode);
int nodeValue(int key, int* ptrKey, TreeNode* node, TreeNode** child);
void insertInTree(int key);
void traverse(TreeNode* current);

int main() {
    int N;
    cout << "How many random integer keys would you like in your B-tree? " << endl;
    cin >> N;

    while (N < 399) {
        cout << "The value you entered was less than 400, please enter a value greater than 400. " << endl;
        cout << "How many random integer keys would you like in your B-tree? " << endl;
        cin >> N;
    }

    int randArray[N];
    int randIntMax = 3 * N + 1;
    int findbtwnRange = 2 * N;

    for (int i = 0; i < N; i++) {
        int x;
        bool check;

        do {
            x = rand() % randIntMax;
            check = true;

            for (int j = 0; j < i; j++) {
                if (x == randArray[j]) {
                    check = false;
                    break;
                }
            }
        } while (!check);

        randArray[i] = x;
    }

    for (int i = 0; i < N; i++) {
        insertInTree(randArray[i]);
    }

    cout << "\nThe following keys are all of the random keys generated between 0 and 3N that appear in the B-Tree:" << endl;
    traverse(root);
    cout << "\n\nThe following keys are all of the random keys in the range of N and 2N that appear in the B-Tree:" << endl;

    for (int j = 0; j < N; j++) {
        if ((randArray[j] <= findbtwnRange) && (randArray[j] >= N)) {
            cout << randArray[j] << " ";
        }
    }

    cout << "\n";

    return 0;
}

// Function to create a new node with a single key
TreeNode* createNode(int key, TreeNode* child) {
    TreeNode* newNode = new TreeNode;
    newNode->keys[1] = key;
    newNode->numKeys = 1;
    newNode->children[0] = nullptr;
    newNode->children[1] = child;
    return newNode;
}

// Function to insert a key into a node at a specified location
void insertInNode(int key, int location, TreeNode* node, TreeNode* child) {
    int count = node->numKeys;
    while (count > location) {
        node->keys[count + 1] = node->keys[count];
        node->children[count + 2] = node->children[count + 1];
        count--;
    }
    node->keys[count + 1] = key;
    node->children[count + 1] = child;
    node->numKeys++;
}

// Function to transfer keys from one node to another during node splitting
void transferNode(int key, int* ptrKey, int location, TreeNode* node, TreeNode* child, TreeNode** newNode) {
    int mid = (location > MIN_KEYS) ? MIN_KEYS + 1 : MIN_KEYS;
    *newNode = new TreeNode;

    for (int i = mid + 1, j = 1; i <= MAX_KEYS; i++, j++) {
        (*newNode)->keys[j] = node->keys[i];
        (*newNode)->children[j] = node->children[i];
    }

    (*newNode)->numKeys = MAX_KEYS - mid;
    node->numKeys = mid;

    if (MIN_KEYS >= location) {
        insertInNode(key, location, node, child);
    } else {
        insertInNode(key, location - mid, *newNode, child);
    }

    *ptrKey = node->keys[node->numKeys];
    (*newNode)->children[0] = node->children[node->numKeys];
    node->numKeys--;
}

// Function to find the appropriate node for inserting a key
int nodeValue(int key, int* ptrKey, TreeNode* node, TreeNode** child) {
    int location;
    if (!node) {
        *ptrKey = key;
        *child = nullptr;
        return 1;
    }
    if (node->keys[1] > key) {
        location = 0;
    } else {
        for (location = node->numKeys; (node->keys[location] > key && location > 1); location--);
    }
    if (nodeValue(key, ptrKey, node->children[location], child)) {
        if (node->numKeys < MAX_KEYS) {
            insertInNode(*ptrKey, location, node, *child);
        } else {
            transferNode(*ptrKey, ptrKey, location, node, *child, child);
            return 1;
        }
    }
    return 0;
}

// Function to insert a key into the B-tree
void insertInTree(int key) {
    int value;
    int insert;
    TreeNode* child;
    value = nodeValue(key, &insert, root, &child);
    if (value)
        root = createNode(insert, child);
}

// Function to traverse the B-tree and output keys in sorted order
void traverse(TreeNode* current) {
    if (current) {
        int index;
        for (index = 0; index < current->numKeys; index++) {
            traverse(current->children[index]);
            cout << current->keys[index + 1] << " ";
        }
        traverse(current->children[index]);
    }
}

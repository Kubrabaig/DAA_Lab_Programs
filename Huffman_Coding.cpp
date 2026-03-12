#include <iostream>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node* createNode(char ch, int freq) {
    Node* newNode = new Node();
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printCodes(Node* root, string code) {
    if (!root) return;

    if (root->ch != '$')
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    Node *root = createNode('$', 5);
    root->left = createNode('A', 2);
    root->right = createNode('$', 3);
    root->right->left = createNode('B', 1);
    root->right->right = createNode('C', 2);

    cout << "Huffman Codes:\n";
    printCodes(root, "");

    return 0;
}
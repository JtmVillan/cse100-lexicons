#include "Set.h"
#include <iostream>

MultiwayTrieSet::MultiwayTrieSet() {
    root = new Node();
    numElements = 0;
}

void MultiwayTrieSet::deallocate(Node *currNode) { 
    // currNode = root;
    // if (currNode->isWord == true) {
    //     // deallocate the children
    //     currNode->children.clear();
    //     cout << "here " << endl;
    //     delete currNode;
    //     currNode = nullptr;
    // }
    // cout << "size of node" << currNode->children.size() << endl;
    // for (size_t i = 0; i < currNode->children.size(); i++) {
    //     deallocate(currNode->children[i]);
    // }
}

MultiwayTrieSet::~MultiwayTrieSet() {
    // deallocate(root);
    root = nullptr;
    delete root;
    numElements = 0;
}

// returns the number of words in the MWT
unsigned int MultiwayTrieSet::size() {
    return numElements;
}

void MultiwayTrieSet::insert(string s) {
    // word already in string
    if (MultiwayTrieSet::contains(s) == true) {
        return;
    }

    // start at the root Node
    Node *curr = root;

    // traverse through each letter of the word
    for (size_t i = 0; i < s.length(); i++) {
        // edge we need to traverse doesn't exist
        if (curr->children[s[i]] == nullptr) {
            // create the edge and node it should point to
            Node *newNode = new Node();
            curr->children[s[i]] = newNode;
            // last letter in string
            if (i == s.length() - 1) {
                // make word node
                curr->children[s[i]]->isWord = true;
                numElements++;
             }
            // update curr node
            curr = curr->children[s[i]];
        }
    }
}

void MultiwayTrieSet::erase(const string & s) {
    // word not present, nothing to erase
    if (MultiwayTrieSet::contains(s) == false) {
        return;
    }
    // word present, can erase
    if (MultiwayTrieSet::contains(s) == true) {
        // begin at root node
        Node *curr = root;
        // traverse through each letter of the word
        for (size_t i = 0; i < s.length(); i++) {
            // last node is a word node
            if (i == s.length() - 1 && curr->children[s[i]]->isWord == true) {
                curr->children[s[i]]->isWord = false;
                numElements--;
            }
            // update curr node to next char in string
            curr = curr->children[s[i]];
        }
    }
}

bool MultiwayTrieSet::contains(const string & s) {
    // start at the root Node
    Node *curr = root;
    // traverse for each letter of the word
    for (size_t i = 0; i < s.length(); i++) {
        // edge we need to traverse doesn't exist
        if (curr->children[s[i]] == nullptr) {
            // word doesn't exist
            return false;
        }
        // last node is not a word node
        else if (i == s.length() - 1 && curr->children[s[i]]->isWord == false ) {
            // word doesn't exist
            return false;
        }
        // last node is a word node
        else if (i == s.length() - 1 && curr->children[s[i]]->isWord == true ) {
            return true;
        }
        // follow the corresponding edge of the current node
        curr = curr->children[s[i]];
    }
    return false;
}

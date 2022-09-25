#include "Set.h"

unsigned int ArrayListSet::size() {
    unsigned int size = arr.size();
    return size;
}

void ArrayListSet::insert(string s) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        // check if element is already in the Set
        if (arr[i] == s) {
            // duplicate
            return;
        }
    }
    // o.w. insert at end of Set
    arr.emplace_back(s);
}

void ArrayListSet::erase(const string & s) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        // element to erase found
        if (arr[i] == s) {
            // erase at iterator position
            arr.erase(arr.begin() + i);
        }
    }
    // nothing to erase
}

bool ArrayListSet::contains(const string & s) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        // Set contains element
        if (arr[i] == s) {
            return true;
        }
    }
    // Set does not contain element
    return false;
}

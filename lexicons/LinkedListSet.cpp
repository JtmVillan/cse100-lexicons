#include "Set.h"

unsigned int LinkedListSet::size() {
    unsigned int size = linked.size();
    return size;
}

void LinkedListSet::insert(string s) {
    for (string l : linked) {
        // check if element already in Set
        if (l == s) {
            // duplicate
            return;
        }
    }
    // o.w. insert at end of Set
    linked.push_back(s);
}

void LinkedListSet::erase(const string & s) {
    for (string l : linked) {
        // element to erase found
        if (l == s) {
            linked.remove(s);
            return;
        }
    }
    // nothing to erase;
}

bool LinkedListSet::contains(const string & s) {
    for (string l : linked) {
        // Set contains element
        if (l == s) {
            return true;
        }
    }
    // Set does not contain element
    return false;
}

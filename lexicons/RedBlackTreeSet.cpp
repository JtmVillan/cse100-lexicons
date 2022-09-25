#include "Set.h"

unsigned int RedBlackTreeSet::size() {
    unsigned int size = rbt.size();
    return size;
}

void RedBlackTreeSet::insert(string s) {
    set<string>::iterator got = rbt.find(s);
    set<string>::iterator end = rbt.end();
    // element not in Set, insert
    if (got == end) {
        rbt.emplace(s);
    }
    //element in Set, do nothing
    return;
}

void RedBlackTreeSet::erase(const string & s) {
    set<string>::iterator got = rbt.find(s);
    set<string>::iterator end = rbt.end();
    // element not in Set, do nothing
    if (got == end) {
        return;
    }
    //element in Set, erase
    rbt.erase(got);
}

bool RedBlackTreeSet::contains(const string & s) {
    set<string>::iterator got = rbt.find(s);
    set<string>::iterator end = rbt.end();
    // element not in Set
    if (got == end) {
        return false;
    }
    //element in Set
    return true;
}

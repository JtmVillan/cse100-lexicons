#include "Set.h"

unsigned int HashTableSet::size() {
    unsigned int size = ht.size();
    return size;
}

void HashTableSet::insert(string s) {
    unordered_set<string>::iterator got = ht.find(s);
    unordered_set<string>::iterator end = ht.end();
    // element not in Set, insert
    if (got == end) {
        ht.emplace(s);
    }
    //element in Set, do nothing
    return;
}

void HashTableSet::erase(const string & s) {
    unordered_set<string>::iterator got = ht.find(s);
    unordered_set<string>::iterator end = ht.end();
    // element not in Set, do nothing
    if (got == end) {
        return;
    }
    //element in Set, erase
    ht.erase(got);
}

bool HashTableSet::contains(const string & s) {
    unordered_set<string>::iterator got = ht.find(s);
    unordered_set<string>::iterator end = ht.end();
    // element not in Set
    if (got == end) {
        return false;
    }
    //element in Set
    return true;
}



/*
 * Name: Lukas Bostick
 * Date Submitted:
 * Lab Section: Section 003
 * Assignment Name: Lab 05
 */

#include "stringset.h"
#include <iostream>

//Table starts at size 4.
Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const { return table; }

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const { return num_elems; }

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const { return size; }

//Function that accomplishes multiple things: first checks if the given word already exists (if so, return). If not, check if the table is full
//If so, double the size of the table and re-hash all values. Finally, insert the given word by determining the hash value of the word and using
//that number as a base to insert into the table.
void Stringset::insert(string word) {
    list<string>::iterator it; 

    //find element that word would be inserted into, then iterate through list to determine if word already exists in table.
    int wordHash = stringHash(word) % size;
    for(it = table[wordHash].begin(); it != table[wordHash].end(); it++) {
        if(*it == word) { return; }
    }

    int newSize = size * 2;
    //then check if table is full
    if (num_elems == size) {
        vector<list<string>> copy(newSize);

        //copy over vector, re-hashing each word into copy
        for (int i = 0; i < size; i++) {
            for(it = table[i].begin(); it != table[i].end(); it++) {
                int newIndex = stringHash(*it) % newSize;
                copy[newIndex].push_back(*it);
            }
        }
        
        size = newSize;

        table.clear();
        table = copy;
    }

    //then insert
    wordHash = stringHash(word) % size;
    table[wordHash].push_back(word);
    num_elems++;
}

//Finds the element in the vector the given word would be found in, then uses an iterator to find the word within the list. Returns true if found.
bool Stringset::find(string word) {
    list<string>::iterator it; 
    int hashWord = stringHash(word) % size;
    
    for(it = table[hashWord].begin(); it != table[hashWord].end(); it++) {
        if(*it == word) { return true; }
    }

    return false;
}

//Uses an iterator that searches for the provided word within the vector, removes it and decrements num_elems by one.
void Stringset::remove(string word) {
    list<string>::iterator it; 
    for (int i = 0; i < size; i++) {
        for(it = table[i].begin(); it != table[i].end(); it++) {
            if(*it == word) {
                table[i].remove(*it);
                num_elems--;
                return;
            }
        }
    }
}
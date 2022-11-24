/*
 * Name: Lukas Bostick
 * Date Submitted:
 * Lab Section: Section 003
 * Assignment Name: Lab 05
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 /*
 int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }
 */
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 //loadStringset simply opens the given file and loads in each line as a word to be inserted into the provided Stringset class.
 void loadStringset(Stringset& words, string filename) {
    ifstream infile(filename);
    string word;
    while(getline(infile, word)) {
        words.insert(word);
    }
 }
 
 //function that takes in a const Stringset class that contains a vector, as well as a string. The purpose of this function is to find 
 //all words within the vector that is one letter off from being the given word. Spellcheck returns a vector of all of these words.
 vector<string> spellcheck(const Stringset& words, string word) {
    int length = word.length();
    vector<string> matches;
    Stringset ex = words;

    //use find() for each word that is one letter adjacent to given word
    for(int i = 0; i < length; i++) {
        for(char j = 'a'; j <= 'z'; j++) {
            if(j != word[i]) {
                string newWord = word;
                newWord[i] = j;
                if(ex.find(newWord)) {
                    matches.push_back(newWord);
                }
            }
        }
    }

    return matches;
 }
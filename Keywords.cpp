#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "Responding.cpp"
#include "Keywords.hpp"
//all the imports we may need

//ease of life
using namespace std;

//constructor
KeywordsTrie::KeywordsTrie() {
  readKeywords();
  Responding responder();
}
void KeywordsTrie::findWord(string word) {
  //find word then update type and identifier to this words for use by takeInSentence
  //wordType = the guys you found type
  //wordIdentifier = the guy you found identifier
}
void KeywordsTrie::addWord(string word, int i, int t) {
  //adds a word to the trie and txt file
}
//remove a word from the keywords trie and txt file
void KeywordsTrie::removeWord(string word) {

}
//take in the users response
void KeywordsTrie::takeInSentence(string userInput) {
  //find a word in the keyword trie, and add that words type int
  //to end of sentence structure and its identifier to the end
  //of sentenceIdentifier int
  //findword(first word);
  //example: sentenceStructore = sentenceStructore*10 + wordType;
  //example: sentenceIdentifier = sentenceIdentifier*10 + wordIdentifier;
}
//read the key words from a file
void KeywordsTrie::readKeywords() {

    ifstream myfile("keywords.txt");
    if(myfile.is_open()) {
        //read the file
        string line;

        while(getline(myfile, line)) {
            stringstream ss;
            ss<<line;
            string word;
            while(getline(ss, word, ' ')) {  //this gives me one word

                //if(!isStopWord(word, ignoreWords))
            }
        }
    }
    myfile.close();
}

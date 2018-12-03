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
    start = initializeLetterNode('a');
    readKeywords();
}

struct letterNode* KeywordsTrie::initializeLetterNode(char letterToAdd) {
    letterNode *letter = new letterNode;

    letter->isEnd = false;
    letter->identifier = letter->type = -1;
    letter->letter = letterToAdd;

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        letter->children[i] = NULL;
    }

    return letter;
} 

void KeywordsTrie::findWord(string word) {
  //find word then update type and identifier to this words for use by takeInSentence
  //wordType = the type of the word you found 
  //wordIdentifier = the identifier of the word you found 
  //if its type is 7, then use the previous noun data not this words

    letterNode *crawl = start;

    for(int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if(crawl->children[index] == NULL) {
            wordType = 9;
            wordIdentifier = 9;
            return;
        }
        crawl = crawl->children[index];
    }

    if(crawl != NULL && crawl->isEnd) {
        wordType = crawl->type;
        wordIdentifier = crawl->identifier;
    }
    else {
        wordType = 9;
        wordIdentifier = 9;
    }
}

//adds a word to the trie and txt file
void KeywordsTrie::addWord(string word, int t, int i) {
    //check if the word already exists or not
    findWord(word);
    if(wordType == t && wordIdentifier == i) return;

    //add word to the trie
    prepTrie(word, t, i);

    //add word to txtfile
    /*
    ofstream myfile;
    myfile.open("testKeywords.txt", ios_base::app);
    myfile << word << " " << t << " " << i << "\n";
    myfile.close();
    */
}

//add a similar word
void KeywordsTrie::synonym(string toAdd, string similar) {
    findWord(toAdd);
    if(wordType != 9 && wordIdentifier != 9) return;
    findWord(similar);
    addWord(toAdd, wordType, wordIdentifier);  
}

//remove a word from the keywords trie and txt file
void KeywordsTrie::removeWord(string word) {
    findWord(word);
    if(wordType == 9 && wordIdentifier == 9) return;

    letterNode *crawl = start;

    for(int i = 0; i < word.size(); i++) {
        int index = word[i]-'a';
        if(crawl->children[index] == NULL) {
            return;
        }
        crawl = crawl->children[index];
    }

    crawl->isEnd = false;

    //then remove the word from the file

}

//take in the users response
void KeywordsTrie::takeInSentence(string userInput) {
  //find a word in the keyword trie, and add that words type int
  //to end of sentence structure and its identifier to the end
  //of sentenceIdentifier int
  //findword(first word);
  //example: sentenceStructure = sentenceStructure*10 + wordType;
  //example: sentenceIdentifier = sentenceIdentifier*10 + wordIdentifier;
  //then once done with every word responder.respond(sentenceStructure, sentenceIdentifier);

    stringstream ss;
    ss << userInput;
    string word;
    
    sentenceStructure = 0;
    sentenceIdentifier = 0;

    while(getline(ss, word, ' ')) {
        findWord(word);
        sentenceStructure = sentenceStructure*10 + wordType;
        sentenceIdentifier = sentenceIdentifier*10 + wordIdentifier;
    }
    responder.respond(sentenceStructure, sentenceIdentifier);
}

void KeywordsTrie::prepTrie(string word, int t, int i) {
    letterNode *crawl = start;

    for(int i = 0; i < word.size(); i++) {
        //get ascii value of word - ascii value of a to have an index in range of [0, 26)
        int index = word[i]-'a';

        //if the first letter of the word does not exist in keywords trie, make a new letterNode
        if(crawl->children[index] == NULL) {
            char charOfLetter = word[i];
            crawl->children[index] = initializeLetterNode(charOfLetter);
        }

        //move through each letterNode in keywords trie
        crawl = crawl->children[index];
    }

    crawl->isEnd = true;
    crawl->type = t;
    crawl->identifier = i;
}

//read the key words from a file
void KeywordsTrie::readKeywords() {

    ifstream myfile("keywords.txt");
    if(myfile.is_open()) {
        //read the file
        string line;

        while(getline(myfile, line)) { //gives me a line
            stringstream ss;
            ss<<line;
            string word;
            string input[3] = {};
            int index = 0;
            while(getline(ss, word, ' ')) {  //this gives me one word
                input[index] = word;
                index++;
            }
            //at 0 = word
            //at 1 = type
            //at 2 = identifier
            prepTrie(input[0], stoi(input[1]), stoi(input[2]));
        }
    }
    myfile.close();
}

/*
int main() {

    KeywordsTrie k;
    k.addWord("bananas", 7, 7);

    return 0;
}
*/



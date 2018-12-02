#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include "Responding.cpp"
//all the imports we may need

//ease of life
using namespace std;

//variables so that we are passing ints instead of strings which is a lot faster
const int NOUN = 1, VERB = 2, ADJECTIVE = 3, ADVERB = 4, OBJECT = 5;

//this struct is a letter node used used in the keyword trie
struct letterNode {
  //the letter at this node
  char letter;
  //the type of word it is if its a stop word, noun, verb, adjective
  int type;
  //the score that determines what to do with that word, the different nouns, different adj
  int identifier;
  //these are all the next nodes
  vector<letterNode> adjacents;
};

class KeywordsTrie {
public:
  //read the key words from a file
  void readKeywords() {

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
  //constructor
  KeywordsTrie() {
    readKeywords();
    Responding responder();
  }
  void findWord(String word) {
    //find word then update type and identifier to this words for use by takeInSentence
    //wordType = the guys you found type
    //wordIdentifier = the guy you found identifier 
  }
  void addWord(string word, int i, int t) {
    //adds a word to the trie and txt file
  }
  //remove a word from the keywords trie and txt file
  void removeWord(string word) {

  }
  //take in the users response
  void takeInSentence(string userInput) {
    //find a word in the keyword trie, and add that words type int
    //to end of sentence structure and its identifier to the end
    //of sentenceIdentifier int
    //findword(first word);
    //example: sentenceStructore = sentenceStructore*10 + wordType;
    //example: sentenceIdentifier = sentenceIdentifier*10 + wordIdentifier;
  }
  //int that stores each words type in order
  int sentenceStructore;
  //int that sotres each words identifier in order
  int sentenceIdentifier;
  //word identifier and type for use by guys
  int wordType;
  int wordIdentifier;
};

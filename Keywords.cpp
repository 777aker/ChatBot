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
  }
  //find a word and update the class's score, type, and identifier for passing to responsetrie
  bool findWord(string wordToFind) {
    //return false if word not found
    //return true if word found, and update the
    //score, type, identifier
    return false;
  }
  void addWord(string word, int i, int t) {
    //adds a word to the trie
  }
  void removeWord(string word) {

  } //each of the above methods will split the word into characters itself
  void takeInSentence(string userInput) {
    //split up by word and pass each word into findWord
  }
  //these are the variables to pass to the responsesTrie
  int score;
  int type;
  int identifier;
};

#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
//all the imports we may need

//ease of life
using namespace std;

//this struct is a letter node used used in the keyword trie
struct letterNode {
  //the letter at this node
  char letter;
  //the type of word it is if its a stop word, noun, verb, adjective
  int type;
  //the score that determines what to do with that word, the different nouns, different adj
  int identifier;
  //this is the score the word has, for example negative will be a -1
  int score;
  //these are all the next nodes
  vector<letterNode> adjacents;
};

//this is the struct used in the response trie
struct wordNode {
  //the word held at this node
  string word;
  //trieIdentifier, trieType, endScore all correlate to letterNode's type, identifier, score
  //this is one of the variables to help determine what type of sentence it is, and therefore whether or not
  //to use this trie
  int trieIdentifier;
  //this is the second identifier to determine which response trie to use
  int trieType;
  //this will be the score of the word that ends the sentence, for example -1 means this is a negative statement
  int endScore;
  //these are all the next nodes
  vector<wordNode> adjacents;
};

class keywordsTrie {
public:
  //
  bool findWord(String wordToFind) {
    //return false if word not found
    //return true if word found, and update the
    //score, type, identifier
  }
  void addWord(String word) {
    //adds a word to the trie
  }
  void removeWord(String word) {

  } //each of the above methods will split the word into characters itself
  //these are the variables to pass to the responsesTrie
  int score;
  int type;
  int identifier;
};

class responsesTrie {
public:

};

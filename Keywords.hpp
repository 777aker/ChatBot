#ifndef KEYWORDS
#define KEYWORDS

#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <string>

using namespace std;

//variables to help us and pass ints because ints are much faster to use than a string
const int NOUN = 1, VERB = 2, ADJECTIVE = 3, ADVERB = 4, MULTIPLIER = 5, QUESTION = 6, PREVIOUS = 7;

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
  //constructor
  KeywordsTrie();
  //finds a word for use by takeInSentence
  //unnecisary words will be 0 so they dont affect my sentence computations
  void findWord(string word);
  //adds a word to keyword trie and txt file
  void addWord(string word, int i, int t);
  //removes a word from the keyword trie and txt file
  void removeWord(string word);
  //takes in the users response
  void takeInSentence(string userInput);
  //reads in the txt file and puts the words in a trie
  void readKeywords();
  //int that stores each words type in order
  int sentenceStructore;
  //int that stores each words identifier in order
  int sentenceIdentifier;
  //word identifier and type for use by find word and takeInSentence
  int wordType;
  int wordIdentifier;
};

#endif

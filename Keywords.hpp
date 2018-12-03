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

const int ALPHABET_SIZE = 26;

//this struct is a letter node used used in the keyword trie
struct letterNode {
  //the letter at this node
  char letter;
  //the type of word it is if its a stop word, noun, verb, adjective
    //if it isn't an end letter, the value will be -1
  int type;
  //the score that determines what to do with that word, the different nouns, different adj
    //if it isn't an end letter, the value will be -1
  int identifier;
  //these are all the next nodes
  struct letterNode *children[ALPHABET_SIZE];
  //the letter is at the end of a word
  bool isEnd;
};

class KeywordsTrie {
public:
  //constructor
  KeywordsTrie();
  //finds a word for use by takeInSentence
  //unecessary words will be 0 so they dont affect the sentence computations
  void findWord(string word);
  //adds a word to keyword trie and txt file
  void addWord(string word, int t, int i);
  //removes a word from the keyword trie and txt file
  void removeWord(string word);
  //takes in the users response
  void takeInSentence(string userInput);
  //reads in the txt file and puts the words in a trie
  void readKeywords();

  //initialize a letterNode to be used in the Trie
  struct letterNode *initializeLetterNode(char letterToAdd);

  //first word, the word to add
  //second word, the word it's similar to
  void synonym(string toAdd, string similar);

  //helper function for the readKeywords function
  void prepTrie(string word, int t, int i);

  //the root of the keywords trie
  struct letterNode *start;
  //int that stores each words type in order
  int sentenceStructure;
  //int that stores each words identifier in order
  int sentenceIdentifier;
  //word identifier and type for use by find word and takeInSentence
  int wordType;
  int wordIdentifier;
  //make a responding object for taking in responses and responding
  Responding responder;
};

#endif

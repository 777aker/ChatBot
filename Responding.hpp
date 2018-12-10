#ifndef RESPONDING
#define RESPONDING

#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <deque>

using namespace std;

//variables to identify words
const int IGNORE = 1, NOUN = 2, DESCRIBER = 3,
  PREPOSITION = 4, VERBS = 5, HELPER = 6,
  QUESTION = 7, ADVERB = 8, UNKOWN = 9;
//this stores the previous subject of the sentence for use in the next sentence sometimes
string previousSubject = " ";
//this stores the word to add until the user gives us all the input we need to add it
string wordToAdd;
//this stores the subject of the sentence
string subject;
//verb of the sentence
string verb;
//object and potentially preposition
string directObject;
//this is what it will respond with constructed out of the above strings, subject, verb, directObject
string responseSentence;
//boolean whether the user sent a question or not
bool question;
//fruits for the robot to use
string pluralFruits[] = {"bananas", "strawberries", "pears", "kiwis", "grapefruits"};
string fruits[] = {"banana", "strawberry", "pear", "kiwi", "grapefruit"};
//integer for the fruit we are using this time
int fruity;
//holds all the guys that have fruit
vector<string> owners;
class Responding {
private:
  deque<int> structure, identifier;
  deque<string> input;
public:
  //constructor and initialization of responseHandler
  //also reads in the responses.txt and put them into the hash table
  Responding();
  //picks which sentence to use and responds
  void respond(int sentenceStructure, int sentenceIdentifier, string userInput);
  //prints the sentence slowly
  void prints(string sentence);
};

#endif

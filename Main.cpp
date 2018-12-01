#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
//all the imports we may need

//ease of life
using namespace std;

//variables so that we are passing ints instead of strings which is a lot faster
const int NOUN = 1, VERB = 2, ADJ = 3;

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
  int wordIdentifier;
  //this is the second identifier to determine which response trie to use
  int wordType;
  //this will be the score of the word that ends the sentence, for example -1 means this is a negative statement
  int endScore;
  //these are all the next nodes
  vector<wordNode> adjacents;
};

class KeywordsTrie {
public:
  //find a word and update the class's score, type, and identifier for passing to responsetrie
  bool findWord(string wordToFind) {
    //return false if word not found
    //return true if word found, and update the
    //score, type, identifier
    return false;
  }
  void addWord(string word) {
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

class responseHandler {
public:
  //constructor and initialization of responseHandler
  responseHandler() {

  }
  //pick which trie to use based on score, type, and identifier
  void pickTrie() {
    //also prints out the response to the user

  }
  //the keywordstrie will update the variables for use
  void updateVariables(int s, int t, int i) {
    score = s;
    type = t;
    identifier = i;
    pickTrie();
  }
  //a vector of all the tries
  vector<wordNode> responseTries;
  int score, type, identifier;
};

//add keyword to the file, string word, i = identifier, t = type, s = score
void addKeyword(String word, int i, int t, int s) {

}

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



int main(int argc, char* argv[]) {

    //when we get into testing, we will use argv to input user files of random inputs
        //then we can save the data from "chats". good for showing progress

    //first read in words known file
    readKeywords();
    //start taking in user input



    //before exiting save the keywordstrie in case user added or deleted words

    saveKeywords();

    return 0;
}

/*
    string response = "";
    cout << "type a letter" << endl;
    getline(cin, response);

    letterNode t1(response, "noun", 2);
    cout << t1.letter << endl;
*/

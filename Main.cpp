#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include "Keywords.cpp"
//all the imports we may need

//ease of life
using namespace std;

//this guy prints a string slowly, looks like the bot is typing, more coolio
void printSentence(string sentence) {
  //for every character, sleep for a little and then print the character
  for(char c: sentence) {
    this_thread::sleep_for(chrono::milliseconds(25));
    cout << c << flush;
  }
  //end the line once donejfda;
  cout << endl;
}

//this returns a lower case and no punctuation version of the sentence
string convert(string sentence) {
  //makes the string lowercase
  for(int i = 0; i < sentence.size(); i++) {
    sentence[i] = tolower(sentence[i]);
  }
  //the new input for the program to use
  string returnGuy;
  for(int i = 0; i < sentence.size(); i++) {
    if(sentence[i] != '.' && sentence[i] != ',' && sentence[i] != '?' && sentence[i] != '!') {
      returnGuy += sentence[i];
    }
  }
  return returnGuy;
}

int main(int argc, char* argv[]) {
  //initialize the keyword
  KeywordsTrie keyWordsObj;
  printSentence("Hello! Welcome to Kelley's and Lara's bot thing.");
  printSentence("To add a new word to what I know, type \"add word\", then follow my instructions.");
  printSentence("To remove a word I know, type \"remove word\", then follow my instructions.");
  printSentence("To stop talking, just say bye, or goodbye.");
  printSentence("Now you may type whatever you want.");
  cout << endl;
  //whether to quit or not
  bool quit = false;
  //now start taking in input stuff
  //send it to keyWordsObj.takeInSentence or the other stuff
  while(!quit) {
    string input;
    getline(cin, input);
    input = convert(input);
    if(input == "bye") {
      printSentence("Fine, bye.");
      quit = true;
    } else if(input == "goodbye") {
      printSentence("Ok then, goodbye.");
      quit = true;
    } else if(input == "add word") {
      printSentence("What word would you like to add?");
      string word;
      int type;
      int identifier;
      getline(cin, word);
      printSentence("Is it a synonym to anything? Type yes or no please.");
      getline(cin, input);
      if(input == "yes") {
        printSentence("What word is it a synonym to?");
        getline(cin, input);
        keyWordsObj.synonym(word, input);
        printSentence("Ok cool, thanks.");
      } else {
        printSentence("Ok, is it a noun, verb, adjective, preposition, or adverb?");
        getline(cin, input);
        if(input == "noun") {
          type = 1;
          identifier = 4;
        } else if(input == "verb") {
          type = 2;
          identifier = 5;
        } else if(input == "adjective") {
          type = 3;
          printSentence("From 1 to 9, how bad or good is its connotation?");
          printSentence("1 would be very naughty word, 9 such a compliment :).");
          getline(cin, input);
          identifier = stoi(input);
          if(identifier/10 != 0)
            printSentence("I said 1 to 9 dummy. No word for you.");
        } else if(input == "adverb") {
          type = 4;
          identifier = 1;
        } else if(input == "preposition") {
          type = 4;
          identifier = 6;
        } else {
          printSentence("That was not an option so you don't get your word :P");
          type = 9;
          identifier = 9;
        }
        keyWordsObj.addWord(word, type, identifier);
        printSentence(word + " " + to_string(type) + " " + to_string(identifier));
        printSentence("Ok, added " + word + ".");
      }
    } else if(input == "remove word") {
      printSentence("What word would you like me to forget, fooorrreeevvvvveeeerrrrr.");
      getline(cin, input);
      keyWordsObj.removeWord(input);
      printSentence("Ok, removed " + input + ".");
    } else {
      keyWordsObj.takeInSentence(input);
      input = convert(input);
    }
  }

  return 0;
}

/*
    string response = "";
    cout << "type a letter" << endl;
    getline(cin, response);

    letterNode t1(response, "noun", 2);
    cout << t1.letter << endl;
*/

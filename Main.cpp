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
  //end the line once done
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
  KeywordsTrie keyWordsObj();
  printSentence("Hello! Welcome to Kelley's and Lara's bot thing.");
  printSentence("To add a new word to what I know, type \"add word\", then follow my instructions.");
  printSentence("To remove a word I know, type \"remove word\", then follow my instructions.");
  printSentence("To stop talking, just say bye, or goodbye.");
  //whether to quit or not
  bool quit = false;
  //now start taking in input stuff
  //send it to keyWordsObj.takeInSentence or the other stuff
  while(!quit) {
    string input;
    getline(cin, input);
    input = convert(input);
    switch(input) {
      case "bye":
        printSentence("Fine, bye.");
        quit = true;
      break;
      case "goodbye":
        printSentence("Ok then, goodbye.");
        quit = true;
      break;
      case "add word":
        printSentence("What word would you like to add?");
        //the word, its type, and identifier
        string word;
        int type;
        int identifier;
        getline(cin, word);
        printSentence("Is it a synonym to anything? Type yes or no please.")
        getline(cin, input);
        if(input == "yes") {
          printSentence("What word is it a synonym to?");
          getline(cin, input);
          keyWordsObj.synonym(word, input);
          printSentence("Ok cool, thanks.");
        } else {
          printSentence("Ok, is it a noun, verb, adjective, or adverb?");
          getline(cin, input);
          switch(input) {
            case "noun":
              type = 1;
              identifier = (rand()%6) + 2;
              break;
            case "verb":
              type = 2;
              identifier = (rand()%9) + 1;
              break;
            case "adjective":
              type = 3;
              printSentence("From 0 to 9, how bad or good is its connotation?");
              printSentence("0 would be very naughty word, 9 such a compliment :).")
              getline(cin, stoi(identifier));
              break;
            case "adverb":
              type = 4;
              printSentence("From 0 to 9, how bad or good is its connotation?");
              printSentence("0 would be very naughty word, 9 such a compliment :).")
              getline(cin, stoi(identifier));
              break;
            default:
              printSentence("That was not an option. I'll just make it something random.")
              type = rand()%8;
              identifier = (rand()%8)+2;
              break;
          }
          printSentence("Ok, added " + input + ".")
        }
      break;
      case "remove word":
        printSentence("What word would you like me to forget, fooorrreeevvvvveeeerrrrr.");
        getline(cin, input);
        keyWordsObj.removeWord(input);
        printSentence("Ok, removed " + input + ".");
      break;
      default:
        keyWordsObj.takeInSentence(input);
      break;
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

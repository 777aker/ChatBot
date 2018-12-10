#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <deque>
#include "Responding.hpp"
//all the imports we may need

//ease of life
using namespace std;

Responding::Responding() {
  fruity = rand()%5;
}

void Responding::respond(int sentenceStructure, int sentenceIdentifier, string userInput) {
  //delete the old guys so we can put in the new sentence
  structure.clear();
  identifier.clear();
  input.clear();
  owners.clear();
  //and reset all variables just in case
  subject = "";
  verb = "";
  directObject = "";
  responseSentence = "";
  object = "";
  question = false;
  //split the structure and put into an array
  while(sentenceStructure != 0) {
    int digit = sentenceStructure%10;
    sentenceStructure /= 10;
    structure.push_front(digit);
  }
  //split the indentifier and put into an array
  while(sentenceIdentifier != 0) {
    int digit = sentenceIdentifier%10;
    sentenceIdentifier /= 10;
    identifier.push_front(digit);
  }
  //split the sentence string into parts and put into an array
  stringstream ss;
  ss << userInput;
  string word;
  while(getline(ss, word, ' ')) {
    input.push_back(word);
  }
  //cases they said you
  if((structure[0] == NOUN && identifier[0] == 2) || (structure[1] == NOUN && identifier[1] == 2))
  //------------------------------------------------------------------------------------------ this should be i or me later but for now leave it so no confusion in testing
    subject = "you";
  //cases they said i
  if((structure[0] == NOUN && identifier[0] == 3) || (structure[2] == NOUN && identifier[2] == 3))
  //------------------------------------------------------------------------------------------ this should be you later but for now leave it so no confusion in testing
    subject = "i";
  //cases that they said you and i
  if(input[0] == "you" && input[1] == "and" && input[3] == "i")
    subject = "you and I";
  //check if they asked question
  int questionWord;
  for(int i = 0; i < structure.size(); i++)
    if(structure[i] == QUESTION) {
      question = true;
      questionWord = i;
      i = structure.size();
    }
  if(structure[0] == HELPER && identifier[0] > 5) {
    questionWord = 0;
    question = true;
  }
  //cases they used a known verb
  int verbWord;
  for(int i = 0; i < structure.size(); i++)
    if(structure[i] == VERBS) {
      verb =  input[i];
      verbWord = i;
      i = structure.size();
    }
  //cases they used a known preposition
  int prepWord = -1;
  for(int i = 0; i < structure.size(); i++)
    if(structure[i] == PREPOSITION) {
      prepWord = i;
      i = structure.size();
    }

  //now if we dont know the verb but know the preposition
  if(prepWord != -1 && verb == "" && structure[prepWord-1] == UNKOWN) {
    verbWord = prepWord-1;
    verb = input[prepWord-1];
  }
  //if we dont know the subject lets try to find it
  if(subject == "" && verb != "" && verbWord != 0) { //if a verb than the word before it is probably subject
    if(structure[verbWord-1] == QUESTION || structure[verbWord-1] == HELPER)
      subject = input[verbWord+1];
    else
      subject = input[verbWord-1];
  } else if(structure[0] == HELPER && identifier[0] == 2 && subject == "") {
    subject = input[1];
  } else if(subject == "") {
    subject = input[0];
  }
  //finally lets try to find a direct object of the sentence
  if(prepWord != -1 && structure[prepWord+1] != HELPER)
    for(int i = prepWord+1; i < structure.size(); i++) {
      directObject += input[i];
    }
  else if(prepWord != -1)
    for(int i = prepWord+2; i < structure.size(); i++) {
      directObject += input[i] + " ";
    }
  if(verb != "" && structure[verbWord+1] != PREPOSITION)
    for(int i = verbWord+1; i < structure.size(); i++) {
      object += input[i] + " ";
    }
  //this is the positivity or negativity of the sentence
  //ranges from -4 to 4
  int connotation = 0;
  for(int i = 0; i < structure.size(); i++) {
    if(structure[i] == DESCRIBER)
      connotation += identifier[i] - 5;
  }
  //but if they used an adverb
  for(int i = 0; i < structure.size(); i++) {
    if(structure[i] == ADVERB)
      if(identifier[i] == 1)
        connotation *= -1;
  }
  //and what if they said you are not all those things
  for(int i = 0; i < structure.size(); i++) {
    if(structure[i] == HELPER && identifier[i] == 3)
      connotation *= -1;
  }
  prints("The subject of your sentence is " + subject);
  prints("The verb of your sentence is " + verb);
  prints("The direct object(s) of your sentence is(are) " + directObject);
  if(question) {
    prints("Your sentence is a question asking " + input[questionWord]);
  } else
    prints("Your sentence is not a question.");
  prints("The objects of your sentence are: " + object);
  prints("Your sentences connotation is: " + to_string(connotation));
  prints("The words in your sentence I don't know the meaning of are: ");
  for(int i = 0; i < input.size(); i++) {
    if(structure[i] == UNKOWN) {
      prints(input[i] + " ");
    }
  }
  //now we have gotten everything we can so lets switch based on stuff
  if(subject == "I") {
    //if the computer was asked a question
    if(question) {
      if(structure[questionWord] == QUESTION) {
        switch(identifier[questionWord]) {
          //they used which
          case 1:

          break;
          //they used who
          case 2:

          break;
          //they used what
          case 3:

          break;
          //they used when
          case 4:

          break;
          //they used where
          case 5:

          break;
          //they used why
          case 6:

          break;
          //they used how
          case 7:

          break;
        }
      } else if(structure[questionWord] == HELPER) {
        switch(identifier[questionWord]) {
          //they used do
          case 6:

          break;
          //they used does
          case 7:

          break;
          //they used did
          case 8:

          break;
          //they used will
          case 9:

          break;
        }
      }
      //this is if they referred to the computer but didn't ask a question
    } else {
      //now we gotta switch based off what verb they used

      //then connotation
    }
    //this is they referred to themself
  } else if(subject == "you") {
    //this is they asked a question

    //this is if they referred to both
  } else if(subject == "you and I") {
    //asked a question
    if(question) {
      prints("OOF, I'm not sure I can answer that.");
      //didn't ask a question
    } else {
      //switch based on verb of connotation
    }
    //they used some other noun
  } else {
    if(userInput == "whatever i want" || userInput == "whatever you want") {
      prints("Haha your so clever :/  ....  I'm not amused.");
    }
    //asked a question
    if(question) {
      prints("That's too much and too complicated for me.");
      //didn't ask a question
    } else {
      //if the first word is a or the or something skip it
      if(structure[0] == HELPER)
        subject = input[1];
      else
        subject = input[0];
      if(verb == "")
        prints("I don't know enough words to respond to that.");
      else {
        //this is they used a known verb and we probably have the correct subject now

      }
    }
  }
  //ok now we will reset previousSubject to be this subject for when they use things like it
  previousSubject = subject;
  cout << endl;
}

//this guy prints a string slowly, looks like the bot is typing, more coolio
void Responding::prints(string sentence) {
  //for every character, sleep for a little and then print the character
  for(char c: sentence) {
    this_thread::sleep_for(chrono::milliseconds(25));
    cout << c << flush;
  }
  //end the line once donejfda;
  cout << endl;
}

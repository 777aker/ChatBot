#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "Responding.cpp"
#include "Keywords.hpp"
//all the imports we may need

//ease of life
using namespace std;

//constructor
KeywordsTrie::KeywordsTrie() {
    //this is the root of the trie
    start = initializeLetterNode('a');
    //this creates this trie with all the keywords
    readKeywords();
}

//this is a helper function to create a letterNode to be used in tries
struct letterNode* KeywordsTrie::initializeLetterNode(char letterToAdd) {

    //this makes a temporary letterNode
    letterNode *letter = new letterNode;

    //this sets the basic information of a letterNode
    letter->isEnd = false;
    letter->identifier = letter->type = -1;
    letter->letter = letterToAdd;

    //this fills in the values of the children of the letterNode
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        letter->children[i] = NULL;
    }

    //return the created letterNode
    return letter;
} 

void KeywordsTrie::findWord(string word) {
  //find word then update type and identifier to this words for use by takeInSentence
  //wordType = the type of the word you found 
  //wordIdentifier = the identifier of the word you found 
  //if its type is 7, then use the previous noun data not this words

    //we use this to navigate through the keywords trie
    letterNode *crawl = start;

    //this grabs each individual letter in the word, because each node of the trie is a letterNode not a word node
    for(int i = 0; i < word.size(); i++) {
        //this gives me the child index for the current letterNode
        int index = word[i] - 'a';
        //if the letter at the index is NULL, then we know the word is not located in the trie
        //we return wordType and wordIdentifier as 9 to represent that it isn't in the trie, then we leave the method
        if(crawl->children[index] == NULL) {
            wordType = 9;
            wordIdentifier = 9;
            return;
        }
        //this goes to the next letter in the word
        crawl = crawl->children[index];
    }

    //we check if the letter is an isEnd letter which ensures we found a complete word and not just a part of a word
    if(crawl != NULL && crawl->isEnd) {
        wordType = crawl->type;
        wordIdentifier = crawl->identifier;
    }
    //if we did not find a complete word, we set wordType and wordIdentifier as 9
    else {
        wordType = 9;
        wordIdentifier = 9;
    }
}

//adds a word to the trie and txt file
void KeywordsTrie::addWord(string word, int t, int i) {
    //check if the word already exists or not
    findWord(word);
    //if the word doesn't exists, then we add the word to the trie
    if(wordType == 9 && wordIdentifier == 9) {
        //add word to the trie
        prepTrie(word, t, i);

        //add word to text file of keywords
        ofstream writer("testKeywords.txt", ios::app);

        //create toAdd to ensure the format of the new word matches the keywords text file
        string toAdd = "\n" +word + " " + to_string(t) + " " + to_string(i);
        writer << toAdd;
        writer.close();
        return;
    }
    else {
        //delete word
        removeWord(word);
        //then add new word
        addWord(word, t, i);
    }
}

//add a similar word
void KeywordsTrie::synonym(string toAdd, string similar) {
    //we check to see if the word exists in the trie
    findWord(toAdd);
    //if the word exists, we do not move forward with the method
    if(wordType != 9 && wordIdentifier != 9) return;
    //we find similar to get the set the wordType and wordIdentifier
    findWord(similar);
    //then we add the new word with the same wordType and wordIdentifier as the similar word
    addWord(toAdd, wordType, wordIdentifier);  
}

//remove a word from the keywords trie and txt file
void KeywordsTrie::removeWord(string word) {
    //we check if the word exists in the trie
    findWord(word);
    //if the word does not exist, we cannot remove it
    if(wordType == 9 && wordIdentifier == 9) return;


    //we use this to navigate through the keywords trie
    letterNode *crawl = start;

    //this grabs each individual letter in the word, because each node of the trie is a letterNode not a word node
    for(int i = 0; i < word.size(); i++) {
        //this gives me the child index for the current letterNode
        int index = word[i] - 'a';
        //if the letter at the index is NULL, then we know the word is not located in the trie
        //we leave the method, because there is nothing to do
        if(crawl->children[index] == NULL) {
            return;
        }
        crawl = crawl->children[index];
    }
    
    //once we hit the end of the word, we change it's isEnd value to establish that the word is no longer a complete word
    crawl->isEnd = false;
}

//take in the users response
void KeywordsTrie::takeInSentence(string userInput) {
  //find a word in the keyword trie, and add that words type int
  //to end of sentence structure and its identifier to the end
  //of sentenceIdentifier int
  //findword(first word);
  //example: sentenceStructure = sentenceStructure*10 + wordType;
  //example: sentenceIdentifier = sentenceIdentifier*10 + wordIdentifier;
  //then once done with every word responder.respond(sentenceStructure, sentenceIdentifier);

    stringstream ss;
    ss << userInput;
    string word;
    
    sentenceStructure = 0;
    sentenceIdentifier = 0;

    while(getline(ss, word, ' ')) {
        findWord(word);
        sentenceStructure = sentenceStructure*10 + wordType;
        sentenceIdentifier = sentenceIdentifier*10 + wordIdentifier;
    }
    responder.respond(sentenceStructure, sentenceIdentifier);
}

void KeywordsTrie::prepTrie(string word, int t, int i) {
    letterNode *crawl = start;

    for(int i = 0; i < word.size(); i++) {
        //get ascii value of word - ascii value of a to have an index in range of [0, 26)
        int index = word[i]-'a';

        //if the first letter of the word does not exist in keywords trie, make a new letterNode
        if(crawl->children[index] == NULL) {
            char charOfLetter = word[i];
            crawl->children[index] = initializeLetterNode(charOfLetter);
        }

        //move through each letterNode in keywords trie
        crawl = crawl->children[index];
    }

    crawl->isEnd = true;
    crawl->type = t;
    crawl->identifier = i;
}

//read the key words from a file
void KeywordsTrie::readKeywords() {

    ifstream myfile("testKeywords.txt");
    if(myfile.is_open()) {
        //read the file
        string line;

        while(getline(myfile, line)) { //gives me a line
            
            stringstream ss;
            ss<<line;
            string word;
            string input[3] = {}; //this isolates each word and it's type and identifier
            int index = 0;
            while(getline(ss, word, ' ')) {  //this gives me one word
                input[index] = word;
                index++;
            }
            //at 0 = word
            //at 1 = type
            //at 2 = identifier
            prepTrie(input[0], stoi(input[1]), stoi(input[2]));
        }
    }
    myfile.close();
}


//for testing
int main() {

    KeywordsTrie k;
    k.addWord("bananas", 2, 2);
    k.addWord("bananas", 2, 4);
    k.addWord("grapefruit", 5, 5);

    return 0;
}




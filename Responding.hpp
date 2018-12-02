#ifndef RESPONDING
#define RESPONDING

#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

class Responding {
public:
  //constructor and initialization of responseHandler
  //also reads in the responses.txt and put them into the hash table
  Responding();
  //picks which sentence to use and responds
  void respond(int sentence);
};

#endif 

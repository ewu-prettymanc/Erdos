#ifndef _SCENARIO_H__
#define _SCENARIO_H__
#include"AuthorNode.h"
#include"MyHashTable.h"
#include<string>
#include<stdlib.h>
#include<assert.h>
#include<iostream>

using namespace std;

class Scenario
{
 public:
  Scenario();
  ~Scenario();

  int GetErdosNum( string author);
  void StoreLine(string line);
  void UpdateTable();
  string Print();
  
 protected:
  void UpdateErdosNum( AuthorNode * node, int erdosnum );
  MyHashTable* _table;

};
#endif

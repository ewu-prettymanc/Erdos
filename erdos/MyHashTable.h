#ifndef _MyHashTable_H__
#define _MYHASHTABLE_H__

#include"AuthorNode.h"
#include<assert.h>
#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;

class MyHashTable
{
 public:
  MyHashTable(int length );
  ~MyHashTable();
  
  void AddConnection( string author, string coauthor );
  void Put( string author );
  int GetKey( string s );
  double HashCode( string s );
  string Print();

  AuthorNode* GetIndex( int i ) { return _table[i]; };
  AuthorNode* GetNode( string author ) { return _table[GetKey(author)]; };

 protected:
  AuthorNode** _table;
  int _length;
};
#endif

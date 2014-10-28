#ifndef __AUTHORNODE_H__
#define __AUTHORNODE_H__

#include<math.h>
#include<stdlib.h>
#include<deque>
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
 
class AuthorNode
{
 public:
  AuthorNode( string author );
  ~AuthorNode();

  void AddCoAuthor( AuthorNode* coauthor );
  void SetErdos( int num );
  double HashCode();
  string Print();

  string GetName() { return _author; };
  deque<AuthorNode*> GetCoAuthors() { return _coauthors; };
  bool IsVisited() { return _isvisited; };
  int GetErdosNum() { return _erdos; };

 protected: 
  string _author;
  deque<AuthorNode*> _coauthors;
  int _erdos;
  bool _isvisited;
};
#endif

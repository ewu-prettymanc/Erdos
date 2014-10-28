#include"AuthorNode.h"

AuthorNode::AuthorNode( string author )
  :_author(author)
{
  _erdos = -1;
  _isvisited=false;
}

AuthorNode::~AuthorNode() {};

void AuthorNode::SetErdos( int num )
{
  // Only update the erdos number if it is less then the current one
  // And is greater then -1....which is the unintiallized value.
  // The first time any number goes
  if( _erdos < 0 )
    {
      _erdos = num;
      _isvisited = true;
      return;
    }
  // next make sure it is less then current erdos
  if( num < _erdos )
    {
      _erdos = num;
      _isvisited = true;
    }
}

// Adds an author to the list
void AuthorNode::AddCoAuthor( AuthorNode* coauthor )
{
  // Ignore the case that an author wrote with himself
  // or if we are trying to add an author to his own coathors.
  if( _author == coauthor->GetName() )
    return;
  
  // Check and make sure we aren't adding a duplicate co-author
  // Can just address compare here
  for( int i=0; i < (int)_coauthors.size(); i ++ )
    if( coauthor == _coauthors[i] )
      return;

  _coauthors.push_front( coauthor );
}

double AuthorNode::HashCode( ) 
{
 double res = 0;
 int i, hash=7;
 
 // each character ascii value raised to its elements power
 for( i=0; i < (int)_author.size(); i ++ )
   res +=  hash*31 + static_cast<int>(_author[i] );
    
  return res;
}

string AuthorNode::Print()
{
  string res="";
  res += "AuthorName: " + _author + "\n CoAuthors: ";
  
   for( int i=0; i < (int)_coauthors.size(); i ++ )
     res += _coauthors[i]->GetName() + " ";
 
  return res;
}

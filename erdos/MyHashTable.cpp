#include"MyHashTable.h"

MyHashTable::MyHashTable( int length )
  : _length(length)
{
  _table = new AuthorNode*[ _length ];
  assert( _table );

   for( int i=0; i < _length; i ++ )
    _table[i] = NULL;
}

MyHashTable::~MyHashTable()
{
  int i;
  for( i = 0; i < _length; i ++ )
    if( _table[i] != NULL )
      delete _table[i];

  delete [] ( _table );
}

// Essentially the key first and element to put second
void MyHashTable::Put(string author )
{
  int index = GetKey( author );

  // First make sure there is a node.
  if( _table[index] == NULL )
    {
      _table[index] = new AuthorNode( author );
      assert( _table[index] );
    }

  if( _table[index]->GetName() != author )
    {
      string s = _table[index]->GetName();

      cerr<<"*********collision in hashtable***********"<<endl;
      cerr<<s<<" not equal to " << (string)author<< endl;
      cerr<<s<<" key is " << GetKey( s ) << endl;
      cerr<<s << " hashcode is " << HashCode( s ) <<  endl;
      cerr<< author<< " key is " << GetKey( author ) << endl;
      cerr<< author<< " hashcode is " << HashCode( author ) << endl;
    }
}

// Essentially the key first and element to put second
void MyHashTable::AddConnection(string author, string coauthor )
{
  _table[GetKey(author)]->AddCoAuthor( _table[GetKey(coauthor)] );
}

//Get the key for the string in the hashtable
int MyHashTable::GetKey(string s )
{
  return  (int) HashCode(s)%_length;
}

double MyHashTable::HashCode( string s ) 
{
 double res = 0;
 int i, hash=7;
 
 // each character ascii value raised to its elements power
 for( i=0; i < (int)s.size(); i ++ )
   res +=  hash*31 + static_cast<int>(s[i] );
    
  return res;
}

string MyHashTable::Print()
{
  string res = "";
 
  // Print the elements in MyHashTable which are not null
  for( int i=0; i < _length; i ++ )
    if( _table[i] != NULL )
      res += _table[i]->Print() + "\n";
    
  return res;
}

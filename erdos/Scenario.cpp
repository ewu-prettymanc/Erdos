#include"Scenario.h"

Scenario::Scenario( )
{
  // Create my HashTable of 3333 elements in size
  // If so desired I could make the hashtable
  // resize to eleminate collisions
  _table = new MyHashTable( 3333 );
  assert(_table);
}

Scenario::~Scenario()
{
   delete _table;
}

// Retrieves the erdos number for the given author.
int Scenario::GetErdosNum(string author)
{
  AuthorNode* node= _table->GetNode( author );

  if( node == NULL )
     return -1;
  return node->GetErdosNum();
}

void Scenario::UpdateTable()
{
   AuthorNode* erdos= _table->GetNode( "Erdos, P.");
     if( erdos == NULL )
       return;
 
     UpdateErdosNum( erdos, 0 );
}

// Goes through the hashtable and calculates the Erdos number
// for each one.Working from Erdos Backwords.
void Scenario::UpdateErdosNum( AuthorNode* node, int erdosnum )
{
  deque<AuthorNode*> co = node->GetCoAuthors();
  
  // We've been here and already set a value lower this current number
  if( node->IsVisited() && node->GetErdosNum() < erdosnum )
    return;

  node->SetErdos( erdosnum );
  // Now call recursively call this method on each element
  for( int i=0; i< (int)co.size(); i ++ )
     UpdateErdosNum( co[i], erdosnum+1 );
}

// In this method we will take an input line from and
// parse the authors from it and store them into our hashtable
void Scenario::StoreLine(string line)
{
  bool done = false; 
  int commas = 0;
  int i=0, j=0;
  deque<string> authors;
  string temp="";
    
  // This parses the different authors from of a line of input
  // Storing them into a queue
  while ( ! done )
    {
      for( ; commas < 2; i++ )
	{
	  temp += line[i];
	  if( line[i+1] == ',' )
	    commas ++;
	 
	  // break once we've reached a colon
	  // and set a flag to exit the outer loop
	  if( line[i+1] == ':' )
	    {
	      done = true;
	      break;
	    }
	}
      // Ignore the first comma and whitespace
      i+=2;
      // Add the freshly read in author to our queue
       authors.push_front( temp );
      // reset our comma counter
      commas = 0;
      temp="";
    }
  
  // Put each author on the hashtable
  for( i=0; i < (int) authors.size(); i ++  )
    _table->Put((string) authors[i] );

  // Now loop through the queue storing/creating author nodes for each
  // then attaching the coauthors to each author.
   for( i=0; i < (int)authors.size(); i ++ )
     // put all of the authors with respect to every other author.
     for( j = 0; j < (int)authors.size(); j ++ )
       _table->AddConnection( (string)authors[i],(string) authors[j] );
      
}

string Scenario::Print()
{
  if( _table == NULL )
    cout<<"HashTable is NULL!!!"<<endl;

  return _table->Print();
}

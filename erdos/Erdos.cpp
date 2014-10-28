#include"Erdos.h"

Erdos::Erdos(string infile, string outfile )
{
  _infile.open( infile.c_str() );
  assert( _infile );
  _outfile.open(  outfile.c_str() );
   assert( _outfile );
   
   _iscenario = false;
}

Erdos::~Erdos()
{
  if( _iscenario )
    delete _scenario;
  _infile.close();
  _outfile.close();
}

void Erdos::Run()
{
  // Read in the scenario count
  int p=0,n=0;
  string author="";
  int erdosnum=0;
  int numscenario=0;
  int i=0,x=0;
  string line="";

  _infile >> numscenario;
  
  for( x =1; x < numscenario+1; x ++ )
    {
      //Just quit when EOF is reached
      _infile >> p;
      if( _infile.eof() )
      break;
      _infile >> n;

      // If we've already created a scenario then delete it
      if(  _iscenario )
	{
	  delete _scenario;
	  _iscenario = false;
	}
      // Allocate a new one
      _scenario = new Scenario();
      assert( _scenario );
      _iscenario = true;
      
      // Read out the new line character in the file
      getline( _infile, line );
      for(i=0; i < p; i ++ )
	{
	  getline( _infile, line );
	  _scenario->StoreLine( line );
	}

        // Update the table's erdos calculations
      _scenario->UpdateTable();
      
       _outfile<<"Scenario " << x<<endl;
       cout<<"Scenario " << x<<endl;
	   
       for( i=0; i < n; i ++ )
	{
	  getline( _infile, author );
	  erdosnum = _scenario->GetErdosNum( author );
		  
	    if( erdosnum > -1  )
	    {
	      _outfile << author << " " <<erdosnum << endl;
	      cout << author << " " <<erdosnum << endl;
	    }
	    else
	    {
	      _outfile << author << " infinity" << endl;
	      cout << author << " infinity" << endl;
	    }
	}
      p=n=erdosnum;
      author="";
      line="";
    }
}

#ifndef __ERDOS_H__
#define __ERDOS_H__

#include<stdlib.h>
#include<assert.h>
#include"Scenario.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class Erdos
{
 public:
  Erdos(string infile, string outfile );
  ~Erdos();
  void Run();

 private:
  Scenario* _scenario;
  ifstream _infile;
  ofstream _outfile;
  bool _iscenario;
};
#endif

#include"Erdos.h"

/* Colton Prettyman 05-09-13
 * CSCD 316 Problem Solving, Professor Thomas Capaul
 * Erdos Number Problem
 *
 *
 * This is a solution to the Erdos number problem. Everything was intuitively
 * Figured out. Suprisingly my search algorithm came out to be the same as
 * the breadth first search algorithm. Accept instead of a queue I use the 
 * stack for my queue.
 * This program was written/compiled in Linux, and debugged using Valgrind.
 * Valgrind claims that no memory leaks and errors are possible.
 */
int main()
{
  Erdos e("input.txt","output.txt");
  e.Run();

  return 0;
}

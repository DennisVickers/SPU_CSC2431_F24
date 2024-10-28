#include <iostream>
#include "doublelinklist.h"
using namespace std;

int main() {
  doubleLinkList list;

  /* Build a list*/
  cout << "\nOriginal List:\n";
  list.prepend(10);
  list.prepend(20);
  list.append(30);
  list.append(40);
  list.showList(); // Output should be "20, 10, 30, 40"
  
  /* update the list */
  cout << "Remove the head of the list\n";
  list.remove(20);
  list.showList();
  
  /* update the list */
  cout << "Remove the tail of the list\n";
  list.remove(40);
  list.showList();

  /* find a node in the list */
  int searchVal = 30;
  if (list.search(searchVal)) {
    cout << "Element holding " << searchVal << " found\n";
  } else {
    cout << "Element holding " << searchVal << " not found\n";
  }

  return 0;
}

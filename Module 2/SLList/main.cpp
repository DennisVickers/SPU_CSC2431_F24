#include <iostream>
#include "singlelinklist.h"
using namespace std;

int main() {
  singleLinkList list;

  list.prepend(10);
  list.prepend(20);
  list.append(30);

  list.showList();  // Output should be "20 10 30"

  list.remove(20);
  list.showList();  // Output should be "10 30"

  if (list.search(30)) {
    std::cout << "Element found\n";
  } else {
    std::cout << "Element not found\n";
  }

  return 0;
}
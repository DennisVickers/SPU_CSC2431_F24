#include "HashTable.h"

int main() {
   HashTable hashTable;

   hashTable.insert("Alice", "Engineering");
   hashTable.insert("Bob", "Computer Science");
   hashTable.insert("Cathy", "Business");
   hashTable.insert("Daniel", "InfoSystems");
   cout << endl << "Initial Hash Table" << endl;
   hashTable.showTable();
   cout << endl;

   string sKey = "Alice";
   cout << "Search for " << sKey << endl;
   string value = hashTable.search(sKey);
   if (!value.empty()) {
      cout << sKey << " is majoring in " << value << endl;
   }

   hashTable.remove("Bob");
   cout << endl << "Hash Table after remove:" << endl;
   hashTable.showTable();

   return 0;
}
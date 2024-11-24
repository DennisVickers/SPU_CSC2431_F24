#include "hashtable.h"

int HashTable::hashFunction(const string& key) const {
   int hash = 0;
   for (char c : key) {
      hash = (hash * 31 + c) % this->size;
   }
   return hash;
};

void HashTable::insert(const string& newKey, const string& newValue) {
   int index = hashFunction(newKey);
   KVPair newKVP;
   newKVP.key = newKey;
   newKVP.value = newValue;

   table[index].emplace_back(newKVP);
};

bool HashTable::remove(const string& delKey) {
   int index = hashFunction(delKey);
   for (auto itr = table[index].begin(); itr != table[index].end(); itr++) {
      if (itr->key == delKey) {
         table[index].erase(itr);
         return true;
      }
   }
   return false;
};

string HashTable::search(const string& searchKey) const {
   string value="";
   int index = hashFunction(searchKey);
   for (auto itr = table[index].begin(); itr != table[index].end(); itr++) {
      if (itr->key == searchKey) {
         value = itr->value;
         break;
      }
   }
   return value;
};

void HashTable::showTable() const {
   for (size_t i = 0; i < this->size; i++) {
      cout << "Bucket " << i << ": ";
      if (!table[i].empty()) {
         for (KVPair kvp : table[i]) {
            cout << " " << kvp.key << ", " << kvp.value << ";";
         }
      }
      cout << endl;
   }
};

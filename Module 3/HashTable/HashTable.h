# pragma once

#include <iostream>
#include <string>
#include <list>

using namespace std;

struct KVPair {
   string key;
   string value;
   KVPair() : key(""), value("") {};
};

class HashTable {
public:
   void insert(const string&, const string&);
   bool remove(const string&);
   string search(const string&) const;
   void showTable() const;

private:
   int size=10;
   list<KVPair> table[10];
   
   int hashFunction(const string&) const;
};
#pragma once

struct Node {
   int data;
   Node* left;
   Node* right;
   int height;
    
   Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};
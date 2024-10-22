#include "queue.h"
#include <iostream>
using namespace std;

int main() {
   Queue q;

   q.enqueue(10);
   q.enqueue(20);
   q.enqueue(30);

   cout << "Front element: " << q.peek() << endl;
   cout << "Queue size: " << q.getSize() << endl;

   if (!q.isEmpty()) {
      cout << "Dequeue: " << q.dequeue() << endl;
      cout << "Queue size after dequeue: " << q.getSize() << endl;
   }

   return 0;
}

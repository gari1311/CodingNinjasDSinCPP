/*
Given a queue of integers, reverse it without help of any explicit stack or queue. You need to change in the given queue itself.
Note : No need to return or print the queue.
Input format :
Line 1 : First Element - Size of Queue, Rest Elements - Elements Of Queue
Output format :
Queue elements
Sample Input :
4 1 2 3 4     (1 is at front)
Sample Output :
4 3 2 1    (4 is at front)
*/

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    queue<int> q;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	q.push(val);
    }
    reverseQueue(q);
    while(!q.empty()) {
    	cout << q.front() << " ";
    	q.pop();
    }
}

#include <queue>

void reverseQueue(queue<int> &q) {
	// Write your code here
 if (q.empty()) 
        return; 
  
    // Dequeue current item (from front)   
   int data = q.front(); 
    q.pop(); 
  
    // Reverse remaining queue   
    reverseQueue(q); 
  
    // Enqueue current item (to rear)   
    q.push(data); 
}

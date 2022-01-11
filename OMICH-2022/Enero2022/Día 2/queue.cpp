#include <bits/stdc++.h>
using namespace std;

void debug(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
		q.pop();
	}
	cout << '\n';
}


/* back.             front
            {}
            {3}
            {1, 3}
            {4, 1, 3}
            {5, 4, 1, 3} 



            Pop

    back             front
            {5, 4, 1}
            {5, 4}
            {5}              
*/


int main() {
  queue<int> q;

  // push(x)
  q.push(3); // 
  cout << q.size() << endl;
  debug(q);
  q.push(1);
  debug(q);
  cout << q.size() << endl; 
  debug(q);

  q.push(4);
  debug(q);
  cout << q.size() << endl; 
  debug(q);

  q.push(5);
  debug(q);
  cout << q.size() << endl; 
  debug(q);


  cout << endl;
  cout << " POP " << endl;
  // pop()
  q.pop();
  debug(q);  

  q.pop();
  debug(q);  

  q.pop();
  debug(q);
  cout << q.empty() << endl;  
  q.pop();
  debug(q);
  cout << q.empty() << endl; 
  return 0;

  // front()
  cout << q.front() << endl;

  // back
  cout << q.back() << endl;


  // empty()


  // size()




	return 0;
}
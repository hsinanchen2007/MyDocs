/*

https://www.educative.io/module/lesson/cpp-basics/RMQ5Dk5wPBw

Base case
When should we stop calling the function recursively in a program?
Since we have divided the larger subproblem into a series of smaller subproblems of itself, 
after some time the problem will become so simple that you can solve it directly without 
dividing it any further. This is the base case.

The condition where the function stops calling itself in its body is known as the base case.

The recursive function only knows how to solve the simplest case known as a base case. When 
we call the recursive function with a base case, it simply returns us the result. There are 
no recursive calls in the function.

📝Every recursive function must have a base case or an error is generated because of memory 
overflow.

Why use recursion?
You might encounter a problem that is too scary. The easiest way to solve such problems is 
to use the divide and conquer rule.

Recursion is a very powerful tool when we can define the problem in terms of itself.

Recursion helps to write shorter code.

We can convert loops into a recursive function.

*/

#include <iostream>

using namespace std;

int ticket_price(int person) {
  int price;
  if (person == 1) {
    price = 100;
    return price;
  } 
  else {
    cout << "Person" << person << " is asking price" << endl;
    person--;
    price = ticket_price(person);
    cout << "Person" << person << " is telling price" << endl;
    return price;
  }
}

int main() {
  int price;
  price = ticket_price(5);
  cout << "Ticket price = " << price << endl;
}


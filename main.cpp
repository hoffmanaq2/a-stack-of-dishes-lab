#include <iostream>
#include "src/dishstack.hpp"
using namespace std;

int main() {
  DishStack stack;

  stack.push(Dish("A dish with one fish pattern on it"));
  stack.push(Dish("A dish with two fish patterns on it"));
  stack.push(Dish("A dish with a red fish pattern on it"));
  stack.push(Dish("A dish with a blue fish pattern on it"));

  cout << "Peek: " << stack.peek().get_description() << endl;
  cout << "Pop: " << stack.pop().get_description() << endl;
  cout << "Pop: " << stack.pop().get_description() << endl;
  cout << "Final size: " << stack.size() << endl;

  return 0;
}

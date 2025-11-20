#include "DishStack.hpp"
#include <iostream>
using namespace std;

DishStack::DishStack() {
   top = -1;
}

bool DishStack::is_full() const {
   return top == MAX_SIZE - 1;
}

bool DishStack::is_empty() const {
   return top == -1;
}

void DishStack::push(const Dish& dish) {
   if (is_full()) {
      cout << "Stack is full — cannot push.\n";
      return;
   }
   dishes[++top] = dish;
}

Dish DishStack::pop() {
   if (is_empty()) {
      cout << "Stack is empty — cannot pop.\n";
      return Dish(""); // return empty description dish
   }
   return dishes[top--];
}

Dish DishStack::peek() const {
   if (is_empty()) {
      cout << "Stack is empty — nothing to peek.\n";
      return Dish("");
   }
   return dishes[top];
}

int DishStack::size() const {
   return top + 1;
}

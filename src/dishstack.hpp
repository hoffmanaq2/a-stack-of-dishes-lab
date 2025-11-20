#include "Dish.hpp"

class DishStack {
private:
    static const int MAX_SIZE = 10;
    Dish dishes[MAX_SIZE];
    int top;

public:
    DishStack();

    bool is_full() const;
    bool is_empty() const;

    void push(const Dish& dish);
    Dish pop();
    Dish peek() const;

    int size() const;
};


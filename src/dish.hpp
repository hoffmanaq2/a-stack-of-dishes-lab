#include <string>
using namespace std;

class Dish {
private:
  string description;

public:
  Dish() : description("") {} // default constructor
  Dish(string description) {
    this->description = description;
  }

  string get_description() const {
    return this->description;
  }
};

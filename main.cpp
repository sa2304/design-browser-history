#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class BrowserHistory {
 public:
  BrowserHistory(string homepage) {
    //FIXME
  }

  void visit(string url) {
    //FIXME
  }

  string back(int steps) {
    //FIXME
    return {};
  }

  string forward(int steps) {
    //FIXME
    return {};
  }
};

void Test1() {
  BrowserHistory history{"leetcode.com"s};
  history.visit("google.com"s);
  history.visit("yandex.ru"s);
  history.visit("search.domain"s);
  assert("yandex.ru"s == history.back(1));
  assert("google.com"s == history.back(1));
  assert("yandex.ru"s == history.forward(1));
  history.visit("gnu.org"s);
  assert("gnu.org"s == history.forward(2));
  assert("google.com"s == history.back(2));
  assert("leetcode.com"s == history.back(7));

}

int main() {
  Test1();
  std::cout << "Ok!" << std::endl;
  return 0;
}

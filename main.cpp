#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class BrowserHistory {
  vector<string> history;
  int current = 0;
 public:
  BrowserHistory(string homepage) {
    history.push_back(homepage);
  }

  void visit(string url) {
    history.resize(current + 1);
    history.push_back(url);
    ++current;
  }

  string back(int steps) {
    while (0 < steps && 0 < current) {
      --current;
      --steps;
    }

    return history[current];
  }

  string forward(int steps) {
    while (0 < steps && current < history.size() - 1) {
      --steps;
      ++current;
    }

    return history[current];
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

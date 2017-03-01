#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

void print(int tree[100]) {
  for (int i = 0; i < 100 && tree[i] != 0; i++) {
    std::cout << tree[i] << " " << (floor(log2(tree[i])) == log2(tree[i])) ? "\n" : "" << std::flush;
  }
}

int main (int argc, char* argv[]) {
  int nums = new int[100];
  int tree = new int[100];

  memset(nums, 0, sizeof int);
  memset(tree, 0, sizeof int);

  if (argc == 1) {  //Manual input
    std::cout << "Enter integers separated by newlines.
    q to finish" << std::endl;

    bool finished = false;
    int i = 0;
    while (!finished) {
      std::string line;
      std::cin >> line;
      try {
        nums[i++] = line.stoi();
      } catch (const std::exception &e) {
        finished = true;
      }
    }
  }

  if (argc == 2) {  //File input
    std::ifstream numfile;

    try {
      numfile.open(argv[1]);
    } catch (const std::exception &) {
      std::cout << "Use: " << argv[0] << " <filepath>" << std::endl;
      return 1;
    }

    bool finished = false;
    int i = 0;
    while (!finished) {
      std::string line;
      numfile >> line;
      try {
        nums[i++] = line.stoi();
      } catch (const std::exception &e) {
        finished = true;
      }
    }

  }

  if (argc > 2) { //Improperly called
    std::cout << "Use: " << argv[0] << " <filepath>" << std::endl;
  }

  /*Fill the tree with input*/
  int end = 0;
  for (int i = 0; i < 100; i++) {
    
  }


}

/*Implementation of a max heap
* Takes 100 numbers, from input or a file
* Puts into a max heap, prints representation, and removes
* and prints numbers max to min
* Note: In the array storing the tree, index 1 is root
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

void print(int tree[]) {
  int level = 0;
  int nextbreak = 1;
  for (int i = 1; i < 101 && tree[i] != 0; i++) {
    std::cout << tree[i] << std::flush;
	if (i == nextbreak) {
		std::cout << std::endl;
		nextbreak += pow(2, ++level);
	}
  }
}

int main (int argc, char* argv[]) {
  int* nums = new int[101];	//Numbers to put into heap
  int* tree = new int[101];	//Binary tree of heap in array form
  int len;	//Size of heap

  if (argc == 1) {  //Manual input
    std::cout << "Enter integers separated by newlines. q to finish" << std::endl;

    bool finished = false;
    int i = 0;
    while (!finished) {
      int num;
      std::cin >> num;
			if (std::cin.fail()) {
				finished = true;
				std::cin.clear();
			}
			i++;
			if (i = 102) {
				finished = true;
			}
    }
		len = i-2;
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
    int i = 1;
    while (!finished) {
      int num;
      numfile >> num;
			if (std::cin.fail()) {
				finished = true;
				std::cin.clear();
			}
			i++;
			if (i = 102) {
				finished = true;
			}
    }
		len = i-2;
  }

  if (argc > 2) { //Improperly called
    std::cout << "Use: " << argv[0] << " <filepath>" << std::endl;
  }

  /*Fill the tree with input*/
  for (int i = 1; i <= len+1; i++) {	//For each number
    int n = i;	//The current location of the newest number
	tree[i] = nums[i];	//Add to end
	while (n!=1 && tree[n] > tree[n/2]) {	//Percolate up
	  int temp = tree[n/2];
	  tree[n/2] = tree[n];
	  tree[n] = temp;
	  n /= 2;
	}
  }
  
  print(tree);  //Print the complete tree
  
  /*Print out the tree max to min*/
  for (int i = 0; i < len-1; i++) {	//For each number, exept last
    std::cout << tree[1] << std::endl;
		int n = 1;	//Location of number being percolated (the one that used to be last)
		tree[n] = tree[len-i+1];	//Set root to last
		bool finished = false;
		while (!finished) {
			int rightmore = 0, leftmore = 0;
			if (2*n <= len)
				leftmore = tree[2*n] - tree[n];
			if (2*n+1 <= len)
				rightmore = tree[2*n+1] - tree[n];
			
			if (rightmore || leftmore) {
				int child = rightmore > leftmore;
				int temp = tree[2*n+child];
				tree[2*n+child] = tree[n];
				tree[n] = temp;
				n = 2*n+child;
			}
			else
				finished = true;
		}
		std::cout << tree[i] << std::endl;	//Print last one
	}
}
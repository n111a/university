#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "WordGenerator.h"
#pragma warning(disable : 4996)
using namespace std;

void WordGenerator::generator(int n, int size, char* file) {
   // srand(time(NULL));
    freopen("./in.txt", "w", stdout);
    string word;
    for (int i = 0, j = 0; i < n; i++) {
        //j = rand() % size + 1;
        word = "";
        for (int k = 0; k < size; k++) {
           word += (char)(rand() % 26 + 97);
        }
        cout << word<< endl;
    }


  
}
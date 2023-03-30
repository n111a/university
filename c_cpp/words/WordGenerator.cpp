#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include"WordGenerator.h"
#pragma warning(disable : 4996)
using namespace std;

void WordGenerator::generator_of_first_word(int size, char* file) {
    srand(time(NULL));
    ofstream fout(file, ios_base::app);

    string text;

    for (int k = 0; k < size; k++) {
        text += (char)(rand() % 26 + 97);
    }
    fout << text << endl;
    fout.close();
}

void WordGenerator::generator(int n, int size, char* file) {
    srand(time(NULL));
    ofstream fout(file, ios_base::app);

    string text;

    for (int i = 0, j = 0; i < n; i++) {
        j = rand() % (size / 2) + 1;

        for (int k = 0; k < j; k++) {
            text += (char)(rand() % 26 + 97);
        }
        text += ' ';
    }


    fout << text << endl;
    fout.close();
}
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include"WordGenerator.h"
#pragma warning(disable : 4996)
using namespace std;

size_t global_count = 0;
size_t n_global = 1;

int n_generator(char* file) {
    int n;
    ofstream fout(file, ios_base::app);
    srand(time(NULL));
    //n = rand() % 1000 + 1;
    n = n_global;
    fout << n << endl;
    //fout.close();
    return n;
}

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int count = 0, i, j = 0, n, size = rand() % 1000 + 1;
    string first, second;
    WordGenerator generator;

    //n = n_generator(argv[1]);

    ifstream fin(argv[1], ios_base::app);
    ofstream fout(argv[2], ios_base::app);
    ofstream time(argv[3], ios_base::app);
    ofstream steps(argv[4], ios_base::app);
    for (int l = 3; l < 10000; l += 100) {
        global_count = 0;
        size = l;
        n = n_generator(argv[1]);
        generator.generator_of_first_word(size, argv[1]);
        generator.generator(n, size, argv[1]);
        unsigned int start_time = clock(); // начальное время

        fin >> n;
        fin >> first;
        int flag = 1, k = 0;
        for (i = 0; i < n; i++)
        {
            fin >> second;
            for (j = 0; j < first.size(); j++)
            {
                flag = 1;
                if (second.size() < first.size() - j)
                {
                    for (k = 0; k < second.size(); k++)
                    {
                        if (first[j + k] != second[k])
                        {
                            global_count++;
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 1)
                        count++;
                }
                global_count += first.size() + 1;
            }
        }

        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time; // искомое время
        fout << count << endl;
        time << search_time << endl;
        steps << global_count << endl;
        n_global++;
    }
    //fin.close();
    //fout.close();
    return 0;
}
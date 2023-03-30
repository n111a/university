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

int global_n = 500000;
int global_size = 500;
int n_generator(char* file) {
    int n=global_n;
    return n;
}

int main(int argc, char* argv[])
{
    int i = 0, j = 0, n, cur, size;
    int max_meaning = 512;
    int* count = new int[max_meaning];
    string* dictionary;
    WordGenerator generator;
    n = global_n;
    size = global_size;
    generator.generator(n, size, argv[1]);
    dictionary = new string[n];
    freopen("./in.txt", "r", stdin);
    for (i = 0; i < max_meaning; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        cin >> dictionary[i];

    srand(time(NULL));
    unsigned int start_time;
    unsigned int end_time;
    unsigned int search_time;
    unsigned int steps;
    // Hash #1
    start_time = clock();
    steps = 0;
    for (i = 0; i < n; i++)
    {
        cur = 0;
        for (j = 0; j < dictionary[i].length(); j++)
        {
            cur = cur * 31 + ((dictionary[i][j]) - 'a' + 1);
            steps++;
        }
        cur = cur % max_meaning;
        count[cur]++;
    }

    freopen("./out1.txt", "w", stdout);
    end_time = clock();
    search_time = end_time - start_time;
    cout << "time:" << search_time << "   steps: " << steps <<endl;

    for (i = 0; i < max_meaning; i++)
    {
        cout << count[i] << endl;
        count[i] = 0;
    }
    // Hash #2
    start_time = clock();
    steps = 0;
    for (i = 0; i < n; i++)
    {
        cur = 0;
        for (j = 0; j < dictionary[i].length(); j++)
        {
            cur = cur * 19 + 2711 % ((dictionary[i][j]) - 'a' + 1);
            steps++;
        }
        cur = cur % max_meaning;
        count[cur]++;
    }
    freopen("./out2.txt", "w", stdout);
    end_time = clock();
    search_time = end_time - start_time;
    cout << "time:" << search_time << "   steps: " << steps << endl;
    for (i = 0; i < max_meaning; i++)
    {
        cout << count[i] << endl;
        count[i] = 0;
    }
    // Hash #3
    start_time = clock();
    steps = 0;
    for (i = 0; i < n; i++)
    {
        cur = 0;
        for (j = 0; j < dictionary[i].length(); j++)
        {
            cur = cur * 13 + ((dictionary[i][j]) - 'a' + 1);
            steps++;
        }
        cur = cur % max_meaning;
        count[cur]++;
    }
    freopen("./out3.txt", "w", stdout);
    end_time = clock();
    search_time = end_time - start_time;
    cout << "time:" << search_time << "   steps: " << steps << endl;
    for (i = 0; i < max_meaning; i++)
    {
        cout << count[i] << endl;
        count[i] = 0;
    }
    // Hash #4
    start_time = clock();
    steps = 0;
    for (i = 0; i < n; i++)
    {
        cur = 1549;
        for (j = 0; j < dictionary[i].length(); j++)
        {
            cur = cur * 37 + dictionary[i][j];
            steps++;
        }
        cur = cur % max_meaning;
        count[cur]++;
    }
    freopen("./out4.txt", "w", stdout);
    end_time = clock();
    search_time = end_time - start_time;
    cout << "time:" << search_time << "   steps: " << steps << endl;
    for (i = 0; i < max_meaning; i++)
    {
        cout << count[i] << endl;
        count[i] = 0;
    }
    // Hash #5
    start_time = clock();
    steps = 0;
    for (i = 0; i < n; i++)
    {
        cur = 0;
        for (j = 0; j < dictionary[i].length(); j++)
        {
            cur = cur * 2 + ((dictionary[i][j]) - 'a' + 1);
            steps++;
        }
        cur = cur % max_meaning;
        count[cur]++;
    }
    freopen("./out5.txt", "w", stdout);
    end_time = clock();
    search_time = end_time - start_time;
    cout << "time:" << search_time << "   steps: " << steps << endl;
    for (i = 0; i < max_meaning; i++)
        cout << count[i] << endl;

   
    return 0;
}
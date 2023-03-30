#include<iostream>
#include <string>
#include <vector>
using namespace std;

char rom_nums[7] = { 'I','V','X','L', 'C', 'D', 'M' };
int ar_nums[7] = { 1, 5, 10, 50, 100, 500, 1000 };
vector <int> numbers;
vector <char> operations;
int rom_to_ar(string rom_num)
{
    int num = 0;
    int t = 0;
    int j = 0;
    int i = 0;
    int len = 0;
    
    num = 0; len = rom_num.length();
    for (i = len - 1, t = 0; i >= 0; --i)
    {
        for (j = 0; j < 7; ++j)
            if (rom_nums[j] == rom_num[i])
                break;

        if (ar_nums[j] < t)
            num -= (t = ar_nums[j]);
        else
            num += (t = ar_nums[j]);
    }
    return num;
}
string create_task(string inp)
{
    
    int curr;
    string num = "", task = "";
    for (int i = 0; i < inp.length(); i++)
    {
        if (inp[i] != '+' && inp[i] != '-' && inp[i] != '/' && inp[i] != '*')
        {
            num += inp[i];
        }
        else
        {
            curr = rom_to_ar(num);
            numbers.push_back(curr);
            num = "";
            task += to_string(curr) + inp[i];
            operations.push_back(inp[i]);
        }

    }
    curr = rom_to_ar(num);
    numbers.push_back(curr);
    num = "";
    task += to_string(curr);
    return task;
}
int calc(string task)
{
    int curr = 0;
    int i = 0;
    while(operations.size() > 0)
    { 
        if (operations[i] == '/' || operations[i] == '*' || i == operations.size()-1)
        {
            switch (operations[i])
            {
                case '+': if (i > 0) 
                        {
                        if (operations[i - 1] != '-') { numbers[i] = numbers[i] + numbers[i + 1]; }
                        else { numbers[i] = numbers[i + 1] - numbers[i]; operations[i - 1] = '+'; }
                        }
                     else { numbers[i] = numbers[i] + numbers[i + 1]; } break;
                case '-': if (i > 0)
                {
                    if (operations[i - 1] != '-') { numbers[i] = numbers[i] - numbers[i + 1]; }
                    else { numbers[i] = numbers[i + 1] + numbers[i];}
                }
                        else { numbers[i] = numbers[i] - numbers[i + 1]; }  break;
                case '*': numbers[i] = numbers[i] * numbers[i + 1];  break;
                case '/': numbers[i] = numbers[i] / numbers[i + 1]; break;
            }
            operations.erase(operations.begin() + i);
            numbers.erase(numbers.begin() + i + 1);
            i = 0;
            continue;
        } 
        i++;
    }
    return numbers[0];
}
string ar_to_rom(int ans)
{
    int i = 0;
    int num = 0;
    string rom_ans="";
    num = ans;
    for (i = 6; i >= 0; --i)
    {
        while (num >= ar_nums[i])
        {
            if ((num >= ar_nums[i-1]*9 ) &&(i==1 || i==3 || i == 5) )
            {
                num -= ar_nums[i-1] * 9;
                rom_ans += rom_nums[i - 1];
                rom_ans += rom_nums[i + 1];
            }
            else
            {
                num -= ar_nums[i];
                rom_ans += rom_nums[i];
            }
        }
    }

    return rom_ans;
}
int main()
{
    string inp;
    cin >> inp;
    string task = create_task(inp);
    cout << task << "=";
    int ar_ans = calc(task);
    cout << ar_ans << endl;
    string rom_ans = ar_to_rom(ar_ans);
    cout << rom_ans;
}
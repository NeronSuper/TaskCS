#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>


using namespace std;

vector<string> split(const string& numbers)
{
    vector<string> nums;

    stringstream ss(numbers);
    string word;
    while (ss >> word) {
        nums.push_back(word);
    }

    return nums;
}


int chToInt(char num)
{
    if (num >= '0' && num <= ':')
        return num - 48;
    if (num >= 'A' && num <= '[')
        return num - 55;
}

char intToStr(int num)
{
    if (num >= 0 && num <= 9)
    {
        return num + 48;
    }
    else
    {
        return num + 55;
    }
}

int toDecimal(const string& num, int base)
{
    int index = 0, value = 0;

    for (auto i = num.rbegin(); i != num.rend(); ++i, ++index)
    {
        value += pow(base, index) * chToInt(*i);
    }

    return value;
}

string toStr(int num, int base)
{
    string value;

    while (num != 0)
    {
        value.insert(value.begin(), intToStr(num % base));
        num /= base;
    }

    return value;
}



string translate(string& numbers, int base)
{
    vector<string> nums = move(split(numbers));

    int value = toDecimal(nums[0], base);

    for (int i = 1; i < nums.size(); ++i)
    {
        value += toDecimal(nums[i], base);
    }

    return toStr(value, base); // fix
}

int main()
{
    int t;
    cin >> t;
    cin.clear();
    
    while (t--)
    {
        char base;
        cin >> base;

        string numbers;
        cin.ignore();
        getline(cin, numbers);

        cout << translate(numbers, chToInt(base + 1)) << '\n';
    }

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>
#include "../inc/Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string, size_t> word_count;
    set<string> exclude{"the", "The", "And", "and", "Or", "or", "But", "but", "An", "an"};
    string word;

    while (cin >> word)
    {
        if (exclude.find(word) == exclude.end())
        {
            auto ret = word_count.insert({word, 1});
            if (!ret.second)
            {
                ret.first->second++;
            }
        }
    }

    for_each(word_count.cbegin(), word_count.cend(), [](const pair<string, size_t> &i)
             { cout << i.first << ends << i.second << endl; });

    return 0;
}
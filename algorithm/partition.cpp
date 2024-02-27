#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool prviot(const string &s)
{
    return s.size() >= 5;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.cend());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2)
                { return s1.size() < s2.size(); });

    auto wc = stable_partition(words.begin(), words.end(), [sz](const string &s)
                        { return s.size() >= sz; });

    auto count = words.end() - wc;
    for_each(wc, words.end(), [](const string &s)
             { cout << s << ends; });
}

int main(int argc, char const *argv[])
{
    vector<string> words;
    biggies(words = {"word", "red", "www", "red", "tea", "word", "over", "apple"}, 4);

    return 0;
}
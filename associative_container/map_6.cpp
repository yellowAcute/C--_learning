#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>
#include "../inc/Sales_data.h"
using namespace std;

// 建立单词转换map容器
map<string, string> buildMap(ifstream &input)
{
    map<string, string> map_trans;
    string key, value;

    while (input >> key && getline(input, value))
    {
        if (value.size() > 1)
        {
            map_trans[key] = value.substr(1);
        }
        else
            throw runtime_error("no rule for " + key);
    }
    return map_trans;
}

// 输出转换后的单词
const string &display(map<string, string> &m, const string &word)
{

    if (m.find(word) == m.end())
    {
        return word;
    }
    else
        // 下标运算符只能对非const的map使用
        return m[word];
}

// 对转换的文本中的每个单词，对着映射map进行转换
void transform(ifstream &map_file, ifstream &input)
{
    // 建立转换map容器
    auto trans_map = buildMap(input);

    string text;
    // 读取文本中每一行字符串
    while (getline(map_file, text))
    {
        // 读取每一行中每一个单词，查找map是否有对应的转换单词
        istringstream is(text);
        string word;
        bool firstword = true;
        while (is >> word)
        {
            if (firstword)
            {
                firstword = false;
            }
            else
            {
                cout << ends;
            }
            cout << display(trans_map, word);
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{

    ifstream input("D:/transform.txt");
    ifstream map_file("D:/map_file.txt");

    transform(map_file, input);

    return 0;
}
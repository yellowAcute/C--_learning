#include "../inc/Bulk_quote.h"
#include <algorithm>
#include <vector>
#include <memory>

int main(int argc, char const *argv[])
{
    // vector中存放是指向Quote类型的指针，那么会有指向的对象存在动态，静态类型的区别
    // 根据对象的动态类型调用对应类型的成员函数
    vector<shared_ptr<Quote>> p;

// 动态类型为Bulk_quote类型的指针，调用Bulk_quote其中的构造函数
    p.push_back(make_shared<Bulk_quote>("111", 20, 10, .25));
    // 调用Quote类中构造函数，
    p.push_back(make_shared<Quote>("222", 20));

    double total_price = 0;
    total_price = p[0]->net_price(20);
    cout << total_price << endl;


    for (auto &&i : p)
    {
        // 实际调用的net_price函数版本取决于指针指向的动态类型
        total_price += i->net_price(20);
    }

    cout << total_price << endl;

    return 0;
}

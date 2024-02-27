#if !defined(BULK_QUOTE_H)
#define BULK_QUOTE_H
#include "../inc/Disc_quote.h"

class Bulk_quote : public Disc_quote 
{
private:
 
public:
    Bulk_quote() = default;
    // Bulk_quote(const string &, double, size_t, double);
    void debug() const override;
    
    // 使用using声明构造函数等价于生成下方的构造函数，编译器产生下方代码,
    // 形参列表与using声明的构造函数中的形参类型相同
    using Disc_quote::Disc_quote;

    double net_price(size_t) const override;
};

void Bulk_quote::debug() const
{
    // 调用基类的debug（）函数
    Quote::debug();
    cout << "min_qty = " << quantity 
        << "\tdiscount = " << discount << endl;
}

// Bulk_quote::Bulk_quote(const string &book, double p,
//                        size_t qty, double disc) :
//                        Disc_quote(book, p, qty, disc) {}

// 虚函数，基类中的函数重新定义过
double Bulk_quote::net_price(size_t n) const
{
    if (n >= quantity)
    {
        return n * (1 - discount) * price;
    }
    else
    {
        return n * price;
    }
}

#endif // BULK_QUOTE_H

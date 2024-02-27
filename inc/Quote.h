#if !defined(QUOTE_H)
using namespace std;
#include <string>
#include <iostream>
#define QUOTE_H

class Quote
{
private:
    string bookNo;

protected:
    double price = 0;

public:
    Quote() = default;
    virtual ~Quote() = default;
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const;

    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
    string isbn() const { return bookNo; }
};

#endif // QUOTE_H

void Quote::debug() const{
    cout << "ISBN = " << bookNo << "\tprice = " << price << endl;

}


double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    cout << "ISBN: " << item.isbn()
         << " #sold: " << n << " total due: " << ret << endl;
}

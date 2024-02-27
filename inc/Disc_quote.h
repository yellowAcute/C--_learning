#if !defined(DISC_QUOTE_H)
#define DISC_QUOTE_H
#include "../inc/Quote.h"



class Disc_quote : public Quote
{
protected:
    size_t quantity = 0;
    double discount = 0;
                
    
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double price, size_t qty, double disc):
                Quote(book, price), 
                quantity(qty), discount(disc){ }
    
    //  =0 定义为纯虚函数，只能在类内部声明
    double net_price(size_t t) const = 0;
    virtual ~ Disc_quote() = default;
};



#endif // DISC_QUOTE_H

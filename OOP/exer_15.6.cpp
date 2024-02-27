#include "../inc/Bulk_quote.h"

int main(int argc, char const *argv[])
{
    Quote q("aaa", 10);
    Bulk_quote bq("bbb", 20, 10, 0.8);

    // 抽象类类型不能创建对象
    // Disc_quote dq;

    print_total(cout, q, 20);
    print_total(cout, bq, 20);

    q.debug();
    bq.debug();

    return 0;
}

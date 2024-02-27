#include ".\inc\Range_Plane_total.h"
using namespace std;

// 计算飞机与HM之间的直线作用距离（km），波长：8~12um, summer，时间：24：00, 探测概率：50%
int main(int argc, char const *argv[])
{

    //  HM与飞机之间的直线距离
    getDistance(Range_plane_HM, Distance);

    auto j = MRTD;
    for (f = 1; f < 8; f += 0.5)
    {
        MRTD_x_2 = *(*j + 0);
        MRTD_y_2 = *(*j + 1);


        //  最小分辨温差作用距离公式
        getRange(f, 50);
        j++;
    }

    return 0;
}

#include ".\inc\Range_Plane_total.h"
using namespace std;

// ����ɻ���HM֮���ֱ�����þ��루km����������8~12um, summer��ʱ�䣺24��00, ̽����ʣ�50%
int main(int argc, char const *argv[])
{

    //  HM��ɻ�֮���ֱ�߾���
    getDistance(Range_plane_HM, Distance);

    auto j = MRTD;
    for (f = 1; f < 8; f += 0.5)
    {
        MRTD_x_2 = *(*j + 0);
        MRTD_y_2 = *(*j + 1);


        //  ��С�ֱ��²����þ��빫ʽ
        getRange(f, 50);
        j++;
    }

    return 0;
}

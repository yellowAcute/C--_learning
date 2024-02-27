#include ".\inc\Range_Plane_total.h"
using namespace std;

// ����ɻ���HM֮���ֱ�����þ��루km����������8~12um, summer��ʱ�䣺24��00, ̽����ʣ�?50%
int main(int argc, char const *argv[])
{

    selectPrecent(50);

    for (auto &&s : stripe)
    {
        cout << "ne = " << s << endl;
        getMRTD(287.21, s);
    }

    return 0; 
}
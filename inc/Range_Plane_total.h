#ifndef RANGE_PLANE_H
#define RANGE_H

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#define TL 300

// HM的长、高、宽
double Length = 340.469, Height = 48.21, Witdh = 83.7035;

// 作用距离
double plane_range = 0;

//  x、y方向上的MRTD, 空间频率：2
double f, MRTD_x_2, MRTD_y_2;

// 海天背景, HM的整体温度, 12：00，total—speed， summer
// double Temp_HM_total = 312.85, Temp_sea_sky = 303.85;

// 海天背景, HM的整体温度, 12：00，xunhang， summer
double Temp_HM_total = 317.8097, Temp_sea_sky = 303.85;

// 背景温度，HM左右弦温度，12：00，summer，单位：K
// double T_HM_left = 312.25, TB = 311.15, T_HM_right = 313.05, T_HM_broad = 323.25;
// double T_HM_left = 303.7578, TB = 300.4115, T_HM_right = 303.7578, T_HM_broad = 323.25;

// 背景温度，HM左右弦, 甲板温度，时间12月20号12：00， winter，单位：K
// double T_HM_left = 289.25, TB = 288.15, T_HM_right = 298.95, T_HM_broad = 296.85;

// 背景温度，HM左右弦温度，24：00，summer，单位：K
// double T_HM_left = 312.25, TB = 309.75, T_HM_right = 313.05, T_HM_broad = 323.25;

// 背景温度，HM左右弦, 甲板温度，时间12月20号24：00， winter，单位：K
// double T_HM_left = 289.25, TB = 285.05, T_HM_right = 298.95, T_HM_broad = 296.85;

// 实际MRTD
double MRTD_x = 0, MRTD_y = 0;

// HM与飞机的高度 km
const double plane_altitude = 3;

// 大气透过率的临界条件
double temp_x = 0, temp_y = 0;

//  信噪比
double SNR, SNR_DT = 2.8;

//  飞机——HM之间的直线距离
vector<double> Distance(10);

// plane，summer，8-12um
// 探测概率80% 50%下的条带数
vector<double> stripe(3);
int precent;

//  HM整体温度与海天背景温度温差
const double T_gap_sea_sky = abs(Temp_HM_total - Temp_sea_sky);

// const double T_gap_Left_background = abs(T_HM_left - TB);
// const double T_gap_Right_background = abs(T_HM_right - TB);
// const double T_gap_Broad_background = abs(T_HM_broad - TB);

//  plane，summer， 8-12um
// vector<double> transmission = {0.4965, 0.308, 0.1947, 0.1256, 0.0805, 0.0532, 0.0356, 0.0241, 0.0165, 0.0115};

//  plane， winter, 8-12um
// vector<double> transmission = {0.7964, 0.6827, 0.5912, 0.5163, 0.4447, 0.3896, 0.3427, 0.3023, 0.2676, 0.2375};

//  plane , summer, 12:00, air transmission, new
vector<double> transmission{0.7750, 0.6461, 0.5812, 0.5284, 0.4841, 0.4463, 0.4135, 0.3847, 0.3590, 0.3361};

// plane与HM的水平距离
vector<int> Range_plane_HM = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

// 不同频率的xy方向MRTD
double MRTD[][2] = {0.0346, 0.0344, 0.0604, 0.0598, 0.0974, 0.0957, 0.1527, 0.1486, 0.2381, 0.2289, 0.3738, 0.3545,
                    0.5963, 0.5562, 0.9733, 0.8913, 1.6388, 1.4701, 2.8750, 2.5210, 5.3332, 4.5611, 10.7282, 8.9293,
                    24.6729, 19.9424, 75.9837, 59.5115};

void selectPrecent(const int &precent)
{
    switch (precent)
    {
    case 80:
    {
        stripe = {1.5, 6, 12};
        SNR = 3.4;
    }
    break;
    case 50:
    {
        stripe = {1, 4, 6};
        SNR = 2.8;
    }
    break;
    }
}

// x方向的修正因子
double getM_X(int ne)
{
    return 2 * ne * Witdh / Height;
}

// y方向的修正因子
double getM_Y(int ne)
{
    return 2 * ne * Height / Length;
}

// 计算HM的左、右舷的大气透过率最小值
void transmissionMin(double t)
{

    temp_x = MRTD_x / t;
    temp_y = MRTD_y / t;

    cout << "大气透过率x >= " << temp_x << endl;
    cout << "大气透过率y >= " << temp_y << endl;
}

void getDistance(vector<int> &Range_plane_HM, vector<double> &Distance)
{
    for (size_t i = 0; i < Range_plane_HM.size(); i++)
    {
        Distance[i] = sqrt(pow(Range_plane_HM[i], 2) + pow(plane_altitude, 2));
    }
}

void getMRTD(const double &Temp_sea_sky, const int &s)
{
    auto j = MRTD;
    double m_x = getM_X(s);
    double m_y = getM_Y(s);

    for (double f = 1; f < 8; f += 0.5)
    {
        MRTD_x_2 = *(*j + 0);
        MRTD_y_2 = *(*j + 1);

        //  计算修正后的MTRD
        MRTD_x = sqrt(7 / m_x) * (SNR / SNR_DT) * pow(Temp_sea_sky / TL, 2) * MRTD_x_2;
        MRTD_y = sqrt(7 / m_y) * (SNR / SNR_DT) * pow(Temp_sea_sky / TL, 2) * MRTD_y_2;

        cout << "f = " << f << "\t";
        cout << "MRTD x = " << MRTD_x << "\t"
             << "MRTD y = " << MRTD_y << endl;
        j++;
    }
    cout << endl;
}

//  计算最小分辨温差作用距离公式
void getRange(double &f, const int &precent)
{

    selectPrecent(precent);

    cout << "summer, 时间7月20号12:00, 飞机——HM, 巡航, TOTAL_COMPUTE"
         << "\n空间频率: " << f
         << "\n探测概率: " << precent << "%" << endl
         << endl;
    for (auto s : stripe)
    {
        //  计算尺寸修正因子
        double m_x = getM_X(s);
        double m_y = getM_Y(s);

        //  计算修正后的MTRD
        MRTD_x = sqrt(7 / m_x) * (SNR / SNR_DT) * pow(Temp_sea_sky / TL, 2) * MRTD_x_2;
        MRTD_y = sqrt(7 / m_y) * (SNR / SNR_DT) * pow(Temp_sea_sky / TL, 2) * MRTD_y_2;

        // 直线作用距离的临界条件
        double heightMax = f * Height / s;

        cout << "ne = " << s << endl;
        cout << "直线最大距离 <= " << heightMax << "km" << endl;

        cout << "MRTD x方向:" << MRTD_x << endl;
        cout << "MRTD y方向:" << MRTD_y << endl;

        // HM的整体温度MRTD的临界条件
        cout << "HM的total温度计算: " << endl;
        transmissionMin(T_gap_sea_sky);

        for (int i = Range_plane_HM.size() - 1; i >= 0; i--)
        {
            if (Range_plane_HM[i] <= heightMax)
            {
                cout << "水平作用距离R = " << Range_plane_HM[i] << "km"
                     << ", 直线距离 = " << Distance[i] << "km"
                     << ", 大气透过率：" << transmission[i] << endl;
                cout << endl;

                break;
            }
        }

        cout << endl;
    }
}

#endif // RANGE_H

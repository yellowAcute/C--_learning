#ifndef RANGE_MISSILE_H
#define RANGE_MISSILE_H

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#define TL 300

// HM的长、高、宽
double Length = 340.469, Height = 48.21, Witdh = 83.7035;

//  x、y方向上的MRTD, 空间频率：2
double f, MRTD_x_2, MRTD_y_2;

// 背景温度，HM左右弦，甲板温度，时间7月20号12：00，summer，单位：K
// double T_HM_left = 312.25 , TB=311.15 , T_HM_right=313.05, T_HM_broad = 323.25;

// 背景温度，HM左右弦, 甲板温度，时间12月20号12：00， winter，单位：K
// double T_HM_left = 289.25, TB = 288.15, T_HM_right = 298.95, T_HM_broad = 296.85;


// 背景温度，HM左右弦温度，24：00，summer，单位：K
// double T_HM_left = 312.25, TB = 309.75, T_HM_right = 313.05, T_HM_broad = 323.25;


// 背景温度，HM左右弦, 甲板温度，时间12月20号24：00， winter，单位：K
double T_HM_left = 289.25, TB = 285.05, T_HM_right = 298.95, T_HM_broad = 296.85;


// 实际MRTD
double MRTD_x = 0, MRTD_y = 0;

// HM与导弹的高度 m
const double missile_altitude = 0.01;

// 大气透过率的临界条件
double temp_x = 0, temp_y = 0;

//  信噪比
double SNR, SNR_DT = 2.8;

// 导弹——HM之间的直线距离
vector<double> Distance(4);

// missile，8-12um
// 探测概率80% 50%下的条带数
vector<double> stripe(3);
int precent;

//  HM左右舷与背景温度温差
const double T_gap_Left_background = abs(T_HM_left - TB);
const double T_gap_Right_background = abs(T_HM_right - TB);
const double T_gap_Broad_background = abs(T_HM_broad - TB);

//  missile, winter , 8-12um
vector<double> transmission = {0.6819, 0.499, 0.3722, 0.2809};

// missile, summer, 8-12um
// vector<double> transmission={0.2645, 0.0894, 0.0329, 0.0128};



// missile与HM的水平距离
vector<int> Range_Missile_HM = {5, 10, 15, 20};

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

void getDistance(vector<int> &Range_Missile_HM, vector<double> &Distance)
{
    for (size_t i = 0; i < Range_Missile_HM.size(); i++)
    {
        Distance[i] = sqrt(pow(Range_Missile_HM[i], 2) + pow(missile_altitude, 2));
    }
}

//  计算最小分辨温差作用距离公式
void getRange(double &f, const int &precent)
{

    selectPrecent(precent);

    cout << "winter, 时间12月20号24:00, 导弹——HM, 全速"
         << "\n空间频率: " << f
         << "\n探测概率: " << precent << "%" << endl
         << endl;
    for (auto s : stripe)
    {
        //  计算尺寸修正因子
        double m_x = getM_X(s);
        double m_y = getM_Y(s);

        //  计算修正后的MTRD
        MRTD_x = sqrt(7 / m_x) * (SNR / SNR_DT) * pow(TB / TL, 2) * MRTD_x_2;
        MRTD_y = sqrt(7 / m_y) * (SNR / SNR_DT) * pow(TB / TL, 2) * MRTD_y_2;

        // 直线作用距离的临界条件
        double heightMax = f * Height / s;

        cout << "ne = " << s << endl;
        cout << "直线最大距离 <= " << heightMax << "km" << endl;

        cout << "MRTD x方向:" << MRTD_x << endl;
        cout << "MRTD y方向:" << MRTD_y << endl;

        // HM的左右舷MRTD的临界条件
        cout << "HM左舷温度计算: " << endl;
        transmissionMin(T_gap_Left_background);
        cout << "HM右舷温度计算: " << endl;
        transmissionMin(T_gap_Right_background);
        cout << "HM甲板温度计算: " << endl;
        transmissionMin(T_gap_Broad_background);

        for (int i = Distance.size() - 1; i >= 0; i--)
        {
            if (Distance[i] <= heightMax)
            {
                cout << "水平作用距离R = " << Range_Missile_HM[i] << "km"
                     << ", 直线距离 = " << Distance[i] << "km"
                     << ", 大气透过率：" << transmission[i] << endl;
                cout << endl;

                break;
            }
        }

        cout << endl;
    }
}

#endif // RANGE_MISSILE_H

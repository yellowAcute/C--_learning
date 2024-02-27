#ifndef RANGE_MISSILE_H
#define RANGE_MISSILE_H

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#define TL 300

// HM�ĳ����ߡ���
double Length = 340.469, Height = 48.21, Witdh = 83.7035;

//  x��y�����ϵ�MRTD, �ռ�Ƶ�ʣ�2
double f, MRTD_x_2, MRTD_y_2;

// �����¶ȣ�HM�����ң��װ��¶ȣ�ʱ��7��20��12��00��summer����λ��K
// double T_HM_left = 312.25 , TB=311.15 , T_HM_right=313.05, T_HM_broad = 323.25;

// �����¶ȣ�HM������, �װ��¶ȣ�ʱ��12��20��12��00�� winter����λ��K
// double T_HM_left = 289.25, TB = 288.15, T_HM_right = 298.95, T_HM_broad = 296.85;


// �����¶ȣ�HM�������¶ȣ�24��00��summer����λ��K
// double T_HM_left = 312.25, TB = 309.75, T_HM_right = 313.05, T_HM_broad = 323.25;


// �����¶ȣ�HM������, �װ��¶ȣ�ʱ��12��20��24��00�� winter����λ��K
double T_HM_left = 289.25, TB = 285.05, T_HM_right = 298.95, T_HM_broad = 296.85;


// ʵ��MRTD
double MRTD_x = 0, MRTD_y = 0;

// HM�뵼���ĸ߶� m
const double missile_altitude = 0.01;

// ����͸���ʵ��ٽ�����
double temp_x = 0, temp_y = 0;

//  �����
double SNR, SNR_DT = 2.8;

// ��������HM֮���ֱ�߾���
vector<double> Distance(4);

// missile��8-12um
// ̽�����80% 50%�µ�������
vector<double> stripe(3);
int precent;

//  HM�������뱳���¶��²�
const double T_gap_Left_background = abs(T_HM_left - TB);
const double T_gap_Right_background = abs(T_HM_right - TB);
const double T_gap_Broad_background = abs(T_HM_broad - TB);

//  missile, winter , 8-12um
vector<double> transmission = {0.6819, 0.499, 0.3722, 0.2809};

// missile, summer, 8-12um
// vector<double> transmission={0.2645, 0.0894, 0.0329, 0.0128};



// missile��HM��ˮƽ����
vector<int> Range_Missile_HM = {5, 10, 15, 20};

// ��ͬƵ�ʵ�xy����MRTD
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

// x�������������
double getM_X(int ne)
{
    return 2 * ne * Witdh / Height;
}

// y�������������
double getM_Y(int ne)
{
    return 2 * ne * Height / Length;
}

// ����HM�������ϵĴ���͸������Сֵ
void transmissionMin(double t)
{

    temp_x = MRTD_x / t;
    temp_y = MRTD_y / t;

    cout << "����͸����x >= " << temp_x << endl;
    cout << "����͸����y >= " << temp_y << endl;
}

void getDistance(vector<int> &Range_Missile_HM, vector<double> &Distance)
{
    for (size_t i = 0; i < Range_Missile_HM.size(); i++)
    {
        Distance[i] = sqrt(pow(Range_Missile_HM[i], 2) + pow(missile_altitude, 2));
    }
}

//  ������С�ֱ��²����þ��빫ʽ
void getRange(double &f, const int &precent)
{

    selectPrecent(precent);

    cout << "winter, ʱ��12��20��24:00, ��������HM, ȫ��"
         << "\n�ռ�Ƶ��: " << f
         << "\n̽�����: " << precent << "%" << endl
         << endl;
    for (auto s : stripe)
    {
        //  ����ߴ���������
        double m_x = getM_X(s);
        double m_y = getM_Y(s);

        //  �����������MTRD
        MRTD_x = sqrt(7 / m_x) * (SNR / SNR_DT) * pow(TB / TL, 2) * MRTD_x_2;
        MRTD_y = sqrt(7 / m_y) * (SNR / SNR_DT) * pow(TB / TL, 2) * MRTD_y_2;

        // ֱ�����þ�����ٽ�����
        double heightMax = f * Height / s;

        cout << "ne = " << s << endl;
        cout << "ֱ�������� <= " << heightMax << "km" << endl;

        cout << "MRTD x����:" << MRTD_x << endl;
        cout << "MRTD y����:" << MRTD_y << endl;

        // HM��������MRTD���ٽ�����
        cout << "HM�����¶ȼ���: " << endl;
        transmissionMin(T_gap_Left_background);
        cout << "HM�����¶ȼ���: " << endl;
        transmissionMin(T_gap_Right_background);
        cout << "HM�װ��¶ȼ���: " << endl;
        transmissionMin(T_gap_Broad_background);

        for (int i = Distance.size() - 1; i >= 0; i--)
        {
            if (Distance[i] <= heightMax)
            {
                cout << "ˮƽ���þ���R = " << Range_Missile_HM[i] << "km"
                     << ", ֱ�߾��� = " << Distance[i] << "km"
                     << ", ����͸���ʣ�" << transmission[i] << endl;
                cout << endl;

                break;
            }
        }

        cout << endl;
    }
}

#endif // RANGE_MISSILE_H

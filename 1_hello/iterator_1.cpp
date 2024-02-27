#include <iostream>
#include <vector>
using   namespace std;



int main(int argc, char const *argv[])
{
    vector<unsigned> scores(11, 0);

    unsigned grade;
    while (cin >> grade )
    {
        if (grade <= 100)
        {
            ++*(scores.begin()+grade/10);
        }else if(grade == 'a'){
            break;
        }
    }
    
    for (auto i : scores)
    {
        cout << i << " ";
        
    }
    cout << endl;


    return 0;
}
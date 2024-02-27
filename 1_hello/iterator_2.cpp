#include <vector>
#include <iostream>
using   namespace std;



int main(int argc, char const *argv[])
{
    int  ia[3][4] = {0,1,2,3,
                    4,5,6,7,
                    8,9,10,11};


    for (int (&row)[4] : ia)
    {
        for (int &col : row)
        {
            cout << col << " ";
        }
        cout << endl;

    }

    for (size_t i = 0; i < sizeof(ia) / sizeof(ia[0]); i++)
    {
        for (size_t j = 0; j < sizeof(ia[0]) / sizeof(int); j++)
        {
            cout << ia[i][j] << " ";
        }
        cout << endl;
        
    }

    for (int (*i)[4] = ia; i != ia + sizeof(ia) / sizeof ia[0] ; i++)
    {
        for (int *j = *i; j != *i + sizeof ia[0] / sizeof(int) ; j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
    

    
    
    
    
                
                    


    return 0;
}
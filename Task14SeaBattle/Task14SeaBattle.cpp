#include <iostream>
#include <iomanip>
using namespace std;
void initial(string field[][11])
{
 for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {   
            if (i == 0)
            {   
                if(j==10)
                    field[i][j] = "10";
                else
                    field[i][j] = (int)'0' + j;
            }
            else if (j == 0 || j == 10&& i==0)
            {
                if (j == 0)
                {   
                    if(i==10 || j==10)
                        field[i][j] = "10";
                    else
                    field[i][j] = (int)'0' + i;
                }
                else
                    field[i][j] = "10";
            }
            else
                field[i][j] = ".";
        }
    }
}
void print(string field[][11], bool gemer)
{   
    if (gemer)
        cout << "\t\t1 player\n\n";
    else 
        cout << "\t\t2 player\n\n";
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cout << setw(2) << field[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "\t\tSea battle\n\n";
    string fieldОne[11][11];
    string fieldTwo[11][11];
    initial(fieldОne);
    initial(fieldTwo);
    print(fieldОne,true);
    cout << endl;
    print(fieldTwo,false);
}


#include <iostream>
#include <iomanip>
#include <vector>
#include<string>
using namespace std;
void initial(string field[][11]) // инициализация
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
void print(string field[][11], bool gemer)// печать массива
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
bool checkInput(string num, int position[],int size)  // Проверка ввода символов
{
    int a = 0,c=0;
    int b = 0;
    int var = 0;
    if (num.length() > 5)
        return false;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == ',' || num[i]=='.')
            b = i;
    }
    for (int i = 0; i < b; i++)
    {   
        if (num[i] < '0' || num[i]>'9')
            var++;
        else
        {
            a += (num[i] - '0')+(i*9);
        }
    }
   
    for (int i = b+1; i < num.length(); i++)
    {
        if (num[i] < '0' || num[i]>'9')
            var++;
        else
        {
            c += (num[i] - '0')+((i-(b+1))*9);
        }
    }
    position[0] = a;
    position[1] = c;
    if (var > 0||a>10||c>10)
        return false;
    else
        return true;
}

void ship(string field[][11])
{

}
int main()
{
    cout << "\t\tSea battle\n\n";
    string fieldОne[11][11];
    string fieldTwo[11][11];
    int position[2];
    initial(fieldОne);
    initial(fieldTwo);
    print(fieldОne,true);
    cout << endl;
    print(fieldTwo,false);
    string num;
    cin >> num;
    cout << checkInput(num, position,2) << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << position[i] << " ";
    }
}


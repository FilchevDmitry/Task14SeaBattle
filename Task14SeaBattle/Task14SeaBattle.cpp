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
bool checkInput(string num, int position[])  // Проверка ввода символов
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
    if (var > 0||a>10||c>10||a<1||c<1)
        return false;
    else
        return true;
}
void shipInitial(string field[][11],int a,int b, int c, int d, int len, bool hov)
{
    char R = 'O';
    if (len == 0)
        field[a][b] = R;
    else
    {
        if (hov)
        {
            for (int i = b; i < b+len; i++)
            {
                field[a][i] = R;
            }
        }
        else
        {
            for (int i = a; i < a + len; i++)
            {
                field[i][b] = R;
            }
        }
    }
}
void ship(string field[][11],int position[],bool gemer)
{   
    print(field, gemer);
    string num;
    int a=0, b=0, c=0, d=0, len=0;
    bool hov=true;
    cout << "Enter the coordinates ship (1,2 or 1.2) :";
    cin >> num;
    if (checkInput(num, position))
    {
        a = position[0];
        b = position[1];
        shipInitial(field,a, b, c, d, len, hov);
    }
}
int main()
{
    const int S = 2;                    // размер массива позиции
    string fieldОne[11][11];            // массив 1го поля
    string fieldTwo[11][11];            // массив 2го поля
    int position[S];                    // позиции
    initial(fieldОne);
    initial(fieldTwo);
    print(fieldОne,true);
    cout << endl;
    print(fieldTwo,false);
    cout << endl;
    ship(fieldОne, position,true);
    ship(fieldTwo, position,false);
    
    print(fieldОne, true);
}


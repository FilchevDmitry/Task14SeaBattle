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
void shipInitial(string field[][11],int a,int b, int c, int d, int len, bool hov)  // инициализация объекта
{   
    string O = "O";

    if (hov) 
    {
      for (int i = b; i < b+len; i++)
        {
          field[a][i] = O;
        }
    }
    else 
    {
       for (int i = a; i < a + len; i++)
       {
           field[i][b] = O;
       }
    }
}
void Coordinates(int position[], int deck)  // проверка введеных координат
{
    string num;
    cout << "Enter the coordinates of the " <<deck<<" deck ship(1,2 or 1.2) :";
    cin >> num;
    while (!checkInput(num, position))
    {   
        cout << "wrong" << endl;
        cout << "Enter the coordinates ship (1,2 or 1.2) :";
        cin >> num;
        checkInput(num, position);
    }
}
bool verify(string field[][11], int a, int b, int len, bool hov)   //проверка на наличие коробля 
{
    string O = "O";
    int temp = 0;
    int horizontal = 0, vertical = 0;
    if (hov)
    {
        for (int i = b; i < b + len; i++)
        {
            if(field[a][i] == O)
            temp++;
        }
    }
    else
    {
        for (int i = a; i < a + len; i++)
        {
            if(field[i][b] == O)
            temp++;
        }
    }
    if (temp == 0)
        return true;
    else
        return false;
}
void shipGo(int len, int cycle, int position[], string field[][11], int deck, bool gemer) // инициализация корабля на поле
{   
    int a = 0, b = 0, c = 0, d = 0;
    bool hov = true;
    bool pop = true;
    if (cycle == 4)
    {
        for (int i = 0; i < cycle; i++)
        {   
            Coordinates(position, 1);
            a = position[0];
            b = position[1];
            while (!verify(field, a, b, len, hov))
            {
                cout << "There is a ship at these coordinates!!!\n";
                Coordinates(position, 1);
                a = position[0];
                b = position[1];
            }
            shipInitial(field, a, b, c, d, len, hov);
            print(field, gemer);
        }
    }
    else
    {
        for (int i = 0; i < cycle; i++)
        {
            Coordinates(position, deck);
            a = position[0];
            b = position[1];
            Coordinates(position, deck);
            c = position[0];
            d = position[1];
            (a == c) ? hov = true : hov = false;
            while (a != c && b != d)
            {   
                cout << "It is impossible to put the ship diagonally!!!\n";
                Coordinates(position, deck);
                c = position[0];
                d = position[1];
            }
            while (!verify(field, a, b, len, hov))
            {   
                cout << "There is a ship at these coordinates!!!\n";
                Coordinates(position, deck);
                a = position[0];
                b = position[1];
                Coordinates(position, deck);
                c = position[0];
                d = position[1];
                (a == c) ? hov = true : hov = false;
                while (a != c && b != d)
                {
                    cout << "It is impossible to put the ship diagonally!!!\n";
                    Coordinates(position, deck);
                    c = position[0];
                    d = position[1];
                }
            }
            shipInitial(field, a, b, c, d, len, hov);
            print(field, gemer);
        }
    }
}
void ship(string field[][11],int position[],bool gemer) // инициализация кораблей
{   
    int len = 1, cycle = 4;
    for (int  i = 0; i < 4; i++)
    {
        shipGo(len, cycle, position, field, len, gemer);
        len++;
        cycle--;
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
    ship(fieldОne, position,true);
    ship(fieldTwo, position,false);
    print(fieldОne, true);
}


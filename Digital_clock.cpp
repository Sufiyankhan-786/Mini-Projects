#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
    int hour=17,min=13,sec=0;
    while (hour<=24)
    {   system("cls");
        cout<<"Hour  Min  Sec\n";
        cout<<hour<<"  :  "<<min<<"  :  "<<sec;

        sec++;
        if (sec == 60)
        {
            min++;
            sec = 0;
        }
        if (min == 60)
        {
            hour++;
            min= 0;
        }
        if (hour==24)
        {
            hour=0;
        }
        Sleep(1000);    
    }
    return 0;
    
}
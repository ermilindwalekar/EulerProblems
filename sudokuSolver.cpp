#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;

bool col(int s,int o,int n);
bool row(int s,int o,int n);
bool square(int s,int o,int n);
 
int a[9][9];
int main()
{
        int un=0,s,o,tmp;
        bool b=1;
        char c[20];

        cout << "give the sudoku filename: ";
        cin >> c;
        cout << endl;
        ifstream in(c);
        for(int i=0;i<9;i++)
        {
              for(int j=0;j<9;j++)
              {
                    in >> a[i][j];
                    if(!a[i][j])
                    un++;
              }
        }
        in.close();

        while(un && b)
        {
                b=0;
                for(int i=0;i<9;i++)
                {
                        for(int j=0;j<9;j++)
                        {
                                if(a[i][j]!=0)
                                        continue;
                                tmp=0;
                                for(int x=1;x<10;x++)
                                {
                                        if(col(i,j,x) && row(i,j,x) && square(i,j,x))
                                        {
                                                if(tmp==0)
                                                        tmp=x;
                                                else{
                                                        tmp=0;
                                                        break;
                                                }
                                        }      
                                }
                        if(tmp!=0)
                        {
                                a[i][j]=tmp;
                                b=1;
                                un--;
                        }
                }
        }
        }
        if(!b)
                cout << "It cannot be solved" << endl;
        else if(!un)
                cout << "solved" << endl;
                cout << endl;
                for(int i=0;i<9;i++)
                {
                        for(int j=0;j<9;j++)
                        {
                                cout << a[i][j] << " ";
                        }
                        cout << endl;
                }
        cout << endl;
}
 
bool col(int s,int o,int n)
{
        for(int g=0;g<9;g++)
        {
 
                if(a[s][g]==n)
                {
                        return 0;
                }      
        }
        return 1;
}
bool row(int s,int o,int n)
{
        for(int g=0;g<9;g++)
        {
                if(a[g][o]==n)
                        return 0;
        }
        return 1;
}
bool square(int s,int o,int n)
{
        int col=ceil((s+1)/3.);
        int row=ceil((o+1)/3.);
        for(int g=(col-1)*3;g<((col-1)*3+3);g++)
                for(int h=(row-1)*3;h<((row-1)*3+3);h++)
                {
                        if(a[g][h]==n)
                                return 0;
                }
        return 1;
}

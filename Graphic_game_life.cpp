#include <stdio.h>
#include <windows.h>
#include "TXLib.h"
#include "SeaLib.h"

void show_life(int a[], int n, int m, int schet   );
int next_state(int a[], int n, int m, int i, int j);
void draw_gull(int x,int y,COLORREF color,COLORREF color1,double scale, double wing1,double wing2,int nose2,int eye,int dir);

int main()
{
    txCreateWindow(1500,500);
    txSetFillColor(TX_BLACK);
    txClear();
    FILE *Fin;
    int i, j, n, m;
    int schet=0;

    srand(time(NULL));

    if((Fin = fopen("gun.txt", "r")) == NULL)
    {
        printf("Couldn't open file");
        return 1;
    }

    fscanf(Fin, "%d%d", &n, &m);

    int a[n][m];
    int b[n][m];

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            fscanf(Fin, "%d", &a[i][j]);
            b[i][j] = 0;
        }
    }
    fclose(Fin);
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        show_life(&a[0][0], n, m, schet);
        txSleep(100);

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                b[i][j] = next_state(&a[0][0], n, m, i, j);
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                a[i][j] = b[i][j];
            }
        }
        txSetFillColor(TX_BLACK);
        txClear();
        schet++;
    }
}


void show_life(int a[], int n, int m,int schet)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i*m+j]==1)
            {
                if(schet%2==0)
                {
                    draw_gull(j*25+10,i*12.5+10, RGB(255,153,157),  RGB(255,144,171), 0.045, 1 , 1.5 , 0, 1, -1);
                }
                else
                {
                    draw_gull(j*25+10,i*12.5+10, RGB(255,153,157),  RGB(255,144,171), 0.045, -1 , -1.5 , 0, 1, -1);
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int next_state(int a[], int n, int m, int i, int j)
{
    int summa=0;

    summa=((a[((n+(i-1))% n)*m + ((m+(j-1))%m)])+
           (a[((n+(i-1))% n)*m + j            ])+
           (a[((n+(i-1))% n)*m + ((j+1)%m)    ])+
           (a[i             *m + ((m+(j-1))%m)])+
           (a[i             *m + ((j+1)%m)    ])+
           (a[((i+1)%n)     *m + ((m+(j-1))%m)])+
           (a[((i+1)%n)     *m + j            ])+
           (a[((i+1)%n)     *m + ((j+1)%m)    ]));

    if( (summa==3)  || ( (a[i*m+j]==1) && (summa==2) ) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

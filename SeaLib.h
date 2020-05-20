#include "TXLib.h"

/**
 *file "SeaLib.h"
 *\author Anya Kuzmenkova 8V
 *\date  2019-11-23
 */


/**
 *��������� ����:
 *\param x x-���������� ������� ����� = 170

 *\param y y-���������� ������� ����� = 420
 *������� ����� � ������ ����� ����

 *\param x1 ����� ������ ��������
 *�������� �� �������� ��������� ����������� �� ����� ����
 *\warning ������! ������ ���� �������� 450

 *\param egg-������ ����
 *���� egg ����� 1,�� �������� ����� ����
 *���� egg �� ����� 1, �� �������� ������ ������ ����� ��������
 *\warning ����� ���������� ������ ������ ����� ����� ����� �������� scorlupa ��� �� ����� 1

 *\param scorlupa-��������� ������� ����� ��������
 *���� scorlupa ����� 1, �� �������� ������� �����
 *���� scorlupa �� ����� 1, �� �������� ������ ������ ����� ��������
 *\warning ����� ����� ������������� ������ ����� �������� egg �� ����� 1

 *\param sdvigX �������� ������� ����� ��������
 *�������� ������� ����� �������� ������ � �����
 *���� sdvigX>0, �� �������� ������
 *���� sdvigX<0, �� �������� �����
 *���� sdvigX=0, �� �������� �� ��������
 *\warning ����� ����� ������������� ������ ����� �������� scorlupa ����� 1

 *\param sdvigY �������� ������� ����� ��������
 *�������� ������� ����� �������� ���� � �����
 *���� sdvigY>0, �� �������� �����
 *���� sdvigY<0, �� �������� ���� (�� ���������� ����� ����� ��������, �� ��� �������� �������)
 *���� sdvigY=0, �� �������� �� ��������
 *\warning ����� ����� ������������� ������ ����� �������� scorlupa ����� 1

 *\param lines ��������� ������ �� ����
 *���� lines ����� 1, �� �������� ������� �� ����
 *���� lines �� ����� 1, �� ������� �� ��������
 *\warning ����� ����� ������������� ������ ����� �������� egg ����� 1

 *\param color ���� ����
 *������ ���� ������ �����, ������� �� ������

 *\param scale ������ ����
 *������ ���� ������ �������, ������� �� ������
 *\warning ������������� �������� �� 0.1 �� 2.5 (��� ������� ���� �������� 1500*900)

 *\param dir ��������� ���� �� �����������
 *���� dir = 1, �� ���� �� ����������
 *���� dir = -1, �� ���� ���������� �� �����������
 *\warning ������������ ��������� ������ ����� �������� egg ����� 1

 */
void draw_egg     (int x,int x1,int y,COLORREF color,                                double scale, int egg,     int scorlupa,int dir,       int sdvigX,int sdvigY,int lines);
/**
 *��������� ��������: x x-���������� ������� ����� = x x-���������� ������� ����� =
 *\param x x-���������� ������� ����� = 600

 *\param y y-���������� ������� ����� = 245

 *
*/
void draw_turtle  (int x,       int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int hand,    double head, int piatnoshko,int dir                        );

void draw_crab    (int x,       int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int foot,    double smile,int shine,     int dir,   int cleshni         );

void draw_gull    (int x,       int y,COLORREF color,COLORREF color1,                double scale, double wing1,double wing2,int nose2,     int eye,   int dir             );

void draw_dolphin (int x,       int y,COLORREF color,COLORREF color1,                double scale, double smile,int tail,    int blush,     int dir,   double plavnic      );

void draw_egg(int x,int x1,int y,COLORREF color,double scale,int egg,int scorlupa,int dir,int sdvigX,int sdvigY,int lines)
{
    if(egg==1)
    {
        txSetColor(TX_BLACK, 5*scale);
        txSetFillColor(color);
        txEllipse (x-140*scale, y-380*scale*dir, x+200*scale, y);
        txSetFillColor(TX_WHITE);
        txCircle(x-80 *scale, y-200*scale*dir, 7*scale );
        txCircle(x,           y-120*scale*dir, 10*scale);
        txCircle(x+20 *scale, y-220*scale*dir, 6*scale );
        txCircle(x+140*scale, y-180*scale*dir, 8*scale );
        txCircle(x+120*scale, y-80 *scale*dir, 11*scale);    //����� �� ����
        txCircle(x-60 *scale, y-60 *scale*dir, 7*scale );
        txCircle(x+60*scale,  y-340*scale*dir, 9*scale);
        txCircle(x-20*scale,  y-320*scale*dir, 6*scale);
        if(lines==1)
        {
            txLine(x-110*scale, y-300*scale*dir, x-90*scale,  y-260*scale*dir);
            txLine(x-90 *scale, y-260*scale*dir, x-30*scale,  y-300*scale*dir);
            txLine(x-30*scale,  y-300*scale*dir, x+27*scale,  y-260*scale*dir); //����� ��������
            txLine(x+27 *scale, y-260*scale*dir, x+85*scale, y-300*scale*dir);
            txLine(x+85*scale, y-300*scale*dir, x+145*scale, y-260*scale*dir);
            txLine(x+145*scale, y-260*scale*dir, x+165*scale, y-300*scale*dir);
        }
    }
    else
    {
        txSetColor(TX_BLACK, 5*scale);
        txSetFillColor(color);
        txChord(x-140*scale, y-380*scale*dir,x+200*scale, y, -220, 260);//������ ����� ��������
        txSetFillColor(TX_WHITE);
        POINT decor[7]={{int(x-111*scale), int(y-300*scale*dir) },
                        {int(x-90*scale) , int(y-260*scale*dir) },
                        {int(x-30*scale) , int(y-300*scale*dir) },
                        {int(x+27*scale) , int(y-260*scale*dir) },
                        {int(x+85*scale) , int(y-300*scale*dir) },
                        {int(x+145*scale), int(y-260*scale*dir) },
                        {int(x+168*scale), int(y-300*scale*dir)}};
        txPolygon (decor,7);
        txSetColor(TX_WHITE,11*scale);
        txLine(x-111*scale, y-302*scale*dir,x+165*scale,y-302*scale*dir);
        txSetColor(TX_BLACK,5*scale);
        txLine(x-110*scale, y-298*scale*dir, x-90*scale,  y-260*scale*dir);
        txLine(x-90 *scale, y-260*scale*dir, x-30*scale,  y-300*scale*dir);
        txLine(x-30*scale,  y-300*scale*dir, x+27*scale,  y-260*scale*dir);
        txLine(x+27 *scale, y-260*scale*dir, x+85*scale, y-300*scale*dir);
        txLine(x+85*scale, y-300*scale*dir, x+145*scale, y-260*scale*dir);
        txLine(x+145*scale, y-260*scale*dir, x+167*scale, y-300*scale*dir);
        txSetColor(TX_BLACK, 5*scale);
        txSetFillColor(TX_WHITE);
        txCircle(x-80 *scale, y-200*scale*dir, 7*scale );
        txCircle(x,           y-120*scale*dir, 10*scale);
        txCircle(x+20 *scale, y-220*scale*dir, 6*scale );
        txCircle(x+140*scale, y-180*scale*dir, 8*scale );
        txCircle(x+120*scale, y-80 *scale*dir, 11*scale);    //����� �� ����
        txCircle(x-60 *scale, y-60 *scale*dir, 7*scale );
        if(scorlupa==1)
        {
            txSetColor(TX_BLACK, 5*scale);
            txSetFillColor(color);
            txChord(x-(140-sdvigX)*scale, y-(380+sdvigY)*scale*dir, x+(200+sdvigX)*scale, y-sdvigY*scale*dir, 40, 100);//������� ����� ��������
            txSetFillColor(TX_WHITE);
            txCircle(x+(60+sdvigX)*scale, y-(340+sdvigY)*scale*dir, 9*scale);
            txCircle(x-(20-sdvigX)*scale, y-(320+sdvigY)*scale*dir, 6*scale);
            txSetFillColor(color);
            POINT decor[7]={{int(x-(111-sdvigX)*scale), int(y-(300+sdvigY)*scale*dir) },
                            {int(x-(90 -sdvigX)*scale), int(y-(260+sdvigY)*scale*dir) },
                            {int(x-(30 -sdvigX)*scale), int(y-(300+sdvigY)*scale*dir) },
                            {int(x+(27 +sdvigX)*scale), int(y-(260+sdvigY)*scale*dir) },
                            {int(x+(85 +sdvigX)*scale), int(y-(300+sdvigY)*scale*dir) },
                            {int(x+(145+sdvigX)*scale), int(y-(260+sdvigY)*scale*dir) },
                            {int(x+(168+sdvigX)*scale), int(y-(300+sdvigY)*scale*dir)}};
            txPolygon (decor,7);
            txSetColor(color,11*scale);
            txLine(x-(99-sdvigX)*scale, y-(302+sdvigY)*scale*dir,x+(155+sdvigX)*scale,y-(302+sdvigY)*scale*dir);
            txSetColor(TX_BLACK,5*scale);
            txLine(x-(110-sdvigX)*scale, y-(298+sdvigY)*scale*dir, x-(90 -sdvigX)*scale, y-(260+sdvigY)*scale*dir);
            txLine(x-(90 -sdvigX)*scale, y-(260+sdvigY)*scale*dir, x-(30 -sdvigX)*scale, y-(300+sdvigY)*scale*dir);
            txLine(x-(30 -sdvigX)*scale, y-(300+sdvigY)*scale*dir, x+(27 +sdvigX)*scale, y-(260+sdvigY)*scale*dir);
            txLine(x+(27 +sdvigX)*scale, y-(260+sdvigY)*scale*dir, x+(85 +sdvigX)*scale, y-(300+sdvigY)*scale*dir);
            txLine(x+(85 +sdvigX)*scale, y-(300+sdvigY)*scale*dir, x+(145+sdvigX)*scale, y-(260+sdvigY)*scale*dir);
            txLine(x+(145+sdvigX)*scale, y-(260+sdvigY)*scale*dir, x+(167+sdvigX)*scale, y-(300+sdvigY)*scale*dir);
        }
    }



}

void draw_turtle(int x, int y,COLORREF color,COLORREF color1,COLORREF color2,double scale, int hand, double head, int piatnoshko, int dir)
{
    txSetColor(TX_BLACK, 5*scale);                                                               //�������� head- �������� ������
    txSetFillColor(color);                                                                       //head >/=0
    txCircle(x,int(y-(130+30*head)*scale*dir),45*scale); //������                                //����� head=3, ������ �� �����
    POINT polygon[8]= {{int(x-45 *scale), int(y- 70       *scale*dir) },                          //������������� ����� �� -0.5 �� -2.5
                       {int(x-90 *scale), int(y-(105-hand)*scale*dir) },
                       {int(x-120*scale), int(y-(105-hand)*scale*dir) },
                       {int(x-180*scale), int(y-(60 -hand)*scale*dir) }, //���� �����             //�������� hand-�������� ���������
                       {int(x-180*scale), int(y-(15 -hand)*scale*dir) },                          //������������� ����� �� 50 �� -50
                       {int(x-135*scale), int(y-(60 -hand)*scale*dir) },                          //��� + �������� ��������� ����,
                       {int(x-90 *scale), int(y-(75 -hand)*scale*dir) },                          //��� - �������� ��������� �����
                       {int(x-70 *scale), int(y- 60       *scale*dir)}};
    txPolygon (polygon,8);                                                                        //piatnoshko-���������/������������ ������� �� �������
    POINT polygon1[8]={{int(x+55*scale ),int(y- 70       *scale*dir) },
                       {int(x+100*scale),int(y-(105-hand)*scale*dir) },
                       {int(x+130*scale),int(y-(105-hand)*scale*dir) },
                       {int(x+190*scale),int(y-(60 -hand)*scale*dir) },
                       {int(x+190*scale),int(y-(15 -hand)*scale*dir) }, //���� ������
                       {int(x+145*scale),int(y-(60 -hand)*scale*dir) },
                       {int(x+100*scale),int(y-(75 -hand)*scale*dir) },
                       {int(x+70*scale ),int(y- 55       *scale*dir)}};
    txPolygon (polygon1,8);
    POINT polygon2[5]= {{int(x-50*scale),int(y+65 *scale*dir) },
                        {int(x-90*scale),int(y+90 *scale*dir) },
                        {int(x-90*scale),int(y+120*scale*dir) },   //���� �����
                        {int(x-60*scale),int(y+135*scale*dir) },
                        {int(x-30*scale),int(y+75 *scale*dir)}};
    txPolygon (polygon2,5);
    POINT polygon3[5]={{int(x+50*scale),int(y+65 *scale*dir) },
                       {int(x+90*scale),int(y+90 *scale*dir) },
                       {int(x+90*scale),int(y+120*scale*dir) }, //���� ������
                       {int(x+60*scale),int(y+135*scale*dir) },
                       {int(x+30*scale),int(y+75 *scale*dir)}};
    txPolygon (polygon3,5);
    POINT rhomb[4]={{    x,          int(y+80 *scale*dir) },
                    {int(x-15*scale),int(y+105*scale*dir) },  //�����
                    {    x,          int(y+120*scale*dir) },
                    {int(x+15*scale),int(y+105*scale*dir)}};
    txPolygon (rhomb,4);
    txSetFillColor(TX_BLACK);
    txEllipse(int(x+25*scale),int(y-(155+30*head)*scale*dir ), //���� ������
              int(x+40*scale),int(y-(125+30*head)*scale*dir));
    txEllipse(int(x-25*scale),int(y-(155+30*head)*scale*dir ),
              int(x-40*scale),int(y-(125+30*head)*scale*dir)); //���� �����
    txSetFillColor(color1);
    txCircle(x,y,int(90*scale)); //�������
    txSetFillColor(color2);

     if (piatnoshko==1)
     {
         POINT draw[6]={{int(x-45*scale),int(y-50*scale*dir) },
                        {int(x-30*scale),    y               },
                        {int(x-45*scale),int(y+50*scale*dir) },   //������� �� �������
                        {int(x+45*scale),int(y+50*scale*dir) },
                        {int(x+30*scale),    y               },
                        {int(x+45*scale),int(y-50*scale*dir)}};
         txPolygon(draw,6);
     }
}

void draw_crab(int x, int y,COLORREF color,COLORREF color1,COLORREF color2,double scale,int foot, double smile,int shine, int dir, int cleshni)
{
                                                                                                                    //����  (1150,325)   //�������� foot-�������� ���
    txSetColor(TX_BLACK, 5*scale);                                                                                  //������������� �������� �� 30 �� -30
    txSetFillColor(color);                                                                                          //��� �������� + ���������� ������ � ������
    txEllipse(int(x-150*scale),int(y-75*scale*dir),int(x+150*scale),int(y+75*scale*dir));                           //��� �������� - ���������� ����� � �����
    txSetFillColor(color1);
    POINT crab[5]={{int(x+100*scale),int(y+5  *scale*dir) },
                   {int(x+100*scale),int(y-30 *scale*dir) },                                    //�������� smile-������ �����
                   {int(x+130*scale),int(y-110*scale*dir) }, //������ ������ ������ �����       //������������� �������� �� 10 �� -10
                   {int(x+155*scale),int(y-85 *scale*dir) },                                    //��� + �������� ������ ����
                   {int(x+130*scale),int(y-25 *scale*dir)}};                                    //��� - ��������� ������ �����
    txPolygon (crab,5);
    POINT crab2[5]={{int(x-100*scale),int(y+5  *scale*dir) },                                   //shine-����� � ������
                    {int(x-100*scale),int(y-30 *scale*dir) },
                    {int(x-130*scale),int(y-110*scale*dir) },  //����� ������ ������ �����      //cleshni-��������/���������� ������� �����
                    {int(x-155*scale),int(y-85 *scale*dir) },                                   //�����. ����- �� 25 �� -25
                    {int(x-130*scale),int(y-25 *scale*dir)}};                                   //"-"-���������; "+"-�����������
    txPolygon (crab2,5);
    POINT crabb[10]={{int(x-125*scale),int(y+45 *scale*dir) },
                     {int(x-225*scale),int(y-125*scale*dir) },
                     {int(x-250*scale),int(y-100*scale*dir) },
                     {int(x-235*scale),int(y-65 *scale*dir) },  //��� ����� ���� ������� �����
                     {int(x-125*scale),int(y+45 *scale*dir) },
                     {int(x-235*scale),int(y-45 *scale*dir) },
                     {int(x-245*scale),int(y+5  *scale*dir) },
                     {int(x-125*scale),int(y+45 *scale*dir) },
                     {int(x-200*scale),int(y+25 *scale*dir) },
                     {int(x-180*scale),int(y+65 *scale*dir)}};
    txPolygon (crabb,10);
    POINT crabb1[10]={{int(x+125*scale),int(y+45 *scale*dir) },
                      {int(x+225*scale),int(y-125*scale*dir) },
                      {int(x+250*scale),int(y-100*scale*dir) },
                      {int(x+235*scale),int(y-65 *scale*dir) },
                      {int(x+125*scale),int(y+45 *scale*dir) }, //��� ������ ���� ������� �����
                      {int(x+235*scale),int(y-45 *scale*dir) },
                      {int(x+245*scale),int(y+5  *scale*dir) },
                      {int(x+125*scale),int(y+45 *scale*dir) },
                      {int(x+200*scale),int(y+25 *scale*dir) },
                      {int(x+180*scale),int(y+65 *scale*dir)}};
    txPolygon (crabb1,10);
    txSetFillColor(color2);
    POINT crab1[10]={{int(x+ 130            *scale),int(y-110*scale*dir) },
                     {int(x+(105+10+cleshni)*scale),int(y-205*scale*dir) },
                     {int(x+(130   -cleshni)*scale),int(y-310*scale*dir) },
                     {int(x+ 130            *scale),int(y-260*scale*dir) },
                     {int(x+ 155            *scale),int(y-235*scale*dir) }, //������ ������ ������� �����
                     {int(x+ 180            *scale),int(y-260*scale*dir) },
                     {int(x+(180   +cleshni)*scale),int(y-325*scale*dir) },
                     {int(x+ 205            *scale),int(y-300*scale*dir) },
                     {int(x+ 180            *scale),int(y-145*scale*dir) },
                     {int(x+ 155            *scale),int(y-85 *scale*dir)}};
    txPolygon (crab1,10);
    POINT crab3[10]={{int(x- 130            *scale),int(y-110*scale*dir) },
                     {int(x-(105+10+cleshni)*scale),int(y-205*scale*dir) },
                     {int(x-(130   -cleshni)*scale),int(y-310*scale*dir) },
                     {int(x- 130            *scale),int(y-260*scale*dir) },
                     {int(x- 155            *scale),int(y-235*scale*dir) },
                     {int(x- 180            *scale),int(y-260*scale*dir) }, //����� ������ ������� �����
                     {int(x-(180   +cleshni)*scale),int(y-325*scale*dir) },
                     {int(x- 205            *scale),int(y-300*scale*dir) },
                     {int(x- 180            *scale),int(y-145*scale*dir) },
                     {int(x- 155            *scale),int(y-85 *scale*dir)}};
    txPolygon (crab3,10);
    POINT craab[3]={{int(x- 245      *scale),int(y-105*scale*dir) },
                    {int(x-(370+foot)*scale),int(y+75 *scale*dir) },  //����� ������� ���� ������ �����
                    {int(x-(290+foot)*scale),int(y+25 *scale*dir)}};
    txPolygon (craab,3);
    POINT craab2[3]={{int(x- 245      *scale),int(y-10 *scale*dir) },
                     {int(x-(245+foot)*scale),int(y+100*scale*dir) }, //������ ������� ���� ������ �����
                     {int(x-(215+foot)*scale),int(y+50 *scale*dir)}};
    txPolygon (craab2,3);
    POINT craab4[3]={{int(x- 200      *scale),int(y+20*scale*dir) },
                     {int(x-(175+foot)*scale),int(y+120*scale*dir)}, //����� ������ ���� ������ �����
                     {int(x- 175      *scale),int(y+45*scale*dir)}};
    txPolygon (craab4,3);
    POINT craab1[3]={{int(x+ 245      *scale),int(y-105*scale*dir) },
                     {int(x+(375+foot)*scale),int(y+75 *scale*dir) },  //����� ������� ���� ������ �����
                     {int(x+(295+foot)*scale),int(y+25 *scale*dir)}};
    txPolygon (craab1,3);
    POINT craab3[3]={{int(x+ 245      *scale),int(y-10 *scale*dir) },
                     {int(x+(245+foot)*scale),int(y+100*scale*dir) },  //������ ������� ���� ������ �����
                     {int(x+(215+foot)*scale),int(y+50 *scale*dir)}};
    txPolygon (craab3,3);
    POINT craab5[3]={{int(x+ 200      *scale),int(y+20 *scale*dir) },
                     {int(x+(175+foot)*scale),int(y+120*scale*dir) }, //������ ������ ���� ������ �����
                     {int(x+ 175      *scale),int(y+45 *scale*dir)}};
    txPolygon (craab5,3);
    txSetColor(TX_BLACK,7*scale);
    txLine(int(x-50*scale),int(y+(15+smile)*scale*dir),int(x-25*scale),int(y+ 15       *scale*dir));
    txLine(int(x-25*scale),int(y+ 15       *scale*dir),int(x+25*scale),int(y+ 15       *scale*dir));  //���
    txLine(int(x+25*scale),int(y+ 15       *scale*dir),int(x+50*scale),int(y+(15+smile)*scale*dir));
    if (shine==1)
    {
        txSetFillColor(TX_BLACK);
        txEllipse(int(x+40*scale),int(y-145*scale*dir),int(x+90*scale),int(y-35*scale*dir)); //������ ����
        txEllipse(int(x-80*scale),int(y-145*scale*dir),int(x-30*scale),int(y-35*scale*dir)); //����� ����
        txSetColor(TX_WHITE);
        txLine(int(x+60*scale),int(y-100*scale*dir),int(x+70*scale),int(y-100*scale*dir));
        txLine(int(x+65*scale),int(y-110*scale*dir),int(x+65*scale),int(y-90*scale*dir ));    //����� � ������
        txLine(int(x-45*scale),int(y-100*scale*dir),int(x-55*scale),int(y-100*scale*dir));
        txLine(int(x-50*scale),int(y-110*scale*dir),int(x-50*scale),int(y-90*scale*dir ));
    }
    else
    {
        txSetFillColor(TX_BLACK);
        txEllipse(int(x+40*scale),int(y-145*scale*dir),int(x+90*scale),int(y-35*scale*dir));  //�����
        txEllipse(int(x-80*scale),int(y-145*scale*dir),int(x-30*scale),int(y-35*scale*dir));
    }
}

void draw_gull(int x,int y,COLORREF color,COLORREF color1,double scale,double wing1,double wing2,int nose2,int eye, int dir)
{
                                                                                                           //�����  (325,835)   //�������� wing1-����� �� �������� �����
    txSetColor(TX_BLACK, 5*scale);                                                                                              //������������� ���������-�� 2 �� -2
    txSetFillColor(color);                                                                                                      //��� + ����� ����������� �����
    POINT gull2[8]={{int(x- 100          *scale*dir),int(y- 35           *scale) },                                             //��� - ����� ���������� ����
                    {int(x-(125+20*wing2)*scale*dir),int(y-(110+40*wing2)*scale) },
                    {int(x-(175+20*wing2)*scale*dir),int(y-(135+40*wing2)*scale) },
                    {int(x-(225+20*wing2)*scale*dir),int(y-(185+40*wing2)*scale) }, //������ ����� �����  //�������� wing2-����� �� ������ �����
                    {int(x-(225+20*wing2)*scale*dir),int(y-(235+40*wing2)*scale) },                       //������������� ��������� �� 2 �� -2
                    {int(x-(125+20*wing2)*scale*dir),int(y-(160+40*wing2)*scale) },                       //��� + ����� ����������� �����
                    {int(x-(50+20 *wing2)*scale*dir),int(y-(135+40*wing2)*scale) },                       //��� - ����� ���������� ����
                    {int(x- 25           *scale*dir),int(y- 35           *scale)}};
    txPolygon (gull2,8);
    txSetFillColor(color1);                                                                               //�������� nose2- ����������/���������� �����
    POINT gull[17]={{int(x- 200         *scale*dir),int(y+15           *scale)  },                        //������������� ��������� �� 30 �� -10
                    {int(x- 175         *scale*dir),int(y-35           *scale)  },                        //��� + ���� �����������
                    {int(x- 50          *scale*dir),int(y-35           *scale)  },                        //��� - ���� �����������
                    {int(x- 25          *scale*dir),int(y-(60+10*wing1)*scale)  },
                    {int(x+(50+10*wing1)*scale*dir),int(y-(185+50*wing1)*scale) },                        //eye-����������� � �������� ����
                    {int(x+ 275         *scale*dir),int(y-(335+60*wing1)*scale) },
                    {int(x+ 275         *scale*dir),int(y-(285+60*wing1)*scale) }, //���� �����
                    {int(x+ 200         *scale*dir),int(y-(185+40*wing1)*scale) },
                    {int(x+ 150         *scale*dir),int(y-(160+40*wing1)*scale) },
                    {int(x+ 75          *scale*dir),int(y-35            *scale) },
                    {int(x+ 150         *scale*dir),int(y-10            *scale) },
                    {int(x+ 275         *scale*dir),int(y-10            *scale) },
                    {int(x+ 250         *scale*dir),int(y+15            *scale) },
                    {int(x+ 100         *scale*dir),int(y+15            *scale) },
                    {    x,                         int(y+40            *scale) },
                    {int(x- 125         *scale*dir),int(y+40            *scale) },
                    {int(x- 175         *scale*dir),int(y+25            *scale)}};
    txPolygon (gull,17);
    txSetFillColor(RGB(189,102,9));
    POINT nose1[3]={{int(x-175*scale*dir),int(y+25        *scale) },
                    {int(x-235*scale*dir),int(y+(45+nose2)*scale) }, //���� (������ �����)
                    {int(x-215*scale*dir),int(y+(55+nose2)*scale)}};
    txPolygon (nose1,3);
    txSetFillColor(RGB(224,158,16));
    POINT nose[4]={{int(x-200*scale*dir),int(y+15*scale) },
                   {int(x-235*scale*dir),int(y+35*scale) },  //���� (������� �����)
                   {int(x-245*scale*dir),int(y+55*scale) },
                   {int(x-175*scale*dir),int(y+25*scale)}};
    txPolygon (nose,4);

    if (eye==1)
    {
         txSetFillColor(TX_BLACK);
         txCircle(int(x-150*scale*dir),int(y-5*scale),4*scale);     //����
         txSetColor(TX_BLACK,5*scale);
    }
    else
    {
          txSetColor(TX_BLACK,5*scale);
          txLine(int(x-160*scale*dir),int(y-5*scale),int(x-130*scale*dir),int(y-5*scale));
    }
}

void draw_dolphin(int x,int y,COLORREF color,COLORREF color1,double scale, double smile, int tail, int blush, int dir, double plavnic)
{
                                                                                                //�������  (925,625)   //�������� smile-������
    txSetColor(TX_BLACK, 5*scale);                                                                                     //������������� �������� �� 1 �� -1
    txSetFillColor(color);                                                                                             //��� +1 ���������, ��� -1 �� ���������
    POINT dolph1[6]={{int(x-75 *scale*dir),int(y-45 *scale) },
                     {int(x-75 *scale*dir),int(y-75 *scale) },
                     {int(x-125*scale*dir),int(y-100*scale) },                                  //�������� tail-�������� ������
                     {int(x-75 *scale*dir),int(y-125*scale) }, //������� �������                //������������� �������� �� 40 �� -40
                     {int(x-25 *scale*dir),int(y-125*scale) },                                  //��� + �������� ������ �����
                     {int(x+25 *scale*dir),int(y-95 *scale)}};                                  //��� - �������� ������ ������
    txPolygon (dolph1,6);
    POINT dolph2[7]={{int(x+ 150            *scale*dir),int(y-(35 +10*plavnic)*scale) },                                      //blush-�������
                     {int(x+(175+25*plavnic)*scale*dir),int(y+(25 +10*plavnic)*scale) },
                     {int(x+(175+25*plavnic)*scale*dir),int(y+(75 +10*plavnic)*scale) },                                      //plavnic-��������
                     {int(x+(150+25*plavnic)*scale*dir),int(y+(125+10*plavnic)*scale) }, //������ (�������) �������           //������������� �� -0.5 �� 1
                     {int(x+(150+25*plavnic)*scale*dir),int(y+(100+10*plavnic)*scale) },                                      //��� "-" �������� � �����������
                     {int(x+(125+25*plavnic)*scale*dir),int(y+(50 +10*plavnic)*scale) },                                      //��� "+" ����������� � �������������
                     {int(x+ 100            *scale*dir),int(y+(15 +10*plavnic)*scale)}};
    txPolygon (dolph2,7);
    txSetFillColor(color1);
    POINT dolph[22]={{int(x+ 200      *scale*dir),int(y-75 *scale) },
                     {int(x+ 225      *scale*dir),int(y-75 *scale) },
                     {int(x+ 250      *scale*dir),int(y-50 *scale) },
                     {int(x+ 225      *scale*dir),int(y-25 *scale) },
                     {int(x+ 150      *scale*dir),int(y-25 *scale) },
                     {int(x+ 100      *scale*dir),int(y+25 *scale) },
                     {int(x- 50       *scale*dir),int(y+150*scale) },
                     {int(x- 100      *scale*dir),int(y+275*scale) },
                     {int(x-(50+tail) *scale*dir),int(y+300*scale) },
                     {int(x-(25+tail) *scale*dir),int(y+350*scale) },
                     {int(x-(75+tail) *scale*dir),int(y+350*scale) },
                     {int(x-(100+tail)*scale*dir),int(y+325*scale) }, //���� ��������
                     {int(x-(125+tail)*scale*dir),int(y+350*scale) },
                     {int(x-(175+tail)*scale*dir),int(y+375*scale) },
                     {int(x-(175+tail)*scale*dir),int(y+325*scale) },
                     {int(x- 125      *scale*dir),int(y+275*scale) },
                     {int(x- 150      *scale*dir),int(y+100*scale) },
                     {int(x- 100      *scale*dir),int(y-25 *scale) },
                     {int(x- 75       *scale*dir),int(y-50 *scale) },
                     {int(x+ 25       *scale*dir),int(y-100*scale) },
                     {int(x+ 100      *scale*dir),int(y-125*scale) },
                     {int(x+ 150      *scale*dir),int(y-125*scale)}};
    txPolygon (dolph,22);
    txSetFillColor(TX_BLACK);
    txCircle(int(x+125*scale*dir),int(y-75*scale),5*scale); //����
    txSetFillColor(color);
    POINT dolph3[6]={{int(x+(75+20*plavnic)*scale*dir),int(y-(25 +10*plavnic)*scale) },
                     {int(x+(50+20*plavnic)*scale*dir),int(y+(25 +10*plavnic)*scale) },
                     {    x                           ,int(y+(75 +10*plavnic)*scale) },
                     {int(x-(50+20*plavnic)*scale*dir),int(y+(100+10*plavnic)*scale) }, //�������� �������
                     {    x                           ,int(y+(25 +10*plavnic)*scale) },
                     {    x                           ,    y                        }};
    txPolygon (dolph3,6);
    txSetColor(TX_BLACK,5*scale);
    txLine(int(x+250*scale*dir),int(y- 50          *scale ),
           int(x+200*scale*dir),int(y- 50          *scale));
    txLine(int(x+200*scale*dir),int(y- 50          *scale ),  //������
           int(x+165*scale*dir),int(y-(60+10*smile)*scale));
    if (blush==1)
    {
        txSetColor(TX_PINK,3*scale);
        txLine(int(x+135*scale*dir),int(y-65*scale ),
               int(x+130*scale*dir),int(y-50*scale));
        txLine(int(x+145*scale*dir),int(y-65*scale ),     //������� �� ������
               int(x+140*scale*dir),int(y-50*scale));
        txLine(int(x+155*scale*dir),int(y-65*scale ),
               int(x+150*scale*dir),int(y-50*scale));
    }
}

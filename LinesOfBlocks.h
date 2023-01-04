#include "varSetup.h"
#include <iostream>
using namespace std;
void calcDir(int x1,int y1,int x2, int y2, int &distX,int &distY)
{
     distX=x2-x1;
    if(distX<0)
        distX=distX*(-1);

     distY=y2-y1;
    if(distY<0)
        distY=distY*(-1);
}
int counter=0;
void DrawSmartLine(int x1,int y1,int x2,int y2,int color)
{
    int dirX,dirY; // -1 0 1
    int distX=x2-x1;
    if(distX>=0)
        dirX=1;
    if(distX<0)
    {
        distX=distX*(-1);
        dirX=-1;
    }
    int distY=y2-y1;
    if(distY>=0)
        dirY=1;
    if(distY<0)
    {
        distY=distY*(-1);
        dirY=-1;
    }
    setcolor(0);
    while(distX&&distY)
    {
        if(distX>=distY)
        {
            x1+=dirX;
        }
        if(distY>distX)
        {
            y1+=dirY;
        }
        if(schemGrid[y1][x1])
            {
                counter++;
            }
        if(counter%2==0)
        line(x1,y1,x1,y1-1);
        calcDir(x1,y1,x2,y2,distX,distY);
    }
    cout<<counter;
}
void DrawLineOffBlock(int index,int color)
{
    for(int indexcircle=0;indexcircle<CreatedBlocks[index].nrCircles;indexcircle++)
    if(CreatedBlocks[index].isCircleConected[indexcircle])
    {
        setcolor(color);
        int x1=CreatedBlocks[index].ConnectCircle[indexcircle].dwn_right.x-5;
        int y1=CreatedBlocks[index].ConnectCircle[indexcircle].dwn_right.y;
        int x2=CreatedBlocks[ CreatedBlocks[index].indexBlockConnexionTo[indexcircle]  ].ConnectCircle[  CreatedBlocks[index].indexCirecleConnexionTo[indexcircle]  ].up_left.x+5;
        int y2=CreatedBlocks[ CreatedBlocks[index].indexBlockConnexionTo[indexcircle]  ].ConnectCircle[  CreatedBlocks[index].indexCirecleConnexionTo[indexcircle]  ].up_left.y;
        DrawSmartLine(x1,y1,x2,y2,color);
        //line(x1,y1,x2,y2);
    }

}
void DrawAllLines()
{
    CleanSpace();
    for(int i=0;i<nr_CreatedBlock;i++)
        for(int j=0;j<CreatedBlocks[i].nrCircles;j++)
            {
                DrawBlock(CreatedBlocks[i],0);
                DrawLineOffBlock(i,0);
                DrawInputText(i,3);
            }
}
void InfoUserClicksCircles(bool isConnected)
{
        setcolor(8);
        setbkcolor(15);
        settextstyle(3, HORIZ_DIR, 1);
    if(isConnected)
    {
        outtextxy(1200-textwidth("Click Dreapta")/2,50,"Click Dreapta");
        outtextxy(1200-textwidth("pentru a sterge legatura")/2,70,"pentru a sterge legatura");
    }
    else
    {
        outtextxy(1200-textwidth("Click Stanga")/2,50,"Click Stanga");
        outtextxy(1200-textwidth("pentru a crea o legatura")/2,70,"pentru a crea o legatura");
    }
}
void CheckOverBlockCircle()
{
    for (int k = 0; k < nr_CreatedBlock; k++)
        for (int h = 0; h < CreatedBlocks[k].nrCircles; h++)//test desenare pe cerc
        {

            //if(ismouseclick(WM_LBUTTONDOWN))
            if (overBTN(CreatedBlocks[k].ConnectCircle[h], mousex(), mousey())&&h!=0)
            {
                //info user
                InfoUserClicksCircles(CreatedBlocks[k].isCircleConected[h]);
                bool wait = 1, notClick = 1;
                DrawBlock(CreatedBlocks[k], 4);
                setfillstyle(SOLID_FILL, RGB(0, 100, 155));
                bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y-1);
                while (wait)
                {
                    if (!overBTN(CreatedBlocks[k].ConnectCircle[h], mousex(), mousey()))
                    {
                        setfillstyle(SOLID_FILL, 15);
                        bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                        DrawBlock(CreatedBlocks[k], 0);
                        wait = 0;
                        CleanRightArea();
                    }
                    if (ismouseclick(WM_RBUTTONDOWN)&&wait&&CreatedBlocks[k].isCircleConected[h])
                    {
                        clearmouseclick(WM_RBUTTONDOWN);
                        clearmouseclick(WM_RBUTTONUP);
                        DrawLineOffBlock(k,15);
                        CreatedBlocks[k].isCircleConected[h]=0;
                        CreatedBlocks[CreatedBlocks[k].indexBlockConnexionTo[h]].ConnectCircle[CreatedBlocks[k].indexCirecleConnexionTo[h]].selected--;
                        DrawLineOffBlock(k,0);
                        CleanRightArea();

                    }
                    if (ismouseclick(WM_LBUTTONDOWN) && wait&&CreatedBlocks[k].isCircleConected[h]==0) {
                        clearmouseclick(WM_LBUTTONUP);
                        clearmouseclick(WM_LBUTTONDOWN);
                        //DrawDynamicLine(mousex(),mousey());
                        while (wait) {
                            if (ismouseclick(WM_LBUTTONDOWN))
                            {

                                //DrawDynamicLine(mousex(),mousey());
                                for (int p = 0; p < nr_CreatedBlock; p++)
                                    for (int r = 0; r < CreatedBlocks[p].nrCircles; r++)
                                        if (overBTN(CreatedBlocks[p].ConnectCircle[r], mousex(), mousey()) && ((h == 0 && r > 0) || (r == 0 && h > 0)) && k != p)
                                        {
                                            CreatedBlocks[k].isCircleConected[h]=1;
                                            CreatedBlocks[k].indexBlockConnexionTo[h]=p;
                                            CreatedBlocks[k].indexCirecleConnexionTo[h]=r;
                                            CreatedBlocks[p].ConnectCircle[r].selected++;
                                            DrawLineOffBlock(k,0);
                                            wait = 0;
                                            CleanRightArea();
                                            setfillstyle(SOLID_FILL, 15);
                                            bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                                            DrawBlock(CreatedBlocks[k], 4);
                                            }
                                clearmouseclick(WM_LBUTTONUP);
                                clearmouseclick(WM_LBUTTONDOWN);
                            }
                        }/*
                   }
                       if(!overBTN(CreatedBlocks[k].ConnectCircle[h],mousex(),mousey()))
                           {

                               setfillstyle(SOLID_FILL, 15);
                           bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                           DrawBlock(CreatedBlocks[k],4);
                           }*/

                    }
                }
                //clearmouseclick(WM_LBUTTONUP);
                   // clearmouseclick(WM_LBUTTONDOWN);
            }
        }
}

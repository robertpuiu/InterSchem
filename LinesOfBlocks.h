#include "varSetup.h"
#include <iostream>
using namespace std;
int SpotInsideOfBlock(int x,int y)
{
    for(int i=0;i<nr_CreatedBlock;i++)
    {
        if(x>=CB_HitBox[i].dwnLeft.x&&x<=CB_HitBox[i].upRight.x&&y>=CB_HitBox[i].upLeft.y&&y<=CB_HitBox[i].dwnRight.y)
            return i;
    }
    return -1;
}
void calcDir(int x1,int y1,int x2, int y2, int &distX,int &distY)
{
     distX=x2-x1;
    if(distX<0)
        distX=distX*(-1);

     distY=y2-y1;
    if(distY<0)
        distY=distY*(-1);
}
void LineGoAroundBlock(Spot StartGoAround,Spot EndGoAround,int indexBlockGoAround)
{
    if(StartGoAround.y<CB_HitBox[indexBlockGoAround].dwnRight.y&&StartGoAround.y>CB_HitBox[indexBlockGoAround].upLeft.y&&EndGoAround.y<CB_HitBox[indexBlockGoAround].dwnRight.y&&EndGoAround.y>CB_HitBox[indexBlockGoAround].upLeft.y)
    {
        if(StartGoAround.y>(CB_HitBox[indexBlockGoAround].dwnRight.y+CB_HitBox[indexBlockGoAround].upLeft.y)/2)
        {
            line(StartGoAround.x,StartGoAround.y,StartGoAround.x,CB_HitBox[indexBlockGoAround].dwnRight.y);
            line(StartGoAround.x,CB_HitBox[indexBlockGoAround].dwnRight.y,EndGoAround.x,CB_HitBox[indexBlockGoAround].dwnRight.y);
            line(EndGoAround.x,CB_HitBox[indexBlockGoAround].dwnRight.y,EndGoAround.x,EndGoAround.y);
        }
        else
        {

            line(StartGoAround.x,StartGoAround.y,StartGoAround.x,CB_HitBox[indexBlockGoAround].upLeft.y);
            line(StartGoAround.x,CB_HitBox[indexBlockGoAround].upLeft.y,EndGoAround.x,CB_HitBox[indexBlockGoAround].upLeft.y);
            line(EndGoAround.x,CB_HitBox[indexBlockGoAround].upLeft.y,EndGoAround.x,EndGoAround.y);
        }

    }
    else
    {
        int xMidBlock=(CreatedBlocks[indexBlockGoAround].dwnLeft.x+CreatedBlocks[indexBlockGoAround].upRight.x)/2;
        int xMidStartStop=(StartGoAround.x+EndGoAround.x)/2;
        if(xMidBlock>=xMidStartStop)
        {
            line(StartGoAround.x,StartGoAround.y,CB_HitBox[indexBlockGoAround].dwnLeft.x,StartGoAround.y);
            line(CB_HitBox[indexBlockGoAround].dwnLeft.x,StartGoAround.y,CB_HitBox[indexBlockGoAround].dwnLeft.x,EndGoAround.y);
            line(CB_HitBox[indexBlockGoAround].dwnLeft.x,EndGoAround.y,EndGoAround.x,EndGoAround.y);
        }
        else
        {
            line(StartGoAround.x,StartGoAround.y,CB_HitBox[indexBlockGoAround].upRight.x,StartGoAround.y);
            line(CB_HitBox[indexBlockGoAround].upRight.x,StartGoAround.y,CB_HitBox[indexBlockGoAround].upRight.x,EndGoAround.y);
            line(CB_HitBox[indexBlockGoAround].upRight.x,EndGoAround.y,EndGoAround.x,EndGoAround.y);
        }
    }
}
void DrawSmartLine(int x1,int y1,int x2,int y2,int color)
{
    bool colisionLineBlock=0;
    Spot StartGoAround,EndGoAround;
    StartGoAround.x=x1;
    StartGoAround.y=y1;
    int indexBlockGoAround=SpotInsideOfBlock(x1,y1);
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
    if(color!=15)
    setcolor(RGB(100+rand()%100,100+rand()%100,100+rand()%100));
    else
        setcolor(color);
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

        if(SpotInsideOfBlock(x1,y1)==-1)
        {
            line(x1,y1,x1,y1-1);
            if(colisionLineBlock)
            {
                EndGoAround.x=x1;
                EndGoAround.y=y1;
                colisionLineBlock=0;
                LineGoAroundBlock(StartGoAround,EndGoAround,indexBlockGoAround);
            }
        }
        else
        if(colisionLineBlock==0)
        {
            indexBlockGoAround=SpotInsideOfBlock(x1,y1);
            StartGoAround.x=x1;
            StartGoAround.y=y1;
            colisionLineBlock=1;
        }
        calcDir(x1,y1,x2,y2,distX,distY);
    }
    //line(x1,y1+1,x1,y1+7);
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
        if(CreatedBlocks[index].CB_type!=1)
        {
            line(x1,y1,x1,y1+6);
            DrawSmartLine(x1,y1+7,x2,y2-7,color);
        }
        else
        {
            if(indexcircle==1)
                {
                    line(x1,y1,x1-10,y1);
                    DrawSmartLine(x1-10,y1,x2,y2-7,color);
                }
            else
            {
                line(x1,y1,x1+10,y1);
                DrawSmartLine(x1+10,y1,x2,y2-7,color);
            }
        }
        line(x2,y2,x2,y2-6);
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
        outtextxy(1200-textwidth("Click Stanga")/2,90,"Click Stanga");
        outtextxy(1200-textwidth("pentru a crea o legatura")/2,110,"pentru a crea o legatura");
    }
}
void DrawDynamicLine(int indexBlock,int indexCircle,int &mouse_x,int &mouse_y)
{
    int actualX=mousex();
    int actualY=mousey();
    int lineStartX,lineStartY;

    if(CreatedBlocks[indexBlock].CB_type==1)
    {
        lineStartY=CreatedBlocks[indexBlock].dwnLeft.y;
        if(indexCircle==1)
        {
            lineStartX=CB_HitBox[indexBlock].dwnLeft.x-10;
            line(lineStartX+13,lineStartY,lineStartX,lineStartY);
        }
        else
        {
            lineStartX=CB_HitBox[indexBlock].upRight.x+10;
            line(lineStartX-13,lineStartY,lineStartX,lineStartY);
        }
    }
    else
    {
        lineStartY=CB_HitBox[indexBlock].dwnRight.y+3;
        lineStartX=(CB_HitBox[indexBlock].dwnLeft.x+CB_HitBox[indexBlock].upRight.x)/2;
        line(lineStartX,lineStartY-10,lineStartX,lineStartY);
    }
    if(actualX>110&&actualX<1025&&actualY>60&&actualY<760)
    if(mouse_x!=actualX||mouse_y!=actualY)
    {
        DrawSmartLine(lineStartX,lineStartY,mouse_x,mouse_y,15);
        DrawSmartLine(lineStartX,lineStartY,actualX,actualY,0);
        mouse_x=actualX;
        mouse_y=actualY;
    }
}
void ColorInTypeCircles(int indexCurrentBlock,int color)
{
    for(int indexBlock=0;indexBlock<nr_CreatedBlock;indexBlock++)
    {
        if(indexBlock!=indexCurrentBlock)
        {
            setfillstyle(SOLID_FILL, color);
            bar(CreatedBlocks[indexBlock].ConnectCircle[0].up_left.x+1, CreatedBlocks[indexBlock].ConnectCircle[0].up_left.y+3, CreatedBlocks[indexBlock].ConnectCircle[0].dwn_right.x-1, CreatedBlocks[indexBlock].ConnectCircle[0].dwn_right.y+1);
            if(overBTN(CreatedBlocks[indexBlock].ConnectCircle[0],mousex(),mousey())&&color!=15)
            {
                setfillstyle(SOLID_FILL, 3);
            bar(CreatedBlocks[indexBlock].ConnectCircle[0].up_left.x+1, CreatedBlocks[indexBlock].ConnectCircle[0].up_left.y+3, CreatedBlocks[indexBlock].ConnectCircle[0].dwn_right.x-1, CreatedBlocks[indexBlock].ConnectCircle[0].dwn_right.y+1);
            }
        }
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
                int mouse_x=mousex(),mouse_y=mousey();
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
                        InfoUserClicksCircles(1);
                        while (wait) {
                                ColorInTypeCircles(k,RGB(rand()%180,220,rand()%180));
                                DrawDynamicLine(k,h,mouse_x,mouse_y);
                                if (ismouseclick(WM_RBUTTONDOWN))
                                    {
                                        clearmouseclick(WM_RBUTTONDOWN);
                                        clearmouseclick(WM_RBUTTONUP);
                                        CleanRightArea();
                                        wait=0;
                                        DrawAllLines();
                                    }
                            if (ismouseclick(WM_LBUTTONDOWN)&&wait)
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
                                            DrawAllLines();
                                            wait = 0;
                                            ColorInTypeCircles(k,15);
                                            CleanRightArea();
                                            setfillstyle(SOLID_FILL, 15);
                                            bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                                            DrawBlock(CreatedBlocks[k], 4);
                                            }
                                clearmouseclick(WM_LBUTTONUP);
                                clearmouseclick(WM_LBUTTONDOWN);
                            }
                        }

                    }
                }
            }
        }
}

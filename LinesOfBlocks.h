#include "varSetup.h"
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
        line(x1,y1,x2,y2);
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
bool CheckOverBlockCircle()
{
    for (int k = 0; k < nr_CreatedBlock; k++)
        for (int h = 0; h < CreatedBlocks[k].nrCircles; h++)//test desenare pe cerc
        {

            //if(ismouseclick(WM_LBUTTONDOWN))
            if (overBTN(CreatedBlocks[k].ConnectCircle[h], mousex(), mousey())&&h!=0)
            {
                bool wait = 1, notClick = 1;
                DrawBlock(CreatedBlocks[k], 4);
                setfillstyle(SOLID_FILL, RGB(0, 100, 155));
                bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                while (wait)
                {
                    if (!overBTN(CreatedBlocks[k].ConnectCircle[h], mousex(), mousey()))
                    {
                        setfillstyle(SOLID_FILL, 15);
                        bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                        DrawBlock(CreatedBlocks[k], 0);
                        wait = 0;
                    }
                    if (ismouseclick(WM_LBUTTONDOWN) && wait) {
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

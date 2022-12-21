#include "varSetup.h"
/*
void calcDirectie(int curentx,int curenty,int Finalx,int Finaly)
{
    int difx=curent
}*/
void desenareLinii(int index)
{

    {
        for(int j=0;j<CreatedBlocks[index].nrLinesIn;j++)
        {
            for(int i=0;i<CreatedBlocks[index].nrCircles;i++)
            {setcolor(0);
    line(CreatedBlocks[index].ConnectCircle[i].up_left.x, CreatedBlocks[index].ConnectCircle[i].up_left.y, CreatedBlocks[index].vectIn[j].x, CreatedBlocks[index].vectIn[j].y);
       } }

    }
}

void CreateLine(int indexBlock1, int indexCerc1, int indexBlock2, int indexCerc2)
{
    Spot punctStart, punctFinal;
    punctStart.x = (CreatedBlocks[indexBlock1].ConnectCircle[indexCerc1].up_left.x + CreatedBlocks[indexBlock1].ConnectCircle[indexCerc1].dwn_right.x) / 2;
    punctStart.y = (CreatedBlocks[indexBlock1].ConnectCircle[indexCerc1].up_left.y + CreatedBlocks[indexBlock1].ConnectCircle[indexCerc1].dwn_right.y) / 2;

    punctFinal.x = (CreatedBlocks[indexBlock2].ConnectCircle[indexCerc2].up_left.x + CreatedBlocks[indexBlock2].ConnectCircle[indexCerc2].dwn_right.x) / 2;
    punctFinal.y = (CreatedBlocks[indexBlock2].ConnectCircle[indexCerc2].up_left.y + CreatedBlocks[indexBlock2].ConnectCircle[indexCerc2].dwn_right.y) / 2;

    if (CreatedBlocks[indexBlock1].CB_type != 1)
    {
        if (indexCerc1 == 0)
            punctStart.y = punctStart.y - 5;
        else
            punctStart.y = punctStart.y + 5;
    }
    if (CreatedBlocks[indexBlock2].CB_type != 1)
    {
        if (indexCerc2 == 0)
            punctFinal.y = punctFinal.y - 5;
        else
            punctFinal.y = punctFinal.y + 5;
    }

    setcolor(0);
    line(punctStart.x, punctStart.y, punctFinal.x, punctFinal.y);
        if(indexCerc1==0)
        {
            CreatedBlocks[indexBlock1].nrLinesIn++;
            CreatedBlocks[indexBlock1].vectIn[CreatedBlocks[indexBlock1].nrLinesIn].x=punctFinal.x;
            CreatedBlocks[indexBlock1].vectIn[CreatedBlocks[indexBlock1].nrLinesIn].y=punctFinal.y;
            CreatedBlocks[indexBlock2].nrLinesOut++;
            CreatedBlocks[indexBlock2].vectOut[CreatedBlocks[indexBlock2].nrLinesOut].x=punctStart.x;
            CreatedBlocks[indexBlock2].vectOut[CreatedBlocks[indexBlock2].nrLinesOut].y=punctStart.y;


        }
        else
            {CreatedBlocks[indexBlock1].nrLinesOut++;
            CreatedBlocks[indexBlock1].vectOut[CreatedBlocks[indexBlock1].nrLinesOut].x=punctStart.x;
            CreatedBlocks[indexBlock1].vectOut[CreatedBlocks[indexBlock1].nrLinesOut].y=punctStart.y;
            CreatedBlocks[indexBlock2].nrLinesIn++;
            CreatedBlocks[indexBlock2].vectIn[CreatedBlocks[indexBlock2].nrLinesIn].x=punctFinal.x;
            CreatedBlocks[indexBlock2].vectIn[CreatedBlocks[indexBlock2].nrLinesIn].y=punctFinal.y;

            }


}
//nu merge cu click ka nu day clear
//clearmouseclick(WM_LBUTTONUP);
           // clearmouseclick(WM_LBUTTONDOWN);

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
                setfillstyle(SOLID_FILL, RGB(0, 100, 155));
                bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                while (wait)
                {
                    if (!overBTN(CreatedBlocks[k].ConnectCircle[h], mousex(), mousey()))
                    {
                        setfillstyle(SOLID_FILL, 15);
                        bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                        DrawBlock(CreatedBlocks[k], 4);
                        wait = 0;
                    }
                    if (ismouseclick(WM_LBUTTONDOWN) && wait) {
                        clearmouseclick(WM_LBUTTONUP);
                        clearmouseclick(WM_LBUTTONDOWN);
                        while (wait) {
                            if (ismouseclick(WM_LBUTTONDOWN))
                            {
                                for (int p = 0; p < nr_CreatedBlock; p++)
                                    for (int r = 0; r < CreatedBlocks[p].nrCircles; r++)
                                        if (overBTN(CreatedBlocks[p].ConnectCircle[r], mousex(), mousey()) && ((h == 0 && r > 0) || (r == 0 && h > 0)) && k != p)
                                        {
                                            CreatedBlocks[k].isCircleConected[h]=1;
                                            CreatedBlocks[k].indexBlockConnexionTo[h]=p;
                                            CreatedBlocks[k].indexCirecleConnexionTo[h]=r;
                                            //CreatedBlocks[k].lineEndSpot.x=CreatedBlocks[p].ConnectCircle[r].up_left.x+5;
                                           // CreatedBlocks[k].lineEndSpot.y=CreatedBlocks[p].ConnectCircle[r].up_left.y;
                                            DrawLineOffBlock(k,0);
                                            //CreateLine(k, h, p, r);
                                            //memorare legaturi
                                            wait = 0;
                                            delay(700);
                                            setfillstyle(SOLID_FILL, 15);
                                            bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                                            DrawBlock(CreatedBlocks[k], 4);
                                            // dupa ce dai click pe cerculetul 2 esti deasupra lui si cand se iese din while wait se face 1 iar, rezolvare momentana cu delay
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

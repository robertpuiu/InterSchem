#include "varSetup.h"
/*
void calcDirectie(int curentx,int curenty,int Finalx,int Finaly)
{
    int difx=curent
}*/
void CreateLine(int indexBlock1,int indexCerc1,int indexBlock2,int indexCerc2 )
{
    Spot punctStart,punctFinal;
    punctStart.x=(CreatedBlocks[indexBlock1].ConnectCircle[indexCerc1].up_left.x+CreatedBlocks[indexBlock1].ConnectCircle[indexCerc1].dwn_right.x)/2;
    punctStart.y=(CreatedBlocks[indexBlock1].ConnectCircle[indexCerc1].up_left.y+CreatedBlocks[indexBlock1].ConnectCircle[indexCerc1].dwn_right.y)/2;

    punctFinal.x=(CreatedBlocks[indexBlock2].ConnectCircle[indexCerc2].up_left.x+CreatedBlocks[indexBlock2].ConnectCircle[indexCerc2].dwn_right.x)/2;
    punctFinal.y=(CreatedBlocks[indexBlock2].ConnectCircle[indexCerc2].up_left.y+CreatedBlocks[indexBlock2].ConnectCircle[indexCerc2].dwn_right.y)/2;

    if(CreatedBlocks[indexBlock1].CB_type!=1)
    {
        if(indexCerc1==0)
                punctStart.y=punctStart.y-13;
        else
            punctStart.y=punctStart.y+13;
    }
    if(CreatedBlocks[indexBlock2].CB_type!=1)
    {
        if(indexCerc2==0)
                punctFinal.y=punctFinal.y-13;
        else
            punctFinal.y=punctFinal.y+13;
    }

setcolor(0);

    line(punctStart.x,punctStart.y,punctFinal.x,punctFinal.y);

}
//nu merge cu click ka nu day clear
//clearmouseclick(WM_LBUTTONUP);
           // clearmouseclick(WM_LBUTTONDOWN);
 bool CheckOverBlockCircle()
 {
     for(int k=0;k<nr_CreatedBlock;k++)
            for(int h=0;h<CreatedBlocks[k].nrCircles;h++)//test desenare pe cerc
            {

            //if(ismouseclick(WM_LBUTTONDOWN))
            if(overBTN(CreatedBlocks[k].ConnectCircle[h],mousex(),mousey()))
        {
            bool wait=1,notClick=1;
            setfillstyle(SOLID_FILL, RGB(0, 100, 155));
                bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
        while(wait)
        {
            if(!overBTN(CreatedBlocks[k].ConnectCircle[h],mousex(),mousey()))
            {
                setfillstyle(SOLID_FILL, 15);
                bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                DrawBlock(CreatedBlocks[k],4);
                wait=0;
            }
            if(ismouseclick(WM_LBUTTONDOWN)&&wait){
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);
            while(wait){
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                for(int p=0;p<nr_CreatedBlock;p++)
            for(int r=0;r<CreatedBlocks[p].nrCircles;r++)
                if(overBTN(CreatedBlocks[p].ConnectCircle[r],mousex(),mousey())&&((h==0&&r>0) ||(r==0&&h>0)))
            {
                CreateLine(k,h,p,r);
                //memorare legaturi
                wait=0;
                delay(700);
                setfillstyle(SOLID_FILL, 15);
                bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
                DrawBlock(CreatedBlocks[k],4);
                // dupa ce dai click pe cerculetul 2 esti deasupra lui si cand se iese din while wait se face 1 iar, rezolvare momentana cu delay
            }
                clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);
            }}/*
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
 }}

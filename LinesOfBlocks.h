#include "varSetup.h"
void FillCirlce(int color, int k,int h)
{
    setfillstyle(SOLID_FILL, color);
    bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
}
 bool CheckOverBlockCircle()
 {
    // bool okay=0;
     for(int k=0;k<nr_CreatedBlock;k++)
            for(int h=0;h<CreatedBlocks[k].nrCircles;h++)//test desenare pe cerc
            if(overBTN(CreatedBlocks[k].ConnectCircle[h],mousex(),mousey()))
        {
                FillCirlce(RGB(0, 100, 155),k,h);
                //okay=1;

        }

 }

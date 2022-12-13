#include "varSetup.h"
 bool CheckOverBlockCircle()
 {
     for(int k=0;k<nr_CreatedBlock;k++)
            for(int h=0;h<CreatedBlocks[k].nrCircles;h++)//test desenare pe cerc
            if(overBTN(CreatedBlocks[k].ConnectCircle[h],mousex(),mousey()))
        {

            setfillstyle(SOLID_FILL, RGB(0, 100, 155));
                bar(CreatedBlocks[k].ConnectCircle[h].up_left.x, CreatedBlocks[k].ConnectCircle[h].up_left.y, CreatedBlocks[k].ConnectCircle[h].dwn_right.x, CreatedBlocks[k].ConnectCircle[h].dwn_right.y);
        }
 }

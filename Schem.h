#include "varSetup.h"
#include <graphics.h>

void DrawBlocks(Block Blocks[1])
{
 for(int i=0;i<1;i++)
    {
        setcolor(0);
        line(Blocks[i].upLeft.x,Blocks[i].upLeft.y,Blocks[i].upRight.x,Blocks[i].upRight.y);//sus
        line(Blocks[i].upRight.x,Blocks[i].upRight.y,Blocks[i].dwnRight.x,Blocks[i].dwnRight.y);//dreapta
        line(Blocks[i].upLeft.x,Blocks[i].upLeft.y,Blocks[i].dwnLeft.x,Blocks[i].dwnLeft.y);//stanga
        line(Blocks[i].dwnLeft.x,Blocks[i].dwnLeft.y,Blocks[i].dwnRight.x,Blocks[i].dwnRight.y);//jos
    }
}
void Schem()
{
   DrawBlocks(Blocks);

}

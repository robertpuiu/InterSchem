#include "varSetup.h"
/*
struct Button {
    Spot up_left;
    Spot dwn_right;
    char text[100];
    char Litera;
    int textSize;
    int color;
    bool selected=0; */
void    atribuireMainInsertCreatedBlocks()//aici am ramas
{


}
void atribuireMainInsert()
{
    int Y=150;
    char v[]="abcdefgh";
    for(int i=0;i<8;i++)
    {
        ButtonsInputs[i].up_left.x=1100;
        ButtonsInputs[i].up_left.y=Y;
        ButtonsInputs[i].dwn_right.x=1300;
        ButtonsInputs[i].dwn_right.y=Y+40;
        Y=Y+50;
        strncpy(ButtonsInputs[i].text,v+i,1);
        ButtonsInputs[i].Litera=v[i];
        ButtonsInputs[i].textSize=3;
        if(ButtonsInputs[i].selected==0)
        ButtonsInputs[i].color=2;
        else ButtonsInputs[i].color=4;
    }
}
void InserInput()
{
        int mouse_x = mousex();
        int mouse_y = mousey();
     DrawButtons(ButtonsInputs,8);
     bool ok=1;
     while(ok)
     {

         if(ismouseclick(WM_LBUTTONDOWN))
         {
             mouse_x = mousex();
             mouse_y = mousey();
             for(int i=0;i<8;i++)
                if(overBTN(ButtonsInputs[i],mouse_x,mouse_y))
             {
                 if(ButtonsInputs[i].selected==0)
                 {
                     ButtonsInputs[i].color=4;
                     ButtonsInputs[i].selected=1;
                     ButtonsInputs[i].selected==0;
                     DrawButtons(ButtonsInputs,8);
                     ok=0;
                 }
             }
         }
     }
     //delete var menu sau functie clean instrc
}
void MainInsertFNC(int i)
{
    atribuireMainInsert();
    if(i==0)
       InserInput();
}

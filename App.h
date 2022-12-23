#include "Schem.h"
#include <fstream>
using namespace std;
ofstream fout;
char typedText[100]="";
void ScrieTextSalvareSchema()
{
    setcolor(0);
    setbkcolor(15);
    settextstyle(3, HORIZ_DIR, 2);
    int x=1200-textwidth(typedText)/2;
    int y=400;
    outtextxy(x, y,typedText );//modificate coordonatele in fuctie de type

}
void AfisareTextSalvareSchema()
{
    setfillstyle(SOLID_FILL, 15);
    bar(1050, 100, 1350, 550);
    setcolor(0);
    setbkcolor(15);
    settextstyle(3 , HORIZ_DIR, 2);
    outtextxy(1120, 300,"Numeste noul fisier" );
    //ScrieTextSalvareSchema()

}
void SalvareSchema()
{
    AfisareTextSalvareSchema();
    int indexTypedText=0;
    char tasta,enter=13,backspace=8;
    bool ok=1;
    while(ok)
    {
        tasta=getch();
        if(tasta==enter)
        {
            AfisareTextSalvareSchema();
        ScrieTextSalvareSchema();
            break;
        }
        if(tasta==backspace)
        {
            AfisareTextSalvareSchema();
            typedText[--indexTypedText]=NULL;
        ScrieTextSalvareSchema();
        }
        if(tasta!=backspace)
        {
        typedText[indexTypedText]=tasta;
        indexTypedText++;
        AfisareTextSalvareSchema();
        ScrieTextSalvareSchema();
        }

    }
    setfillstyle(SOLID_FILL, 15);
    bar(1050, 100, 1350, 550);

}
void WriteOnFile();
void App()
{
    readimagefile("bckgnd.jpg", 0, 0, 1360, 765);
    setfillstyle(SOLID_FILL, RGB(0, 155, 155));
    DrawButtons(ButtonsApp, nrOfButtons);

    clearmouseclick(WM_LBUTTONDOWN);
    int mouse_x = mousex();
    int mouse_y = mousey();
    bool ok = 1;
    while (ok)
    {


        mouse_hover_m(mouse_x, mouse_y, ButtonsApp, nrOfButtons); //functioneaza pana la click

        if (ismouseclick(WM_LBUTTONUP))
        {
            mouse_x = mousex();
            mouse_y = mousey();
            if (overBTN(ButtonsApp[0], mouse_x, mouse_y))
            {
                clearmouseclick(WM_LBUTTONUP);
                clearmouseclick(WM_LBUTTONDOWN);
                ok = 0;
            }
            else if (overBTN(ButtonsApp[1], mouse_x, mouse_y))
            {
                setfillstyle(SOLID_FILL, 15);
                bar(0, 61, 1025, 900);
                clearmouseclick(WM_LBUTTONUP);
                clearmouseclick(WM_LBUTTONDOWN);
                DrawButtons(PannelSchem, nrOfButtons + 2);
                //mouse_hover_m(mouse_x,  mouse_y,PannelSchem,1);
                Schem();

            }
            else if(overBTN(ButtonsApp[3], mouse_x, mouse_y))
            {
                //strcpy(typedText,"");
                SalvareSchema();
                fout.open(typedText);
                WriteOnFile();
            }
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);

        }
    }
}
void WriteOnFile()
{
    for(int i=0;i<nr_CreatedBlock;i++)
      {
        fout<<"index: "<<i<<endl;
        fout<<"Tip bloc: ";
        switch(CreatedBlocks[i].CB_type)
        {
            case 0:fout<<"Input"<<endl;break;
            case 1:fout<<"If"<<endl;break;
            case 2:fout<<"Calcul"<<endl;break;
            case 3:fout<<"Output"<<endl;break;
        }
        fout<<"coordonate colt stanga sus: x="<<CreatedBlocks[i].upLeft.x<<" y="<<CreatedBlocks[i].upLeft.y<<endl;
        bool ok=0;
        for(int j=0;j<CreatedBlocks[i].nrCircles;j++)
            if(CreatedBlocks[i].isCircleConected[j])
                ok=1;
        if(ok)
        {
            fout<<"Este conectat la blocurile cu indicii: (index cerc block curent, indicele blocului la care este conectat -> indicele cercului la care este conectat)"<<endl;
        for(int j=0;j<CreatedBlocks[i].nrCircles;j++)
            if(CreatedBlocks[i].isCircleConected[j])
                    fout<<"("<<j<<","<<CreatedBlocks[i].indexBlockConnexionTo[j]<<"->"<<CreatedBlocks[i].indexCirecleConnexionTo[j]<<")"<<"";
        fout<<endl;}
        fout<<"Textul blocului: "<<CreatedBlocks[i].inputText<<endl<<endl<<endl;
      }
}

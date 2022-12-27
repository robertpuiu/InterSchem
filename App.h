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
int indexBlockIfBehind[20]={0};
int indexIFBehind=0;
int indentation=0;
void WriteCodeOfBlock(int indexBlock)
{
    CreatedBlocks[indexBlock].ConnectCircle[0].visited++;
    char LineToDisplay[256]="";
    delay(150);
    setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    if(CreatedBlocks[indexBlock].inputText)
    {if(CreatedBlocks[indexBlock].CB_type==0)
        {strcat(LineToDisplay,"cin>>");strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,";");outtextxy(1120+indentation, yLineWriten ,LineToDisplay );}
    if(CreatedBlocks[indexBlock].CB_type==1)
        {
            if(CreatedBlocks[indexBlock].ConnectCircle[0].selected==1)
            {
                strcat(LineToDisplay,"if(");strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,")");
            outtextxy(1120+indentation, yLineWriten ,LineToDisplay );
            yLineWriten+=20;
            indentation+=20;
            outtextxy(1120+indentation, yLineWriten ,"{" );
            indexBlockIfBehind[indexIFBehind]=indexBlock;
            indexIFBehind++;
            }
            else
            {
                strcat(LineToDisplay,"While(");strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,")");
            outtextxy(1120+indentation, yLineWriten ,LineToDisplay );
            yLineWriten+=20;
            indentation+=20;
            outtextxy(1120+indentation, yLineWriten ,"{" );
            indexBlockIfBehind[indexIFBehind]=indexBlock;
            indexIFBehind++;

            }

            }
    if(CreatedBlocks[indexBlock].CB_type==2)
        {strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,";");outtextxy(1120+indentation, yLineWriten ,LineToDisplay );}
    if(CreatedBlocks[indexBlock].CB_type==3)
            {strcat(LineToDisplay,"cout>>");strcat(LineToDisplay,CreatedBlocks[indexBlock].inputText);strcat(LineToDisplay,";");outtextxy(1120+indentation, yLineWriten ,LineToDisplay );}

    strcpy(LineToDisplay,"");
    yLineWriten+=20;
    }
}
void GoThroughSchemLeft(int indexCurrentBlock)
{
    while(CreatedBlocks[indexCurrentBlock].ConnectCircle[1].color!=4&&(CreatedBlocks[indexCurrentBlock].ConnectCircle[0].selected==CreatedBlocks[indexCurrentBlock].ConnectCircle[0].visited+1||CreatedBlocks[indexCurrentBlock].CB_type==1))
    {
        if(CreatedBlocks[indexCurrentBlock].ConnectCircle[0].selected>1&&CreatedBlocks[indexCurrentBlock].CB_type!=1)
        {
            for(int i=0;i<CreatedBlocks[indexCurrentBlock].ConnectCircle[0].selected-1;i++)
            {
                outtextxy(1120+indentation, yLineWriten ,"}" );
    indentation-=20;
    yLineWriten+=20;
            }
        }
        if(!(CreatedBlocks[indexCurrentBlock].CB_type==1&&CreatedBlocks[indexCurrentBlock].ConnectCircle[0].visited))
        WriteCodeOfBlock(indexCurrentBlock);
        indexCurrentBlock=CreatedBlocks[indexCurrentBlock].indexBlockConnexionTo[1];
    }
    if(CreatedBlocks[indexCurrentBlock].ConnectCircle[1].color==4)
    {
    WriteCodeOfBlock(indexCurrentBlock);
    setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(1120+indentation, yLineWriten ,"return 0;" );
    yLineWriten+=20;

    outtextxy(1120+indentation, yLineWriten ,"}" );
    indentation-=20;
    yLineWriten+=20;
    }
    else //if(CreatedBlocks[indexCurrentBlock].CB_type!=1)
        {
            CreatedBlocks[indexCurrentBlock].ConnectCircle[0].visited++;
            outtextxy(1120+indentation, yLineWriten ,"}end of branch" );
           // cout<<CreatedBlocks[indexCurrentBlock].inputText<<endl;
    indentation-=20;
    yLineWriten+=20;
    }
}
void GoThroughSchem()
{
    int indexCurrentBlock=indexStartBlock;

    GoThroughSchemLeft(indexCurrentBlock);
    while(indexIFBehind>-1)
    {
        if(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].ConnectCircle[2].color==4)
        {
            setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(1120+indentation, yLineWriten ,"}" );

    yLineWriten+=20;
    outtextxy(1120+indentation, yLineWriten ,"else return 0;" );
    indentation-=20;
    yLineWriten+=20;
        }
        else
        {
    if(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].CB_type==1)
            {
                setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    if(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].ConnectCircle[0].selected==1)
    {
        outtextxy(1120+indentation, yLineWriten ,"else" );
    yLineWriten+=20;
    indentation+=20;
    outtextxy(1120+indentation, yLineWriten ,"{" );
    yLineWriten+=20;
    }
    if(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].ConnectCircle[0].visited+2==CreatedBlocks[indexBlockIfBehind[indexIFBehind]].ConnectCircle[0].selected)
    {
        setcolor(0);
    setbkcolor(15);
    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(1120+indentation, yLineWriten ,"}" );
    yLineWriten+=20;
    }
    GoThroughSchemLeft(CreatedBlocks[indexBlockIfBehind[indexIFBehind]].indexBlockConnexionTo[2]);
            }
        }
        indexIFBehind--;
    }

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
            clearmouseclick(WM_LBUTTONUP);
            clearmouseclick(WM_LBUTTONDOWN);
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
            else if(overBTN(PannelSchem[0],mouse_x,mouse_y))
            {
                yLineWriten=130;
                GoThroughSchem();
            }

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
        if(CreatedBlocks[i].isStart)
        fout<<"Este blocul de start"<<endl;
        if(CreatedBlocks[i].isStop)
        fout<<"Este bloc de stop"<<endl;
        fout<<"Textul blocului: "<<CreatedBlocks[i].inputText<<endl<<endl<<endl;
      }
}

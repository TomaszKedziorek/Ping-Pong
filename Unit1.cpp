//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cstdlib>
#include "mmsystem.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
    int los(int a, int b) {
        int n = 1;
        do{
            n = rand()%(b-a+1)+a;
        }while( n==0);
        return  n;
    }
    int speed;
    int x;
    int y;
    int hits = 0;
    int bluePoints = 0;
    int greenPoints = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    srand(time(NULL));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{

    ball -> Left += x;
    ball -> Top  += y;

    //odbicie od g�rnej sciany
    if ( ball -> Top -8 <= background -> Top ){
        y = -y;
    }

    //odbicie od dolnej sciany
    if ( ball -> Top + ball -> Height + 8 >= background -> Height){
        y = -y ;
    }
    /*
    if ( ball -> Left + ball -> Width + 4 >= background -> Width){
        x = -x;
    }
    if ( ball -> Left - 4 <= background -> Left){
        x = -x;
    }
    */
    //przegrana padel 1
    if ( ball -> Left <= padel1 -> Left + padel1 -> Width - 15 ) {
        ballTimer -> Enabled = false;
        padel1 -> Enabled = false;
        Button1 -> Visible = true;
        Button2 -> Visible = true;
        bluePoints ++;
        winer -> Visible = true;
        winer -> Caption ="  Punkt dla niebieskiego! >>";
        points -> Visible = true;
        points -> Caption = IntToStr( greenPoints) + " : " +IntToStr( bluePoints);
        padelHits -> Visible = true;
        padelHits -> Caption = "Ilo�� odbi�: " + IntToStr( hits) ;
    }
    //odbicie pilki ball od paletki padel1
    else if( ball -> Left <= padel1 -> Left + padel1 -> Width   &&
             ball -> Top < padel1 -> Top + padel1 -> Height &&
             ball -> Top + ball -> Height > padel1 -> Top) {
             if ( x < 0 ) {
                x = los(8 , 12);
                y = los(-1,1) * los(8,12);
                hits++;
             }
    }

    //przegrana padel 2
    if ( ball -> Left + ball -> Width >= padel2 -> Left + padel2 -> Width + 15 ) {
        ballTimer -> Enabled = false;
        padel2 -> Enabled = false;
        Button1 -> Visible = true;
        Button2 -> Visible = true;
        greenPoints++;
        winer -> Visible = true;
        winer -> Caption ="<< Punkt dla zielonego!  ";
        points -> Visible = true;
        points -> Caption = IntToStr( greenPoints) + " : " +IntToStr( bluePoints);
        padelHits -> Visible = true;
        padelHits -> Caption = "Ilo�� odbi�: " + IntToStr( hits) ;
    }
    //odbicie pilki ball od paletki padel2
    else if( ball -> Left + ball-> Width  >= padel2 -> Left  &&
             ball -> Top < padel2 -> Top + padel2 -> Height &&
             ball -> Top + ball -> Height > padel2 -> Top) {
             if ( x > 0 ) {
                x = -los(8 , 12);
                y = los(-1,1) * los(8,12);
                hits++;
             }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    //padel 2
    if( Key == VK_UP ) padel2UpTimer -> Enabled = true;
    if( Key == VK_DOWN ) padel2DownTimer -> Enabled = true;
    //padel 1
    if( Key == 'w' || Key == 'W' ) padel1UpTimer -> Enabled = true;
    if( Key == 's' || Key == 'S'  ) padel1DownTimer -> Enabled = true;
    //spacja nowa runda
    if( Key == VK_SPACE && Button2 -> Visible == true ) Form1 -> Button2Click( Form1 );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    //padel 2
    if( Key == VK_UP ) padel2UpTimer -> Enabled = false;
    if( Key == VK_DOWN ) padel2DownTimer -> Enabled = false;
    //padel 1
    if( Key == 'w' || Key == 'W' ) padel1UpTimer -> Enabled = false;
    if( Key == 's' || Key == 'S'  ) padel1DownTimer -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::padel1UpTimerTimer(TObject *Sender)
{
    if ( padel1 -> Top > 20 )
        padel1 -> Top -= 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::padel1DownTimerTimer(TObject *Sender)
{
    if ( padel1 -> Top + padel1 -> Height < background -> Height -20 )
        padel1 -> Top += 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::padel2UpTimerTimer(TObject *Sender)
{
    if ( padel2 -> Top > 20 )
        padel2 -> Top -= 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::padel2DownTimerTimer(TObject *Sender)
{
    if ( padel2 -> Top + padel2 -> Height < background -> Height -20 )
        padel2 -> Top += 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Form1 -> Button2Click( Form1 );
    pingpong -> Visible = false;
    bluePoints = 0;
    greenPoints = 0;
    ball -> Left = 352;
    ball -> Top  = 280;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    ball -> Top = los(16,512);
    ball -> Left  = 352;
    padel1 -> Left = 24;
    padel1 -> Top = 200;
    padel2 -> Left = 704;
    padel2 -> Top = 200;
    hits = 0;
    speed = los(6,8);
    x = los(-1,1)*speed;
    y = los(-1,1)*speed;

    Button1 -> Visible = false;
    Button2 -> Visible = false;
    winer -> Visible = false;
    points -> Visible = false;
    padelHits -> Visible = false;
    ballTimer -> Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    pingpong -> Visible = true;
    Button1 -> Visible = true;
    AnsiString text1 = "Witamy w Ping-Pong\n\n Zielony: w-g�ra, s-d� \n Niebieski: strza�ki g�ram, d�.";
    AnsiString text2 = "\n\nPr�dko�� pi�ki jest lsowa przy ka�dym odbiciu.";
    AnsiString text3 = "\n\nSpacja - nowa runda.";
    AnsiString text4 = text1 + text3 + text2;
    if (Application -> MessageBox( text4.c_str(), "Sterowanie", MB_OK ) == IDOK)
        Form1 -> BringToFront();
}
//---------------------------------------------------------------------------




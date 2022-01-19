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
    AnsiString hitSound(){
        return "snd/hit (" + IntToStr( los(1, 5)) +").wav";
    }
    int speed;
    int x;
    int y;
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

    //odbicie od lewej sciany
    if ( ball -> Left -4 <= background -> Left ){
        x = -x;
        sndPlaySound( hitSound().c_str(), SND_ASYNC);
    }
    //odbicie od prawej sciany
    if ( ball -> Left + ball -> Width + 4 >= background -> Width){
        x = -x;
        sndPlaySound( hitSound().c_str(), SND_ASYNC);
    }

    //przegrana padel 1
    if ( ball -> Top + ball -> Height >= padel1 -> Top + padel1 -> Height + 15 ) {
        ballTimer -> Enabled = false;
        padel1 -> Enabled = false;
        Button1 -> Visible = true;
        Button2 -> Visible = true;
        bluePoints ++;
        winer -> Visible = true;
        winer -> Caption ="Punkt dla niebieskiego!";
        points -> Visible = true;
        points -> Caption = IntToStr( greenPoints) + " : " +IntToStr( bluePoints);
    }
    //odbicie pilki ball od paletki padel1
    else if( ball -> Left > padel1 -> Left - ball -> Width &&
             ball -> Left < padel1 -> Left + padel1 -> Width &&
             ball -> Top + ball -> Height >= padel1 -> Top ) {
             sndPlaySound( hitSound().c_str(), SND_ASYNC);
             if ( y > 0 ) {
                y = -los(6 , 10);
             }
    }
    //przegrana padel 2
    if ( ball -> Top <= padel2 -> Top + padel2 -> Height - 15 ) {
        ballTimer -> Enabled = false;
        padel2 -> Enabled = false;
        Button1 -> Visible = true;
        Button2 -> Visible = true;
        greenPoints++;
        winer -> Visible = true;
        winer -> Caption ="Punkt dla zielonego!";
        points -> Visible = true;
        points -> Caption = IntToStr( greenPoints) + " : " +IntToStr( bluePoints);
    }
    //odbicie pilki ball od paletki padel2
    else if( ball -> Left + ball-> Width  > padel2 -> Left  &&
             ball -> Left < padel2 -> Left + padel2 -> Width &&
             ball -> Top  <= padel2 -> Top + padel2 -> Height) {
             sndPlaySound( hitSound().c_str(), SND_ASYNC);
             if ( y < 0 ) {
                y = los(6 , 10);
             }
    }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    //padel 1
    if( Key == VK_LEFT ) padel1LeftTimer -> Enabled = true;
    if( Key == VK_RIGHT ) padel1RightTimer -> Enabled = true;
    //padel 2
    if( Key == 'a' || Key == 'A' ) padel2LeftTimer -> Enabled = true;
    if( Key == 'd' || Key == 'D'  ) padel2RightTimer -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    //padel 1
    if( Key == VK_LEFT ) padel1LeftTimer -> Enabled = false;
    if( Key == VK_RIGHT ) padel1RightTimer -> Enabled = false;
    //padel 2
    if( Key == 'a' || Key == 'A' ) padel2LeftTimer -> Enabled = false;
    if( Key == 'd' || Key == 'D'  ) padel2RightTimer -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::padel1LeftTimerTimer(TObject *Sender)
{
    if ( padel1 -> Left > 10 )
        padel1 -> Left -= 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::padel1RightTimerTimer(TObject *Sender)
{
    if ( padel1 -> Left + padel1 -> Width < background -> Width -10 )
        padel1 -> Left += 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::padel2LeftTimerTimer(TObject *Sender)
{
    if ( padel2 -> Left > 10 )
        padel2 -> Left -= 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::padel2RightTimerTimer(TObject *Sender)
{
    if ( padel2 -> Left + padel1 -> Width < background -> Width -10 )
        padel2 -> Left += 20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Form1 -> Button2Click( Form1 );
    pingpong -> Visible = false;
    bluePoints = 0;
    greenPoints = 0;
    ball -> Left = 232;
    ball -> Top  = 232;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    ball -> Left = los(16,472);
    ball -> Top  = 232;
    padel1 -> Left = 176;
    padel2 -> Left = 176;

    speed = los(6,10);
    x = los(-1,1)*speed;
    y = los(-1,1)*speed;

    Button1 -> Visible = false;
    Button2 -> Visible = false;
    winer -> Visible = false;
    points -> Visible = false;
    ballTimer -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
       pingpong -> Visible = true;
       Button1 -> Visible = true;
       AnsiString text1 = "Witamy w Ping-Pong\n\n Niebieski: a-lewo, d-prawo\n Zielony: strza³ki prowo lewo";
       AnsiString text2 = "\n\nPrêdkoœæ pi³ki jest lsowa przy ka¿dym odbiciu.";
       AnsiString text3 = text1 + text2;
       Application -> MessageBox(text3.c_str(), "Sterowanie", MB_OK );
}
//---------------------------------------------------------------------------


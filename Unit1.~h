//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *ball;
    TTimer *ballTimer;
    TShape *background;
    TImage *padel1;
    TImage *padel2;
    TTimer *padel1LeftTimer;
    TTimer *padel1RightTimer;
    TTimer *padel2RightTimer;
    TTimer *padel2LeftTimer;
    TButton *Button1;
    TButton *Button2;
    TLabel *winer;
    TLabel *points;
    TLabel *pingpong;
    void __fastcall ballTimerTimer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall padel1LeftTimerTimer(TObject *Sender);
    void __fastcall padel1RightTimerTimer(TObject *Sender);
    void __fastcall padel2LeftTimerTimer(TObject *Sender);
    void __fastcall padel2RightTimerTimer(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

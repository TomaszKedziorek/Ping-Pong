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
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *ball;
    TTimer *ballTimer;
    TShape *background;
    TImage *padel1;
    TImage *padel2;
    TTimer *padel1UpTimer;
    TTimer *padel1DownTimer;
    TTimer *padel2DownTimer;
    TTimer *padel2UpTimer;
    TButton *Button1;
    TButton *Button2;
    TLabel *winer;
    TLabel *points;
    TLabel *pingpong;
    TLabel *padelHits;
    void __fastcall ballTimerTimer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall padel1UpTimerTimer(TObject *Sender);
    void __fastcall padel1DownTimerTimer(TObject *Sender);
    void __fastcall padel2UpTimerTimer(TObject *Sender);
    void __fastcall padel2DownTimerTimer(TObject *Sender);
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

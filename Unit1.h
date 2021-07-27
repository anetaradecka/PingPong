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
        TShape *background;
        TImage *ball;
        TTimer *timerBall;
        TImage *paddle1;
        TImage *paddle2;
        TTimer *timer_paddle1_up;
        TTimer *timer_paddle1_down;
        TTimer *timer_paddle2_up;
        TTimer *timer_paddle2_down;
        TButton *startGame;
        void __fastcall timerBallTimer(TObject *Sender);
        void __fastcall timer_paddle1_upTimer(TObject *Sender);
        void __fastcall timer_paddle1_downTimer(TObject *Sender);
        void __fastcall timer_paddle2_upTimer(TObject *Sender);
        void __fastcall timer_paddle2_downTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall startGameClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

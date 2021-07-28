//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <sstream>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
        int x = -8;
        int y = -8;
        bool gameHasStarted = false;
        int paddle1_points = 0;
        int paddle2_points = 0;
        int balls = 0;
        int rounds = 0;

        void showScore()
        {
                Form1->score->Visible = true;
                AnsiString paddle1 = IntToStr(paddle1_points);
                AnsiString paddle2 = IntToStr(paddle2_points);
                Form1->score->Caption = "score: " + paddle1 + " : " + paddle2;
        }

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top += y;

  //odbij od gornej sciany
        if(ball->Top - 5 <= background->Top) y = -y;

  //odbij od dolnej sciany
        if(ball->Top + ball->Height - 5 >= background->Height) y = -y;

  //skucha z lewej strony
        if (((ball->Top < paddle1->Top - ball->Height/2) ||
           (ball->Top + ball->Height > paddle1->Top + paddle1->Height + ball->Height/2)) &&
            ball->Left <= paddle1->Left + paddle1->Width)
        {
                timerBall->Enabled = false;
                ball->Visible = false;
                gameHasStarted = false;
                startGame->Visible = true;
                nextRound->Visible = true;
                paddle2_points++;
                showScore();
                //score->Visible = true;
                //AnsiString paddle1 = IntToStr(paddle1_points);
                //AnsiString paddle2 = IntToStr(paddle2_points);
                //score->Caption = "score: " + paddle1 + " : " + paddle2;
                //balls->Visible = true;
                //AnsiString ballsNo = IntToStr(balls);
                //balls->Caption = "balls bounced back: " + ballsNo;
                //pointFor->Visible = true;
                //pointFor->Caption = "Point for the right player";
        }
  //odbicie pilki z lewej strony
        if (ball->Top - ball->Height / 2 >= paddle1->Top &&
            ball->Top - ball->Height <= paddle1->Top + paddle1->Height &&
            ball->Left <= paddle1->Left + paddle1->Width)
         /*(ball->Top >= paddle1->Top - ball->Height/2 &&
            ball->Top + ball->Height <= paddle1->Top + paddle1->Height + ball->Height/2 &&
            ball->Left == paddle1->Left + paddle1->Width)*/
        {
                if (x < 0)
                {
                x = -x;
                balls++;
                if (timerBall->Interval > 1)
                timerBall->Interval -= 1;
                }
        }

  //skucha z prawej strony (prawy bok pilki == prawy bok okna)
        if (((ball->Top < paddle2->Top - ball->Height/2) ||
           (ball->Top + ball->Height > paddle2->Top + paddle2->Height + ball->Height/2)) &&
            ball->Left + ball->Width >= paddle2->Left)
        {
                timerBall->Enabled = false;
                ball->Visible = false;
                gameHasStarted = false;
                startGame->Visible = true;
                nextRound->Visible = true;
                paddle1_points++;
                showScore();
                //score->Visible = true;
                //AnsiString paddle1 = IntToStr(paddle1_points);
                //AnsiString paddle2 = IntToStr(paddle2_points);
                //score->Caption = "score: " + paddle1 + " : " + paddle2;
                //balls->Visible = true;
                //AnsiString ballsNo = IntToStr(balls);
                //balls->Caption = "balls bounced back: " + ballsNo;
                //pointFor->Visible = true;
                //pointFor->Caption = "Point for the right player";
        }
  //odbicie pilki z prawej strony
        if (ball->Top >= paddle2->Top  - ball->Height / 2 &&
        ball->Top  <= paddle2->Top + paddle2->Height &&
        ball->Left + ball->Width >= paddle2->Left)
        {
                {
                x = -x;
                balls++;
                if (timerBall->Interval > 1)
                timerBall->Interval -= 1;
                }
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::timer_paddle1_upTimer(TObject *Sender)
{
        if(paddle1->Top > 10) paddle1->Top -= 10;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timer_paddle1_downTimer(TObject *Sender)
{
        if(paddle1->Top + paddle1->Height < background->Height - 10)
        paddle1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timer_paddle2_upTimer(TObject *Sender)
{
         if(paddle2->Top > 10) paddle2->Top -= 10;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timer_paddle2_downTimer(TObject *Sender)
{
        if(paddle2->Top + paddle2->Height < background->Height - 10)
        paddle2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    //dla prawej paletki
        if (Key == VK_UP) timer_paddle2_up->Enabled = true;
        if (Key == VK_DOWN) timer_paddle2_down->Enabled = true;

   //dla lewej paletki
        if (Key == 0x41) timer_paddle1_up->Enabled = true;
        if (Key == 0x5A) timer_paddle1_down->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    //dla prawej paletki
        if (Key == VK_UP) timer_paddle2_up->Enabled = false;
        if (Key == VK_DOWN) timer_paddle2_down->Enabled = false;

   //dla lewej paletki
        if (Key == 0x41) timer_paddle1_up->Enabled = false;
        if (Key == 0x5A) timer_paddle1_down->Enabled = false;
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        timerBall->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::startGameClick(TObject *Sender)
{
        if (gameHasStarted == false)
        {
        // ustawiam pilke na srodku planszy
                ball->Left = background->Left + background->Width/2;
                ball->Top = background->Top + background->Height/2;
        // wlaczam gre
                gameHasStarted = true;
                timerBall->Enabled = true;
                ball->Visible = true;
        //wylaczam zbedne funkcje
                startGame->Visible = false;
                nextRound->Visible = false;
                score->Visible = false;
                balls->Visible = false;
                pointFor->Visible = false;
                paddle1_points = 0;
                paddle2_points = 0;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
        rounds++;
        // ustawiam pilke na srodku planszy
        ball->Left = background->Left + background->Width/2;
        ball->Top = background->Top + background->Height/2;
        // wlaczam gre
        timerBall->Enabled = true;
        ball->Visible = true;
        //wylaczam zbedne funkcje
        startGame->Visible = false;
        nextRound->Visible = false;
        pointFor->Visible = false;
        score->Visible = false;
        balls->Visible = false;

}
//---------------------------------------------------------------------------



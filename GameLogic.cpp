#include "GameLogic.h"

GameLogic::GameLogic(std::shared_ptr<Ball> ball, std::shared_ptr<HUD> hud) 
    : pBall(ball)
    , pHud(hud)
{
    if (mGoalSoundBuffer.loadFromFile("Sounds\\goal.mp3"))
        mGoalSound.setBuffer(mGoalSoundBuffer);
}

void GameLogic::Update(float dt)
{
    if (pBall->GetPosition().x < 0)
    {
        mScore.first++;

        UpdateAfterGoal();
        PlaySound();
    }

    if (pBall->GetPosition().x > Window::ScreenWidth)
    {
        mScore.second++;

        UpdateAfterGoal();
        PlaySound();
    }
}

void GameLogic::Render(Window& wnd)
{
}

void GameLogic::UpdateAfterGoal()
{
    pBall->SetDefPositionAndDirection();
    pBall->SetSpeed(400.0f);
    pHud->SetScore(mScore);
}

void GameLogic::PlaySound()
{
    if (mGoalSound.getBuffer())
        mGoalSound.play();
}

#include "FPSCountDraw.h"
#include "FontTexture.h"

FPSDrawer::FPSDrawer(FPSCounter& fpsCounter)
    : _fpsCounter(fpsCounter)
{
}


FPSDrawer::~FPSDrawer()
{
}


void FPSDrawer::Draw()
{
    FontTexture::DrawString(Vector2D::zero, std::to_string(_fpsCounter.GetFPS()));
    FontTexture::DrawString(Vector2D(0, 568), std::to_string(_fpsCounter.GetDeltaTime()));
}
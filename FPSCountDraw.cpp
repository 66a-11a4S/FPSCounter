#include "FPSCounter.h"
#include "DxLib.h"

void FPSCounter::Draw()
{
    DrawFormatString(0, 0, GetColor(0x00, 0x00, 0x00), "fps : %.3f", _avarageFPS);
}
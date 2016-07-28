#include "FPSCounter.h"
using namespace std::chrono;

FPSCounter::FPSCounter(int samplingFrame)
    : _samplingFrame(samplingFrame)
    , _countingFrame(0)
    , _totalTime(0)
    , _avarageFPS(0)
{
}


FPSCounter::~FPSCounter()
{
}


void FPSCounter::Update()
{
    //前フレームからここまでの時間をmicro秒で計測
    _currentTime = system_clock::now();
    _totalTime += duration<long double, std::micro>(_currentTime - _beforeTime).count();

    //計測時間更新
    _beforeTime = _currentTime;

    //フレームカウント更新
    _countingFrame++;

    //サンプリング数まで達したら再計算
    if (_countingFrame == _samplingFrame)
    {
        //1フレーム当たりの時間を出して
        long double avarageTime = (_totalTime / _samplingFrame);
        //μ(マイクロ) = 1.000.000
        _avarageFPS = 1000000 / (avarageTime);

        //フレームカウンタをリセット
        _countingFrame = 0;
        _totalTime = 0;

        return;
    }
}
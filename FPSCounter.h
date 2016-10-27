#pragma once
#include <vector>
#include <chrono>

class FPSCounter
{
public:
    FPSCounter(int samplingFrame);
    ~FPSCounter();

    void Update();

    int GetCountingFrame() const { return _countingFrame; }
    double GetFPS() const { return _avarageFPS; }
    static double GetDeltaTime() { return _deltaTime; }

private:

    //移動平均を適用するフレーム数
    int _samplingFrame;
    //計測開始から今までのフレーム数
    int _countingFrame;

    //表示するFPS
    long double _avarageFPS;
    //毎フレーム分カウントした値の総和
    long double _totalTime;
    //前フレームからの経過時間
    static long double _deltaTime;

    //前フレームでの時刻
    std::chrono::system_clock::time_point _beforeTime;
    //現在フレームでの時刻
    std::chrono::system_clock::time_point _currentTime;
};


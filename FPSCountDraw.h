#ifndef FPSDrawer_h
#define FPSDrawer_h

#include "FPSCounter.h"

class FPSDrawer
{
public:
    
    FPSDrawer(FPSCounter& fpsCounter);
    ~FPSDrawer();
    
    void Draw();
    
private:

    FPSCounter& _fpsCounter;
};


#endif /* FPSDrawer_h */

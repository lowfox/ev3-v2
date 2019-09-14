#pragma once

#include "modeSwitcher.h"
#include "braker.h"
#include "angularVelocityDetector.h"
#include "lineTracer.h"
#include <RyujiEv3.h>
#include<Logger.h>
#include"seesawGlobal.h"


#include"tailPositioner.h"
#include"infoTail.h"

#include"../../app.h"
//linetraceTEST
#include <Steering.h>
#include<Drive.h>
#include"distanceRunner.h"

class gotoSeesaw{
    public:
        bool run(void);
        //static float gotoNowDistance=0.0f;
        //static float gotoLastDistance;

    private:
        int32 m_pwm = 4;
        int16 m_seesawDetectValue =6;
        float m_gotoPeriodDistance=100.0f;
        float m_detectDistance=10.0f;
        int m_lineReturnTime=600;
        int16 m_initAngle=90;
       
};


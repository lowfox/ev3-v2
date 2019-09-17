﻿#include "TailControl.h"
#include <stdexcept>
bool TailControl::Angle(int32 target_val, int32 speed) {
#ifdef __LOOKUP_DEBUG__
  if (!StbAngle(target_val, speed)) {
    return false;
  }
#else
  if (!RyujiEv3Engine::GetTailMotor()->setCounts(target_val, speed, true)) {
    return false;
  }
#endif
  return true;
}

#ifdef __LOOKUP_DEBUG__
bool TailControl::StbAngle(int32 target_val, int32 speed) {
  if (target_val != MAX_TARGET && target_val != MIN_TARGET) {
    return false;
  }
  if (speed < 0) {
    return false;
  }
  return true;
}
#endif

bool TailControl::StageAngle(int32 target_val) {
  auto diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();  //目的角度の差
  auto now_dist = Steering::GetDistance();  //今までモーターの回転数
  Drive::SetDriveMode(DriveMode::Nomal);

  if (target_val == MIN_TARGET) {
    if (!RyujiEv3Engine::GetTailMotor()->setCounts(-2, 1, true)) {
      return false;
    }

    tslp_tsk(250);
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = 76 - diff_val;

    if (diff_val >= ANGLE_ADJUST_1) {
      diff_val += ANGLE_ADJUST_VAL_1;
    }

    if (!RyujiEv3Engine::GetTailMotor()->setCounts(-6 + diff_val, 1, true)) {
      return false;
    }

    tslp_tsk(250);
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = 69 - diff_val;

    if (diff_val >= ANGLE_ADJUST_2) {
      diff_val += ANGLE_ADJUST_VAL_2;
    }

    if (!RyujiEv3Engine::GetTailMotor()->setCounts(-10 + diff_val, 1, true)) {
      return false;
    }

    tslp_tsk(500);
    return true;
  }

  // Phase2中に態勢を戻すとき使用する。
  else if (target_val == MAX_TARGET) {
    diff_val = (64 - diff_val);

    if (!Drive::Drive(-10)) {
      return false;
    }

    while (Steering::GetDistance() - now_dist > -5) {
    }
    if (!RyujiEv3Engine::GetTailMotor()->setCounts(diff_val, 100, true)) {
      return false;
    }

    Drive::Stop();
    tslp_tsk(1000);

    now_dist = Steering::GetDistance();
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = (72 - diff_val);

    if (!Drive::Drive(-10)) {
      return false;
    }

    while (Steering::GetDistance() - now_dist > -5) {
    }

    if (!RyujiEv3Engine::GetTailMotor()->setCounts(diff_val, 70, true)) {
      return false;
    }

    Drive::Stop();
    tslp_tsk(1000);

    now_dist = Steering::GetDistance();
    diff_val = RyujiEv3Engine::GetTailMotor()->getCounts();
    diff_val = (79 - diff_val);
    if (diff_val <= MAX_TARGET_BOUNDARY) {
      return true;
    }

    if (!Drive::Drive(-10)) {
      return false;
    }

    while (Steering::GetDistance() - now_dist > -5) {
    }
    if (!RyujiEv3Engine::GetTailMotor()->setCounts(diff_val, 20, true)) {
      return false;
    }

    Drive::Stop();
    tslp_tsk(1000);
    return true;
  }

  return false;
}
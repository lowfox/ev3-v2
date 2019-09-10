// MapStateControl.cpp
// includeファイル
#include "MapStateControl.h"
#include <Logger.h>
#include <RyujiEv3.h>

// 定数定義
#define ERROR -1

MapStateControl::MapStateControl()
{
}

MapStateControl::~MapStateControl()
{
}

MapState MapStateControl::drivePosition() {
  static int nowState = 0;      //現在の走行状態
  float milage = 0.0f;          //累計距離



  //累計距離取得
  milage = DistanceMeasure::getDistance();

  //コースがLかRによって処理を切り替え(設定されていなければエラー終了)
  if (COURSE_MODE == LEFT_COURSE) {
    //現在の距離が現在の規定距離を超え、ゴール(STATE_END)を超えていなければ配列の添え字をインクリメント
    if (milage > m_stateLeft[nowState].Distance && milage <= STATE_END) {
      ++nowState;

      //走行状態切り替え時の距離をログに吐いて音を鳴らす。
      EV3_LOG("State chenge nowState = %d\n Now milage  = %f\n", nowState, milage);//Takeuchi
      RyujiEv3Engine::GetSpeaker()->setVolume(100);
      RyujiEv3Engine::GetSpeaker()->playTone(500, 500);//Takeuchi 音を鳴らす


    }
    return m_stateLeft[nowState].State;

  } else if (COURSE_MODE == RIGHT_COURSE) {
    
    if (milage > m_stateRight[nowState].Distance && milage <= STATE_END) {
      ++nowState;
    }
    return m_stateRight[nowState].State;

  } else {
    return (MapState)ERROR;
  }
}

int MapStateControl::errorCorrection() { return 0; }
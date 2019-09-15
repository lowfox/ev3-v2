#include "SeesawScene.h"

SeesawScene::SeesawScene(ISceneChanger* sceneChanger) : IScene(sceneChanger) {}

bool SeesawScene::init() { return true; }

bool SeesawScene::run() {
  EV3_LOG("seesawScene__Start\n");
// SeesawTest
#ifdef TESTMODE
  seesawTest i_seesawTest;
  if (!i_seesawTest.run()) {
    EV3_LOG("TEST NG!!\n");
    return false;
  }
#else
  // SeesawCode

  seesawCapture i_seesawCapture;
  if (!i_seesawCapture.run()) {
    return false;
  }
#endif

  // 受け渡し時に呼ぶ
  return change(SceneID::Garage);
}

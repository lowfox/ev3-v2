#include "SeesawScene.h"

SeesawScene::SeesawScene(ISceneChanger* sceneChanger):IScene(sceneChanger)
{
}

bool SeesawScene::init()
{
	return true;
}

bool SeesawScene::run()
{
	// SeesawCode


	// 受け渡し時に呼ぶ
	return change(SceneID::Garage);
}

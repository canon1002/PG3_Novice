#pragma once
#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ResultScene.h"

class SceneManager
{
private:

	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	// どのシーンを呼び出すかを管理する変数
	int32_t currentSceneNo_;// 現在のシーン
	int32_t prevSceneNo_ = -1;// 前のシーン

public:

	SceneManager();
	~SceneManager();

	int Run(char* keys, char* preKeys);//　この関数でゲームループを呼び出す

};


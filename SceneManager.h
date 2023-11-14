#pragma once
#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "ResultScene.h"

class SceneManager
{
private:

	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	// どのシーンを呼び出すかを管理する変数
	int currentSceneNo_;// 現在のシーン
	int prevSceneNo_;// 前のシーン

public:

	SceneManager();
	~SceneManager();

	int Run(char* keys ,char* preKeys);//　この関数でゲームループを呼び出す

};


#include "ResultScene.h"
#include "Novice.h"

//　継承した関数
void ResultScene::Init() {

}

void ResultScene::Update(char* keys, char* preKeys) {
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		// メインゲームに切り替え
		IScene::sceneNo = STAGE;
	}
}

void ResultScene::Draw() {
	// 操作案内
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x555555FF, kFillModeSolid);
	Novice::DrawBox(470, 170, 200, 40, 0.0f, 0x333399FF, kFillModeSolid);
	Novice::ScreenPrintf(480, 180, "CLEAR");
	Novice::DrawBox(470, 470, 200, 40, 0.0f, 0x333399FF, kFillModeSolid);
	Novice::ScreenPrintf(480, 480, "Enter -> MainGame");
}

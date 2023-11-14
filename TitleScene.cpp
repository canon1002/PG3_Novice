#include "TitleScene.h"
#include "Novice.h"

//　継承した関数
void TitleScene::Init() {

}

void TitleScene::Update(char* keys, char* preKeys) {
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		// メインゲームに切り替え
		IScene::sceneNo = GAMEMAIN;
	}
}

void TitleScene::Draw(){

	#pragma region どうでもいい処理
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xCCCCCCFF, kFillModeSolid);
	// T
	Novice::DrawBox(140, 100, 200, 40, 0.0f, 0x333333FF, kFillModeSolid);
	Novice::DrawBox(220, 140, 40, 160, 0.0f, 0x333333FF, kFillModeSolid);
	// I
	Novice::DrawBox(420, 100, 40, 200, 0.0f, 0x333333FF, kFillModeSolid);
	// T
	Novice::DrawBox(540, 100, 200, 40, 0.0f, 0x333333FF, kFillModeSolid);
	Novice::DrawBox(620, 100, 40, 200, 0.0f, 0x333333FF, kFillModeSolid);
	// L
	Novice::DrawBox(820, 100, 40, 160, 0.0f, 0x333333FF, kFillModeSolid);
	Novice::DrawBox(820, 260, 120, 40, 0.0f, 0x333333FF, kFillModeSolid);
	// E
	Novice::DrawBox(1020, 100, 40, 160, 0.0f, 0x333333FF, kFillModeSolid);
	Novice::DrawBox(1020, 100, 120, 40, 0.0f, 0x333333FF, kFillModeSolid);
	Novice::DrawBox(1020, 180, 100, 40, 0.0f, 0x333333FF, kFillModeSolid);
	Novice::DrawBox(1020, 260, 120, 40, 0.0f, 0x333333FF, kFillModeSolid);

#pragma endregion

	// 操作案内 
	Novice::DrawBox(470, 470, 200, 40, 0.0f, 0x993333FF, kFillModeSolid);
	Novice::ScreenPrintf(480, 480, "Please Enter");


}

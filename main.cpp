#include <Novice.h>
#include "SceneManager.h"

const char kWindowTitle[] = "LE2B_24_PG3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// シーンマネージャの宣言
	std::unique_ptr<SceneManager> sceneManager;
	sceneManager = std::make_unique<SceneManager>();
	sceneManager->Run(keys, preKeys);

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

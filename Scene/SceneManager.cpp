#include "SceneManager.h"
#include "Novice.h"

// コンストラクタ
SceneManager::SceneManager() {
	// 各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ResultScene>();

	// 初期シーン
	currentSceneNo_ = STAGE;

}

// デストラクタ
SceneManager::~SceneManager() {}

// 処理
int SceneManager::Run(char* keys, char* preKeys) {
	while (Novice::ProcessMessage()==0)	{
		Novice::BeginFrame();// フレームの開始

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// シーンのチェック
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}
		// 前回のシーン番号を上書き
		prevSceneNo_ = currentSceneNo_;

		/// 更新処理
		sceneArr_[currentSceneNo_]->Update(keys,preKeys);
		
		/// 描画処理
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame(); // フレームの終了

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}

	}
	return 0;
}
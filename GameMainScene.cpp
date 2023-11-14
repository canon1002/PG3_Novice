#include "GameMainScene.h"
#include "Novice.h"

//　継承した関数
void GameMainScene::Init() {
	player_ = std::make_unique<Player>();
	player_->Init();
	enemy_ = std::make_unique<Enemy>();
	enemy_->Init();
}

void GameMainScene::Update(char* keys, char* preKeys) {
	preKeys;

	//////////////////////////////////////////
	///	キー入力操作
	/////////////////////////////////////////

	if(!enemy_->GetIsActive()){ IScene::sceneNo = RESULT; }

	if (keys[DIK_W]) {
		player_->Move(UP);
	}
	if (keys[DIK_A]) {
		player_->Move(LEFT);
	}
	if (keys[DIK_S]) {
		player_->Move(DOWN);
	}
	if (keys[DIK_D]) {
		player_->Move(RIGHT);
	}
	if (keys[DIK_RETURN]) {
		player_->Attack();
	}

	////////////////////////////
	///　更新処理
	////////////////////////////

	player_->Update();
	enemy_->Update();

	/////////////////////////
	///　当たり判定を行う
	/////////////////////////

	const std::list<PlayerBullet*> playerBullets = player_->GetBullets();
	for (PlayerBullet* bullet : playerBullets) {
		Vec2 distance = bullet->GetPos() - enemy_->GetPos();

		// 当たったら

		if ((distance * distance) <
			(bullet->GetRad() + enemy_->GetRad()) * (bullet->GetRad() + enemy_->GetRad())
			) {

			// 敵が死ぬ
			enemy_->isActive_ = false;
		}
	}

}

void GameMainScene::Draw() {
	// 背景
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000088FF, kFillModeSolid);
	// 背景左壁
	Novice::DrawBox(0, 0, 100, 720, 0.0f, 0x222222FF, kFillModeSolid);
	// 背景右壁
	Novice::DrawBox(1180, 0, 100, 720, 0.0f, 0x222222FF, kFillModeSolid);
	// プレイヤー
	player_->Draw();
	// エネミー
	enemy_->Draw();
	
#pragma region どうでもいい 操作説明
	Novice::DrawBox(270, 420, 200, 40, 0.0f, 0x333399FF, kFillModeSolid);
	Novice::ScreenPrintf(280, 430, "WASD -> Move");
	Novice::DrawBox(270, 470, 200, 40, 0.0f, 0x333399FF, kFillModeSolid);
	Novice::ScreenPrintf(280, 480, "Enter -> Shot");
#pragma endregion

}

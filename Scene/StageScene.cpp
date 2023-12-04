#include "StageScene.h"

void StageScene::Init() {
	inputHandler_ = std::make_unique<InputHandle>();

	// Assign command
	inputHandler_->AssingnMoveUpCommand2PressKeyW();
	inputHandler_->AssingnMoveDownCommand2PressKeyS();
	inputHandler_->AssingnMoveLeftCommand2PressKeyA();
	inputHandler_->AssingnMoveRightCommand2PressKeyD();
	
	// New Player
	player_ = std::make_unique<Player>();
	player_->Init();
}

void StageScene::Update(char* keys, char* preKeys) {
	
	// get command
	command_ = inputHandler_->HandleInput();

	// set command
	if (this->command_) {
		command_->Exec(*player_);
	}

	player_->Update();
	keys; preKeys;
}

void StageScene::Draw() {
	player_->Draw();
}

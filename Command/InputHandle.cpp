#include "InputHandle.h"
#include <Novice.h>

ICommand* InputHandle::HandleInput() {
	if (Novice::CheckHitKey(DIK_W)) {
		return pressKeyW_;
	}
	if (Novice::CheckHitKey(DIK_S)) {
		return pressKeyS_;
	}
	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}
	return nullptr;					
}

void InputHandle::AssingnMoveUpCommand2PressKeyW() {
	ICommand* command = new MoveUpCommand();
	this->pressKeyW_ = command;
}
void InputHandle::AssingnMoveDownCommand2PressKeyS() {
	ICommand* command = new MoveDownCommand();
	this->pressKeyS_ = command;
}

void InputHandle::AssingnMoveLeftCommand2PressKeyA() {
	ICommand* command = new MoveLeftCommand();
	this->pressKeyA_ = command;
}

void InputHandle::AssingnMoveRightCommand2PressKeyD() {
	ICommand* command = new MoveRightCommand();
	this->pressKeyD_ = command;
}

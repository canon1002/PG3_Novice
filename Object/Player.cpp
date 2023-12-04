#include "Player.h"
#include <Novice.h>

Player::Player() {

}

Player::~Player() {

}

void Player::Init() {
	pos_ = { 100,100 };
	rad_ = { 12,12 };
	vel_ = { 4,4 };
	speed_ = { 4,4 };
	color_ = 0xFFFFFFFF;
}

void Player::Update() {

}

void Player::Draw() {
	Novice::DrawBox(pos_.x, pos_.y, rad_.x, rad_.y, 0.0f, color_, kFillModeSolid);
}

void Player::MoveUp() {
	this->pos_.y -= this->vel_.y;
}

void Player::MoveDown() {
	this->pos_.y += this->vel_.y;
}

void Player::MoveLeft() {
	this->pos_.x -= this->vel_.x;
}

void Player::MoveRight() {
	this->pos_.x += this->vel_.x;
}
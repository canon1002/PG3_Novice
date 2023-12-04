#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy() { this->Init(); }

Enemy::~Enemy() {}


void Enemy::Init() {
	this->pos_ = { 200 ,60 };
	rad_ = { 32,32 };
	vel_ = { 6,0 };
	isActive_ = true;
}

void Enemy::Update() {
	if (!isActive_) { return; }
	// 左右に移動する
	pos_ += vel_;
	if ((pos_.x-rad_.x) <= 100|| (pos_.x + rad_.x) >= 1180) {
		vel_.x *= -1;
	}

}

void Enemy::Draw() {

	if (!isActive_) { return; }
	Novice::DrawEllipse(pos_.x, pos_.y, rad_.x, rad_.y, 0.0f, 0x880000FF, kFillModeSolid);

}
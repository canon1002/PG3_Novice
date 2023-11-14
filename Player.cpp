#include "Player.h"
#include "Novice.h"

Player::Player() {this->Init();}

Player::~Player() {
	for (PlayerBullet* bullet : bullets_) {
		delete bullet;
	}
}


void Player::Init() {
	this->pos_ = { 600 ,400 };
	rad_ = { 32,32 };
	vel_ = { 8, 8 };
	shotCoolTime_ = 10;
	isActive_ = true;
}

void Player::Update() {
	for (PlayerBullet* bullet : bullets_) {
		bullet->Update();
	}
}

void Player::Draw() {

	if (shotCoolTime_ > 0) { --shotCoolTime_; }
	for (PlayerBullet* bullet : bullets_) {
		bullet->Draw();
	}
	if (!isActive_) { return; }
	Novice::DrawEllipse(pos_.x, pos_.y, rad_.x, rad_.y, 0.0f, 0x008800FF, kFillModeSolid);
	
}

void Player::Attack() {
	if (shotCoolTime_ != 0) { return; }

	//　弾の生成と初期化
	PlayerBullet* newBullet = new PlayerBullet();
	newBullet->Init(pos_);
	// 弾の登録
	bullets_.push_back(newBullet);
	// クールタイムを設定
	shotCoolTime_ = 6;
}

void Player::Move(DIRECTION Dir) {
	switch (Dir)
	{
	case UP:
		pos_.y -= vel_.y;
		break;
	case DOWN:
		pos_.y += vel_.y;
		break;
	case LEFT:
		pos_.x -= vel_.x;
		break;
	case RIGHT:
		pos_.x += vel_.x;
		break;
	default:
		break;
	}
}
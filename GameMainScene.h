#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"

class GameMainScene:
	public IScene
{
public:

	//　継承した関数
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

public:

	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;

};


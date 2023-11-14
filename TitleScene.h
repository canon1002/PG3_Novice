#pragma once
#include "IScene.h"
class TitleScene :
    public IScene
{
public:

	//　継承した関数
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

};


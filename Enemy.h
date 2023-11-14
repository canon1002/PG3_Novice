#pragma once
#include "IObject.h"
#include "PlayerBullet.h"
#include <list>

class Enemy :
    public IObject
{
public:
    Enemy();
    ~Enemy();
    void Init()override;
    void Init(PlayerBullet* playerBullet);
    void Update()override;
    void Draw()override;
    bool GetIsActive()const { return isActive_; }
    Vec2 GetPos()const { return pos_; }
    Vec2 GetRad()const { return rad_; }
public:

    Vec2 pos_;
    Vec2 rad_;
    Vec2 vel_;
    bool isActive_;

};


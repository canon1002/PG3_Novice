#pragma once
#include "IObject.h"
#include "PlayerBullet.h"
#include <memory>
#include <list>

enum DIRECTION {UP,DOWN,LEFT,RIGHT};

class Player :
    public IObject
{
public:
    Player();
    ~Player();
    void Init()override;
    void Update()override;
    void Draw()override;
    void Attack();
    void Move(DIRECTION dir);

    // 弾の取得
    const std::list<PlayerBullet*>& GetBullets() const { return bullets_; }

public:

    Vec2 pos_;
    Vec2 rad_;
    Vec2 vel_;
    int shotCoolTime_;
    bool isActive_;
    std::list<PlayerBullet*> bullets_;

};


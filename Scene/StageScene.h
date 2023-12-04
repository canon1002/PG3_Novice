#pragma once
#include "IScene.h"
#include "../Command/ICommand.h"
#include "../Command/InputHandle.h"
#include "../Object/Player.h"
#include <memory>

class StageScene :
    public IScene
{
private:
    std::unique_ptr <InputHandle> inputHandler_ = nullptr;
    ICommand* command_ = nullptr;
    std::unique_ptr<Player> player_;
public:
    void Init()override;
    void Update(char* keys, char* preKeys)override;
    void Draw()override;
};


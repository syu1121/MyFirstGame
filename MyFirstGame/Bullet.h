#pragma once
#include "Engine\\GameObject.h"


class Fbx;
class ChildOden;

class Bullet :
    public GameObject
{
    Fbx* pFbx_;
   
    int hModel_;
public:
    Bullet(GameObject* parent);
    ~Bullet();
    // 純粋仮想関数のオーバーライド
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};


#pragma once
#include "Engine\\GameObject.h"
#include "Engine\\Fbx.h"


class Enemy :
    public GameObject
{
    Fbx* pFbx_;
    
public:
    
    Enemy(GameObject* parent); // コンストラクタ
    ~Enemy(); // デストラクタ
    // 純粋仮想関数のオーバーライド
    void Initialize() override; // 初期化
    void Update() override; // 更新
    void Draw() override; // 描画
    void Release() override; // 解放

    void OnCollision(GameObject* other) override;
};


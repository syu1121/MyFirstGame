#include "TestScene.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"
#include "Engine\\Model.h"
#include <Windows.h>

TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene"), hModel_(-1)
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
    hModel_ = Model::Load("Sikaku.fbx");
    assert(hModel_ >= 0);

    transform_.scale_.x = 0.7f;
    transform_.scale_.y = 0.7f;
    transform_.scale_.z = 0.7f;
}

void TestScene::Update()
{
    transform_.rotate_.y += 1.0f;
    if (Input::IsKeyDown(DIK_SPACE))
    {

        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_PLAY);
        
    }
}

void TestScene::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);

   // 
}

void TestScene::Release()
{
}

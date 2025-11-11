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
    hModel_ = Model::Load("sikaku.fbx");
    assert(hModel_ >= 0);
}

void TestScene::Update()
{
    
    if (Input::IsKeyDown(DIK_SPACE))
    {

        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_PLAY);
        
    }
}

void TestScene::Draw()
{
    Model::Draw(hModel_);

   // MessageBoxA(0, "•\Ž¦‚³‚ê‚½", "TestScene", MB_OK);
}

void TestScene::Release()
{
}

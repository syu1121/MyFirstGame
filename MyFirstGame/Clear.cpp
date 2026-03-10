#include "Clear.h"
#include "Engine\\Model.h"

ClearScene::ClearScene(GameObject* parent)
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
    hModel_ = Model::Load("Oden.fbx");
    assert(hModel_ >= 0);

    transform_.scale_.x = 0.7f;
    transform_.scale_.y = 0.7f;
    transform_.scale_.z = 0.7f;
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void ClearScene::Release()
{
}

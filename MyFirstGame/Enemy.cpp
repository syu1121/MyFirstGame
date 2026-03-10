#include "Enemy.h"
#include "Bullet.h"
#include "Engine\\SphereCollider.h"
#include "Engine\\SceneManager.h"

Enemy::Enemy(GameObject* parent)
	: GameObject(parent, "Enemy"), pFbx_(nullptr)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	pFbx_ = new Fbx;
	pFbx_->Load("Oden.fbx");
	transform_.position_ = { 20.0f,0.0f,40.0f };

	SphereCollider* col = new SphereCollider(0.5f);
	AddCollider(col);
}

void Enemy::Update()
{
	
}

void Enemy::Draw()
{
	pFbx_->Draw(transform_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* other)
{
	//MessageBoxA(0, "hit", "collision", 0);
	if (other->GetName() == "Bullet")
	{
		KillMe();
		
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}

	
}

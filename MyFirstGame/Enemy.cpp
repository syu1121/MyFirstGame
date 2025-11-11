#include "Enemy.h"
#include "Engine\\SphereCollider.h"

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
	transform_.position_ = { 0.0f,0.0f,50.0f };

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

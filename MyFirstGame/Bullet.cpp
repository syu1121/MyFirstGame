#include "Bullet.h"
#include "Engine\\Model.h"
#include "Engine\\SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	: GameObject(parent, "Bullet"), hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);

	transform_.scale_.x = 0.4f;
	transform_.scale_.y = 0.4f;
	transform_.scale_.z = 0.4f;
	
	SphereCollider* col = new SphereCollider(1.0);
	AddCollider(col);
}

void Bullet::Update()
{
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
	vPos = XMVectorAdd(vPos, XMVectorSet(0.2f, 0.0f, 0.0f, 0.0f));
	XMStoreFloat3(&transform_.position_, vPos);
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}

#include "Player.h"
#include "Engine\\Fbx.h"
#include "ChildOden.h"
#include "Engine\\Model.h"
#include "Engine\\SphereCollider.h"
#include "Engine\\Input.h"
#include "Bullet.h"


Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	//pFbx_ = new Fbx;
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);

	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;
	transform_.position_.x = -20.0f;
	transform_.position_.z = 40.0f;

	pRChildOden_ = (ChildOden* )Instantiate<ChildOden>(this);
	pLChildOden_ = (ChildOden* )Instantiate<ChildOden>(this);
	pTChildOden_ = (ChildOden* )Instantiate<ChildOden>(this);
	pRChildOden_->SetPosition(2.0f, 1.0f, 0.0f);
	pLChildOden_->SetPosition(-2.0f, 1.0f, 0.0f);
	pTChildOden_->SetPosition(0.0f, 5.0f, 0.0f);
	
	/*SphereCollider* col = new SphereCollider(1.0);
	AddCollider(col);*/
}

void Player::Update()
{
	static float x = 0.0;
	float tx = sin(x) * 5.0f;
	x += 0.02f;
	

	//transform_.rotate_.y += 1.0f;

	//Instantiate<Bullet>(this);

	if (Input::IsKey(DIK_A))
	{
		//transform_.position_.z += 0.2f;
		Bullet* b = (Bullet*)Instantiate<Bullet>(GetRootJob());
		b->SetPosition(transform_.position_);
	}

	/*if (transform_.rotate_.y > 720.0f)
	{
		KillMe();
	}*/
}

void Player::Draw()
{
	
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
	/*if (pFbx_)
	{

		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}*/
}

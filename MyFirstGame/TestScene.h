#pragma once
#include "Engine\\GameObject.h"

class Fbx;


class TestScene
	: public GameObject
{
	Fbx* pFbx_;
	int hModel_;

public:
	TestScene(GameObject* parent);
	~TestScene();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

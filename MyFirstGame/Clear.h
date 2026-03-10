#pragma once
#include "Engine\\GameObject.h"

class Fbx;



class ClearScene
	: public GameObject
{
	Fbx* pFbx_;
	int hModel_;

public:
	ClearScene(GameObject* parent);
	~ClearScene();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

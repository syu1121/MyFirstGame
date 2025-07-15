#pragma once
#include "Direct3D.h"
#include <DirectxMath.h>


struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX matWVP; // world*view*projection�̍s��
};


class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@

	ID3D11Buffer* pIndexBuffer_;

	ID3D11Buffer* pConstantBuffer_;

public:
	Quad();
	~Quad();
	HRESULT Initialize();
	void Draw();
	void Release();
};


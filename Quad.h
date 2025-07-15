#pragma once
#include "Direct3D.h"
#include <DirectxMath.h>


struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX matWVP; // world*view*projectionの行列
};


class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ

	ID3D11Buffer* pIndexBuffer_;

	ID3D11Buffer* pConstantBuffer_;

public:
	Quad();
	~Quad();
	HRESULT Initialize();
	void Draw();
	void Release();
};


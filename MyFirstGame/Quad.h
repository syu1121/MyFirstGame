#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>


using namespace DirectX;

struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX matWVP; //world*view*projectionの行列
};

struct VERTEX
{
	XMVECTOR pos;
	XMVECTOR uv;
};

class Texture;


class Quad
{

public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();

protected:
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//頂点バッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ
	Texture* pTexture_;

};
#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>


using namespace DirectX;

struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX matWVP; //world*view*projection�̍s��
};

struct VERTEX
{
	XMVECTOR pos;
	XMVECTOR uv;
};

class Texture;


class Quad
{
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@
	Texture* pTexture_;
public:
	Quad();
	~Quad();
	HRESULT Initialize();
	void Draw(XMMATRIX& worldMatrix);
	void Release();
};
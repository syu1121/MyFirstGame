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

public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();

protected:
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@
	Texture* pTexture_;

};
#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <assert.h>


//�����J
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#define SAFE_DELETE(p) if(p != nullptr){ delete p; p = nullptr;}
#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}

namespace Direct3D
{
	//extern�͂ǂ����ɂ���
	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pContext;

	//�V�F�[�_�[����
	HRESULT InitShader();

	//������
	HRESULT Initialize(int winW, int winH, HWND hWnd);

	//�`��J�n
	void BeginDraw();

	//�`��I��
	void EndDraw();

	//���
	void Release();
};
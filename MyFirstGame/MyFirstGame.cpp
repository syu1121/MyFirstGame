// MyFirstGame.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "framework.h"
#include "MyFirstGame.h"
#include "Direct3D.h"
#include "Quad.h"
#include "Camera.h"
#include "Dice.h"


HWND hWnd = nullptr;



#define MAX_LOADSTRING 100


//グローバル変数の宣言:
const wchar_t* WIN_CLASS_NAME = L"SANPLE GAME WINDOW"; //ウィンドウクラス名
const int WINDOW_WIDTH = 800;  //ウィンドウの幅
const int WINDOW_HEIGHT = 600; //ウィンドウの高さ //SVGAサイズ


// グローバル変数:
HINSTANCE hInst;                                // 現在のインターフェイス
WCHAR szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト
WCHAR szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名

// このコード モジュールに含まれる関数の宣言を転送します:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ここにコードを挿入してください。
   
    // グローバル文字列を初期化する
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MYFIRSTGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

   
    // アプリケーション初期化の実行:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // Direct3Dの初期化
    HRESULT hr;
    hr= Direct3D::Initialize(WINDOW_WIDTH, WINDOW_HEIGHT, hWnd);
    if (FAILED(hr))
    {
        return 0;
    }   


    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MYFIRSTGAME));

    MSG msg = {};
    Dice* dice = new Dice();
    dice->Initialize();


    /*Quad* q = new Quad();
    q->Initialize();*/
    if (FAILED(hr))
    {
        return 0;
    }


    Camera::Initialize();

    // メイン メッセージ ループ:
    while (msg.message != WM_QUIT)
    {
        //メッセージあり
        while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))

        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

        }

        //メッセージなし

        //ゲームの処理
        Camera::Update(); //カメラの更新

        Direct3D::BeginDraw();

       //描画処理
        static float angle = 0.0f;
        //static float Angle = 0.0f;
        XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(angle));
        XMMATRIX matrix = XMMatrixRotationZ(XMConvertToRadians(angle));
        XMMATRIX Mat = mat * matrix;
        dice->Draw(Mat);
       
        angle += 0.05f;
       // Angle += 0.05f;
        Direct3D::EndDraw();

    }
    dice->Release();
    SAFE_DELETE(dice);

    Direct3D::Release();

    return (int) msg.wParam;
}



//
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = NULL;//LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYFIRSTGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = CreateSolidBrush(RGB(0, 255, 100));//(HBRUSH)(COLOR_WINDOW+5);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = NULL;//LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   関数: InitInstance(HINSTANCE, int)
//
//   目的: インスタンス ハンドルを保存して、メイン ウィンドウを作成します
//
//   コメント:
//
//        この関数で、グローバル変数でインスタンス ハンドルを保存し、
//        メイン プログラム ウィンドウを作成および表示します。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // グローバル変数にインスタンス ハンドルを格納する


   //ウィンドウサイズの計算
   RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
   AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
   int winW = winRect.right - winRect.left;     //ウィンドウ幅
   int winH = winRect.bottom - winRect.top;     //ウィンドウ高さ


   hWnd = CreateWindowW(szWindowClass, WIN_CLASS_NAME, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, winW, winH, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: メイン ウィンドウのメッセージを処理します。
//
//  WM_COMMAND  - アプリケーション メニューの処理
//  WM_PAINT    - メイン ウィンドウを描画する
//  WM_DESTROY  - 中止メッセージを表示して戻る
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 選択されたメニューの解析:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: HDC を使用する描画コードをここに追加してください...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// バージョン情報ボックスのメッセージ ハンドラーです。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

//①Windowクラスの仕組み
//構造体のメンバの意味を調べる
//・ウィンドウクラスは、Windowsアプリケーションでウィンドウの外観や動作を定義するための仕組みです。
//具体的には、ウィンドウの表示方法（アイコン、カーソル、背景色など）や、メッセージに対する応答（ウィンドウプロシージャ）をまとめて管理します。
//
//・cbSize : 構造体のサイズをバイト単位で指定します。
//・style : ウィンドウのスタイルを指定します。例えば、CS_HREDRAWやCS_VREDRAWは、ウィンドウのサイズが変更されたときに再描画を行うためのスタイルです。
//・lpfnWndProc : ウィンドウプロシージャへのポインターを指定します。ウィンドウプロシージャは、ウィンドウに送られてくるメッセージを処理する関数です。
//・cbClsExtra : ウィンドウクラスに追加のメモリを割り当てる場合に使用します。通常は0を指定します。
//・cbWndExtra : ウィンドウに追加のメモリを割り当てる場合に使用します。通常は0を指定します。
//・hInstance : ウィンドウを作成するインスタンスのハンドルを指定します。
//・hIcon : ウィンドウのアイコンを指定します。
//・hCursor : ウィンドウのカーソルを指定します。
//・hbrBackground : ウィンドウの背景色を指定します。
//・lpszMenuName : メニューの名前を指定します。
//・lpszClassName : ウィンドウクラスの名前を指定します。
//・hIconSm : ウィンドウの小さいアイコンを指定します。
//
//②winmainの引数の意味は？
//・アプリケーションのウィンドウ作成とメッセージ処理に必要な情報をカプセル化しています。
//
//③CreateWindowExの引数の戻り値の意味
//・作成されたウィンドウのハンドルです。ウィンドウハンドルは、プログラムが特定のウィンドウを識別するために使用する数値です。作成に失敗した場合はNULLが返されます。﻿
//
//④メッセージループとコールバックの関係と仕組みを調べてまとめる(メッセージループとWinProcにコメント？)
//・Windows プログラミングでは、アプリケーションはユーザーの操作 (クリック、キー入力など) やシステムイベント (ウィンドウの再描画、タイマーなど) に応答する必要があります。
//  これらのイベントは「メッセージ」としてアプリケーションに送られ、そのメッセージを処理するのが「メッセージループ」と「コールバック関数」の役割です。﻿



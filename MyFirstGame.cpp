// MyFirstGame.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "framework.h"
#include "MyFirstGame.h"
#include <string>
#include "Direct3D.h"
#include "Quad.h"

HWND hWnd = nullptr;




const wchar_t* WIN_CLASS_NAME = L"SAMPLE GAME WINDOW"; // ウィンドウクラス名
const int WINDOW_WIDTH = 800;  //ウィンドウの幅
const int WINDOW_HEIGHT = 600; //ウィンドウの高さ  // SVGAサイズ

// グローバル変数の宣言 

#define MAX_LOADSTRING 100

// グローバル変数:
HINSTANCE hInst;                                // 現在のインターフェイス
WCHAR szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト
WCHAR szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名

// このコード モジュールに含まれる関数の宣言を転送します:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // インスタンスへのハンドル またはモジュールへのハンドルです。
                     _In_opt_ HINSTANCE hPrevInstance, // 意味がありません。 16 ビット Windows で使用されましたが、現在は常に 0 です。
                     _In_ LPWSTR    lpCmdLine, // コマンド ライン引数が Unicode 文字列として含まれています。
                     _In_ int       nCmdShow) // メイン アプリケーション ウィンドウが最小化、最大化、または正常に表示されるかどうかを示すフラグです。
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ここにコードを挿入してください。

    //szWindowClass = WIN_CLASS_NAME;


    // グローバル文字列を初期化する
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MYFIRSTGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);




    // アプリケーション初期化の実行:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HRESULT hr;
    //Direct3D初期化
    hr = Direct3D::Initialize(WINDOW_WIDTH, WINDOW_HEIGHT, hWnd);
    if (FAILED(hr))
    {
        PostQuitMessage(0);
    }
    


    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MYFIRSTGAME));

    MSG msg = {};


    Quad* q = new Quad();
    q->Initialize();
    if (FAILED(hr))
    {
        PostQuitMessage(0);
    }

    // メイン メッセージ ループ:
    // 単純なメッセージ ループは、GetMessage、TranslateMessage、DispatchMessage の 3 つの関数それぞれに対する 1 つの関数呼び出しで構成されます。 エラーが発生した場合、 GetMessage は -1 を返します。
    // GetMessage 関数は、キューからメッセージを取得し、MSG 型の構造体にコピーします。 WM_QUIT メッセージが検出されない限り、0 以外の値が返されます。

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
        Direct3D::BeginDraw();
        //背景の色
        
        q->Draw();

        //描画処理
        Direct3D::EndDraw();


       

    }

    Direct3D::Release();
    q->Release();
    SAFE_DELETE(q);
    return (int)msg.wParam;
}



//
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);                             // この構造体のサイズ (バイト単位)。このメンバーを sizeof(WNDCLASSEX)に設定します。

    wcex.style          = CS_HREDRAW | CS_VREDRAW;                // クラス のスタイル。 このメンバーは、クラス スタイルの任意の組み合わせにすることができます。
    wcex.lpfnWndProc    = WndProc;                                // ウィンドウ プロシージャへのポインター。 ウィンドウ プロシージャを呼び出すには、CallWindowProc 関数を使用する必要があります。
    wcex.cbClsExtra     = 0;                                      // ウィンドウ クラス構造体の後に割り当てる余分なバイト数。 システムはバイトをゼロに初期化します。
    wcex.cbWndExtra     = 0;                                      // ウィンドウ インスタンスの後に割り当てる余分なバイト数。 システムはバイトをゼロに初期化します。
    wcex.hInstance      = hInstance;                              // クラスのウィンドウ プロシージャを含むインスタンスへのハンドル。 
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYFIRSTGAME));                                   // NULL; // クラス カーソルへのハンドル。 このメンバーは、カーソル リソースへのハンドルである必要があります。 このメンバーが NULL場合、アプリケーションは、マウスがアプリケーションのウィンドウに移動するたびにカーソルの形状を明示的に設定する必要があります。
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);         // クラス カーソルへのハンドル。 このメンバーは、カーソル リソースへのハンドルである必要があります。 このメンバーが NULL場合、アプリケーションは、マウスがアプリケーションのウィンドウに移動するたびにカーソルの形状を明示的に設定する必要があります。
    wcex.hbrBackground  = CreateSolidBrush(RGB(185, 255, 255));   // クラスの背景ブラシへのハンドル。 このメンバーは、背景の描画に使用するブラシのハンドルにすることも、色の値にすることもできます。 色の値は、次の標準システム カラーのいずれかである必要があります (値 1 を選択した色に追加する必要があります)。
    wcex.lpszMenuName   = NULL;                                   // リソース ファイルに名前が表示されるように、クラス メニューのリソース名を指定する null で終わる文字列へのポインター。 メニューを識別するために整数を使用する場合は、MAKEINTRESOURCE マクロを使用します。 このメンバーが NULL場合、このクラスに属するウィンドウには既定のメニューはありません。
    wcex.lpszClassName  = szWindowClass;                          // null で終わる文字列へのポインター、またはアトムです。 このパラメーターがアトムの場合は、RegisterClass または RegisterClassEx 関数 以前の呼び出しによって作成されたクラスアトムである必要があります。
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));                                   //NULL; //ウィンドウ クラスに関連付けられている小さなアイコンへのハンドル。 このメンバーが NULL場合、システムは、hIcon メンバーによって指定されたアイコン リソースで、小さいアイコンとして使用する適切なサイズのアイコンを検索します。

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
    // コールバック関数は、アンマネージ DLL 関数がタスクを完了するのに役立つマネージド アプリケーション内のコードです。 コールバック関数の呼び出しは、マネージド アプリケーションから DLL 関数を介して間接的に渡され、マネージド実装に戻ります。
    // メッセージループ	                        コールバック
    // イベントが起きるのを監視し、順に処理する	実際にイベントが起きたときに呼ばれる関数
    // 背景でずっと動いている	                登録されたものが必要なときに呼ばれる
    // イベントをキューから1つずつ取り出す	    そのイベントに対応する処理を実行する

    // メッセージループがコールバックを呼び出すことでアプリが反応する。

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

// CreateWindowExの引数と戻り値の意味
// [in, optional] lpClassName
// null-terminated 文字列、または RegisterClass または registerClassEx 関数への以前の呼び出しによって作成されたクラス アトム 

// [in, optional] lpWindowName
// ウィンドウ名。 ウィンドウ スタイルでタイトル バーが指定されている場合、lpWindowName 指すウィンドウ タイトルがタイトル バーに表示されます。

// [in] dwStyle
// 作成するウィンドウのスタイル。 このパラメーターには、ウィンドウ スタイル値と、「解説」セクションで示されているコントロール スタイルの組み合わせを指定できます。

// [in] x
// ウィンドウの最初の水平位置。 重なったウィンドウまたはポップアップ ウィンドウの場合、x パラメーターは、ウィンドウの左上隅の最初の x 座標 (画面座標) です。

// [in] y
// ウィンドウの最初の垂直方向の位置。 重なったウィンドウまたはポップアップ ウィンドウの場合、y パラメーターは、ウィンドウの左上隅の初期 y 座標 (画面座標) です。

// [in] nWidth
// ウィンドウの幅 (デバイス単位)。 重複するウィンドウの場合、nWidth は、ウィンドウの幅、画面座標、または CW_USEDEFAULTのいずれかです。

// [in] nHeight
// ウィンドウの高さ (デバイス単位)。 重なり合うウィンドウの場合、nHeight はウィンドウの高さ (画面座標) です。

// [in, optional] hWndParent
// 作成されるウィンドウの親ウィンドウまたは所有者ウィンドウへのハンドル。 子ウィンドウまたは所有ウィンドウを作成するには、有効なウィンドウ ハンドルを指定します。 このパラメーターは、ポップアップ ウィンドウでは省略可能です。

// [in, optional] hMenu
// メニューのハンドル。または、ウィンドウ のスタイルに応じて子ウィンドウ識別子を指定します。 重なったウィンドウまたはポップアップ ウィンドウの場合、hMenu はウィンドウで使用するメニューを識別します。

// [in, optional] hInstance
// ウィンドウに関連付けるモジュールのインスタンスへのハンドル。

// [in, optional] lpParam
// WM_CREATE メッセージの lParam パラメーターが指す CREATESTRUCT 構造体 (lpCreateParams メンバー) を介してウィンドウに渡される値へのポインター。

// 戻り値
// 関数が成功した場合、戻り値は新しいウィンドウへのハンドルです。関数が失敗した場合、戻り値は NULL。 拡張エラー情報を取得するには、GetLastError呼び出します。


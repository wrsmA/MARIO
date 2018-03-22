
//定数宣言
#define GAME_TITLE		"MARIO"	//タイトルバーの文字
#define WINDOW_WIDTH	800					//ウィンドウの幅
#define WINDOW_HEIGHT	600					//ウィンドウの高さ
#define WINDOW_MODE		TRUE				//TRUE：ウィンドウ／FALSE：フルスクリーン


//インクルード
#include "DxLib.h"
#include "MyEngine\\Game.h"


//エントリーポイント
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//初期設定
	SetWindowText(GAME_TITLE);						//タイトルバーの文字
	ChangeWindowMode(WINDOW_MODE);					//ウィンドウモード
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16);	//画面モードの設定
	DxLib_Init();									//DXライブラリの初期化


	//ゲームクラスのインスタンス
	Game game;

	//ゲームの初期化
	game.Start();

	//ゲームループ
	while (true)
	{
		//ウインドウのメッセージを処理する
		if(ProcessMessage() != 0)	break;

		//画面をクリアする
		if (ClearDrawScreen() != 0)	break;

		//ゲームの更新
		game.Update();

		//フリップ関数
		if (ScreenFlip() != 0)	break;
	}


	//終了処理
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}
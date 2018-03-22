#pragma once
#include "GameObject.h"
class Sprite : public GameObject
{
protected:
	int _graphicHandle;  //画像の識別番号
	int _srcX, _srcY, _width, _height;
public:
	//コンストラクタ
	Sprite();
	//デストラクタ
	~Sprite();

	//機能：画像の読み込み
	//引数：fileName　ファイル名
	//戻り値：なし
	void Load(char* fileName);

	//機能：描画処理
	//引数：なし
	//戻り値：なし
	void Draw();
	//機能：
	//引数：なし
	//戻り値：なし
	void SetRect(int x, int y, int w, int h)
	{
		_srcX = x;
		_srcY = y;
		_width = w;
		_height = h;
	}
};

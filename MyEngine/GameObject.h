#pragma once
#include "Global.h"
#include <math.h>

class Scene;
class GameObject
{
protected:
	VECTOR _position;//位置
	VECTOR _size;//サイズ
	Scene* _scene;
public:
	//コンストラクタ
	GameObject();
	//デストラクタ
	~GameObject();

	//機能：更新処理
	//引数：なし
	//戻り値：なし
	virtual void Update();   //更新

	//機能：描画処理
	//引数：なし
	//戻り値：なし
	virtual void Draw();     //描画

	//機能：位置のセッター
	//引数：position セットしたい位置
	//戻り値：なし
	void SetPosition(VECTOR position)
	{
		_position = position;
	}
	//機能：中心位置のゲッター
	VECTOR GetPosition()
	{
		return _position;
	}
	VECTOR GetCenter()
	{
		return VAdd(_position, VScale(_size, 0.5f));
	}
	//機能：位置のセッター
	//引数：position セットしたい位置
	//戻り値：なし
	void SetPosition(float x, float y, float z = 0/*引数の語尾に＝０をつけると引数を省略できる*/)
	{
		_position.x = x;
		_position.y = y;
		_position.z = z;
	}//関数のオーバーロード：関数名が同じでも引数が異なれば共存できる。
	void SetScene(Scene* scene)
	{
		_scene = scene;
	}
};

//機能：
//引数：
//戻り値：
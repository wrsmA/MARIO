#pragma once
#include "MyEngine\Sprite.h"

class Stage;
class Player :public Sprite
{
	const int SPEED;
	Stage* _stage;
public:
	Player();
	~Player();
	//機能：更新処理
	//引数：なし
	//戻り値：なし
	void Update() override;
	//機能：移動
	//引数：なし
	//戻り値：なし
	void Move();
	void SetStage(Stage* stage)
	{
		_stage = stage;
	}
};


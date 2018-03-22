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
	//�@�\�F�X�V����
	//�����F�Ȃ�
	//�߂�l�F�Ȃ�
	void Update() override;
	//�@�\�F�ړ�
	//�����F�Ȃ�
	//�߂�l�F�Ȃ�
	void Move();
	void SetStage(Stage* stage)
	{
		_stage = stage;
	}
};


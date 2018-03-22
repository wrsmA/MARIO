#pragma once
#include "GameObject.h"
class Sprite : public GameObject
{
protected:
	int _graphicHandle;  //�摜�̎��ʔԍ�
	int _srcX, _srcY, _width, _height;
public:
	//�R���X�g���N�^
	Sprite();
	//�f�X�g���N�^
	~Sprite();

	//�@�\�F�摜�̓ǂݍ���
	//�����FfileName�@�t�@�C����
	//�߂�l�F�Ȃ�
	void Load(char* fileName);

	//�@�\�F�`�揈��
	//�����F�Ȃ�
	//�߂�l�F�Ȃ�
	void Draw();
	//�@�\�F
	//�����F�Ȃ�
	//�߂�l�F�Ȃ�
	void SetRect(int x, int y, int w, int h)
	{
		_srcX = x;
		_srcY = y;
		_width = w;
		_height = h;
	}
};

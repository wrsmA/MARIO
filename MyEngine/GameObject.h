#pragma once
#include "Global.h"
#include <math.h>

class Scene;
class GameObject
{
protected:
	VECTOR _position;//�ʒu
	VECTOR _size;//�T�C�Y
	Scene* _scene;
public:
	//�R���X�g���N�^
	GameObject();
	//�f�X�g���N�^
	~GameObject();

	//�@�\�F�X�V����
	//�����F�Ȃ�
	//�߂�l�F�Ȃ�
	virtual void Update();   //�X�V

	//�@�\�F�`�揈��
	//�����F�Ȃ�
	//�߂�l�F�Ȃ�
	virtual void Draw();     //�`��

	//�@�\�F�ʒu�̃Z�b�^�[
	//�����Fposition �Z�b�g�������ʒu
	//�߂�l�F�Ȃ�
	void SetPosition(VECTOR position)
	{
		_position = position;
	}
	//�@�\�F���S�ʒu�̃Q�b�^�[
	VECTOR GetPosition()
	{
		return _position;
	}
	VECTOR GetCenter()
	{
		return VAdd(_position, VScale(_size, 0.5f));
	}
	//�@�\�F�ʒu�̃Z�b�^�[
	//�����Fposition �Z�b�g�������ʒu
	//�߂�l�F�Ȃ�
	void SetPosition(float x, float y, float z = 0/*�����̌���Ɂ��O������ƈ������ȗ��ł���*/)
	{
		_position.x = x;
		_position.y = y;
		_position.z = z;
	}//�֐��̃I�[�o�[���[�h�F�֐����������ł��������قȂ�΋����ł���B
	void SetScene(Scene* scene)
	{
		_scene = scene;
	}
};

//�@�\�F
//�����F
//�߂�l�F
#include "GameObject.h"

GameObject::GameObject()
{
	_position.x = 0.0f;
	_position.y = 0.0f;
	_position.z = 0.0f;//position�R���X�g���N�g������
	_size.x = 0.0f;
	_size.y = 0.0f;
	_size.z = 0.0f;//position�R���X�g���N�g������
}

GameObject::~GameObject()
{
}
void GameObject::Update()
{
}
void GameObject::Draw()
{
}
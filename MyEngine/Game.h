#pragma once

class Scene;
class Game
{
	//�ϐ��͂����ɍ��
	static Scene* _scene;

public:
	//�֐��͂����ɍ��
	void Start();
	void Update();	//��ɂ�肽������
	~Game();
	static void ChangeScene(Scene* scene);
};

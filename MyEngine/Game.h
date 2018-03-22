#pragma once

class Scene;
class Game
{
	//変数はここに作る
	static Scene* _scene;

public:
	//関数はここに作る
	void Start();
	void Update();	//常にやりたいこと
	~Game();
	static void ChangeScene(Scene* scene);
};

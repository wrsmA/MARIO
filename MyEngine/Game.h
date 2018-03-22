#pragma once

class Scene;
class Game
{
	//•Ï”‚Í‚±‚±‚Éì‚é
	static Scene* _scene;

public:
	//ŠÖ”‚Í‚±‚±‚Éì‚é
	void Start();
	void Update();	//í‚É‚â‚è‚½‚¢‚±‚Æ
	~Game();
	static void ChangeScene(Scene* scene);
};

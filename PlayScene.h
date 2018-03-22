#pragma once
#include "MyEngine\Scene.h"

class Player;
class Stage;
class PlayScene :	public Scene
{
	Player* _player;
	Stage* _Stage;
public:
	PlayScene();
	~PlayScene();
	void Start() override;
};


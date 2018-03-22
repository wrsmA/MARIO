#pragma once
#include "D:\GC1A18\MARI0\MyEngine\Sprite.h"
class Stage :public Sprite
{
	int _mapTable[100][10];
public:
	Stage();
	~Stage();
	void Draw()override;
	bool IsTraffic(int x, int y);

};


#pragma once
#include "Sprite.h"
class Effect :
	public Sprite
{
	int _frame;
public:
	Effect();
	~Effect();
	void Update()override;
};

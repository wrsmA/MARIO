#include "Effect.h"
#include "Scene.h"

Effect::Effect()
{
	_frame = 0;
}

Effect::~Effect()
{
}
void Effect::Update()
{
	_srcX += _frame*_width;
	if (_srcX > _size.x)
	{
		_scene->Destroy(this);
	}
	else{
		_frame++;
	}
	//_frame++;
}
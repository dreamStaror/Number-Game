#pragma once
#include "GameScene.h"
class MoveManager
{
public:
	MoveManager(GameScene* obj);
	~MoveManager();
	void MoveToUp();
	void MoveToDown();
	void MoveToLeft();
	void MoveToRight();
private:
	unsigned int tmp[4] = { 0,0,0,0 };
	GameScene* pGameScene;
	void dealNum();
};
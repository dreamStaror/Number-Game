#pragma once
#include "GameScene.h"
#include "MoveManager.h"
#include <iostream>
class GameLogic
{
public:
	GameLogic();
	~GameLogic();
	void initMainMenu();
	GameScene* GetGameScene();

private:
	bool bGameRunning;
	GameScene gameScene;
	MoveManager moveManager;
	void GameStart();
	void GameEnd();
	void PlayerMove(char playerOption);
};


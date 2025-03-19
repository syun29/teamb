#include "Game.h"
#include"Game/Player.h"
#include"System/TaskManager.h"
#include"Game/Enemy.h"
#include "Game/EnemyManager.h"
#include"Game/Field.h"
#include"UI/Score.h"
#include"Game/Nomal.h"
#include "Game/SterManager.h"
#include "Game/Constellation_Star.h"
#include"UI/Timer.h"

#include"Title/Title.h"
#include "Game/Constellation_Star.h"

#include"Game/Constellation.h"
Game::Game()
	: Task((int)ETaskPrio::Game, 0,eType_Game)
{
	

	new Player(
		CVector3D(150.0f, 100.0f, 0.0f), CVector3D(100.0f, 230.0f, 20.0f), CVector3D(100.0f, 0.0f, 20.0f));
	new Timer;
	new SterManager;
	new Field(
		CVector3D(100.0f, 100.0f, 0.0f));
	new Score(CVector2D(1700, 300));

	new EnemyManager;
	new Constellation(CVector2D(150, 150));

}

Game::~Game()
{
}

void Game::Update()
{
}

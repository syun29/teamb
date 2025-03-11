#include "SterManager.h"
#include "Constellation_Star.h"
#include"Nomal.h"
struct StarData {
	CVector3D pos;
	int type;
	int id;
};
std::vector<StarData>star_data = {
	{CVector3D(1000,500,200),0,0},
	{CVector3D(2000,200,100),0,0},
	{CVector3D(3000,100,300),0,0},	
	{CVector3D(3500,100,400),0,0},
	{CVector3D(4000,0,0),0,0},
	{CVector3D(5500,100,100),0,0},
};

SterManager::SterManager()
	:sterCnt(4)
	, ObjectBase(eType_Player)

{
	for (auto& v : star_data) {
		new Nomal(v.pos);
	}
}

SterManager::~SterManager()
{
}

void SterManager::Update()
{
	
		/*int sterRand = rand() % 3;
		switch (sterRand)
		{
		case 0:
			new Constellation_Star(
				CVector3D(1920.0f, 100.0f, 0.0f), 0);
			break;
		case 1:
			new Constellation_Star(
				CVector3D(1920.0f, 100.0f, 0.0f), 0);
			break;
		case 2:
			new Constellation_Star(
				CVector3D(1920.0f, 100.0f, 0.0f), 0);
			break;
		}*/
		
	
	 
}



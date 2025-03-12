#include "SterManager.h"
#include "Constellation_Star.h"
#include"Nomal.h"
struct StarData {
	CVector3D pos;
	int type;
	int id;
};
std::vector<StarData>star_data = {
	{CVector3D(1000,100,0),eType_Nomal,0},
	{CVector3D(1500,0,100),eType_Nomal,0},
	{CVector3D(3000,0,0),eType_Nomal,0},
	{CVector3D(3500,0,200),eType_Nomal,0},
	{CVector3D(4000,100,0),eType_Nomal,0},
	{CVector3D(5500,200,0),eType_Nomal,0},
	{CVector3D(4500,200,0),eType_Tri,0},
	{CVector3D(500,200,0),eType_Tri,0},
	{CVector3D(3500,200,0),eType_Tri,0},



};

SterManager::SterManager()
	:sterCnt(4)
	, ObjectBase(eType_Player)

{

	for (auto& v : star_data) {
		if (v.type == eType_Nomal)
			new Nomal(v.pos);
		else
			new Constellation_Star(v.pos, CVector3D(20, 20, 20), v.type);
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



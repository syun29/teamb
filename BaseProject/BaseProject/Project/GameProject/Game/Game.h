#pragma once
#include "../System/Task.h"

class Game : public Task {
public:
	Game();
	~Game();
	void Update();
};
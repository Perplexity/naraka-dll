#pragma once
#include "../cyrix.h"

class Naraka {
public:
	struct Client {
		struct World {
			std::vector<ActorModel*> GetPlayers();
		};
		ActorModel* LocalPlayer;
		World World;
	};
	Client Client;
}extern engine;
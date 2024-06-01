#include "engine.h"

Naraka engine;

std::vector<ActorModel*> Naraka::Client::World::GetPlayers()
{
	std::vector<ActorModel*> entity_list;
    auto cm = CharacterManager::Instance();
    if (!cm) return entity_list;
    auto localPlayer = cm->GetLocalPlayer();
    if (!localPlayer) return entity_list;
    auto list = cm->GetPlayers();
    if (!list) return entity_list;
    if (list->Count() == 1) return entity_list;
    auto arr = list->GetValues();
    if (!arr) return entity_list;
    for (uint8_t i = 0; i < list->Count(); i++) {
        auto p = arr->GetValue(i);
        if (!p || p == localPlayer) continue;
        entity_list.push_back(p);
    }

    return entity_list;
}

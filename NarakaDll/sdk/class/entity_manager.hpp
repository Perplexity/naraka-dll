#pragma once
class GameEntity : UObject {
public:
	String* GetName() {
		return this->GetField("<name>k__BackingField")->GetValue<String*>(this);
	}
};
class EntityManager : UObject {
public:
	static EntityManager* Instance() {
		return Class::Resolve("Assembly-CSharp", "GameLogic.Common", "GameEntity")->GetField("entityManager")->GetStaticValue<EntityManager*>();
	}
	HashSet<GameEntity*>* GetEntities() {
		return this->GetField("entities")->GetValue<HashSet<GameEntity*>*>(this);
	}
};
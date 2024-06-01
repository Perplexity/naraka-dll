#pragma once
enum class CharacterType : int
{
	Player = 0,
	Robot = 1,
	Monster = 2,
	VisualCharacter = 3,
	UICharacter = 10,
	UICharacterWithGravity = 11
};

class ActorModel : UObject {
public:
	Transform* GetTransform() {
		return this->GetField("<transform>k__BackingField")->GetValue<Transform*>(this);
	}
	Vector3 GetPosition() {
		auto t = this->GetTransform();
		if (t) {
			return t->GetPosition();
		}
		return {};
	}
	float Distance(Vector3 pos) {
		return this->GetPosition().Distance(pos);
	}
	CharacterType GetCharacterType() {
		return this->GetField("_selfCharacterType")->GetValue<CharacterType>(this);
	}
};
class CharacterManager : UObject {
public:
	static CharacterManager* Instance() {
		return Class::Resolve("Assembly-CSharp", "", "CharacterManager")->GetField("_instance")->GetStaticValue<CharacterManager*>();
	}
	static List<ActorModel*>* GetPlayers() {
		return Class::Resolve("Assembly-CSharp", "", "CharacterManager")->GetField("allAliveCharacterList")->GetStaticValue<List<ActorModel*>*>();
	}
	ActorModel* GetLocalPlayer() {
		return this->GetField("mainPlayerActorModel")->GetValue<ActorModel*>(this);
	}
};
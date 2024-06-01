#pragma once

enum RoleTypes : byte
{
	Crewmate,
	Impostor,
	Scientist,
	Engineer,
	GuardianAngel,
	Shapeshifter,
	CrewmateGhost,
	ImpostorGhost
};

class PlayerControl;

class RoleBehaviour : public Component {
public:
	RoleTypes GetRole() {
		return this->GetField("Role")->GetValue<RoleTypes>(this);
	}
	void SetRole(RoleTypes role) {
		this->GetField("Role")->SetValue<RoleTypes>(this, role);
	}
	bool isImposter() {
		return this->GetRole() == Impostor;
	}
	Color GetNameColor() {
		return this->GetField("NameColor")->GetValue<Color>(this);
	}
	Color GetTeamColor() {
		return Method::Call<Color(*)(RoleBehaviour*)>("Assembly-CSharp", "", "RoleBehaviour", "get_TeamColor", 0)(this);
	}
};

class PlayerInfo : public Object {
public:
	String* GetName() {
		return this->GetClass()->GetMethod("get_PlayerName", 0)->InternalCall<String*>();
		//return Method::Call<String*(*)(PlayerInfo*)>("Assembly-CSharp", "", "GameData-PlayerInfo", "get_PlayerName", 0)(this);
	}
	String* GetFriendCode() {
		return this->GetField("FriendCode")->GetValue<String*>(this);
	}
	PlayerControl* GetPlayer() {
		return this->GetField("_object")->GetValue<PlayerControl*>(this);
	}
	RoleBehaviour* GetRoleBehaviour() {
		return this->GetField("Role")->GetValue<RoleBehaviour*>(this);
	}
};

class PlayerControl : public Component {
public:
	static PlayerControl* GetLocalPlayer() {
		return Class::Resolve("Assembly-CSharp", "", "PlayerControl")->GetField("LocalPlayer")->GetStaticValue<PlayerControl*>();
	}
	static List<PlayerControl*>* GetPlayers() {
		return Class::Resolve("Assembly-CSharp", "", "PlayerControl")->GetField("AllPlayerControls")->GetStaticValue<List<PlayerControl*>*>();
	}
	PlayerInfo* GetInfo() {
		return Method::Call<PlayerInfo * (*)(PlayerControl*)>("Assembly-CSharp", "", "PlayerControl", "get_Data", 0)(this);
	}
	Vector2 GetTruePosition() {
		return Method::Call<Vector2(*)(PlayerControl*)>("Assembly-CSharp", "", "PlayerControl", "GetTruePosition", 0)(this);
	}
	void SetRole(RoleTypes role) {
		return Method::Call<void(*)(PlayerControl*, RoleTypes)>("Assembly-CSharp", "", "PlayerControl", "SetRole", 1)(this, role);
	}
	bool RpcSendChat(const char* Text) {
		return Method::Call<bool(*)(PlayerControl*, String*)>("Assembly-CSharp", "", "PlayerControl", "RpcSendChat", 1)(this, String::New(Text));
	}
	void RpcSetRole(RoleTypes role) {
		return Method::Call<void(*)(PlayerControl*, RoleTypes)>("Assembly-CSharp", "", "PlayerControl", "RpcSetRole", 1)(this, role);
	}
	void RpcSetName(const char* Text) {
		return Method::Call<void(*)(PlayerControl*, String*)>("Assembly-CSharp", "", "PlayerControl", "RpcSetName", 1)(this, String::New(Text));
	}
	void RpcSetNamePlate(const char* Text) {
		return Method::Call<void(*)(PlayerControl*, String*)>("Assembly-CSharp", "", "PlayerControl", "RpcSetNamePlate", 1)(this, String::New(Text));
	}
};

class GameData : public Component {
public:
	static List<PlayerInfo*>* GetPlayers() {
		GameData* data = GetInstance();
		if (!data) return nullptr;
		return data->GetField("AllPlayers")->GetValue<List<PlayerInfo*>*>(data);
	}
	static GameData* GetInstance() {
		return Class::Resolve("Assembly-CSharp", "", "GameData")->GetField("Instance")->GetStaticValue<GameData*>();
	}
	int GetPlayerCount() {
		return Method::Call<int(*)(GameData*)>("Assembly-CSharp", "", "GameData", "get_PlayerCount", 0)(this);
	}
};
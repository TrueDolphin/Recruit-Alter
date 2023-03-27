modded class PlayerBase
{

string Recruit_Faction = "Raiders";
ref TStringArray Allowed_Factions ={};

string Recruit_faction() {
    return Recruit_Faction;
}

TStringArray Allowed_Factions(){
    return Allowed_Factions;
}

void Set_Recruit_Faction(string a){
    Recruit_Faction = a;
}

void Set_Allowed_Factions(TStringArray a){
    Allowed_Factions = a;
}

};

#define _ARMA_

class CfgPatches
{
	class Dayz_Expansion_AI_Recruit_scripts
	{
		requiredAddons[] = {"DayZExpansion_AI_Scripts"};
	};
};
class CfgMods
{
	class Dayz_Expansion_AI_Recruit
	{
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "AI Additional Scripts";
		credits = "DayZ Expansion and dolphin";
		author = "Dolphin";
		authorID = "";
		version = "0.1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"dolphin/Dayz-Expansion-AI-Recruit/Scripts/3_Game"};
			};			
			class worldScriptModule
			{
				value = "";
				files[] = {"dolphin/Dayz-Expansion-AI-Recruit/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"dolphin/Dayz-Expansion-AI-Recruit/Scripts/5_Mission"};
			};
		};
	};
};
class RecruitSettings {
  //declares
  private const static string EXP_RECRUIT_FOLDER = "$profile:ExpansionMod\\AI\\Utils\\";
  private const static string EXP_AI_RECRUIT_SETTINGS = EXP_RECRUIT_FOLDER + "RecruitSettings.json";

  //refs
  ref Recruit_Groups m_Recruit_Groups;

  //load ref to use location
  void PullRef(out Recruit_Groups Data) {
    if (!m_Recruit_Groups) Load();
    Data = m_Recruit_Groups;
  }

  //load from file/data checks
  void Load() {
    if (!FileExist(EXP_AI_RECRUIT_SETTINGS)) {
      if (!FileExist(EXP_RECRUIT_FOLDER))
        MakeDirectory(EXP_RECRUIT_FOLDER);
      loggerPrint("WARNING: Couldn't find config file !");
      loggerPrint("Recruit config will be located in: " + EXP_RECRUIT_FOLDER);
      DefaultRecruitSettings(m_Recruit_Groups);
      JsonFileLoader < Recruit_Groups > .JsonSaveFile(EXP_AI_RECRUIT_SETTINGS, m_Recruit_Groups);
    } else {
      m_Recruit_Groups = new Recruit_Groups();
      JsonFileLoader < Recruit_Groups > .JsonLoadFile(EXP_AI_RECRUIT_SETTINGS, m_Recruit_Groups);
    }
  }

  //generate default array data
  void DefaultRecruitSettings(out Recruit_Groups Data) {
    Data = new Recruit_Groups();

    Data.Group.Insert( new Recruit_players("76562158225858681", "West"));
	  Data.Group.Insert( new Recruit_players("76562158225858682", "West"));
	  Data.Group.Insert( new Recruit_players("76562158225858683", "West"));
	  Data.Group.Insert( new Recruit_players("76561198019858686", "West"));

  }

  //expansion logging (Dynamic AI prefex)
  void loggerPrint(string msg) {
    if (GetExpansionSettings().GetLog().AIGeneral)
      GetExpansionSettings().GetLog().PrintLog("[Recruit Settings] " + msg);
  }
}


//json data
class Recruit_Groups {
  int Version = 1;
  ref TStringArray RecruitFactions = {
    "Shamans",
    "Guards",
    "West"
  };
  ref array< ref Recruit_players > Group;
  void Recruit_Groups() {
    Group = new array < ref Recruit_players > ;
  }
}


class Recruit_players {
  string UID;
  string Faction;

  void Recruit_players(string bod, string fac) {
    UID = bod;
    Faction = fac;
  }
}

//expansion-external data access
static ref RecruitSettings g_RecruitSettings;

static RecruitSettings GetRecruitSettings() {
  if (g_RecruitSettings == NULL) {
    g_RecruitSettings = new RecruitSettings();
    g_RecruitSettings.Load();
  }
  return g_RecruitSettings;
}
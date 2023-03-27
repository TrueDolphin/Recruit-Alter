modded class MissionServer {
  ref Recruit_Groups m_RecruitSettings;

  override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
    eAIFaction factionb;
    bool s_found = false;
    eAIGroup playerGroupb = player.GetGroup();

    if (!playerGroupb) playerGroupb = eAIGroup.GetGroupByLeader(player);
    if (!m_RecruitSettings) GetRecruitSettings().PullRef(m_RecruitSettings);

    foreach(Recruit_players Group: m_RecruitSettings.Group) {
      if (player.GetIdentity().GetPlainId() == Group.UID) {

        factionb = eAIFaction.Create(Group.Player_Faction);
        if (factionb) {
          Print(player.GetIdentity().GetName() + " Set to faction: " + factionb.ToString());
          playerGroupb.SetFaction(factionb);
          player.Set_Recruit_Faction(Group.Player_Faction);
          player.Set_Allowed_Factions(Group.Allowed_Factions);
          s_found = true;
        }
      }
    }

    if (!s_found) {
      Print("Creating config for :" + player.GetIdentity().GetName());
      GetRecruitSettings().New_Player(player.GetIdentity().GetPlainId());
      factionb = eAIFaction.Create(m_RecruitSettings.Global_Faction);
      playerGroupb.SetFaction(factionb);
      player.Set_Recruit_Faction(m_RecruitSettings.Global_Faction);
      player.Set_Allowed_Factions(m_RecruitSettings.Default_Factions);
    }

    super.InvokeOnConnect(player, identity);

  }
};
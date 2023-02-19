modded class MissionServer {
  ref Recruit_Groups m_RecruitSettings;

  override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
    bool s_found = false;
    eAIGroup playerGroupb = player.GetGroup();
    if(!playerGroupb) playerGroupb = eAIGroup.GetGroupByLeader(player);

    if (!m_RecruitSettings) GetRecruitSettings().PullRef(m_RecruitSettings);
    foreach(Recruit_players Group: m_RecruitSettings.Group) {
      if (player.GetIdentity().GetPlainId() == Group.UID) {

        eAIFaction factionb = eAIFaction.Create(Group.Faction);
        if (factionb) {
          Print(player.GetIdentity().GetName() + " Set to faction: " + factionb.ToString());
          playerGroupb.SetFaction(factionb);
          s_found = true;
        }
      } else {
      }
    }
    if (!s_found) Print("No Config for :" + player.GetIdentity().GetName() + " found.");
    super.InvokeOnConnect(player, identity);
  }
};
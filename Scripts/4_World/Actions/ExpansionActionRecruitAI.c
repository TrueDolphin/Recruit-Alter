modded class ExpansionActionRecruitAI {
  ref Recruit_Groups m_RecruitSettings;

  override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		eAIBase tAI;
		if (!Class.CastTo(tAI, target.GetObject()))
			return false;

		if (!tAI.IsAlive() || tAI.IsUnconscious())
			return false;

		if (player.GetGroup() == tAI.GetGroup())
			return false;

		//! Don't allow to recruit other player's AI
		if (tAI.GetGroup().GetLeader() && !tAI.GetGroup().GetLeader().IsAI())
			return false;

		//! Don't allow to recruit passive or invincible AI
		if (tAI.eAI_IsPassive() || tAI.GetGroup().GetFaction().IsInvincible())
			return false;
    //setting disabled
    if (!GetExpansionSettings().GetAI().CanRecruitGuards)
      return false;
    //if enemy, fail
    if (tAI.PlayerIsEnemy(player))
      return false;

    //if match allow
    GetRecruitSettings().PullRef(m_RecruitSettings);
    if (m_RecruitSettings != NULL) {
      foreach(string fName: m_RecruitSettings.RecruitFactions) {
        if (fName == tAI.GetGroup().GetFaction().GetName()) {
          tAI.GetGroup().ClearWaypoints();
          return true;
        }
      }
    }
    //else false
    return false;
  }

};
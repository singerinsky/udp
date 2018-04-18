#include "player.h"
#include "serverpch.h"
#include "netrequestmgr.h"
#include "character_mgr.h"

void CPlayer::DisConnect(){
    assert(m_dwConnId != 0);
    net_request_mgr::Instance()->push_disconnect_outevent(m_dwConnId);
    CCharacterMgr::Instance()->RemovePlayer(m_dwPlayerId);
}

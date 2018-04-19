#ifndef _CHARACTER_MGR_H_
#define _CHARACTER_MGR_H_

#include "timer_manager.h"
#include <map>
#include "serverpch.h"
#include "player.h"
#include "object_pool.h"

using namespace std;

class CPlayerPool:public object_pool<CPlayer>
{
    protected:
        virtual CPlayer*  create(){
            return NULL; 
        }
        virtual bool init_config(){}
 

};


class CCharacterMgr
{
    DECLARE_SINGLETON(CCharacterMgr);    
    public:
        CCharacterMgr(){
            _start_id = 0 ;
            _timer.set_owner(this);    
            _timer.set_expired(timer_manager::Instance()->get_run_ms()+1000);
            timer_manager::Instance()->add_timer(&_timer);
       }

        void _on_timeout(timer_manager* mgr){
            _timer.set_expired(timer_manager::Instance()->get_run_ms()+1000);
            timer_manager::Instance()->add_timer(&_timer);
        }

        void MapConn(e_uint32 dwConnID,e_uint32 dwPlayerId){
            auto itr = _conn_map.find(dwPlayerId); 
            if(itr != _conn_map.end()){
                _conn_map[dwPlayerId] = dwConnID; 
            }else{
                LOG(INFO)<<"New Connection";
                _conn_map[dwPlayerId] = dwConnID; 
            }
        }

        void UnMapConnByPlayerId(e_uint32 dwPlayerId){
            auto itr = _conn_map.begin();
            while(itr != _conn_map.end()){
                if(itr->second == dwPlayerId){
                    _conn_map.erase(itr->first); 
                    return;
                }
                itr++;
            }
        
        }

        CPlayer* AddPlayer(e_uint32 dwPlayerId ,CPlayer* pPlayer){
            auto itr = _player_map.find(dwPlayerId); 
            if(itr != _player_map.end()){
                return itr->second; 
            }
            _player_map[dwPlayerId] = pPlayer;
            return pPlayer;
        }

        CPlayer* GetPlayer(e_uint32 dwPlayerId){
            auto itr = _player_map.find(dwPlayerId);
            if( itr == _player_map.end()){
                return NULL; 
            }
            return itr->second;
        }

        void RemovePlayer(e_uint32 uPlayerId){
            auto itr = _player_map.find(uPlayerId);
            if(itr == _player_map.end()){
                return; 
            }
            UnMapConnByPlayerId(itr->second->GetPlayerId());
            delete itr->second;
            _player_map.erase(itr);
        }

    private:
        e_uint32                                                    _start_id;
        template_timer<CCharacterMgr,&CCharacterMgr::_on_timeout>   _timer;
        std::map<e_uint32,e_uint32>                                 _conn_map;
        std::map<e_uint32,CPlayer*>                                 _player_map;
};


#endif

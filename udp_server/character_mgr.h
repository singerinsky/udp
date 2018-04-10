#ifndef _CHARACTER_MGR_H_
#define _CHARACTER_MGR_H_

#include "timer_manager.h"
#include <map>
using namespace std;

class CPlayer;
class CCharacterMgr
{
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

        CPlayer* AddPlayer(e_uint32 dwConnID){
             
        }
    private:
        e_uint32                                                    _start_id;
        template_timer<CCharacterMgr,&CCharacterMgr::_on_timeout>   _timer;
        std::map<e_uint32,e_uint32>                                 _conn_map;
        std::map<e_uint32,CPlayer*>                                 _player_map;
};


#endif

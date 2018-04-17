#ifndef _PLAYER_H_
#define _PLAYER_H_

class CPlayer
{
    public:
        CPlayer(int playerId){
            m_dwPlayerId = playerId; 
            m_dwConnId = 0;
        }
        ~CPlayer(){};
       
        int GetPlayeId(){
            return m_dwPlayerId; 
        }

        void SetConnId(int connId){
            m_dwConnId = connId; 
        }

        int GetConnId(){
            return m_dwConnId; 
        }

    private:
        int m_dwPlayerId;
        int m_dwConnId;
};

#endif

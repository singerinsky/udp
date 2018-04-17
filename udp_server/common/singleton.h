#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#define DECLARE_SINGLETON(cls)\
    private:\
        static cls* sm_poInstace;\
    public:\
        static bool CreateInstance()\
        {\
            if(NULL == sm_poInstace)sm_poInstace = new cls;\
            return sm_poInstace;\
        }\
        static cls* Instance(){return sm_poInstace;}\
        static void DestoryInstance()\
        {\
            if(sm_poInstace != NULL)\
            {\
                delete sm_poInstace;\
                sm_poInstace = NULL;\
            }\
        }

#define INSTANCE_SINGLETON(cls)\
    cls* cls::sm_poInstace = NULL;

#endif

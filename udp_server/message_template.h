#ifndef _MESSAGE_TEMPLATE_H_
#define _MESSAGE_TEMPLATE_H_

<class uType,class T>
class message_template{
    public:
        enum{packetType = uType,};
        typedef T body_type;
        body_type   m_body;
    public:
        virtual e_uint32 get_type(){return packetType;};
        virtual e_uint32 encode(char* data,e_uint32 size){};
        virtual bool     decode(const char* data,e_uint32 size){
            try{
                istream istr(data);
                m_body.ParseFromIstream(&istr);
            }catch(const std::exception& ex){
                return false; 
            }
            return true;
        };
        virtual void process(e_uint32 connID) = 0;
};



#endif

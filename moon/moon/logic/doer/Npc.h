#ifndef __NPC_H__
#define __NPC_H__

class CNpc : public CDoer
{
public:
	typedef CDoer super;

public:
	CNpc():super()
	{
		m_btType = eNPC;
	}
	~CNpc(){};
	

};

#endif

//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGQuitUnion.h 
// Written By  :
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_QUIT_UNION_H__
#define __CG_QUIT_UNION_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGQuitUnion;
//
//////////////////////////////////////////////////////////////////////

class CGQuitUnion : public Packet
{
public:
	enum{
		QUIT_NORMAL = 0,		// ������ ���� ��û
		QUIT_QUICK,				// �Ϲ������� Ż��
		QUIT_MAX
	};	
    CGQuitUnion() {};
    ~CGQuitUnion() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_CG_QUIT_UNION; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() { return szGuildID+szBYTE; }

	// get packet name
	string getPacketName() const throw() { return "CGQuitUnion"; }

	// get packet's debug string
	string toString() const throw();

    // get/set GuildID
    GuildID_t getGuildID() const throw() { return m_GuildID; }
    void setGuildID(GuildID_t GuildID ) throw() { m_GuildID = GuildID; }

	// get/set Quit Method
	BYTE	getQuitMethod()	const throw() { return m_Method; }
	void	setQuitMethod(BYTE Method ) throw() { m_Method = Method; }


private :

	// Guild ID
	GuildID_t	m_GuildID;
	BYTE		m_Method;


};


//////////////////////////////////////////////////////////////////////
//
// class CGQuitUnionFactory;
//
// Factory for CGQuitUnion
//
//////////////////////////////////////////////////////////////////////

class CGQuitUnionFactory : public PacketFactory {

public:
	
	// constructor
	CGQuitUnionFactory() throw() {}
	
	// destructor
	virtual ~CGQuitUnionFactory() throw() {}

	
public:
	
	// create packet
	Packet* createPacket() throw() { return new CGQuitUnion(); }

	// get packet name
	string getPacketName() const throw() { return "CGQuitUnion"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_CG_QUIT_UNION; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const throw() { return szGuildID + szBYTE; }
};


//////////////////////////////////////////////////////////////////////
//
// class CGQuitUnionHandler;
//
//////////////////////////////////////////////////////////////////////

class CGQuitUnionHandler {

public:

	// execute packet's handler
	static void execute(CGQuitUnion* pCGQuitUnion, Player* pPlayer) throw(Error);

};

#endif
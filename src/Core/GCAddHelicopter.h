//////////////////////////////////////////////////////////////////////////////
// Filename    : GCAddHelicopter.h 
// Written By  : excel96
// Description :
// �����̾ �����⸦ �����, ��⸦ ȣ������ ��쿡 ���ư��� ��Ŷ
//////////////////////////////////////////////////////////////////////////////

#ifndef __GC_ADD_HELICOPTER_H__
#define __GC_ADD_HELICOPTER_H__

#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class GCAddHelicopter;
//////////////////////////////////////////////////////////////////////////////

class GCAddHelicopter : public Packet 
{
public:
    GCAddHelicopter() {};
    ~GCAddHelicopter() {};
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);
	void execute(Player* pPlayer) throw(ProtocolException, Error);
	PacketID_t getPacketID() const throw() { return PACKET_GC_ADD_HELICOPTER; }
	PacketSize_t getPacketSize() const throw() { return szObjectID + szBYTE; }
	string getPacketName() const throw() { return "GCAddHelicopter"; }
	string toString() const throw();

public:
	ObjectID_t getObjectID(void) const { return m_ObjectID; }
	void setObjectID(ObjectID_t d) { m_ObjectID = d; }

	BYTE setCode(void) const { return m_Code; }
	void setCode(BYTE code) { m_Code = code; }
	
private:
	ObjectID_t  m_ObjectID; // ��⸦ ȣ���� �����̾��� ������Ʈ ID
	BYTE        m_Code;     // ��� ��ȯ�� ���õ� �ڵ� (0:ȣ��, 1:����)
};

//////////////////////////////////////////////////////////////////////////////
// class GCAddHelicopterFactory;
//////////////////////////////////////////////////////////////////////////////

class GCAddHelicopterFactory : public PacketFactory 
{
public:
	Packet* createPacket() throw() { return new GCAddHelicopter(); }
	string getPacketName() const throw() { return "GCAddHelicopter"; }
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_ADD_HELICOPTER; }
	PacketSize_t getPacketMaxSize() const throw() { return szObjectID + szBYTE; }
};

//////////////////////////////////////////////////////////////////////////////
// class GCAddHelicopterHandler;
//////////////////////////////////////////////////////////////////////////////

class GCAddHelicopterHandler 
{
public:
	static void execute(GCAddHelicopter* pGCAddHelicopter, Player* pPlayer) throw(Error);
};

#endif
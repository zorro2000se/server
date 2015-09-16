//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCSkillToTileOK3.h 
// Written By  : elca@ewestsoft.com
// Description : ��� ����ڴ� ���� �ְ�, �����ڴ� �� �� ���� ��Ŷ
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GC_SKILL_TO_TILE_OK_3_H__
#define __GC_SKILL_TO_TILE_OK_3_H__


// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class GCSkillToTileOK3;
//
// ���Ӽ������� Ŭ���̾�Ʈ�� �ڽ��� ����� ������ �˷��ֱ� ���� Ŭ����
//
//////////////////////////////////////////////////////////////////////

class GCSkillToTileOK3 : public Packet {

public :
	
	// constructor
	GCSkillToTileOK3() throw();
	
	// destructor
	~GCSkillToTileOK3() throw();

	
public :
	
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GC_SKILL_TO_TILE_OK_3; }
	
	// get packet's body size
	// ����ȭ��, �̸� ���� ������ ����Ѵ�.
//	PacketSize_t getPacketSize() const throw() { return szSkillType + szObjectID +(szCoord* 2)
//			+ szDuration + szBYTE + szObjectID* m_CListNum; }
	PacketSize_t getPacketSize() const throw() { return szSkillType + szObjectID +(szCoord* 2) + szBYTE;}

	// get packet's name
	string getPacketName() const throw() { return "GCSkillToTileOK3"; }
	
	// get packet's debug string
	string toString() const throw();

	// get / set ObjectID 
	CEffectID_t getObjectID() const throw() { return m_ObjectID; }
	void setObjectID(ObjectID_t ObjectID) throw() { m_ObjectID = ObjectID; }

	// get / set SkillType
	SkillType_t getSkillType() const throw() { return m_SkillType; }
	void setSkillType(SkillType_t SkillType) throw() { m_SkillType = SkillType; }

	// get / set Duration
//	Duration_t getDuration() const throw() { return m_Duration; }
//	void setDuration(Duration_t Duration) throw() { m_Duration = Duration; }

	// get / set X, Y
	Coord_t getX() { return m_X; }
	void setX(Coord_t X) { m_X = X; }

	Coord_t getY() { return m_Y; }
	void setY(Coord_t Y) { m_Y = Y; }

	// get / set Creature List Number
//	BYTE getCListNum() const throw() { return m_CListNum; }

//	void setCListNum(BYTE CListNum) throw() { m_CListNum = CListNum; }

	// add / delete  Creature List
//	void addCListElement(ObjectID_t ObjectID) throw();

	// Clear CreatureList
//	void clearCList() throw() { m_CList.clear(); m_CListNum = 0; }

	// pop front Element in Status List
//	ObjectID_t popCListElement() throw() { ObjectID_t CreatureList = m_CList.front(); m_CList.pop_front(); return CreatureList; }

	BYTE getGrade() const { return m_Grade; }
	void setGrade(BYTE grade ) { m_Grade = grade; }

private :
	
	// CEffectID
	ObjectID_t m_ObjectID;

	// SkillType
	SkillType_t m_SkillType;

	// Duration
//	Duration_t m_Duration;

	// X, Y Position
	Coord_t m_X;

	Coord_t m_Y;

	// CreatureList Element Number 
//	BYTE m_CListNum;

	// Creature List
//	list<ObjectID_t> m_CList;

	BYTE m_Grade;
};


//////////////////////////////////////////////////////////////////////
//
// class GCSkillToTileOK3Factory;
//
// Factory for GCSkillToTileOK3
//
//////////////////////////////////////////////////////////////////////

class GCSkillToTileOK3Factory : public PacketFactory {

public :
	
	// constructor
	GCSkillToTileOK3Factory() throw() {}
	
	// destructor
	virtual ~GCSkillToTileOK3Factory() throw() {}

	
public :
	
	// create packet
	Packet* createPacket() throw() { return new GCSkillToTileOK3(); }

	// get packet name
	string getPacketName() const throw() { return "GCSkillToTileOK3"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_SKILL_TO_TILE_OK_3; }

	// get Packet Max Size
//	PacketSize_t getPacketMaxSize() const throw() { return szSkillType + szObjectID +(szCoord* 2) 
//			+ szDuration + szBYTE + szObjectID + 255; }
	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const throw() { return szSkillType + szObjectID +(szCoord* 2) + szBYTE; }
};


//////////////////////////////////////////////////////////////////////
//
// class GCSkillToTileOK3Handler;
//
//////////////////////////////////////////////////////////////////////

class GCSkillToTileOK3Handler {

public :

	// execute packet's handler
	static void execute(GCSkillToTileOK3* pGCSkillToTileOK3, Player* pPlayer) throw(Error);

};

#endif
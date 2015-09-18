//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectComa.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectComa.h"
#include "Assert1.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Tile.h"
#include "Zone.h"
#include "GamePlayer.h"
#include "ZoneGroupManager.h"
#include "ZoneInfo.h"
#include "ZoneInfoManager.h"
#include "ZonePlayerManager.h"
#include "IncomingPlayerManager.h"
#include "Event.h"
#include "EventResurrect.h"
#include "ResurrectLocationManager.h"
#include "ItemUtil.h"
#include "AlignmentManager.h"
#include "ItemFactoryManager.h"

#include "SlayerCorpse.h"
#include "VampireCorpse.h"
//#include "LogClient.h"
#include "Thread.h"
    
#include "GCCreatureDied.h"
#include "GCGetOffMotorCycle.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

EffectComa::EffectComa(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

EffectComa::~EffectComa()
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

void EffectComa::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);

	affect(pCreature);

	__END_CATCH 

}

void EffectComa::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

void EffectComa::unaffect(Creature* pDeadCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pDeadCreature != NULL);
	//Assert(pDeadCreature->isDead());

	// ����Ʈ �÷��׸� �������ش�.
	pDeadCreature->removeFlag(Effect::EFFECT_CLASS_COMA);
	// ���ƿ��� ������ ���̴� �ڵ带 ����ִ´�.
	if (pDeadCreature->isSlayer()) {
		Slayer* pSlayer = dynamic_cast<Slayer*>(pDeadCreature);
		pSlayer->setHP(0, ATTR_CURRENT);
	}
	else if (pDeadCreature->isVampire()) {
		Vampire* pVampire = dynamic_cast<Vampire*>(pDeadCreature);
		pVampire->setHP(0, ATTR_CURRENT);
	}
	else if (pDeadCreature->isOusters())
	{
		Ousters* pOusters = dynamic_cast<Ousters*>(pDeadCreature);
		pOusters->setHP(0, ATTR_CURRENT);
	}

	__END_CATCH
}

void EffectComa::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

void EffectComa::create(const string & ownerID) 
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

void EffectComa::destroy(const string & ownerID)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

void EffectComa::save(const string & ownerID) 
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

// ��Ÿ�� �ð��� ����Ʈ�� ������ �ð�����, �÷��̾ ���� �ð��̴�.
// �� �ð����� 5�ʸ� �������ν�, canResurrect �Լ����� ���� �� 5�ʰ� ������
// ���� ����� Resurrect���ϰ� �˻��� �� �ִ�.
void EffectComa::setStartTime(void)
{
	getCurrentTime(m_StartTime);
	m_StartTime.tv_sec += 5;
}

bool EffectComa::canResurrect(void)
{
	Timeval currentTime;
	getCurrentTime(currentTime);

	if (m_StartTime < currentTime)
	{
		return true;
	}

	return false;
}

string EffectComa::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectComa("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}

void EffectComaLoader::load(Creature* pCreature) 
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

EffectComaLoader* g_pEffectComaLoader = NULL;











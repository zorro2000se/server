////////////////////////////////////////////////////////////////////////////////
// Filename    : ConditionFlagOff.h
// Written By  : 
// Description :
////////////////////////////////////////////////////////////////////////////////

#ifndef __FLAG_OFF_H__
#define __FLAG_OFF_H__

#include "Condition.h"
#include "ConditionFactory.h"
#include "Creature.h"

//////////////////////////////////////////////////////////////////////////////
// class ConditionFlagOff;
//////////////////////////////////////////////////////////////////////////////

class ConditionFlagOff : public Condition 
{
public:
	virtual ConditionType_t getConditionType() const throw() { return CONDITION_FLAG_OFF; }
	virtual bool isPassive() const throw() { return true; }
	virtual bool isSatisfied(Creature* pNPC, Creature* pPC = NULL, void* pParam = NULL) const throw();
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual string toString() const throw();

public:
	int getIndex(void) const throw() { return m_Index; }
	void setIndex(int index) throw() { m_Index = index; }

private:
	int m_Index; // 플래그의 값

};

//////////////////////////////////////////////////////////////////////////////
// class ConditionFlagOffFactory;
//////////////////////////////////////////////////////////////////////////////

class ConditionFlagOffFactory : public ConditionFactory 
{
public:
    virtual ConditionType_t getConditionType() const throw() { return Condition::CONDITION_FLAG_OFF; }
    virtual Condition* createCondition() const throw() { return new ConditionFlagOff(); }
    virtual string getConditionName() const throw() { return "FlagOff"; }
};

#endif

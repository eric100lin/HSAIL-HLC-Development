
#include "HSAILTestGenSample.h"
#include "HSAILTestGenContext.h"

namespace TESTGEN {

//==============================================================================
//==============================================================================
//==============================================================================

unsigned Sample::get(unsigned propId) const
{
    assert(PROP_MINID < propId && propId < PROP_MAXID);
    assert(!isEmpty());

    switch(propId)
    {
    case PROP_D0:
    case PROP_S0:      return getContext()->operand2id(inst.operand(0));
    case PROP_D1:      
    case PROP_S1:      return getContext()->operand2id(inst.operand(1));
    case PROP_S2:      return getContext()->operand2id(inst.operand(2));
    case PROP_S3:      return getContext()->operand2id(inst.operand(3));
    case PROP_S4:      return getContext()->operand2id(inst.operand(4));
    }

    unsigned val = getBrigProp(inst, propId);

    return (propId == PROP_EQUIVCLASS)? getContext()->eqclass2id(val) : val;
}

void Sample::set(unsigned propId, unsigned val)
{
    assert(PROP_MINID < propId && propId < PROP_MAXID);
    assert(!isEmpty());

    using namespace Brig;

    switch(propId)
    {
    case PROP_D0:
    case PROP_S0:   inst.operand(0) = getContext()->id2operand(val);    return;
    case PROP_D1:
    case PROP_S1:   inst.operand(1) = getContext()->id2operand(val);    return;
    case PROP_S2:   inst.operand(2) = getContext()->id2operand(val);    return;
    case PROP_S3:   inst.operand(3) = getContext()->id2operand(val);    return;
    case PROP_S4:   inst.operand(4) = getContext()->id2operand(val);    return;
    }

    if (propId == PROP_EQUIVCLASS) val = getContext()->id2eqclass(val);

    setBrigProp(inst, propId, val);
}

void Sample::copyFrom(const Sample s)
{
    assert(!s.isEmpty());
    assert(inst.brig()->kind == s.inst.brig()->kind);

    memcpy(inst.brig(), s.inst.brig(), s.inst.brig()->size);
}

//==============================================================================
//==============================================================================
//==============================================================================

} // namespace TESTGEN

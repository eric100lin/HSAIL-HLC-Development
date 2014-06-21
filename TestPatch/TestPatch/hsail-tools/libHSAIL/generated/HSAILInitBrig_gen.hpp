// University of Illinois/NCSA
// Open Source License
//
// Copyright (c) 2013, Advanced Micro Devices, Inc.
// All rights reserved.
//
// Developed by:
//
//     HSA Team
//
//     Advanced Micro Devices, Inc
//
//     www.amd.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal with
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimers.
//
//     * Redistributions in binary form must reproduce the above copyright notice,
//       this list of conditions and the following disclaimers in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the names of the LLVM Team, University of Illinois at
//       Urbana-Champaign, nor the names of its contributors may be used to
//       endorse or promote products derived from this Software without specific
//       prior written permission.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE
// SOFTWARE.
void AluModifier::initBrig() {
  brig()->allBits = 0;
}

void BlockEnd::initBrig() {
  brig()->size = sizeof(Brig::BrigBlockEnd);
  brig()->kind = Brig::BRIG_DIRECTIVE_BLOCK_END;
}

void BlockNumeric::initBrig() {
  brig()->size = sizeof(Brig::BrigBlockNumeric);
  brig()->kind = Brig::BRIG_DIRECTIVE_BLOCK_NUMERIC;
  brig()->reserved = 0;
  brig()->elementCount = 0;
}

void BlockString::initBrig() {
  brig()->size = sizeof(Brig::BrigBlockString);
  brig()->kind = Brig::BRIG_DIRECTIVE_BLOCK_STRING;
  brig()->string = 0;
}

void BlockStart::initBrig() {
  brig()->size = sizeof(Brig::BrigBlockStart);
  brig()->kind = Brig::BRIG_DIRECTIVE_BLOCK_START;
  brig()->code = 0;
  brig()->name = 0;
}

void DirectiveArgScopeEnd::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveArgScopeEnd);
  brig()->kind = Brig::BRIG_DIRECTIVE_ARG_SCOPE_END;
  brig()->code = 0;
}

void DirectiveArgScopeStart::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveArgScopeStart);
  brig()->kind = Brig::BRIG_DIRECTIVE_ARG_SCOPE_START;
  brig()->code = 0;
}

void DirectiveFunction::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveFunction);
  brig()->kind = Brig::BRIG_DIRECTIVE_FUNCTION;
  brig()->code = 0;
  brig()->name = 0;
  brig()->inArgCount = 0;
  brig()->outArgCount = 0;
  brig()->firstInArg = 0;
  brig()->firstScopedDirective = 0;
  brig()->nextTopLevelDirective = 0;
  brig()->instCount = 0;
  modifier().initBrig();
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void DirectiveKernel::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveKernel);
  brig()->kind = Brig::BRIG_DIRECTIVE_KERNEL;
  brig()->code = 0;
  brig()->name = 0;
  brig()->inArgCount = 0;
  brig()->outArgCount = 0;
  brig()->firstInArg = 0;
  brig()->firstScopedDirective = 0;
  brig()->nextTopLevelDirective = 0;
  brig()->instCount = 0;
  modifier().initBrig();
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void DirectiveSignature::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveSignature);
  brig()->kind = Brig::BRIG_DIRECTIVE_SIGNATURE;
  brig()->code = 0;
  brig()->name = 0;
  brig()->inArgCount = 0;
  brig()->outArgCount = 0;
  args().initBrig();
}

void DirectiveComment::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveComment);
  brig()->kind = Brig::BRIG_DIRECTIVE_COMMENT;
  brig()->code = 0;
  brig()->name = 0;
}

void DirectiveControl::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveControl);
  brig()->kind = Brig::BRIG_DIRECTIVE_CONTROL;
  brig()->code = 0;
  brig()->reserved = 0;
  brig()->valueCount = 0;
  for (int i=0;i<1;i++) {
    brig()->values[i] = 0;
  }
}

void DirectiveExtension::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveExtension);
  brig()->kind = Brig::BRIG_DIRECTIVE_EXTENSION;
  brig()->code = 0;
  brig()->name = 0;
}

void DirectiveFbarrier::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveFbarrier);
  brig()->kind = Brig::BRIG_DIRECTIVE_FBARRIER;
  brig()->code = 0;
  brig()->name = 0;
}

void DirectiveImageProperties::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveImageProperties);
  brig()->kind = Brig::BRIG_DIRECTIVE_IMAGE_PROPERTIES;
  brig()->code = 0;
  brig()->width = 0;
  brig()->height = 0;
  brig()->depth = 0;
  brig()->array = 0;
  brig()->geometry = Brig::BRIG_GEOMETRY_UNKNOWN;
  brig()->channelOrder = Brig::BRIG_CHANNEL_ORDER_UNKNOWN;
  brig()->channelType = Brig::BRIG_CHANNEL_TYPE_UNKNOWN;
  brig()->reserved = 0;
}

void DirectiveLabel::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveLabel);
  brig()->kind = Brig::BRIG_DIRECTIVE_LABEL;
  brig()->code = 0;
  brig()->name = 0;
}

void DirectiveLabelInit::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveLabelInit);
  brig()->kind = Brig::BRIG_DIRECTIVE_LABEL_INIT;
  brig()->code = 0;
  brig()->labelCount = 0;
  brig()->reserved = 0;
  for (int i=0;i<1;i++) {
    brig()->labels[i] = 0;
  }
}

void DirectiveLabelTargets::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveLabelTargets);
  brig()->kind = Brig::BRIG_DIRECTIVE_LABEL_TARGETS;
  brig()->code = 0;
  brig()->name = 0;
  brig()->labelCount = 0;
  brig()->reserved = 0;
  for (int i=0;i<1;i++) {
    brig()->labels[i] = 0;
  }
}

void DirectiveLoc::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveLoc);
  brig()->kind = Brig::BRIG_DIRECTIVE_LOC;
  brig()->code = 0;
  brig()->filename = 0;
  brig()->column = 1;
}

void DirectiveImageInit::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveImageInit);
  brig()->kind = Brig::BRIG_DIRECTIVE_IMAGE_INIT;
  brig()->code = 0;
  brig()->imageCount = 0;
  brig()->reserved = 0;
  for (int i=0;i<1;i++) {
    brig()->images[i] = 0;
  }
}

void DirectiveSamplerInit::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveSamplerInit);
  brig()->kind = Brig::BRIG_DIRECTIVE_SAMPLER_INIT;
  brig()->code = 0;
  brig()->samplerCount = 0;
  brig()->reserved = 0;
  for (int i=0;i<1;i++) {
    brig()->samplers[i] = 0;
  }
}

void DirectivePragma::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectivePragma);
  brig()->kind = Brig::BRIG_DIRECTIVE_PRAGMA;
  brig()->code = 0;
  brig()->name = 0;
}

void DirectiveSamplerProperties::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveSamplerProperties);
  brig()->kind = Brig::BRIG_DIRECTIVE_SAMPLER_PROPERTIES;
  brig()->code = 0;
  brig()->addressing = Brig::BRIG_ADDRESSING_CLAMP_TO_EDGE;
  brig()->reserved = 0;
}

void DirectiveVariable::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveVariable);
  brig()->kind = Brig::BRIG_DIRECTIVE_VARIABLE;
  brig()->code = 0;
  brig()->name = 0;
  brig()->init = 0;
  brig()->segment = 0;
  brig()->align = 0;
  brig()->dimLo = 0;
  brig()->dimHi = 0;
  modifier().initBrig();
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void DirectiveVariableInit::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveVariableInit);
  brig()->kind = Brig::BRIG_DIRECTIVE_VARIABLE_INIT;
  brig()->code = 0;
  brig()->elementCount = 0;
  brig()->reserved = 0;
}

void DirectiveVersion::initBrig() {
  brig()->size = sizeof(Brig::BrigDirectiveVersion);
  brig()->kind = Brig::BRIG_DIRECTIVE_VERSION;
  brig()->code = 0;
  brig()->profile = Brig::BRIG_PROFILE_FULL;
  brig()->machineModel = Brig::BRIG_MACHINE_LARGE;
  brig()->reserved = 0;
}

void DirectiveSignatureArgument::initBrig() {
  modifier().initBrig();
}

void ExecutableModifier::initBrig() {
  brig()->allBits = 0;
}

void InstAddr::initBrig() {
  brig()->size = sizeof(Brig::BrigInstAddr);
  brig()->kind = Brig::BRIG_INST_ADDR;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->segment = 0;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstAtomic::initBrig() {
  brig()->size = sizeof(Brig::BrigInstAtomic);
  brig()->kind = Brig::BRIG_INST_ATOMIC;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->segment = 0;
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
  brig()->memoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstBasic::initBrig() {
  brig()->size = sizeof(Brig::BrigInstBasic);
  brig()->kind = Brig::BRIG_INST_BASIC;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
}

void InstBr::initBrig() {
  brig()->size = sizeof(Brig::BrigInstBr);
  brig()->kind = Brig::BRIG_INST_BR;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstCmp::initBrig() {
  brig()->size = sizeof(Brig::BrigInstCmp);
  brig()->kind = Brig::BRIG_INST_CMP;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  modifier().initBrig();
  brig()->pack = Brig::BRIG_PACK_NONE;
  brig()->reserved = 0;
}

void InstCvt::initBrig() {
  brig()->size = sizeof(Brig::BrigInstCvt);
  brig()->kind = Brig::BRIG_INST_CVT;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  modifier().initBrig();
}

void InstImage::initBrig() {
  brig()->size = sizeof(Brig::BrigInstImage);
  brig()->kind = Brig::BRIG_INST_IMAGE;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->geometry = Brig::BRIG_GEOMETRY_UNKNOWN;
  brig()->reserved = 0;
}

void InstLane::initBrig() {
  brig()->size = sizeof(Brig::BrigInstLane);
  brig()->kind = Brig::BRIG_INST_LANE;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->reserved = 0;
}

void InstMem::initBrig() {
  brig()->size = sizeof(Brig::BrigInstMem);
  brig()->kind = Brig::BRIG_INST_MEM;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->segment = 0;
  modifier().initBrig();
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstMemFence::initBrig() {
  brig()->size = sizeof(Brig::BrigInstMemFence);
  brig()->kind = Brig::BRIG_INST_MEM_FENCE;
  brig()->type = Brig::BRIG_TYPE_NONE;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
  brig()->memoryScope = Brig::BRIG_MEMORY_SCOPE_SYSTEM;
  brig()->reserved = 0;
}

void InstMod::initBrig() {
  brig()->size = sizeof(Brig::BrigInstMod);
  brig()->kind = Brig::BRIG_INST_MOD;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  modifier().initBrig();
  brig()->pack = Brig::BRIG_PACK_NONE;
  brig()->reserved = 0;
}

void InstQueryImage::initBrig() {
  brig()->size = sizeof(Brig::BrigInstQueryImage);
  brig()->kind = Brig::BRIG_INST_QUERY_IMAGE;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->geometry = Brig::BRIG_GEOMETRY_UNKNOWN;
}

void InstQuerySampler::initBrig() {
  brig()->size = sizeof(Brig::BrigInstQuerySampler);
  brig()->kind = Brig::BRIG_INST_QUERY_SAMPLER;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstQueue::initBrig() {
  brig()->size = sizeof(Brig::BrigInstQueue);
  brig()->kind = Brig::BRIG_INST_QUEUE;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->segment = 0;
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
  brig()->reserved = 0;
}

void InstSeg::initBrig() {
  brig()->size = sizeof(Brig::BrigInstSeg);
  brig()->kind = Brig::BRIG_INST_SEG;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->segment = 0;
  for (int i=0;i<3;i++) {
    brig()->reserved[i] = 0;
  }
}

void InstSegCvt::initBrig() {
  brig()->size = sizeof(Brig::BrigInstSegCvt);
  brig()->kind = Brig::BRIG_INST_SEG_CVT;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->segment = 0;
  modifier().initBrig();
}

void InstSignal::initBrig() {
  brig()->size = sizeof(Brig::BrigInstSignal);
  brig()->kind = Brig::BRIG_INST_SIGNAL;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->memoryOrder = Brig::BRIG_MEMORY_ORDER_RELAXED;
}

void InstSourceType::initBrig() {
  brig()->size = sizeof(Brig::BrigInstSourceType);
  brig()->kind = Brig::BRIG_INST_SOURCE_TYPE;
  for (int i=0;i<5;i++) {
    brig()->operands[i] = 0;
  }
  brig()->reserved = 0;
}

void InstNone::initBrig() {
  brig()->size = sizeof(Brig::BrigInstNone);
  brig()->kind = Brig::BRIG_INST_NONE;
}

void MemoryModifier::initBrig() {
  brig()->allBits = 0;
}

void OperandAddress::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandAddress);
  brig()->kind = Brig::BRIG_OPERAND_ADDRESS;
  brig()->symbol = 0;
  brig()->reg = 0;
}

void OperandImmed::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandImmed);
  brig()->kind = Brig::BRIG_OPERAND_IMMED;
  brig()->reserved = 0;
}

void OperandArgumentList::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandArgumentList);
  brig()->kind = Brig::BRIG_OPERAND_ARGUMENT_LIST;
  brig()->reserved = 0;
  brig()->elementCount = 0;
  for (int i=0;i<1;i++) {
    brig()->elements[i] = 0;
  }
}

void OperandFunctionList::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandFunctionList);
  brig()->kind = Brig::BRIG_OPERAND_FUNCTION_LIST;
  brig()->reserved = 0;
  brig()->elementCount = 0;
  for (int i=0;i<1;i++) {
    brig()->elements[i] = 0;
  }
}

void OperandFbarrierRef::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandFbarrierRef);
  brig()->kind = Brig::BRIG_OPERAND_FBARRIER_REF;
  brig()->ref = 0;
}

void OperandFunctionRef::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandFunctionRef);
  brig()->kind = Brig::BRIG_OPERAND_FUNCTION_REF;
  brig()->ref = 0;
}

void OperandLabelRef::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandLabelRef);
  brig()->kind = Brig::BRIG_OPERAND_LABEL_REF;
  brig()->label = 0;
}

void OperandLabelTargetsRef::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandLabelTargetsRef);
  brig()->kind = Brig::BRIG_OPERAND_LABEL_TARGETS_REF;
  brig()->targets = 0;
}

void OperandLabelVariableRef::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandLabelVariableRef);
  brig()->kind = Brig::BRIG_OPERAND_LABEL_VARIABLE_REF;
  brig()->symbol = 0;
}

void OperandSignatureRef::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandSignatureRef);
  brig()->kind = Brig::BRIG_OPERAND_SIGNATURE_REF;
  brig()->ref = 0;
}

void OperandReg::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandReg);
  brig()->kind = Brig::BRIG_OPERAND_REG;
  brig()->reg = 0;
}

void OperandVector::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandVector);
  brig()->kind = Brig::BRIG_OPERAND_VECTOR;
  brig()->reserved = 0;
  brig()->operandCount = 0;
  for (int i=0;i<1;i++) {
    brig()->operands[i] = 0;
  }
}

void OperandWavesize::initBrig() {
  brig()->size = sizeof(Brig::BrigOperandWavesize);
  brig()->kind = Brig::BRIG_OPERAND_WAVESIZE;
}

void SegCvtModifier::initBrig() {
  brig()->allBits = 0;
}

void SymbolModifier::initBrig() {
  brig()->allBits = 0;
}


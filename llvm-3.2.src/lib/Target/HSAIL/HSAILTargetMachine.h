//=-- HSAILMachine.h - Define TargetMachine for the HSAIL ---*- C++ -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the HSAIL specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef _HSAIL_TARGET_MACHINE_H_
#define _HSAIL_TARGET_MACHINE_H_

#include "HSAIL.h"
#include "HSAILFrameLowering.h"
#include "HSAILInstrInfo.h"
#include "HSAILIntrinsicInfo.h"
#include "HSAILISelLowering.h"
#include "HSAILSelectionDAGInfo.h"
#include "HSAILSubtarget.h"
#include "llvm/CodeGen/Passes.h"

#include "HSAILLLVMVersion.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/DataLayout.h"
#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {

class formatted_raw_ostream;

class HSAILTargetMachine : public LLVMTargetMachine {
public:
  HSAILSubtarget      Subtarget;
  HSAILFrameLowering  FrameLowering;
  Reloc::Model      DefRelocModel; // Reloc model before it's overridden.
  HSAILIntrinsicInfo IntrinsicInfo;
  bool mDebugMode;
  
private:
public:

  //  HSAILTargetMachine(const Target &T,
  //                   const std::string &TT,
  //                   const std::string &FS,
  //                   bool is64Bit);

 HSAILTargetMachine(const Target &T, StringRef TT, StringRef CPU, StringRef FS,
    const TargetOptions &Options, Reloc::Model RM, CodeModel::Model CM,CodeGenOpt::Level OL, bool is64bitTarget);

  virtual const HSAILIntrinsicInfo*
  getIntrinsicInfo() const { return &IntrinsicInfo; }

  virtual const HSAILInstrInfo*
  getInstrInfo() const {
    llvm_unreachable("getInstrInfo not implemented");
  }

  virtual const HSAILFrameLowering*
  getFrameLowering() const { return &FrameLowering; }

  virtual const HSAILSubtarget*
  getSubtargetImpl() const { return &Subtarget; }

  virtual const HSAILTargetLowering*
  getTargetLowering() const {
    llvm_unreachable("getTargetLowering not implemented");
  }

  virtual const HSAILSelectionDAGInfo*
  getSelectionDAGInfo() const {
    llvm_unreachable("getSelectionDAGInfo not implemented");
  }

  virtual const HSAILRegisterInfo*
  getRegisterInfo() const { return &getInstrInfo()->getRegisterInfo(); }

  virtual TargetPassConfig *createPassConfig(PassManagerBase &PM);

  CodeGenFileType HSAILFileType;

public:
  /// addPassesToEmitFile - Add passes to the specified pass manager to get the
  /// specified file emitted.  Typically this will involve several steps of code
  /// generation.
  virtual bool addPassesToEmitFile(PassManagerBase &PM,
                                   formatted_raw_ostream &Out,
                                   CodeGenFileType FT,
                                   bool DisableVerify = true,
                                   AnalysisID StartAfter = 0,
                                   AnalysisID StopAfter = 0);
};

/// HSAIL_32TargetMachine - HSAIL 32-bit target machine.
class HSAIL_32TargetMachine : public HSAILTargetMachine {
  const DataLayout    DLInfo; // Calculates type size & alignment
  HSAILInstrInfo      InstrInfo;
  HSAILSelectionDAGInfo TSInfo;
  HSAILTargetLowering TLInfo;
public:
  HSAIL_32TargetMachine(const Target &T,
			StringRef TT, StringRef CPU, 
			StringRef FS,const TargetOptions &Options,
			Reloc::Model RM, 
			CodeModel::Model CM,CodeGenOpt::Level OL);


  // Interfaces to the major aspects of target machine information:
  // -- Instruction opcode and operand information
  // -- Pipelines and scheduling information
  // -- Stack frame information
  // -- Selection DAG lowering information

  virtual const DataLayout*
  getDataLayout() const { return &DLInfo; }

  virtual const HSAILTargetLowering*
  getTargetLowering() const { return &TLInfo; }

  virtual const HSAILSelectionDAGInfo*
  getSelectionDAGInfo() const { return &TSInfo; }

  virtual const HSAILInstrInfo*
  getInstrInfo() const { return &InstrInfo; }

  void dump(OSTREAM_TYPE &O);
  void setDebug(bool debugMode);
  bool getDebug() const;
};

/// HSAIL_64TargetMachine - HSAIL 64-bit target machine.
///
class HSAIL_64TargetMachine : public HSAILTargetMachine {
  const DataLayout  DLInfo; // Calculates type size & alignment
  HSAILInstrInfo      InstrInfo;
  HSAILSelectionDAGInfo TSInfo;
  HSAILTargetLowering TLInfo;
public:
  HSAIL_64TargetMachine(const Target &T,
			StringRef TT, StringRef CPU, 
			StringRef FS,const TargetOptions &Options,
			Reloc::Model RM, 
			CodeModel::Model CM,CodeGenOpt::Level OL);

  // Interfaces to the major aspects of target machine information:
  // -- Instruction opcode and operand information
  // -- Pipelines and scheduling information
  // -- Stack frame information
  // -- Selection DAG lowering information
  virtual const DataLayout*
  getDataLayout() const
  {
    return &DLInfo;
  }

  virtual const HSAILTargetLowering*
  getTargetLowering() const
  {
    return &TLInfo;
  }

  virtual const HSAILSelectionDAGInfo*
  getSelectionDAGInfo() const
  {
    return &TSInfo;
  }

  virtual const HSAILInstrInfo*
  getInstrInfo() const
  {
    return &InstrInfo;
  }

};

} // End llvm namespace

namespace llvm {
class HSAILPassConfig : public TargetPassConfig {
public:
  HSAILPassConfig(HSAILTargetMachine *TM, PassManagerBase &PM)
    : TargetPassConfig(TM, PM)
  {
// D2_OPENCL_HSA
#if 0
    setEnableRetToEnd(true);
    setDisableTailMergeAcrossLoop(true);
    setLsrCheckRegRecalc(true);
    setLsrIgnoreAddRecCost(true);
    setLsrCheckLoserOnTie(true);
#endif
  }

  HSAILTargetMachine &getHSAILTargetMachine() const {
    return getTM<HSAILTargetMachine>();
  }

  const HSAILSubtarget &getHSAILSubtarget() const {
    return *getHSAILTargetMachine().getSubtargetImpl();
  }

  // Pass Pipeline Configuration
  virtual void addIRPasses() LLVM_OVERRIDE;
  virtual bool addPreEmitPass();
  virtual bool addPreISel();
  virtual bool addInstSelector();
  virtual bool addPreRegAlloc();
  virtual bool addPostRegAlloc();

};
} // End llvm namespace
#endif

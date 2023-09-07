#include <string>
#include <vector>
#include <map>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include "llvm/IR/IRBuilder.h"
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>

#include "LLVMController.h"

LLVMController::LLVMController() {
    // this->ctx = std::make_unique<llvm::LLVMContext>();
    this->module = std::make_unique<llvm::Module>("amukh", ctx);
}


llvm::Function* LLVMController::declareFunction(std::string name, llvm::FunctionType* type) {

    llvm::Function* fn = this->module->getFunction(name);
    if(fn != nullptr) {
        return fn;
    }

    fn = llvm::Function::Create(type, llvm::Function::ExternalLinkage, name, *module);
    verifyFunction(*fn);
    return fn;
}

llvm::BasicBlock* LLVMController::defineFunction(std::string name) {
    llvm::Function* fn = this->module->getFunction(name);
    if(fn == nullptr) {
        return nullptr;
    }

    llvm::BasicBlock* entry = llvm::BasicBlock::Create(this->ctx, "entry", fn);
    // this->builder->SetInsertPoint(entry);
    return entry;
}

llvm::AllocaInst* LLVMController::declareVariable(std::string name, llvm::Type* type) {
  return this->builder->CreateAlloca(type, nullptr, name);
}

llvm::StoreInst* LLVMController::assignVariable(llvm::AllocaInst* ref, llvm::Value* value) {
  return this->builder->CreateStore(value, ref);
}

llvm::LoadInst* LLVMController::getVariable(llvm::AllocaInst* ref) {
  return this->builder->CreateLoad(ref->getAllocatedType(),ref);
}


llvm::AllocaInst* LLVMController::declareArray(std::string name, llvm::Type* type, llvm::Value* size) {
  return this->builder->CreateAlloca(type, size, name);
}

llvm::StoreInst* LLVMController::assignArray(llvm::AllocaInst* ref, llvm::Value* index, llvm::Value* value) {
  llvm::Value* ptr = this->builder->CreateGEP(index->getType(), ref, index);
  return this->builder->CreateStore(value, ptr);
}

llvm::LoadInst* LLVMController::getArray(llvm::AllocaInst* ref, llvm::Value* index, llvm::Type* type) {
  llvm::Value* ptr = this->builder->CreateGEP(ref->getAllocatedType(), ref, index);
return this->builder->CreateLoad(type, ptr);
}

// llvm::Value* LLVMController::getFromScope(std::string name) {
//     llvm::Value* value = this->globalScope[name];
//     if(value == nullptr) {
//         return nullptr;
//     }
//     return value;
// }
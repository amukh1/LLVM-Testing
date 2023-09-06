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

llvm::Value* LLVMController::getFromScope(std::string name) {
    llvm::Value* value = this->globalScope[name];
    if(value == nullptr) {
        return nullptr;
    }
    return value;
}
#pragma once

#include <string>
#include <vector>
#include <map>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Instructions.h>
#include <llvm/Support/raw_ostream.h>

#include <iostream>
#include <map>

class LLVMController {
    public:

    llvm::LLVMContext ctx;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder = std::make_unique<llvm::IRBuilder<>>(ctx);

    // global variable context (dictionary/map)

    std::map<std::string, llvm::Value*> globalScope;

    LLVMController();

    // functions
    llvm::Function* declareFunction(std::string name, llvm::FunctionType* type);
    llvm::BasicBlock* defineFunction(std::string name);
    
    void callFunction(llvm::Function* fn, std::vector<llvm::Value*> args);

    // // llvm::Value* getFromScope(std::string name);

    // // variables
    llvm::AllocaInst* declareVariable(std::string name, llvm::Type* type);
    llvm::StoreInst* assignVariable(llvm::AllocaInst* ref, llvm::Value* value);
    llvm::LoadInst* getVariable(llvm::AllocaInst* ref);

    // arrays
    llvm::AllocaInst* declareArray(std::string name, llvm::Type* type, llvm::Value* size);
    llvm::StoreInst* assignArray(llvm::AllocaInst* ref, llvm::Value* index, llvm::Value* value); 
    llvm::LoadInst* getArray(llvm::AllocaInst* ref, llvm::Value* index, llvm::Type* type);
};
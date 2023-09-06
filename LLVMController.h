#pragma once

#include <string>
#include <vector>
#include <map>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include "llvm/IR/IRBuilder.h"
#include <llvm/IR/Verifier.h>
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

    llvm::Function* declareFunction(std::string name, llvm::FunctionType* type);
    llvm::BasicBlock* defineFunction(std::string name);

    llvm::Value* getFromScope(std::string name);
};
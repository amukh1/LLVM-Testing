#include <string>
#include <vector>
#include <map>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include "llvm/IR/IRBuilder.h"
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>

#include <iostream>

#include "LLVMController.h"

// using namespace llvm;

int main() {

 /* llvm::LLVMContext ctx;

 std::unique_ptr<llvm::Module> module = std::make_unique<llvm::Module>("amukh", ctx);

 std::unique_ptr<llvm::IRBuilder<>> builder = std::make_unique<llvm::IRBuilder<>>(ctx);

// string Name, llvm::FunctionType* type
// llvm::FunctionType::get(builder->getInt32Ty(), false);
 llvm::Function* func;
 auto fn = llvm::Function::Create(llvm::FunctionType::get(builder->getInt32Ty(),false), llvm::Function::ExternalLinkage, "main", *module);
 verifyFunction(*fn);

 auto entry = llvm::BasicBlock::Create(ctx, "entry", fn);
 builder->SetInsertPoint(entry);
 builder->CreateRet(builder->CreateIntCast(builder->getInt32(5), builder->getInt32Ty(), false));  */

 LLVMController Controller;
 Controller.module->getOrInsertFunction("printf", llvm::FunctionType::get(Controller.builder->getInt32Ty(), Controller.builder->getInt8PtrTy(), true));

 llvm::FunctionType* fnTy = llvm::FunctionType::get(Controller.builder->getInt32Ty(), false);
 llvm::Function* fn = Controller.declareFunction("main", fnTy);


//  auto entry = llvm::BasicBlock::Create(Controller.ctx, "entry", fn);
//  Controller.builder->SetInsertPoint(entry);
 llvm::BasicBlock* entry = Controller.defineFunction("main");
 Controller.builder->SetInsertPoint(entry);

 auto string = Controller.builder->CreateGlobalStringPtr("Hello World!\n");
 auto printfn = Controller.module->getFunction("printf");
 
 Controller.builder->CreateCall(printfn, string);
 string->setName("string");

 Controller.builder->CreateRet(Controller.builder->CreateIntCast(Controller.builder->getInt32(5), Controller.builder->getInt32Ty(), false));

// out
 llvm::outs() << *Controller.module << '\n';
 // dump code into file
    std::error_code ec;
    llvm::raw_fd_ostream os("output.ll", ec);
    Controller.module->print(os, nullptr);

}

//	static std::unique_ptr<LLVMContext> TheContext;
//	static std::unique_ptr<IRBuilder<>> Builder(TheContext);
//	static std::unique_ptr<Module> TheModule;
//	static std::map<std::string, Value *> NamedValues;
g++ index.cpp LLVMController.cpp -o index `llvm-config --cflags --libs`

./index

lli output.ll

echo $?


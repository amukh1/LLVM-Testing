g++ index.cpp LLVMController.cpp -o index `llvm-config-14 --cflags --libs`

./index

lli output.ll

echo $?


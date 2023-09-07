; ModuleID = 'amukh'
source_filename = "amukh"

@0 = private unnamed_addr constant [46 x i8] c"Hello World! Almost %d years of programming!\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %variable = alloca i32
  store i32 5, i32* %variable
  %0 = load i32, i32* %variable
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([46 x i8], [46 x i8]* @0, i32 0, i32 0), i32 %0)
  %arr = alloca i32, i32 5
  %2 = getelementptr i32, i32* %arr, i32 2
  store i32 5, i32* %2
  %3 = getelementptr i32, i32* %arr, i32 2
  %4 = load i32, i32* %3
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([46 x i8], [46 x i8]* @0, i32 0, i32 0), i32 %4)
  ret i32 0
}

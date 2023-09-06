; ModuleID = 'amukh'
source_filename = "amukh"

@0 = private unnamed_addr constant [14 x i8] c"Hello World!\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @0, i32 0, i32 0))
  ret i32 5
}

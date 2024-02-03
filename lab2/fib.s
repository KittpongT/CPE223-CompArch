fib:
   PUSH %BP 
   MOV  %SP, %BP
@fib_body:
@if0:
   CMP  8(%BP), $0
   JEQ  @true0
@false0:
   CMP  8(%BP), $1
   JNE  @false1
@true0:
   MOV  $1, %13
   JMP  @fib_exit
   JMP  @exit0
@false1:
@exit0:
   SUB  8(%BP), $1, %0
   PUSH %0
   CALL fib
   ADD  %SP, $4, %SP
   SUB  8(%BP), $2, %0
   PUSH %0
   CALL fib
   ADD  %SP, $4, %SP
   ADD  %13, %13, %0
   MOV  %0, %13
   JMP  @fib_exit
@fib_exit:
   MOV  %BP, %SP
   POP  %BP
   RET 
main:
   PUSH %BP
   MOV  %SP, %BP
@main_body:
   SUB  %SP, $4, %SP
   MOV  $44, -4(%BP)
   PUSH -4(%BP)
   CALL fib
   ADD  %SP, $4, %SP
@main_exit:
   MOV  %BP, %SP
   POP  %BP
   RET
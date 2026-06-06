;
;  TriCoreTasking setjmp/longjmp functions
;
;  Copyright ETAS GmbH 2024
;
; [$TargetTT  155]
;
  .name  "Os_setjmp.asm"
  .sdecl '.text.Os_setjmp.Os_setjmp',CODE
  .sect  '.text.Os_setjmp.Os_setjmp'
  .align 4
  .global Os_setjmp
  ; Entered with A4 containing the address of the jump buffer
Os_setjmp: .type func
  st.a  [a4]0, a11    ; Save return address
  dsync               ; This sync is necessary
  ; Get the address of the top CSA into a15
  mfcr  d14, #0xFE00
  extr  d15, d14, #0, #16
  sha   d15, #6
  movh  d13, #0xf
  and   d14, d13
  sha   d14, d14, #12
  or    d15, d14
  mov.a a15, d15

  ; Clone the context
  ld.d  e8, [a15]0x00
  st.d  [a4]0x04, e8
  ld.d  e8, [a15]0x08
  st.d  [a4]0x0c, e8
  ld.d  e8, [a15]0x10
  st.d  [a4]0x14, e8
  ld.d  e8, [a15]0x18
  st.d  [a4]0x1c, e8
  ld.d  e8, [a15]0x20
  st.d  [a4]0x24, e8
  ld.d  e8, [a15]0x28
  st.d  [a4]0x2c, e8
  ld.d  e8, [a15]0x30
  st.d  [a4]0x34, e8
  ld.d  e8, [a15]0x38
  st.d  [a4]0x3c, e8

  ; Return 0
  mov   d2, #0
  ret

  .sdecl '.text.Os_setjmp.Os_longjmp',CODE
  .sect  '.text.Os_setjmp.Os_longjmp'
  .align 4
  .global Os_longjmp
   ; Entered with A4 containing the address of the jump buffer. OS level
Os_longjmp: .type func
  disable              ; [$TgtCore 186]
  ld.w    d2,[a4]4     ; Read saved PCXI
  ; Get loop address into a5
  movh.a  a5,#@his(Os_longjmp_loop)
  lea     a5,[a5]@los(Os_longjmp_loop)
Os_longjmp_loop:
  mfcr    d15,#0xFE00  ; Read PCXI
  jeq     d2,d15, Os_longjmp_exit
  mov.aa  a11,a5       ; 'ret' back to loop, popping a CSA
  ret

  .align  4
  .global Os_longjmp_exit
Os_longjmp_exit:
  ; PCXI matches the one recorded at setjmp
  ld.w    d2,[a4]8     ; Restore PSW
  mtcr    #0xFE04,d2
  dsync                ;# Sync needed
  ; ld.da a12,[a4]12 ; A10/A11 from CSA of Os_setjmp (accounting for TC.081 bug)
  .word  0x09cc4c09
  mov.aa  a10,a12
  mov.aa  a11,a13
  ld.d    e8,[a4]0x14
  ld.d    e10,[a4]0x1C
  ;ld.da a12,[a4]0x24
  .word  0x09e44c09
  ;ld.da a14,[a4]0x2C
  .word  0x09ec4e09
  ld.d    e12,[a4]0x34
  ld.d    e14,[a4]0x3C
  ; Return 1
  mov     d2, #1

  ; Indirect jump to saved return address
  ld.a    a5,[a4]0
  enable  ; [$TgtCore 186]
  nop     ; CPU_TC.048
  ji      a5



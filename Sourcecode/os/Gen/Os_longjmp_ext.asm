;
; TriCoreTasking longjmp functions
;
; Copyright ETAS GmbH 2024
;
; [$TargetTT  155]
;
; Notes:
;    This version checks for lower contexts and hence copes with longjmp over
;    frames with ISRs in the way.
;
;    1) Need to handle trusted/nontrusted longjmps
;
;    Gets the PCXI value from the buffer and then pops off CSAs of the CSA
;    list until we get to the CSA used when calling setjmp.
;
;    If it finds a lower context in the CSA list then restores this
;
;    Checks if the the PSW needs to change to USER mode for untrusted code
;
;    Clears the PSW call depth counter
;
  .name  "Os_longjmp_ext.asm"
  .sdecl '.text.Os_longjmp_ext.Os_longjmp_ext',CODE
  .sect  '.text.Os_longjmp_ext.Os_longjmp_ext'
  .align 4

  .global Os_longjmp_ext
  ; Entered with A4 containing the address of the jump buffer. OS level
Os_longjmp_ext: .type func
  ld.w    d2,[a4]4                       ; Read saved PCXI
Os_longjmp_ext1:
  movh.a  a5,#@his(Os_longjmp_ext_loop)  ; Get loop address into a5
  lea     a5,[a5]@los(Os_longjmp_ext_loop)
Os_longjmp_ext_loop:
  mfcr    d15,#0xFE00                    ; Read PCXI
  jeq     d2,d15, Os_longjmp_vexit       ; Does it match exit value?
  jz.t    d15: 20, Os_longjmp_lcx        ; Is this a lower context (1.6E/P case) ?
  mov.aa  a11,a5                         ; 'ret' back to loop, popping a CSA
  ret

  .align  4
  .extern Os_longjmp_exit
Os_longjmp_vexit:
  nop                                    ; CPU_TC.065
  j Os_longjmp_exit
Os_longjmp_lcx:
  mov     d15,d2
  mov.aa  a12,a4
  rslcx
  nop                                    ; CPU_TC.069
  mov     d2,d15
  mov.aa  a4,a12
  ; Cancel CDC [$TargetTT 58]
  mfcr    d15,#0xFE04
  or      d15,#0x7f
  mtcr    #0xFE04, d15
  j Os_longjmp_ext1


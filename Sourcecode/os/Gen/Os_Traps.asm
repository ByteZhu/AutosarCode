;
; TriCoreTasking Traps
; Copyright ETAS GmbH 2024
;

  .name "Os_Traps.asm"
  .extern Os_UnhandledTrap
;  #===========================================================================
;  # Os Traps
;  #===========================================================================


;  # --------------------------------------------------------------------------
;  # MMU (Virtual memory)
;  # --------------------------------------------------------------------------
  .sdecl  '.text.traptab0.trapvec.000',CODE
  .sect   '.text.traptab0.trapvec.000'
  .align 32
  .global Os_TrapVectorTable
.align 256 ; The vector table must be aligned such that the lowest 8 bits of its address are zero
Os_TrapVectorTable: ; [$Satisfies $TgtCore 112]
  .global Os_memory_trap
Os_memory_trap:
  mov    d5, # 0
  mov    d4, #14
  j      Os_trap_fault

;  # --------------------------------------------------------------------------
;  # Internal Protection
;  # --------------------------------------------------------------------------
  .sdecl  '.text.traptab0.trapvec.001',CODE
  .sect   '.text.traptab0.trapvec.001'
  .align 32
  .global Os_protection_trap
Os_protection_trap:
  mov    d5, # 1
  mov    d4, #14
  j      Os_trap_fault

;  # --------------------------------------------------------------------------
;  # Instruction (Illegal ops, address errors) [$Satisfies $TgtCore 110]
;  # --------------------------------------------------------------------------
  .sdecl  '.text.traptab0.trapvec.002',CODE
  .sect   '.text.traptab0.trapvec.002'
  .align 32
  .global Os_instruction_trap
Os_instruction_trap:
  mov    d5, # 2
  mov    d4, #18
  j      Os_trap_fault

;  # --------------------------------------------------------------------------
;  # Context call fault
;  # --------------------------------------------------------------------------
  .sdecl  '.text.traptab0.trapvec.003',CODE
  .sect   '.text.traptab0.trapvec.003'
  .align 32
  .global Os_context_trap
Os_context_trap:
  mov    d5, # 3
  mov    d4, #18
  j      Os_trap_fault

;  # --------------------------------------------------------------------------
;  # Bus errors
;  # --------------------------------------------------------------------------
  .sdecl  '.text.traptab0.trapvec.004',CODE
  .sect   '.text.traptab0.trapvec.004'
  .align 32
  .global Os_bus_trap
Os_bus_trap:
  mov    d5, # 4
  mov    d4, #18
  j      Os_trap_fault

;  # --------------------------------------------------------------------------
;  # Assertion (Arithmetic overflows)
;  # --------------------------------------------------------------------------
  .sdecl  '.text.traptab0.trapvec.005',CODE
  .sect   '.text.traptab0.trapvec.005'
  .align 32
  .global Os_assert_trap
Os_assert_trap:
  mov    d5, # 5
  mov    d4, #18
  j      Os_trap_fault

;  # --------------------------------------------------------------------------
;  # Syscall [$TargetTT 176] [$TargetTT 177]
;  # --------------------------------------------------------------------------
  .sdecl  '.text.traptab0.trapvec.006',CODE
  .sect   '.text.traptab0.trapvec.006'
  .align 32
  .global Os_syscall_trap
Os_syscall_trap:
  mov    d5, #6
  mov    d4, #18
  j      Os_trap_fault

;  # --------------------------------------------------------------------------
;  # NMI
;  # --------------------------------------------------------------------------
  .sdecl  '.text.traptab0.trapvec.007',CODE
  .sect   '.text.traptab0.trapvec.007'
  .align 32
  .global Os_nmi_trap
Os_nmi_trap:
  mov    d5, # 7
  mov    d4, #18
  j      Os_trap_fault

  .sdecl  '.text.Os_trap_handlers',CODE
  .sect   '.text.Os_trap_handlers'
  .align 2
Os_trap_fault: ; [$TargetTT 178]
  mov    d6, d15   ; TIN
  mov.d  d7, a11   ; Return
;  # Call depth counting must be disabled in case the OS is reset in the
;  # Shutdown hook. This is because Os_longjmp will otherwise see a call depth
;  # underflow
  mfcr   d15, #0xFE04
  or     d15,#0x7f
  mtcr   #0xFE04,d15
  movh.a  a14,#@his(Os_UnhandledTrap)
  lea     a14,[a14]@los(Os_UnhandledTrap)
  ji      a14



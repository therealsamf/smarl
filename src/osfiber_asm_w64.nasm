; Copyright 2019 The Marl Authors.
;
; Licensed under the Apache License, Version 2.0 (the "License");
; you may not use this file except in compliance with the License.
; You may obtain a copy of the License at
;
;     https://www.apache.org/licenses/LICENSE-2.0
;
; Unless required by applicable law or agreed to in writing, software
; distributed under the License is distributed on an "AS IS" BASIS,
; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; See the License for the specific language governing permissions and
; limitations under the License.

%define MARL_REG_RBX 0x00
%define MARL_REG_RBP 0x08
%define MARL_REG_R12 0x10
%define MARL_REG_R13 0x18
%define MARL_REG_R14 0x20
%define MARL_REG_R15 0x28
%define MARL_REG_RDI 0x30
%define MARL_REG_RSI 0x38
%define MARL_REG_RCX 0x40
%define MARL_REG_RDX 0x48
%define MARL_REG_RSP 0x50
%define MARL_REG_RIP 0x58

%define MARL_REG_XMM6  0x60
%define MARL_REG_XMM7  0x70
%define MARL_REG_XMM8  0x80
%define MARL_REG_XMM9  0x90
%define MARL_REG_XMM10 0xA0
%define MARL_REG_XMM11 0xB0
%define MARL_REG_XMM12 0xC0
%define MARL_REG_XMM13 0xD0
%define MARL_REG_XMM14 0xE0
%define MARL_REG_XMM15 0xF0

; void marl_fiber_swap(marl_fiber_context* from, const marl_fiber_context* to)
; RCX: from
; RDX: to

global  marl_fiber_swap
section .text align=16
marl_fiber_swap:

    ; Save context 'from'

    ; Store callee-preserved registers
    mov        [RCX + MARL_REG_RBX]  , RBX
    mov        [RCX + MARL_REG_RBP]  , RBP
    mov        [RCX + MARL_REG_R12]  , R12
    mov        [RCX + MARL_REG_R13]  , R13
    mov        [RCX + MARL_REG_R14]  , R14
    mov        [RCX + MARL_REG_R15]  , R15
    mov        [RCX + MARL_REG_RDI]  , RDI
    mov        [RCX + MARL_REG_RSI]  , RSI
    movq       [RCX + MARL_REG_XMM6] , XMM6
    movq       [RCX + MARL_REG_XMM7] , XMM7
    movq       [RCX + MARL_REG_XMM8] , XMM8
    movq       [RCX + MARL_REG_XMM9] , XMM9
    movq       [RCX + MARL_REG_XMM10], XMM10
    movq       [RCX + MARL_REG_XMM11], XMM11
    movq       [RCX + MARL_REG_XMM12], XMM12
    movq       [RCX + MARL_REG_XMM13], XMM13
    movq       [RCX + MARL_REG_XMM14], XMM14
    movq       [RCX + MARL_REG_XMM15], XMM15

    mov        R8, [RSP]                ; call stores the return address on the stack before jumping */
    mov        [RCX + MARL_REG_RIP], R8
    lea        R8, [RSP + 8]            ; skip the pushed return address */
    mov        [RCX + MARL_REG_RSP], R8

    ; Load context 'to'
    mov        R8, RDX

    ; Load callee-preserved registers
    mov        RBX  , [R8 + MARL_REG_RBX]
    mov        RBP  , [R8 + MARL_REG_RBP]
    mov        R12  , [R8 + MARL_REG_R12]
    mov        R13  , [R8 + MARL_REG_R13]
    mov        R14  , [R8 + MARL_REG_R14]
    mov        R15  , [R8 + MARL_REG_R15]
    mov        RDI  , [R8 + MARL_REG_RDI]
    mov        RSI  , [R8 + MARL_REG_RSI]
    movq       XMM6 , [R8 + MARL_REG_XMM6]
    movq       XMM7 , [R8 + MARL_REG_XMM7]
    movq       XMM8 , [R8 + MARL_REG_XMM8]
    movq       XMM9 , [R8 + MARL_REG_XMM9]
    movq       XMM10, [R8 + MARL_REG_XMM10]
    movq       XMM11, [R8 + MARL_REG_XMM11]
    movq       XMM12, [R8 + MARL_REG_XMM12]
    movq       XMM13, [R8 + MARL_REG_XMM13]
    movq       XMM14, [R8 + MARL_REG_XMM14]
    movq       XMM15, [R8 + MARL_REG_XMM15]

    ; Load first two call parameters
    mov        RCX, [R8 + MARL_REG_RCX]
    mov        RDX, [R8 + MARL_REG_RDX]

    ; Load stack pointer
    mov        RSP, [R8 + MARL_REG_RSP]

    ; Load instruction pointer, and jump
    jmp        [R8 + MARL_REG_RIP]

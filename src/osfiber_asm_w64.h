
// Copyright 2019 The Marl Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#define MARL_REG_RBX 0x00
#define MARL_REG_RBP 0x08
#define MARL_REG_R12 0x10
#define MARL_REG_R13 0x18
#define MARL_REG_R14 0x20
#define MARL_REG_R15 0x28
#define MARL_REG_RDI 0x30
#define MARL_REG_RSI 0x38
#define MARL_REG_RCX 0x40
#define MARL_REG_RDX 0x48
#define MARL_REG_RSP 0x50
#define MARL_REG_RIP 0x58

#define MARL_REG_XMM6  0x60
#define MARL_REG_XMM7  0x70
#define MARL_REG_XMM8  0x80
#define MARL_REG_XMM9  0x90
#define MARL_REG_XMM10 0xA0
#define MARL_REG_XMM11 0xB0
#define MARL_REG_XMM12 0xC0
#define MARL_REG_XMM13 0xD0
#define MARL_REG_XMM14 0xE0
#define MARL_REG_XMM15 0xF0

#include <stdint.h>
#include <xmmintrin.h>

struct marl_fiber_context {
  // callee-saved registers
  uintptr_t RBX;
  uintptr_t RBP;
  uintptr_t R12;
  uintptr_t R13;
  uintptr_t R14;
  uintptr_t R15;
  uintptr_t RDI;
  uintptr_t RSI;

  // parameter registers
  uintptr_t RCX;
  uintptr_t RDX;

  // stack and instruction registers
  uintptr_t RSP;
  uintptr_t RIP;

  // XMM registers
  __m128 XMM6;
  __m128 XMM7;
  __m128 XMM8;
  __m128 XMM9;
  __m128 XMM10;
  __m128 XMM11;
  __m128 XMM12;
  __m128 XMM13;
  __m128 XMM14;
  __m128 XMM15;
};

#ifdef __cplusplus
#include <cstddef>
static_assert(offsetof(marl_fiber_context, RBX) == MARL_REG_RBX,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, RBP) == MARL_REG_RBP,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, R12) == MARL_REG_R12,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, R13) == MARL_REG_R13,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, R14) == MARL_REG_R14,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, R15) == MARL_REG_R15,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, RDI) == MARL_REG_RDI,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, RSI) == MARL_REG_RSI,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, RCX) == MARL_REG_RCX,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, RDX) == MARL_REG_RDX,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, RSP) == MARL_REG_RSP,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, RIP) == MARL_REG_RIP,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM6) == MARL_REG_XMM6,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM7) == MARL_REG_XMM7,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM8) == MARL_REG_XMM8,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM9) == MARL_REG_XMM9,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM10) == MARL_REG_XMM10,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM11) == MARL_REG_XMM11,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM12) == MARL_REG_XMM12,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM13) == MARL_REG_XMM13,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM14) == MARL_REG_XMM14,
              "Bad register offset");
static_assert(offsetof(marl_fiber_context, XMM15) == MARL_REG_XMM15,
              "Bad register offset");
#endif  // __cplusplus

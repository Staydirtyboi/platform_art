// Copyright 2016, VIXL authors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of ARM Limited nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


// -----------------------------------------------------------------------------
// This file is auto generated from the
// test/aarch32/config/template-assembler-aarch32.cc.in template file using
// tools/generate_tests.py.
//
// PLEASE DO NOT EDIT.
// -----------------------------------------------------------------------------


#include "test-runner.h"

#include "test-utils.h"
#include "test-utils-aarch32.h"

#include "aarch32/assembler-aarch32.h"
#include "aarch32/macro-assembler-aarch32.h"

#define BUF_SIZE (4096)

namespace vixl {
namespace aarch32 {

// List of instruction mnemonics.
#define FOREACH_INSTRUCTION(M) \
  M(Add)                       \
  M(Sub)


// Values to be passed to the assembler to produce the instruction under test.
struct Operands {
  Condition cond;
  Register rd;
  Register rn;
  Register rm;
};

// This structure contains all data needed to test one specific
// instruction.
struct TestData {
  // The `operands` field represents what to pass to the assembler to
  // produce the instruction.
  Operands operands;
  // Optionally expect the MacroAssembler to have generated an extra
  // instruction. This is used when the instruction needs to be in an IT block.
  const char* expect_instruction_before;
  // Description of the operands, used for error reporting.
  const char* operands_description;
  // Unique identifier, used for generating traces.
  const char* identifier;
};

struct TestResult {
  size_t size;
  const byte* encoding;
};

// Each element of this array produce one instruction encoding.
static const TestData kTests[] =
    {{{mi, r7, r4, r3}, "It mi;", "mi r7 r4 r3", "mi_r7_r4_r3"},
     {{ge, r5, r0, r4}, "It ge;", "ge r5 r0 r4", "ge_r5_r0_r4"},
     {{mi, r0, r4, r1}, "It mi;", "mi r0 r4 r1", "mi_r0_r4_r1"},
     {{cs, r6, r0, r2}, "It cs;", "cs r6 r0 r2", "cs_r6_r0_r2"},
     {{lt, r6, r7, r3}, "It lt;", "lt r6 r7 r3", "lt_r6_r7_r3"},
     {{lt, r5, r7, r3}, "It lt;", "lt r5 r7 r3", "lt_r5_r7_r3"},
     {{gt, r7, r3, r6}, "It gt;", "gt r7 r3 r6", "gt_r7_r3_r6"},
     {{le, r5, r7, r4}, "It le;", "le r5 r7 r4", "le_r5_r7_r4"},
     {{le, r6, r2, r3}, "It le;", "le r6 r2 r3", "le_r6_r2_r3"},
     {{vc, r0, r4, r2}, "It vc;", "vc r0 r4 r2", "vc_r0_r4_r2"},
     {{cc, r7, r2, r7}, "It cc;", "cc r7 r2 r7", "cc_r7_r2_r7"},
     {{lt, r0, r0, r2}, "It lt;", "lt r0 r0 r2", "lt_r0_r0_r2"},
     {{ls, r0, r4, r7}, "It ls;", "ls r0 r4 r7", "ls_r0_r4_r7"},
     {{cc, r1, r5, r2}, "It cc;", "cc r1 r5 r2", "cc_r1_r5_r2"},
     {{cc, r1, r6, r5}, "It cc;", "cc r1 r6 r5", "cc_r1_r6_r5"},
     {{vc, r6, r6, r0}, "It vc;", "vc r6 r6 r0", "vc_r6_r6_r0"},
     {{pl, r3, r7, r2}, "It pl;", "pl r3 r7 r2", "pl_r3_r7_r2"},
     {{mi, r6, r5, r5}, "It mi;", "mi r6 r5 r5", "mi_r6_r5_r5"},
     {{pl, r3, r5, r7}, "It pl;", "pl r3 r5 r7", "pl_r3_r5_r7"},
     {{cc, r6, r3, r0}, "It cc;", "cc r6 r3 r0", "cc_r6_r3_r0"},
     {{vc, r4, r6, r4}, "It vc;", "vc r4 r6 r4", "vc_r4_r6_r4"},
     {{le, r1, r2, r5}, "It le;", "le r1 r2 r5", "le_r1_r2_r5"},
     {{eq, r2, r1, r0}, "It eq;", "eq r2 r1 r0", "eq_r2_r1_r0"},
     {{ne, r6, r3, r4}, "It ne;", "ne r6 r3 r4", "ne_r6_r3_r4"},
     {{cs, r6, r5, r6}, "It cs;", "cs r6 r5 r6", "cs_r6_r5_r6"},
     {{gt, r2, r6, r2}, "It gt;", "gt r2 r6 r2", "gt_r2_r6_r2"},
     {{eq, r1, r3, r5}, "It eq;", "eq r1 r3 r5", "eq_r1_r3_r5"},
     {{mi, r7, r4, r2}, "It mi;", "mi r7 r4 r2", "mi_r7_r4_r2"},
     {{hi, r7, r2, r3}, "It hi;", "hi r7 r2 r3", "hi_r7_r2_r3"},
     {{le, r2, r4, r7}, "It le;", "le r2 r4 r7", "le_r2_r4_r7"},
     {{pl, r6, r3, r0}, "It pl;", "pl r6 r3 r0", "pl_r6_r3_r0"},
     {{vs, r4, r7, r5}, "It vs;", "vs r4 r7 r5", "vs_r4_r7_r5"},
     {{vs, r4, r5, r3}, "It vs;", "vs r4 r5 r3", "vs_r4_r5_r3"},
     {{vs, r4, r5, r5}, "It vs;", "vs r4 r5 r5", "vs_r4_r5_r5"},
     {{cs, r1, r1, r5}, "It cs;", "cs r1 r1 r5", "cs_r1_r1_r5"},
     {{le, r5, r3, r1}, "It le;", "le r5 r3 r1", "le_r5_r3_r1"},
     {{pl, r3, r6, r4}, "It pl;", "pl r3 r6 r4", "pl_r3_r6_r4"},
     {{hi, r4, r5, r4}, "It hi;", "hi r4 r5 r4", "hi_r4_r5_r4"},
     {{ls, r1, r2, r0}, "It ls;", "ls r1 r2 r0", "ls_r1_r2_r0"},
     {{vc, r0, r3, r4}, "It vc;", "vc r0 r3 r4", "vc_r0_r3_r4"},
     {{ge, r1, r4, r5}, "It ge;", "ge r1 r4 r5", "ge_r1_r4_r5"},
     {{mi, r7, r1, r1}, "It mi;", "mi r7 r1 r1", "mi_r7_r1_r1"},
     {{eq, r5, r6, r2}, "It eq;", "eq r5 r6 r2", "eq_r5_r6_r2"},
     {{vc, r3, r1, r2}, "It vc;", "vc r3 r1 r2", "vc_r3_r1_r2"},
     {{hi, r2, r3, r3}, "It hi;", "hi r2 r3 r3", "hi_r2_r3_r3"},
     {{hi, r6, r3, r4}, "It hi;", "hi r6 r3 r4", "hi_r6_r3_r4"},
     {{cs, r2, r7, r4}, "It cs;", "cs r2 r7 r4", "cs_r2_r7_r4"},
     {{mi, r5, r6, r1}, "It mi;", "mi r5 r6 r1", "mi_r5_r6_r1"},
     {{vc, r1, r1, r7}, "It vc;", "vc r1 r1 r7", "vc_r1_r1_r7"},
     {{vc, r7, r2, r4}, "It vc;", "vc r7 r2 r4", "vc_r7_r2_r4"},
     {{eq, r5, r6, r4}, "It eq;", "eq r5 r6 r4", "eq_r5_r6_r4"},
     {{gt, r7, r1, r6}, "It gt;", "gt r7 r1 r6", "gt_r7_r1_r6"},
     {{mi, r5, r5, r2}, "It mi;", "mi r5 r5 r2", "mi_r5_r5_r2"},
     {{eq, r3, r6, r3}, "It eq;", "eq r3 r6 r3", "eq_r3_r6_r3"},
     {{ge, r4, r7, r2}, "It ge;", "ge r4 r7 r2", "ge_r4_r7_r2"},
     {{cs, r0, r0, r6}, "It cs;", "cs r0 r0 r6", "cs_r0_r0_r6"},
     {{lt, r4, r3, r6}, "It lt;", "lt r4 r3 r6", "lt_r4_r3_r6"},
     {{cs, r6, r3, r0}, "It cs;", "cs r6 r3 r0", "cs_r6_r3_r0"},
     {{pl, r6, r3, r7}, "It pl;", "pl r6 r3 r7", "pl_r6_r3_r7"},
     {{cs, r0, r7, r4}, "It cs;", "cs r0 r7 r4", "cs_r0_r7_r4"},
     {{ne, r5, r6, r0}, "It ne;", "ne r5 r6 r0", "ne_r5_r6_r0"},
     {{ne, r2, r2, r7}, "It ne;", "ne r2 r2 r7", "ne_r2_r2_r7"},
     {{cc, r0, r0, r6}, "It cc;", "cc r0 r0 r6", "cc_r0_r0_r6"},
     {{mi, r7, r1, r4}, "It mi;", "mi r7 r1 r4", "mi_r7_r1_r4"},
     {{pl, r7, r0, r4}, "It pl;", "pl r7 r0 r4", "pl_r7_r0_r4"},
     {{hi, r4, r1, r5}, "It hi;", "hi r4 r1 r5", "hi_r4_r1_r5"},
     {{vc, r0, r6, r6}, "It vc;", "vc r0 r6 r6", "vc_r0_r6_r6"},
     {{vc, r1, r4, r6}, "It vc;", "vc r1 r4 r6", "vc_r1_r4_r6"},
     {{ne, r5, r2, r7}, "It ne;", "ne r5 r2 r7", "ne_r5_r2_r7"},
     {{lt, r4, r6, r5}, "It lt;", "lt r4 r6 r5", "lt_r4_r6_r5"},
     {{ge, r7, r3, r5}, "It ge;", "ge r7 r3 r5", "ge_r7_r3_r5"},
     {{le, r1, r3, r0}, "It le;", "le r1 r3 r0", "le_r1_r3_r0"},
     {{eq, r4, r7, r2}, "It eq;", "eq r4 r7 r2", "eq_r4_r7_r2"},
     {{cc, r1, r4, r3}, "It cc;", "cc r1 r4 r3", "cc_r1_r4_r3"},
     {{ge, r6, r3, r1}, "It ge;", "ge r6 r3 r1", "ge_r6_r3_r1"},
     {{hi, r6, r4, r0}, "It hi;", "hi r6 r4 r0", "hi_r6_r4_r0"},
     {{cs, r4, r4, r5}, "It cs;", "cs r4 r4 r5", "cs_r4_r4_r5"},
     {{mi, r1, r7, r1}, "It mi;", "mi r1 r7 r1", "mi_r1_r7_r1"},
     {{cc, r2, r2, r4}, "It cc;", "cc r2 r2 r4", "cc_r2_r2_r4"},
     {{hi, r3, r0, r7}, "It hi;", "hi r3 r0 r7", "hi_r3_r0_r7"},
     {{ne, r0, r5, r6}, "It ne;", "ne r0 r5 r6", "ne_r0_r5_r6"},
     {{vs, r2, r0, r1}, "It vs;", "vs r2 r0 r1", "vs_r2_r0_r1"},
     {{ls, r1, r4, r5}, "It ls;", "ls r1 r4 r5", "ls_r1_r4_r5"},
     {{vc, r1, r3, r3}, "It vc;", "vc r1 r3 r3", "vc_r1_r3_r3"},
     {{mi, r4, r2, r7}, "It mi;", "mi r4 r2 r7", "mi_r4_r2_r7"},
     {{ne, r2, r7, r5}, "It ne;", "ne r2 r7 r5", "ne_r2_r7_r5"},
     {{hi, r4, r6, r6}, "It hi;", "hi r4 r6 r6", "hi_r4_r6_r6"},
     {{pl, r6, r0, r5}, "It pl;", "pl r6 r0 r5", "pl_r6_r0_r5"},
     {{lt, r6, r4, r2}, "It lt;", "lt r6 r4 r2", "lt_r6_r4_r2"},
     {{lt, r0, r6, r3}, "It lt;", "lt r0 r6 r3", "lt_r0_r6_r3"},
     {{gt, r5, r2, r5}, "It gt;", "gt r5 r2 r5", "gt_r5_r2_r5"},
     {{ge, r5, r7, r2}, "It ge;", "ge r5 r7 r2", "ge_r5_r7_r2"},
     {{eq, r2, r3, r5}, "It eq;", "eq r2 r3 r5", "eq_r2_r3_r5"},
     {{ge, r2, r4, r3}, "It ge;", "ge r2 r4 r3", "ge_r2_r4_r3"},
     {{cc, r7, r3, r6}, "It cc;", "cc r7 r3 r6", "cc_r7_r3_r6"},
     {{hi, r3, r3, r6}, "It hi;", "hi r3 r3 r6", "hi_r3_r3_r6"},
     {{vc, r0, r2, r2}, "It vc;", "vc r0 r2 r2", "vc_r0_r2_r2"},
     {{mi, r1, r1, r4}, "It mi;", "mi r1 r1 r4", "mi_r1_r1_r4"},
     {{eq, r2, r4, r2}, "It eq;", "eq r2 r4 r2", "eq_r2_r4_r2"},
     {{cc, r4, r6, r0}, "It cc;", "cc r4 r6 r0", "cc_r4_r6_r0"},
     {{cs, r7, r7, r5}, "It cs;", "cs r7 r7 r5", "cs_r7_r7_r5"},
     {{gt, r1, r6, r7}, "It gt;", "gt r1 r6 r7", "gt_r1_r6_r7"},
     {{ge, r0, r7, r2}, "It ge;", "ge r0 r7 r2", "ge_r0_r7_r2"},
     {{gt, r2, r7, r0}, "It gt;", "gt r2 r7 r0", "gt_r2_r7_r0"},
     {{ge, r6, r7, r6}, "It ge;", "ge r6 r7 r6", "ge_r6_r7_r6"},
     {{pl, r6, r3, r4}, "It pl;", "pl r6 r3 r4", "pl_r6_r3_r4"},
     {{ge, r0, r1, r0}, "It ge;", "ge r0 r1 r0", "ge_r0_r1_r0"},
     {{cs, r0, r3, r3}, "It cs;", "cs r0 r3 r3", "cs_r0_r3_r3"},
     {{ge, r0, r1, r2}, "It ge;", "ge r0 r1 r2", "ge_r0_r1_r2"},
     {{cs, r0, r7, r3}, "It cs;", "cs r0 r7 r3", "cs_r0_r7_r3"},
     {{cs, r4, r6, r3}, "It cs;", "cs r4 r6 r3", "cs_r4_r6_r3"},
     {{cs, r0, r6, r6}, "It cs;", "cs r0 r6 r6", "cs_r0_r6_r6"},
     {{gt, r2, r3, r6}, "It gt;", "gt r2 r3 r6", "gt_r2_r3_r6"},
     {{hi, r7, r6, r1}, "It hi;", "hi r7 r6 r1", "hi_r7_r6_r1"},
     {{hi, r3, r4, r4}, "It hi;", "hi r3 r4 r4", "hi_r3_r4_r4"},
     {{vc, r0, r1, r4}, "It vc;", "vc r0 r1 r4", "vc_r0_r1_r4"},
     {{eq, r0, r4, r3}, "It eq;", "eq r0 r4 r3", "eq_r0_r4_r3"},
     {{ne, r1, r0, r0}, "It ne;", "ne r1 r0 r0", "ne_r1_r0_r0"},
     {{ne, r0, r7, r6}, "It ne;", "ne r0 r7 r6", "ne_r0_r7_r6"},
     {{gt, r6, r4, r5}, "It gt;", "gt r6 r4 r5", "gt_r6_r4_r5"},
     {{vc, r0, r7, r6}, "It vc;", "vc r0 r7 r6", "vc_r0_r7_r6"},
     {{gt, r0, r6, r2}, "It gt;", "gt r0 r6 r2", "gt_r0_r6_r2"},
     {{gt, r7, r5, r2}, "It gt;", "gt r7 r5 r2", "gt_r7_r5_r2"},
     {{ge, r5, r0, r3}, "It ge;", "ge r5 r0 r3", "ge_r5_r0_r3"},
     {{hi, r4, r7, r5}, "It hi;", "hi r4 r7 r5", "hi_r4_r7_r5"},
     {{pl, r2, r6, r0}, "It pl;", "pl r2 r6 r0", "pl_r2_r6_r0"},
     {{pl, r4, r2, r0}, "It pl;", "pl r4 r2 r0", "pl_r4_r2_r0"},
     {{ls, r0, r6, r0}, "It ls;", "ls r0 r6 r0", "ls_r0_r6_r0"},
     {{vc, r0, r2, r7}, "It vc;", "vc r0 r2 r7", "vc_r0_r2_r7"},
     {{eq, r4, r3, r5}, "It eq;", "eq r4 r3 r5", "eq_r4_r3_r5"},
     {{ne, r3, r4, r6}, "It ne;", "ne r3 r4 r6", "ne_r3_r4_r6"},
     {{vc, r5, r3, r4}, "It vc;", "vc r5 r3 r4", "vc_r5_r3_r4"},
     {{ls, r6, r6, r2}, "It ls;", "ls r6 r6 r2", "ls_r6_r6_r2"},
     {{vs, r7, r4, r6}, "It vs;", "vs r7 r4 r6", "vs_r7_r4_r6"},
     {{pl, r5, r4, r2}, "It pl;", "pl r5 r4 r2", "pl_r5_r4_r2"},
     {{le, r7, r2, r1}, "It le;", "le r7 r2 r1", "le_r7_r2_r1"},
     {{pl, r1, r7, r7}, "It pl;", "pl r1 r7 r7", "pl_r1_r7_r7"},
     {{cs, r2, r7, r5}, "It cs;", "cs r2 r7 r5", "cs_r2_r7_r5"},
     {{gt, r0, r2, r1}, "It gt;", "gt r0 r2 r1", "gt_r0_r2_r1"},
     {{lt, r2, r0, r0}, "It lt;", "lt r2 r0 r0", "lt_r2_r0_r0"},
     {{mi, r2, r1, r0}, "It mi;", "mi r2 r1 r0", "mi_r2_r1_r0"},
     {{vs, r3, r5, r1}, "It vs;", "vs r3 r5 r1", "vs_r3_r5_r1"},
     {{mi, r2, r3, r4}, "It mi;", "mi r2 r3 r4", "mi_r2_r3_r4"},
     {{vs, r4, r6, r7}, "It vs;", "vs r4 r6 r7", "vs_r4_r6_r7"},
     {{ne, r5, r7, r1}, "It ne;", "ne r5 r7 r1", "ne_r5_r7_r1"},
     {{hi, r2, r6, r1}, "It hi;", "hi r2 r6 r1", "hi_r2_r6_r1"},
     {{ge, r0, r2, r7}, "It ge;", "ge r0 r2 r7", "ge_r0_r2_r7"},
     {{vc, r6, r0, r4}, "It vc;", "vc r6 r0 r4", "vc_r6_r0_r4"},
     {{lt, r5, r4, r2}, "It lt;", "lt r5 r4 r2", "lt_r5_r4_r2"},
     {{ge, r7, r3, r4}, "It ge;", "ge r7 r3 r4", "ge_r7_r3_r4"},
     {{vc, r0, r2, r3}, "It vc;", "vc r0 r2 r3", "vc_r0_r2_r3"},
     {{ne, r6, r1, r0}, "It ne;", "ne r6 r1 r0", "ne_r6_r1_r0"},
     {{mi, r3, r2, r2}, "It mi;", "mi r3 r2 r2", "mi_r3_r2_r2"},
     {{le, r1, r1, r3}, "It le;", "le r1 r1 r3", "le_r1_r1_r3"},
     {{vc, r4, r1, r2}, "It vc;", "vc r4 r1 r2", "vc_r4_r1_r2"},
     {{lt, r0, r5, r6}, "It lt;", "lt r0 r5 r6", "lt_r0_r5_r6"},
     {{hi, r5, r0, r1}, "It hi;", "hi r5 r0 r1", "hi_r5_r0_r1"},
     {{mi, r7, r7, r3}, "It mi;", "mi r7 r7 r3", "mi_r7_r7_r3"},
     {{pl, r7, r6, r4}, "It pl;", "pl r7 r6 r4", "pl_r7_r6_r4"},
     {{ls, r5, r0, r6}, "It ls;", "ls r5 r0 r6", "ls_r5_r0_r6"},
     {{gt, r6, r5, r7}, "It gt;", "gt r6 r5 r7", "gt_r6_r5_r7"},
     {{cs, r0, r6, r0}, "It cs;", "cs r0 r6 r0", "cs_r0_r6_r0"},
     {{mi, r6, r6, r1}, "It mi;", "mi r6 r6 r1", "mi_r6_r6_r1"},
     {{lt, r3, r0, r5}, "It lt;", "lt r3 r0 r5", "lt_r3_r0_r5"},
     {{ge, r5, r1, r2}, "It ge;", "ge r5 r1 r2", "ge_r5_r1_r2"},
     {{ge, r1, r5, r3}, "It ge;", "ge r1 r5 r3", "ge_r1_r5_r3"},
     {{vs, r6, r5, r0}, "It vs;", "vs r6 r5 r0", "vs_r6_r5_r0"},
     {{vs, r4, r6, r5}, "It vs;", "vs r4 r6 r5", "vs_r4_r6_r5"},
     {{hi, r5, r4, r3}, "It hi;", "hi r5 r4 r3", "hi_r5_r4_r3"},
     {{vc, r5, r3, r0}, "It vc;", "vc r5 r3 r0", "vc_r5_r3_r0"},
     {{gt, r4, r7, r5}, "It gt;", "gt r4 r7 r5", "gt_r4_r7_r5"},
     {{lt, r2, r2, r3}, "It lt;", "lt r2 r2 r3", "lt_r2_r2_r3"},
     {{lt, r0, r1, r2}, "It lt;", "lt r0 r1 r2", "lt_r0_r1_r2"},
     {{lt, r6, r2, r0}, "It lt;", "lt r6 r2 r0", "lt_r6_r2_r0"},
     {{gt, r6, r4, r7}, "It gt;", "gt r6 r4 r7", "gt_r6_r4_r7"},
     {{gt, r3, r4, r4}, "It gt;", "gt r3 r4 r4", "gt_r3_r4_r4"},
     {{lt, r4, r5, r7}, "It lt;", "lt r4 r5 r7", "lt_r4_r5_r7"},
     {{ge, r4, r7, r6}, "It ge;", "ge r4 r7 r6", "ge_r4_r7_r6"},
     {{cc, r5, r3, r1}, "It cc;", "cc r5 r3 r1", "cc_r5_r3_r1"},
     {{cc, r6, r0, r6}, "It cc;", "cc r6 r0 r6", "cc_r6_r0_r6"},
     {{ne, r3, r4, r3}, "It ne;", "ne r3 r4 r3", "ne_r3_r4_r3"},
     {{mi, r6, r1, r6}, "It mi;", "mi r6 r1 r6", "mi_r6_r1_r6"},
     {{lt, r6, r5, r2}, "It lt;", "lt r6 r5 r2", "lt_r6_r5_r2"},
     {{cs, r2, r6, r5}, "It cs;", "cs r2 r6 r5", "cs_r2_r6_r5"},
     {{le, r5, r4, r0}, "It le;", "le r5 r4 r0", "le_r5_r4_r0"},
     {{cs, r7, r5, r3}, "It cs;", "cs r7 r5 r3", "cs_r7_r5_r3"},
     {{ne, r6, r6, r3}, "It ne;", "ne r6 r6 r3", "ne_r6_r6_r3"},
     {{eq, r1, r5, r6}, "It eq;", "eq r1 r5 r6", "eq_r1_r5_r6"},
     {{cc, r6, r2, r6}, "It cc;", "cc r6 r2 r6", "cc_r6_r2_r6"},
     {{ge, r5, r4, r0}, "It ge;", "ge r5 r4 r0", "ge_r5_r4_r0"},
     {{cs, r3, r2, r3}, "It cs;", "cs r3 r2 r3", "cs_r3_r2_r3"},
     {{le, r3, r3, r1}, "It le;", "le r3 r3 r1", "le_r3_r3_r1"},
     {{eq, r0, r6, r1}, "It eq;", "eq r0 r6 r1", "eq_r0_r6_r1"},
     {{lt, r1, r5, r4}, "It lt;", "lt r1 r5 r4", "lt_r1_r5_r4"},
     {{gt, r5, r6, r2}, "It gt;", "gt r5 r6 r2", "gt_r5_r6_r2"},
     {{ge, r0, r5, r2}, "It ge;", "ge r0 r5 r2", "ge_r0_r5_r2"},
     {{mi, r2, r5, r6}, "It mi;", "mi r2 r5 r6", "mi_r2_r5_r6"},
     {{vc, r6, r5, r4}, "It vc;", "vc r6 r5 r4", "vc_r6_r5_r4"},
     {{ne, r1, r7, r7}, "It ne;", "ne r1 r7 r7", "ne_r1_r7_r7"},
     {{ge, r6, r1, r7}, "It ge;", "ge r6 r1 r7", "ge_r6_r1_r7"},
     {{ls, r5, r1, r6}, "It ls;", "ls r5 r1 r6", "ls_r5_r1_r6"},
     {{cc, r4, r0, r5}, "It cc;", "cc r4 r0 r5", "cc_r4_r0_r5"},
     {{gt, r0, r0, r0}, "It gt;", "gt r0 r0 r0", "gt_r0_r0_r0"},
     {{gt, r4, r3, r7}, "It gt;", "gt r4 r3 r7", "gt_r4_r3_r7"},
     {{ls, r3, r7, r4}, "It ls;", "ls r3 r7 r4", "ls_r3_r7_r4"},
     {{pl, r0, r1, r5}, "It pl;", "pl r0 r1 r5", "pl_r0_r1_r5"},
     {{hi, r2, r0, r3}, "It hi;", "hi r2 r0 r3", "hi_r2_r0_r3"},
     {{vs, r1, r3, r2}, "It vs;", "vs r1 r3 r2", "vs_r1_r3_r2"},
     {{mi, r6, r5, r6}, "It mi;", "mi r6 r5 r6", "mi_r6_r5_r6"},
     {{gt, r1, r3, r3}, "It gt;", "gt r1 r3 r3", "gt_r1_r3_r3"},
     {{ge, r3, r6, r0}, "It ge;", "ge r3 r6 r0", "ge_r3_r6_r0"},
     {{vc, r6, r6, r5}, "It vc;", "vc r6 r6 r5", "vc_r6_r6_r5"},
     {{ls, r5, r0, r2}, "It ls;", "ls r5 r0 r2", "ls_r5_r0_r2"},
     {{eq, r6, r4, r2}, "It eq;", "eq r6 r4 r2", "eq_r6_r4_r2"},
     {{cc, r4, r2, r7}, "It cc;", "cc r4 r2 r7", "cc_r4_r2_r7"},
     {{ge, r5, r7, r6}, "It ge;", "ge r5 r7 r6", "ge_r5_r7_r6"},
     {{vs, r1, r2, r4}, "It vs;", "vs r1 r2 r4", "vs_r1_r2_r4"},
     {{eq, r3, r7, r2}, "It eq;", "eq r3 r7 r2", "eq_r3_r7_r2"},
     {{vc, r2, r0, r5}, "It vc;", "vc r2 r0 r5", "vc_r2_r0_r5"},
     {{eq, r3, r6, r6}, "It eq;", "eq r3 r6 r6", "eq_r3_r6_r6"},
     {{eq, r1, r3, r3}, "It eq;", "eq r1 r3 r3", "eq_r1_r3_r3"},
     {{mi, r3, r7, r5}, "It mi;", "mi r3 r7 r5", "mi_r3_r7_r5"},
     {{le, r5, r4, r7}, "It le;", "le r5 r4 r7", "le_r5_r4_r7"},
     {{lt, r5, r2, r5}, "It lt;", "lt r5 r2 r5", "lt_r5_r2_r5"},
     {{lt, r0, r1, r3}, "It lt;", "lt r0 r1 r3", "lt_r0_r1_r3"},
     {{eq, r5, r1, r6}, "It eq;", "eq r5 r1 r6", "eq_r5_r1_r6"},
     {{cs, r0, r6, r5}, "It cs;", "cs r0 r6 r5", "cs_r0_r6_r5"},
     {{eq, r3, r1, r1}, "It eq;", "eq r3 r1 r1", "eq_r3_r1_r1"},
     {{ge, r3, r3, r1}, "It ge;", "ge r3 r3 r1", "ge_r3_r3_r1"},
     {{vc, r2, r3, r5}, "It vc;", "vc r2 r3 r5", "vc_r2_r3_r5"},
     {{lt, r1, r4, r7}, "It lt;", "lt r1 r4 r7", "lt_r1_r4_r7"},
     {{hi, r2, r6, r2}, "It hi;", "hi r2 r6 r2", "hi_r2_r6_r2"},
     {{vc, r1, r0, r2}, "It vc;", "vc r1 r0 r2", "vc_r1_r0_r2"},
     {{ne, r1, r6, r2}, "It ne;", "ne r1 r6 r2", "ne_r1_r6_r2"},
     {{le, r2, r2, r4}, "It le;", "le r2 r2 r4", "le_r2_r2_r4"},
     {{cc, r5, r0, r6}, "It cc;", "cc r5 r0 r6", "cc_r5_r0_r6"},
     {{ls, r6, r6, r1}, "It ls;", "ls r6 r6 r1", "ls_r6_r6_r1"},
     {{vs, r1, r3, r4}, "It vs;", "vs r1 r3 r4", "vs_r1_r3_r4"},
     {{vc, r1, r4, r0}, "It vc;", "vc r1 r4 r0", "vc_r1_r4_r0"},
     {{lt, r4, r2, r4}, "It lt;", "lt r4 r2 r4", "lt_r4_r2_r4"},
     {{cc, r7, r2, r6}, "It cc;", "cc r7 r2 r6", "cc_r7_r2_r6"},
     {{hi, r2, r2, r3}, "It hi;", "hi r2 r2 r3", "hi_r2_r2_r3"},
     {{mi, r1, r4, r3}, "It mi;", "mi r1 r4 r3", "mi_r1_r4_r3"},
     {{pl, r6, r0, r0}, "It pl;", "pl r6 r0 r0", "pl_r6_r0_r0"},
     {{pl, r5, r7, r6}, "It pl;", "pl r5 r7 r6", "pl_r5_r7_r6"},
     {{mi, r0, r6, r7}, "It mi;", "mi r0 r6 r7", "mi_r0_r6_r7"},
     {{cs, r4, r3, r2}, "It cs;", "cs r4 r3 r2", "cs_r4_r3_r2"},
     {{vs, r1, r5, r3}, "It vs;", "vs r1 r5 r3", "vs_r1_r5_r3"},
     {{ge, r7, r0, r3}, "It ge;", "ge r7 r0 r3", "ge_r7_r0_r3"},
     {{ne, r5, r6, r2}, "It ne;", "ne r5 r6 r2", "ne_r5_r6_r2"},
     {{ge, r7, r3, r1}, "It ge;", "ge r7 r3 r1", "ge_r7_r3_r1"},
     {{pl, r1, r1, r6}, "It pl;", "pl r1 r1 r6", "pl_r1_r1_r6"},
     {{ls, r7, r1, r4}, "It ls;", "ls r7 r1 r4", "ls_r7_r1_r4"},
     {{vc, r1, r1, r5}, "It vc;", "vc r1 r1 r5", "vc_r1_r1_r5"},
     {{lt, r7, r6, r4}, "It lt;", "lt r7 r6 r4", "lt_r7_r6_r4"},
     {{gt, r2, r6, r3}, "It gt;", "gt r2 r6 r3", "gt_r2_r6_r3"},
     {{ls, r4, r6, r7}, "It ls;", "ls r4 r6 r7", "ls_r4_r6_r7"},
     {{hi, r7, r3, r3}, "It hi;", "hi r7 r3 r3", "hi_r7_r3_r3"},
     {{pl, r3, r4, r3}, "It pl;", "pl r3 r4 r3", "pl_r3_r4_r3"},
     {{gt, r6, r6, r2}, "It gt;", "gt r6 r6 r2", "gt_r6_r6_r2"},
     {{vs, r4, r6, r4}, "It vs;", "vs r4 r6 r4", "vs_r4_r6_r4"},
     {{cs, r3, r0, r2}, "It cs;", "cs r3 r0 r2", "cs_r3_r0_r2"},
     {{ge, r3, r4, r7}, "It ge;", "ge r3 r4 r7", "ge_r3_r4_r7"},
     {{eq, r0, r0, r4}, "It eq;", "eq r0 r0 r4", "eq_r0_r0_r4"},
     {{hi, r7, r4, r0}, "It hi;", "hi r7 r4 r0", "hi_r7_r4_r0"},
     {{le, r4, r0, r7}, "It le;", "le r4 r0 r7", "le_r4_r0_r7"},
     {{cc, r6, r3, r4}, "It cc;", "cc r6 r3 r4", "cc_r6_r3_r4"},
     {{mi, r2, r3, r7}, "It mi;", "mi r2 r3 r7", "mi_r2_r3_r7"},
     {{vc, r0, r0, r7}, "It vc;", "vc r0 r0 r7", "vc_r0_r0_r7"},
     {{pl, r4, r3, r4}, "It pl;", "pl r4 r3 r4", "pl_r4_r3_r4"},
     {{lt, r0, r6, r6}, "It lt;", "lt r0 r6 r6", "lt_r0_r6_r6"},
     {{vs, r2, r6, r5}, "It vs;", "vs r2 r6 r5", "vs_r2_r6_r5"},
     {{ne, r4, r1, r6}, "It ne;", "ne r4 r1 r6", "ne_r4_r1_r6"},
     {{vc, r5, r6, r5}, "It vc;", "vc r5 r6 r5", "vc_r5_r6_r5"},
     {{cs, r5, r3, r2}, "It cs;", "cs r5 r3 r2", "cs_r5_r3_r2"},
     {{vc, r2, r6, r3}, "It vc;", "vc r2 r6 r3", "vc_r2_r6_r3"},
     {{cs, r2, r1, r7}, "It cs;", "cs r2 r1 r7", "cs_r2_r1_r7"},
     {{cs, r4, r0, r1}, "It cs;", "cs r4 r0 r1", "cs_r4_r0_r1"},
     {{eq, r6, r3, r5}, "It eq;", "eq r6 r3 r5", "eq_r6_r3_r5"},
     {{vc, r6, r3, r1}, "It vc;", "vc r6 r3 r1", "vc_r6_r3_r1"},
     {{cs, r4, r1, r7}, "It cs;", "cs r4 r1 r7", "cs_r4_r1_r7"},
     {{ls, r0, r0, r3}, "It ls;", "ls r0 r0 r3", "ls_r0_r0_r3"},
     {{ge, r5, r3, r2}, "It ge;", "ge r5 r3 r2", "ge_r5_r3_r2"},
     {{hi, r5, r7, r7}, "It hi;", "hi r5 r7 r7", "hi_r5_r7_r7"},
     {{cs, r3, r2, r6}, "It cs;", "cs r3 r2 r6", "cs_r3_r2_r6"},
     {{cc, r2, r5, r7}, "It cc;", "cc r2 r5 r7", "cc_r2_r5_r7"},
     {{lt, r4, r7, r7}, "It lt;", "lt r4 r7 r7", "lt_r4_r7_r7"},
     {{pl, r0, r3, r6}, "It pl;", "pl r0 r3 r6", "pl_r0_r3_r6"},
     {{vc, r6, r3, r7}, "It vc;", "vc r6 r3 r7", "vc_r6_r3_r7"},
     {{ne, r0, r7, r3}, "It ne;", "ne r0 r7 r3", "ne_r0_r7_r3"},
     {{ls, r1, r5, r3}, "It ls;", "ls r1 r5 r3", "ls_r1_r5_r3"},
     {{ge, r6, r6, r7}, "It ge;", "ge r6 r6 r7", "ge_r6_r6_r7"},
     {{ne, r2, r4, r4}, "It ne;", "ne r2 r4 r4", "ne_r2_r4_r4"},
     {{cs, r6, r4, r6}, "It cs;", "cs r6 r4 r6", "cs_r6_r4_r6"},
     {{ls, r2, r3, r5}, "It ls;", "ls r2 r3 r5", "ls_r2_r3_r5"},
     {{cs, r4, r3, r7}, "It cs;", "cs r4 r3 r7", "cs_r4_r3_r7"},
     {{pl, r5, r1, r0}, "It pl;", "pl r5 r1 r0", "pl_r5_r1_r0"},
     {{vc, r2, r3, r6}, "It vc;", "vc r2 r3 r6", "vc_r2_r3_r6"},
     {{pl, r1, r1, r0}, "It pl;", "pl r1 r1 r0", "pl_r1_r1_r0"},
     {{cc, r5, r1, r3}, "It cc;", "cc r5 r1 r3", "cc_r5_r1_r3"},
     {{gt, r5, r3, r5}, "It gt;", "gt r5 r3 r5", "gt_r5_r3_r5"},
     {{vs, r5, r2, r4}, "It vs;", "vs r5 r2 r4", "vs_r5_r2_r4"},
     {{hi, r4, r2, r6}, "It hi;", "hi r4 r2 r6", "hi_r4_r2_r6"},
     {{cc, r2, r6, r0}, "It cc;", "cc r2 r6 r0", "cc_r2_r6_r0"},
     {{cc, r3, r0, r5}, "It cc;", "cc r3 r0 r5", "cc_r3_r0_r5"},
     {{cs, r5, r6, r4}, "It cs;", "cs r5 r6 r4", "cs_r5_r6_r4"},
     {{ls, r2, r1, r5}, "It ls;", "ls r2 r1 r5", "ls_r2_r1_r5"},
     {{ne, r7, r0, r0}, "It ne;", "ne r7 r0 r0", "ne_r7_r0_r0"},
     {{vs, r3, r5, r6}, "It vs;", "vs r3 r5 r6", "vs_r3_r5_r6"},
     {{ne, r4, r0, r7}, "It ne;", "ne r4 r0 r7", "ne_r4_r0_r7"},
     {{pl, r5, r3, r4}, "It pl;", "pl r5 r3 r4", "pl_r5_r3_r4"},
     {{cc, r1, r0, r7}, "It cc;", "cc r1 r0 r7", "cc_r1_r0_r7"},
     {{vs, r3, r3, r1}, "It vs;", "vs r3 r3 r1", "vs_r3_r3_r1"},
     {{ne, r4, r0, r0}, "It ne;", "ne r4 r0 r0", "ne_r4_r0_r0"},
     {{ne, r1, r4, r5}, "It ne;", "ne r1 r4 r5", "ne_r1_r4_r5"},
     {{hi, r2, r0, r1}, "It hi;", "hi r2 r0 r1", "hi_r2_r0_r1"},
     {{ne, r5, r7, r3}, "It ne;", "ne r5 r7 r3", "ne_r5_r7_r3"},
     {{ls, r2, r7, r1}, "It ls;", "ls r2 r7 r1", "ls_r2_r7_r1"},
     {{cs, r6, r1, r4}, "It cs;", "cs r6 r1 r4", "cs_r6_r1_r4"},
     {{vc, r3, r0, r6}, "It vc;", "vc r3 r0 r6", "vc_r3_r0_r6"},
     {{hi, r6, r4, r7}, "It hi;", "hi r6 r4 r7", "hi_r6_r4_r7"},
     {{vs, r1, r4, r6}, "It vs;", "vs r1 r4 r6", "vs_r1_r4_r6"},
     {{hi, r2, r7, r6}, "It hi;", "hi r2 r7 r6", "hi_r2_r7_r6"},
     {{ge, r5, r6, r3}, "It ge;", "ge r5 r6 r3", "ge_r5_r6_r3"},
     {{vs, r2, r5, r4}, "It vs;", "vs r2 r5 r4", "vs_r2_r5_r4"},
     {{vc, r0, r2, r0}, "It vc;", "vc r0 r2 r0", "vc_r0_r2_r0"},
     {{gt, r5, r5, r1}, "It gt;", "gt r5 r5 r1", "gt_r5_r5_r1"},
     {{pl, r5, r6, r7}, "It pl;", "pl r5 r6 r7", "pl_r5_r6_r7"},
     {{cc, r6, r0, r5}, "It cc;", "cc r6 r0 r5", "cc_r6_r0_r5"},
     {{ne, r1, r6, r0}, "It ne;", "ne r1 r6 r0", "ne_r1_r6_r0"},
     {{cs, r2, r0, r7}, "It cs;", "cs r2 r0 r7", "cs_r2_r0_r7"},
     {{cc, r4, r0, r1}, "It cc;", "cc r4 r0 r1", "cc_r4_r0_r1"},
     {{ne, r2, r7, r7}, "It ne;", "ne r2 r7 r7", "ne_r2_r7_r7"},
     {{le, r5, r5, r4}, "It le;", "le r5 r5 r4", "le_r5_r5_r4"},
     {{pl, r0, r5, r6}, "It pl;", "pl r0 r5 r6", "pl_r0_r5_r6"},
     {{ne, r2, r2, r1}, "It ne;", "ne r2 r2 r1", "ne_r2_r2_r1"},
     {{ge, r6, r7, r4}, "It ge;", "ge r6 r7 r4", "ge_r6_r7_r4"},
     {{ge, r4, r2, r0}, "It ge;", "ge r4 r2 r0", "ge_r4_r2_r0"},
     {{hi, r2, r2, r7}, "It hi;", "hi r2 r2 r7", "hi_r2_r2_r7"},
     {{eq, r6, r4, r5}, "It eq;", "eq r6 r4 r5", "eq_r6_r4_r5"},
     {{pl, r2, r7, r2}, "It pl;", "pl r2 r7 r2", "pl_r2_r7_r2"},
     {{le, r1, r5, r7}, "It le;", "le r1 r5 r7", "le_r1_r5_r7"},
     {{vc, r0, r4, r0}, "It vc;", "vc r0 r4 r0", "vc_r0_r4_r0"},
     {{cs, r5, r2, r0}, "It cs;", "cs r5 r2 r0", "cs_r5_r2_r0"},
     {{cc, r1, r4, r5}, "It cc;", "cc r1 r4 r5", "cc_r1_r4_r5"},
     {{vs, r6, r4, r7}, "It vs;", "vs r6 r4 r7", "vs_r6_r4_r7"},
     {{ne, r3, r0, r0}, "It ne;", "ne r3 r0 r0", "ne_r3_r0_r0"},
     {{pl, r7, r5, r7}, "It pl;", "pl r7 r5 r7", "pl_r7_r5_r7"},
     {{le, r2, r2, r5}, "It le;", "le r2 r2 r5", "le_r2_r2_r5"},
     {{vc, r3, r0, r7}, "It vc;", "vc r3 r0 r7", "vc_r3_r0_r7"},
     {{ne, r4, r1, r3}, "It ne;", "ne r4 r1 r3", "ne_r4_r1_r3"},
     {{ge, r3, r6, r5}, "It ge;", "ge r3 r6 r5", "ge_r3_r6_r5"},
     {{pl, r6, r0, r6}, "It pl;", "pl r6 r0 r6", "pl_r6_r0_r6"},
     {{vs, r4, r1, r7}, "It vs;", "vs r4 r1 r7", "vs_r4_r1_r7"},
     {{lt, r3, r2, r2}, "It lt;", "lt r3 r2 r2", "lt_r3_r2_r2"},
     {{lt, r1, r4, r1}, "It lt;", "lt r1 r4 r1", "lt_r1_r4_r1"},
     {{mi, r3, r6, r6}, "It mi;", "mi r3 r6 r6", "mi_r3_r6_r6"},
     {{le, r2, r0, r3}, "It le;", "le r2 r0 r3", "le_r2_r0_r3"},
     {{vs, r7, r1, r7}, "It vs;", "vs r7 r1 r7", "vs_r7_r1_r7"},
     {{mi, r2, r5, r0}, "It mi;", "mi r2 r5 r0", "mi_r2_r5_r0"},
     {{cs, r5, r1, r1}, "It cs;", "cs r5 r1 r1", "cs_r5_r1_r1"},
     {{hi, r3, r2, r4}, "It hi;", "hi r3 r2 r4", "hi_r3_r2_r4"},
     {{ne, r3, r1, r4}, "It ne;", "ne r3 r1 r4", "ne_r3_r1_r4"},
     {{gt, r4, r4, r4}, "It gt;", "gt r4 r4 r4", "gt_r4_r4_r4"},
     {{le, r1, r0, r1}, "It le;", "le r1 r0 r1", "le_r1_r0_r1"},
     {{eq, r2, r3, r4}, "It eq;", "eq r2 r3 r4", "eq_r2_r3_r4"},
     {{ge, r6, r2, r0}, "It ge;", "ge r6 r2 r0", "ge_r6_r2_r0"},
     {{hi, r5, r3, r1}, "It hi;", "hi r5 r3 r1", "hi_r5_r3_r1"},
     {{vs, r7, r4, r2}, "It vs;", "vs r7 r4 r2", "vs_r7_r4_r2"},
     {{mi, r7, r2, r2}, "It mi;", "mi r7 r2 r2", "mi_r7_r2_r2"},
     {{gt, r6, r5, r3}, "It gt;", "gt r6 r5 r3", "gt_r6_r5_r3"},
     {{vc, r7, r6, r4}, "It vc;", "vc r7 r6 r4", "vc_r7_r6_r4"},
     {{ge, r1, r3, r4}, "It ge;", "ge r1 r3 r4", "ge_r1_r3_r4"},
     {{pl, r5, r2, r6}, "It pl;", "pl r5 r2 r6", "pl_r5_r2_r6"},
     {{gt, r1, r6, r1}, "It gt;", "gt r1 r6 r1", "gt_r1_r6_r1"},
     {{vs, r5, r6, r0}, "It vs;", "vs r5 r6 r0", "vs_r5_r6_r0"},
     {{cs, r5, r4, r7}, "It cs;", "cs r5 r4 r7", "cs_r5_r4_r7"},
     {{cc, r6, r4, r3}, "It cc;", "cc r6 r4 r3", "cc_r6_r4_r3"},
     {{mi, r3, r7, r3}, "It mi;", "mi r3 r7 r3", "mi_r3_r7_r3"},
     {{le, r2, r4, r6}, "It le;", "le r2 r4 r6", "le_r2_r4_r6"},
     {{ne, r7, r7, r2}, "It ne;", "ne r7 r7 r2", "ne_r7_r7_r2"},
     {{ge, r3, r7, r1}, "It ge;", "ge r3 r7 r1", "ge_r3_r7_r1"},
     {{vc, r2, r3, r2}, "It vc;", "vc r2 r3 r2", "vc_r2_r3_r2"},
     {{eq, r1, r5, r4}, "It eq;", "eq r1 r5 r4", "eq_r1_r5_r4"},
     {{ls, r6, r5, r3}, "It ls;", "ls r6 r5 r3", "ls_r6_r5_r3"},
     {{gt, r1, r3, r1}, "It gt;", "gt r1 r3 r1", "gt_r1_r3_r1"},
     {{hi, r1, r2, r0}, "It hi;", "hi r1 r2 r0", "hi_r1_r2_r0"},
     {{vs, r0, r3, r7}, "It vs;", "vs r0 r3 r7", "vs_r0_r3_r7"},
     {{cs, r7, r7, r3}, "It cs;", "cs r7 r7 r3", "cs_r7_r7_r3"},
     {{pl, r4, r7, r2}, "It pl;", "pl r4 r7 r2", "pl_r4_r7_r2"},
     {{ne, r5, r5, r4}, "It ne;", "ne r5 r5 r4", "ne_r5_r5_r4"},
     {{lt, r4, r4, r1}, "It lt;", "lt r4 r4 r1", "lt_r4_r4_r1"},
     {{eq, r3, r1, r4}, "It eq;", "eq r3 r1 r4", "eq_r3_r1_r4"},
     {{eq, r6, r4, r0}, "It eq;", "eq r6 r4 r0", "eq_r6_r4_r0"},
     {{cc, r3, r1, r6}, "It cc;", "cc r3 r1 r6", "cc_r3_r1_r6"},
     {{lt, r1, r1, r5}, "It lt;", "lt r1 r1 r5", "lt_r1_r1_r5"},
     {{lt, r3, r1, r0}, "It lt;", "lt r3 r1 r0", "lt_r3_r1_r0"},
     {{gt, r1, r0, r3}, "It gt;", "gt r1 r0 r3", "gt_r1_r0_r3"},
     {{ne, r1, r2, r0}, "It ne;", "ne r1 r2 r0", "ne_r1_r2_r0"},
     {{vs, r1, r2, r5}, "It vs;", "vs r1 r2 r5", "vs_r1_r2_r5"},
     {{gt, r4, r4, r1}, "It gt;", "gt r4 r4 r1", "gt_r4_r4_r1"},
     {{mi, r4, r3, r2}, "It mi;", "mi r4 r3 r2", "mi_r4_r3_r2"},
     {{vs, r5, r3, r6}, "It vs;", "vs r5 r3 r6", "vs_r5_r3_r6"},
     {{vs, r7, r4, r4}, "It vs;", "vs r7 r4 r4", "vs_r7_r4_r4"},
     {{ge, r7, r2, r2}, "It ge;", "ge r7 r2 r2", "ge_r7_r2_r2"},
     {{eq, r3, r1, r0}, "It eq;", "eq r3 r1 r0", "eq_r3_r1_r0"},
     {{vs, r4, r3, r7}, "It vs;", "vs r4 r3 r7", "vs_r4_r3_r7"},
     {{ge, r2, r2, r7}, "It ge;", "ge r2 r2 r7", "ge_r2_r2_r7"},
     {{eq, r6, r4, r6}, "It eq;", "eq r6 r4 r6", "eq_r6_r4_r6"},
     {{lt, r4, r2, r6}, "It lt;", "lt r4 r2 r6", "lt_r4_r2_r6"},
     {{gt, r1, r7, r6}, "It gt;", "gt r1 r7 r6", "gt_r1_r7_r6"},
     {{vc, r6, r1, r2}, "It vc;", "vc r6 r1 r2", "vc_r6_r1_r2"},
     {{ls, r4, r2, r4}, "It ls;", "ls r4 r2 r4", "ls_r4_r2_r4"},
     {{vc, r6, r1, r5}, "It vc;", "vc r6 r1 r5", "vc_r6_r1_r5"},
     {{hi, r7, r7, r2}, "It hi;", "hi r7 r7 r2", "hi_r7_r7_r2"},
     {{mi, r5, r3, r3}, "It mi;", "mi r5 r3 r3", "mi_r5_r3_r3"},
     {{pl, r3, r6, r2}, "It pl;", "pl r3 r6 r2", "pl_r3_r6_r2"},
     {{cc, r2, r4, r0}, "It cc;", "cc r2 r4 r0", "cc_r2_r4_r0"},
     {{vc, r6, r1, r7}, "It vc;", "vc r6 r1 r7", "vc_r6_r1_r7"},
     {{ne, r6, r5, r4}, "It ne;", "ne r6 r5 r4", "ne_r6_r5_r4"},
     {{vc, r6, r0, r6}, "It vc;", "vc r6 r0 r6", "vc_r6_r0_r6"},
     {{ge, r3, r6, r6}, "It ge;", "ge r3 r6 r6", "ge_r3_r6_r6"},
     {{eq, r0, r3, r1}, "It eq;", "eq r0 r3 r1", "eq_r0_r3_r1"},
     {{ge, r5, r2, r7}, "It ge;", "ge r5 r2 r7", "ge_r5_r2_r7"},
     {{gt, r4, r0, r0}, "It gt;", "gt r4 r0 r0", "gt_r4_r0_r0"},
     {{hi, r7, r0, r6}, "It hi;", "hi r7 r0 r6", "hi_r7_r0_r6"},
     {{le, r5, r7, r1}, "It le;", "le r5 r7 r1", "le_r5_r7_r1"},
     {{ge, r4, r4, r4}, "It ge;", "ge r4 r4 r4", "ge_r4_r4_r4"},
     {{hi, r2, r4, r0}, "It hi;", "hi r2 r4 r0", "hi_r2_r4_r0"},
     {{vc, r6, r3, r6}, "It vc;", "vc r6 r3 r6", "vc_r6_r3_r6"},
     {{cc, r2, r2, r2}, "It cc;", "cc r2 r2 r2", "cc_r2_r2_r2"},
     {{ls, r7, r6, r1}, "It ls;", "ls r7 r6 r1", "ls_r7_r6_r1"},
     {{le, r7, r3, r5}, "It le;", "le r7 r3 r5", "le_r7_r3_r5"},
     {{ls, r5, r5, r1}, "It ls;", "ls r5 r5 r1", "ls_r5_r5_r1"},
     {{mi, r0, r5, r3}, "It mi;", "mi r0 r5 r3", "mi_r0_r5_r3"},
     {{hi, r3, r4, r0}, "It hi;", "hi r3 r4 r0", "hi_r3_r4_r0"},
     {{cs, r2, r2, r2}, "It cs;", "cs r2 r2 r2", "cs_r2_r2_r2"},
     {{hi, r6, r3, r2}, "It hi;", "hi r6 r3 r2", "hi_r6_r3_r2"},
     {{vs, r1, r4, r7}, "It vs;", "vs r1 r4 r7", "vs_r1_r4_r7"},
     {{vc, r0, r7, r2}, "It vc;", "vc r0 r7 r2", "vc_r0_r7_r2"},
     {{le, r1, r2, r3}, "It le;", "le r1 r2 r3", "le_r1_r2_r3"},
     {{vc, r6, r0, r1}, "It vc;", "vc r6 r0 r1", "vc_r6_r0_r1"},
     {{vs, r4, r6, r0}, "It vs;", "vs r4 r6 r0", "vs_r4_r6_r0"},
     {{pl, r6, r0, r1}, "It pl;", "pl r6 r0 r1", "pl_r6_r0_r1"},
     {{eq, r4, r1, r7}, "It eq;", "eq r4 r1 r7", "eq_r4_r1_r7"},
     {{lt, r6, r4, r3}, "It lt;", "lt r6 r4 r3", "lt_r6_r4_r3"},
     {{ge, r0, r2, r4}, "It ge;", "ge r0 r2 r4", "ge_r0_r2_r4"},
     {{gt, r0, r5, r2}, "It gt;", "gt r0 r5 r2", "gt_r0_r5_r2"},
     {{pl, r4, r5, r3}, "It pl;", "pl r4 r5 r3", "pl_r4_r5_r3"},
     {{ls, r0, r3, r5}, "It ls;", "ls r0 r3 r5", "ls_r0_r3_r5"},
     {{cc, r0, r1, r5}, "It cc;", "cc r0 r1 r5", "cc_r0_r1_r5"},
     {{eq, r4, r4, r6}, "It eq;", "eq r4 r4 r6", "eq_r4_r4_r6"},
     {{hi, r2, r3, r5}, "It hi;", "hi r2 r3 r5", "hi_r2_r3_r5"},
     {{eq, r6, r6, r0}, "It eq;", "eq r6 r6 r0", "eq_r6_r6_r0"},
     {{pl, r5, r1, r3}, "It pl;", "pl r5 r1 r3", "pl_r5_r1_r3"},
     {{vc, r2, r4, r4}, "It vc;", "vc r2 r4 r4", "vc_r2_r4_r4"},
     {{cs, r5, r5, r3}, "It cs;", "cs r5 r5 r3", "cs_r5_r5_r3"},
     {{ne, r5, r3, r7}, "It ne;", "ne r5 r3 r7", "ne_r5_r3_r7"},
     {{gt, r5, r4, r4}, "It gt;", "gt r5 r4 r4", "gt_r5_r4_r4"},
     {{lt, r7, r2, r7}, "It lt;", "lt r7 r2 r7", "lt_r7_r2_r7"},
     {{lt, r4, r6, r7}, "It lt;", "lt r4 r6 r7", "lt_r4_r6_r7"},
     {{ge, r2, r2, r3}, "It ge;", "ge r2 r2 r3", "ge_r2_r2_r3"},
     {{ne, r5, r0, r1}, "It ne;", "ne r5 r0 r1", "ne_r5_r0_r1"},
     {{cc, r0, r5, r2}, "It cc;", "cc r0 r5 r2", "cc_r0_r5_r2"},
     {{ls, r6, r0, r4}, "It ls;", "ls r6 r0 r4", "ls_r6_r0_r4"},
     {{eq, r6, r0, r2}, "It eq;", "eq r6 r0 r2", "eq_r6_r0_r2"},
     {{lt, r7, r7, r2}, "It lt;", "lt r7 r7 r2", "lt_r7_r7_r2"},
     {{ne, r5, r0, r4}, "It ne;", "ne r5 r0 r4", "ne_r5_r0_r4"},
     {{ge, r0, r6, r7}, "It ge;", "ge r0 r6 r7", "ge_r0_r6_r7"},
     {{vs, r7, r3, r6}, "It vs;", "vs r7 r3 r6", "vs_r7_r3_r6"},
     {{gt, r5, r0, r2}, "It gt;", "gt r5 r0 r2", "gt_r5_r0_r2"},
     {{hi, r7, r5, r3}, "It hi;", "hi r7 r5 r3", "hi_r7_r5_r3"},
     {{pl, r5, r0, r2}, "It pl;", "pl r5 r0 r2", "pl_r5_r0_r2"},
     {{le, r7, r4, r2}, "It le;", "le r7 r4 r2", "le_r7_r4_r2"},
     {{le, r3, r6, r4}, "It le;", "le r3 r6 r4", "le_r3_r6_r4"},
     {{cs, r5, r0, r5}, "It cs;", "cs r5 r0 r5", "cs_r5_r0_r5"},
     {{vs, r3, r2, r7}, "It vs;", "vs r3 r2 r7", "vs_r3_r2_r7"},
     {{le, r1, r2, r1}, "It le;", "le r1 r2 r1", "le_r1_r2_r1"},
     {{ls, r5, r1, r3}, "It ls;", "ls r5 r1 r3", "ls_r5_r1_r3"},
     {{vc, r3, r4, r7}, "It vc;", "vc r3 r4 r7", "vc_r3_r4_r7"},
     {{le, r7, r4, r0}, "It le;", "le r7 r4 r0", "le_r7_r4_r0"},
     {{mi, r2, r4, r4}, "It mi;", "mi r2 r4 r4", "mi_r2_r4_r4"},
     {{cc, r5, r7, r7}, "It cc;", "cc r5 r7 r7", "cc_r5_r7_r7"},
     {{cc, r5, r2, r5}, "It cc;", "cc r5 r2 r5", "cc_r5_r2_r5"},
     {{mi, r5, r4, r1}, "It mi;", "mi r5 r4 r1", "mi_r5_r4_r1"},
     {{lt, r5, r2, r4}, "It lt;", "lt r5 r2 r4", "lt_r5_r2_r4"},
     {{mi, r1, r5, r5}, "It mi;", "mi r1 r5 r5", "mi_r1_r5_r5"},
     {{ne, r1, r2, r1}, "It ne;", "ne r1 r2 r1", "ne_r1_r2_r1"},
     {{cs, r3, r7, r5}, "It cs;", "cs r3 r7 r5", "cs_r3_r7_r5"},
     {{hi, r3, r5, r2}, "It hi;", "hi r3 r5 r2", "hi_r3_r5_r2"},
     {{lt, r0, r5, r4}, "It lt;", "lt r0 r5 r4", "lt_r0_r5_r4"},
     {{lt, r2, r4, r2}, "It lt;", "lt r2 r4 r2", "lt_r2_r4_r2"},
     {{gt, r7, r6, r2}, "It gt;", "gt r7 r6 r2", "gt_r7_r6_r2"},
     {{vc, r4, r2, r0}, "It vc;", "vc r4 r2 r0", "vc_r4_r2_r0"},
     {{ls, r5, r4, r5}, "It ls;", "ls r5 r4 r5", "ls_r5_r4_r5"},
     {{hi, r3, r4, r2}, "It hi;", "hi r3 r4 r2", "hi_r3_r4_r2"},
     {{ge, r2, r5, r2}, "It ge;", "ge r2 r5 r2", "ge_r2_r5_r2"},
     {{pl, r0, r1, r1}, "It pl;", "pl r0 r1 r1", "pl_r0_r1_r1"},
     {{lt, r1, r5, r0}, "It lt;", "lt r1 r5 r0", "lt_r1_r5_r0"},
     {{pl, r4, r4, r0}, "It pl;", "pl r4 r4 r0", "pl_r4_r4_r0"}};

// These headers each contain an array of `TestResult` with the reference output
// values. The reference arrays are names `kReference{mnemonic}`.
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-all-low-in-it-block-add.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-rm-t32-all-low-in-it-block-sub.h"


// The maximum number of errors to report in detail for each test.
static const unsigned kErrorReportLimit = 8;

typedef void (MacroAssembler::*Fn)(Condition cond,
                                   Register rd,
                                   Register rn,
                                   const Operand& op);

static void TestHelper(Fn instruction,
                       const char* mnemonic,
                       const TestResult reference[]) {
  unsigned total_error_count = 0;
  MacroAssembler masm(BUF_SIZE);

  masm.UseT32();

  for (unsigned i = 0; i < ARRAY_SIZE(kTests); i++) {
    // Values to pass to the macro-assembler.
    Condition cond = kTests[i].operands.cond;
    Register rd = kTests[i].operands.rd;
    Register rn = kTests[i].operands.rn;
    Register rm = kTests[i].operands.rm;
    Operand op(rm);

    uint32_t start = masm.GetCursorOffset();
    (masm.*instruction)(cond, rd, rn, op);
    uint32_t end = masm.GetCursorOffset();

    const byte* result_ptr =
        masm.GetBuffer().GetOffsetAddress<const byte*>(start);
    uint32_t result_size = end - start;

    if (Test::generate_test_trace()) {
      // Print the result bytes.
      printf("static const byte kInstruction_%s_%s[] = {\n",
             mnemonic,
             kTests[i].identifier);
      for (uint32_t j = 0; j < result_size; j++) {
        if (j == 0) {
          printf("  0x%02" PRIx8, result_ptr[j]);
        } else {
          printf(", 0x%02" PRIx8, result_ptr[j]);
        }
      }
      // This comment is meant to be used by external tools to validate
      // the encoding. We can parse the comment to figure out what
      // instruction this corresponds to.
      printf(" // %s %s %s\n};\n",
             kTests[i].expect_instruction_before,
             mnemonic,
             kTests[i].operands_description);
    } else {
      // Check we've emitted the exact same encoding as present in the
      // trace file. Only print up to `kErrorReportLimit` errors.
      if (((result_size != reference[i].size) ||
           (memcmp(result_ptr, reference[i].encoding, reference[i].size) !=
            0)) &&
          (++total_error_count <= kErrorReportLimit)) {
        printf("Error when testing \"%s\" with operands \"%s\":\n",
               mnemonic,
               kTests[i].operands_description);
        printf("  Expected: ");
        for (uint32_t j = 0; j < reference[i].size; j++) {
          if (j == 0) {
            printf("0x%02" PRIx8, reference[i].encoding[j]);
          } else {
            printf(", 0x%02" PRIx8, reference[i].encoding[j]);
          }
        }
        printf("\n");
        printf("  Found:    ");
        for (uint32_t j = 0; j < result_size; j++) {
          if (j == 0) {
            printf("0x%02" PRIx8, result_ptr[j]);
          } else {
            printf(", 0x%02" PRIx8, result_ptr[j]);
          }
        }
        printf("\n");
      }
    }
  }

  masm.FinalizeCode();

  if (Test::generate_test_trace()) {
    // Finalize the trace file by writing the final `TestResult` array
    // which links all generated instruction encodings.
    printf("static const TestResult kReference%s[] = {\n", mnemonic);
    for (unsigned i = 0; i < ARRAY_SIZE(kTests); i++) {
      printf("  {\n");
      printf("    ARRAY_SIZE(kInstruction_%s_%s),\n",
             mnemonic,
             kTests[i].identifier);
      printf("    kInstruction_%s_%s,\n", mnemonic, kTests[i].identifier);
      printf("  },\n");
    }
    printf("};\n");
  } else {
    if (total_error_count > kErrorReportLimit) {
      printf("%u other errors follow.\n",
             total_error_count - kErrorReportLimit);
    }
  }
}

// Instantiate tests for each instruction in the list.
#define TEST(mnemonic)                                                      \
  static void Test_##mnemonic() {                                           \
    TestHelper(&MacroAssembler::mnemonic, #mnemonic, kReference##mnemonic); \
  }                                                                         \
  static Test test_##mnemonic(                                              \
      "AARCH32_ASSEMBLER_COND_RD_RN_OPERAND_RM_T32_ALL_LOW_IN_IT_"          \
      "BLOCK_" #mnemonic,                                                   \
      &Test_##mnemonic);
FOREACH_INSTRUCTION(TEST)
#undef TEST

}  // aarch32
}  // vixl
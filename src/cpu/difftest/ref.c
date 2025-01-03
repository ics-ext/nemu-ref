/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

__EXPORT const uint32_t to_dut = DIFFTEST_TO_DUT;
__EXPORT const uint32_t to_ref = DIFFTEST_TO_REF;

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  assert(buf);
  if (direction == (bool)to_dut) {
    memcpy(buf, guest_to_host(addr), n);
  } else {
    memcpy(guest_to_host(addr), buf, n);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
  assert(dut);
  if (direction == (bool)to_dut) {
    memcpy(dut, &cpu, sizeof(cpu));
  } else {
    memcpy(&cpu, dut, sizeof(cpu));
  }
}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  // TODO
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}

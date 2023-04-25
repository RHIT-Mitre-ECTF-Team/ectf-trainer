/**
 * Copyright 2022 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include "uart2.h"

void u2putc(char c) {
  while ((UART2FR >> 5) & 1)
    ;

  UART2_DR = c;
  if (c == '\n')
    u2putc('\r');
}

int u2getc(void) {
  if (!((UART2FR >> 4) & 1)) return UART2_DR;

  return -1;
}

void uart2_init(void) {
  /* Disable the UART */
  UART2CTL = 0;

  /* Set the Baud to 115200 */
  UART2IBRD = 8;
  UART2FBRD = 44;

  /* Use system clock for Uart */
  UART2CC = 0;

  /* 8n1 and no fifo */
  UART2LCRH = 0x60;

  /* Enable UART with TXE and RXE */
  UART2CTL = 0x301;
}

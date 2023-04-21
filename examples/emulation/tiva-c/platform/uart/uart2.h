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

#ifndef __UART2_H__
#define __UART2_H__

#define UART2_BASE 0x4000D000
#define UART2_DR *((unsigned int *)(UART2_BASE + 0x00))
#define UART2FR *((unsigned int *)(UART2_BASE + 0x18))
#define UART2IBRD *((unsigned int *)(UART2_BASE + 0x24))
#define UART2FBRD *((unsigned int *)(UART2_BASE + 0x28))
#define UART2CTL *((unsigned int *)(UART2_BASE + 0x30))
#define UART2CC *((unsigned int *)(UART2_BASE + 0xfc8))
#define UART2LCRH *((unsigned int *)(UART2_BASE + 0x2c))

/**
 * @brief Put a character on uart data buffer
 *
 * @param c byte to be sent out
 */
void u2putc(char c);

/**
 * @brief Get a character from uart data buffer
 *
 * @return int byte read from the uart data register
 */
int u2getc(void);

/**
 * @brief Init the uart, set baud etc
 *
 */
void uart2_init(void);

#endif

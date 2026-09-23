/*
Copyright (c) 2020 SparkFun Electronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _SVL_UTILS_H_
#define _SVL_UTILS_H_

#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"

#include "stdint.h"

void        _fill_ticks(void);
size_t      millis(void);
bool        enable_burst_mode(void);
bool        disable_burst_mode(void);
uint32_t    ap3_gpio_enable_interrupts(uint32_t ui32Pin, uint32_t eIntDir);

extern volatile uint32_t ap3_stimer_overflows;

#endif // _SVL_UTILS_H_ 
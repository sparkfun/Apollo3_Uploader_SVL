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

#include "svl_uart.h"





//*****************************************************************************
//
// UART read buffer
//
//*****************************************************************************
size_t svl_uart_read(void *pHandle, char* buf, size_t len){
    uint32_t ui32BytesRead = 0x00;
    am_hal_uart_transfer_t sRead = {
        .ui32Direction = AM_HAL_UART_READ,
        .pui8Data = (uint8_t*)buf,
        .ui32NumBytes = len,
        .ui32TimeoutMs = 0,
        .pui32BytesTransferred = &ui32BytesRead,
    };
    am_hal_uart_transfer(pHandle, &sRead);
    return ui32BytesRead;
}

//*****************************************************************************
//
// UART write buffer
//
//*****************************************************************************
size_t svl_uart_write(void *pHandle, char* buf, size_t len){
    uint32_t ui32BytesWritten = 0;
    const am_hal_uart_transfer_t sUartWrite =
    {
        .ui32Direction = AM_HAL_UART_WRITE,
        .pui8Data = (uint8_t*) buf,
        .ui32NumBytes = len,
        .ui32TimeoutMs = AM_HAL_UART_WAIT_FOREVER,
        .pui32BytesTransferred = &ui32BytesWritten,
    };

    am_hal_uart_transfer(pHandle, &sUartWrite);

    return ui32BytesWritten;
}

//*****************************************************************************
//
// UART write byte
//
//*****************************************************************************
size_t svl_uart_write_byte(void *pHandle, uint8_t c){
    return svl_uart_write(pHandle, (char*)&c, 1);
}

//*****************************************************************************
//
// UART send string
//
//*****************************************************************************
size_t svl_uart_print(void *pHandle, char* str){
    uint32_t ui32StrLen = 0;
    while (str[ui32StrLen] != 0){ ui32StrLen++; } // Measure the length of the string.
    return svl_uart_write( pHandle, str, ui32StrLen);    

    // uint16_t indi = 0; 
    // while((*(debug_buffer+indi)!='\0') && (indi < DEBUG_UART_BUF_LEN)){
    //     svl_uart_write(hUART_debug, debug_buffer+indi, 1);
    //     indi++;
    // }
}
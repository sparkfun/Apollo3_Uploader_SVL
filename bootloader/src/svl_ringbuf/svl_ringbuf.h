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

#ifndef _SVL_RINGBUF_H_
#define _SVL_RINGBUF_H_

#include "stdio.h"

typedef struct _art_svl_ringbuf_t {
    uint8_t*        buf;
    size_t          len;
    volatile size_t r_offset;
    volatile size_t w_offset;
}art_svl_ringbuf_t;

size_t art_svl_ringbuf_init         ( void* rb, uint8_t* buf, size_t len );
size_t art_svl_ringbuf_available    ( void* rb );
size_t art_svl_ringbuf_bytes_free   ( void* rb );
size_t art_svl_ringbuf_write        ( void* rb, uint8_t c );
size_t art_svl_ringbuf_read         ( void* rb, uint8_t* c );


#endif // _SVL_RINGBUF_H_
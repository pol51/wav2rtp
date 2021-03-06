/*
 * $Id$
 * 
 * Copyright (c) 2007, R.Imankulov
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the R.Imankulov nor the names of its contributors may
 *  be used to endorse or promote products derived from this software without
 *  specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef __CODECAPI_H
#define __CODECAPI_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "contrib/simclist.h"



/** Encoder abstraction object */
typedef struct __wr_encoder{
    
    /* Members */
    char * name;        /**< name of the codec as in SDP packet */
    char * description; /**< human-readable description of the codec */
    void * state;       /**< internal state of the encoder, represented for its own struct type for each type of codec */
    int payload_type;   /**< default payload type for this codec */
    int sample_rate;    /**< sample-rate, used at least in SDP description of this codec */ 

    /* Methods */
    int (*get_input_buffer_size)(void *);
    int (*get_output_buffer_size)(void *);
    int (*encode)(void *, const short * , char *);
    struct __wr_encoder* (*init)(struct __wr_encoder *);
    void (*destroy)(struct __wr_encoder * );

} wr_encoder_t;


/** Decoder abstraction object */
typedef struct __wr_decoder{
    
    /* Members */
    char * name;        /**< name of the codec as in SDP packet */
    char * description; /**< human-readable description of the codec */
    void * state;       /**< internal state of the decoder, represented for its own struct type for each type of codec */
    int payload_type;   /**< default payload type for this codec */
    int sample_rate;    /**< sample-rate, used at least in SDP description of this codec */ 

    /* Methods */
    int (*get_input_buffer_size)(void *);
    int (*get_output_buffer_size)(void *);
    int (*decode)(void * state, const char * input, size_t input_size, short * output);
    struct __wr_decoder* (*init)(struct __wr_decoder *);
    void (*destroy)(struct __wr_decoder * );

} wr_decoder_t;

#define wr_encoder_is_initialized(c) (c->state?1:0)
#define wr_decoder_is_initialized(c) (c->state?1:0)

#endif

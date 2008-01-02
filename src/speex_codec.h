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
#ifndef __SPEEX_CODEC_H
#define __SPEEX_CODEC_H

#include <speex/speex.h>
#include "wav2rtp.h"

/** Speex codec object */
typedef struct {

    /* Speex state */
    SpeexBits bits;     /**< speex bit-packing struct  */
    void * enc_state;   /**< speex encoder state */

    /* Speex options */
    int quality;        /**< speex quality: 0<=q<=10 */
    int complexity;     /**< speex encoder complexity */
    int bitrate;        /**< bitrate */
    int abr_enabled;    /**< average bitrate */
    int vad_enabled;    /**< voice activity detection */
    int dtx_enabled;    /**< discontinious transmission */
    int vbr_enabled;    /**< boolean value, true if VBR (vraiable bit-rate) should be enabled */
    float vbr_quality;  /**< VBR quality: 0<=q<=10 */
    #ifdef SPEEX_SET_VBR_MAX_BITRATE
    int vbr_max_bitrate;/**< max bitrate with VBR enabled */
    #endif
    
} speex_state;

wr_codec_t *  wr_speex_init_codec(wr_codec_t * );
void wr_speex_destroy_codec(wr_codec_t *);
int wr_speex_get_input_buffer_size(void * state);
int wr_speex_get_output_buffer_size(void * state);
int wr_speex_encode(void * state, const short * input, char * output); 

#endif

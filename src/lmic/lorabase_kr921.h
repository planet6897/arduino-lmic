/*
* Copyright (c) 2014-2016 IBM Corporation.
* All rights reserved.
*
* Copyright (c) 2017 MCCI Corporation
* All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*  * Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*  * Neither the name of the <organization> nor the
*    names of its contributors may be used to endorse or promote products
*    derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _lorabase_kr921_h_
#define _lorabase_kr921_h_

#ifndef _LMIC_CONFIG_PRECONDITIONS_H_
# include "lmic_config_preconditions.h"
#endif

/****************************************************************************\
|
| Basic definitions for KR921 (always in scope)
|
\****************************************************************************/

//
// Default frequency plan for KR 920MHz ISM band
// data rates
// this is a little confusing: the integer values of these constants are the
// DataRates from the LoRaWAN Regional Parmaeter spec. The names are just
// convenient indications, so we can use them in the rare case that we need to
// choose a DataRate by SF and configuration, not by DR code.

/*
[200~
(01) 920.9  125     10 dbm (10mW)   23 dbm (200mW)
(02) 921.1  125     10      23
(03) 921.3  125     10      23
(04) 921.5  125     10      23
(05) 921.7  125     10      23

(06) 921.9  125     10      23
(07) 922.1  125     14 dbm (25mW)   23 dbm (200mW)  (default channel)
(08) 922.3  125     14      23      (default channel)
(09) 922.5  125     14      23      (default channel)
(10) 922.7  125     14      23

(11) 922.9  125     14      23
(12) 923.1  125     14      23
*/
enum _dr_kr921_t {
        KR921_DR_SF12 = 0,
        KR921_DR_SF11,
        KR921_DR_SF10,
        KR921_DR_SF9,
        KR921_DR_SF8,
        KR921_DR_SF7,
        KR921_DR_NONE
};

// Bands:
//  g1 :   1%  14dBm
//  g2 : 0.1%  14dBm
//  g3 :  10%  27dBm
//                 freq             band     datarates
enum {
        KR921_F1 = 920900000,      // g1   SF7-12
        KR921_F2 = 921100000,      // g1   SF7-12
        KR921_F3 = 921300000,      // g1   SF7-12
        KR921_F4 = 921500000,      // g1   SF7-12
        KR921_F5 = 921700000,      // g1   SF7-12
        KR921_F6 = 921900000,      // g1   SF7-12
        KR921_F7 = 922100000,      // g1   SF7-12
        KR921_F8 = 922300000,      // g1   SF7-12
        KR921_F9 = 922500000,      // g1   SF7-12
        KR921_F10 = 922700000,     // g1   SF7-12
        KR921_F11 = 922900000,     // g1   SF7-12
        KR921_F12 = 923100000,     // g1   SF7-12
        KR921_F13 = 923300000,     // g1   SF7-12
};
enum {
        KR921_FREQ_MIN = 920900000,
        KR921_FREQ_MAX = 923300000
};
enum {
        KR921_TX_EIRP_MAX_DBM = 16      // 16 dBm EIRP. So subtract 3 dBm for a 3 dBi antenna.
};

enum { KR921_LMIC_REGION_EIRP = 1 };         // region uses EIRP

enum { DR_PAGE_KR921 = 0x10 * (LMIC_REGION_kr921 - 1) };

#endif /* _lorabase_kr921_h_ */

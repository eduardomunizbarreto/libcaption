/**********************************************************************************************/
/* The MIT License                                                                            */
/*                                                                                            */
/* Copyright 2016-2017 Twitch Interactive, Inc. or its affiliates. All Rights Reserved.       */
/*                                                                                            */
/* Permission is hereby granted, free of charge, to any person obtaining a copy               */
/* of this software and associated documentation files (the "Software"), to deal              */
/* in the Software without restriction, including without limitation the rights               */
/* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                  */
/* copies of the Software, and to permit persons to whom the Software is                      */
/* furnished to do so, subject to the following conditions:                                   */
/*                                                                                            */
/* The above copyright notice and this permission notice shall be included in                 */
/* all copies or substantial portions of the Software.                                        */
/*                                                                                            */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                 */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                   */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE                */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                     */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,              */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN                  */
/* THE SOFTWARE.                                                                              */
/**********************************************************************************************/

#include "avcsei.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t sei1[] = {
    0x06,
    0x04,
    0x68,
    0xB5,
    0x00,
    0x31,
    0x47,
    0x41,
    0x39,
    0x34,
    0x03,
    0xDF,
    0xFF,
    0xFC,
    0xEC,
    0xE5,
    0xFC,
    0xAE,
    0x80,
    0xFC,
    0x94,
    0x52,
    0xFC,
    0x97,
    0xA1,
    0xFC,
    0x2A,
    0x20,
    0xFC,
    0xDC,
    0x20,
    0xFC,
    0x5E,
    0x20,
    0xFC,
    0xDF,
    0x20,
    0xFC,
    0xE0,
    0x20,
    0xFC,
    0x91,
    0x38,
    0xFC,
    0x20,
    0x80,
    0xFC,
    0x91,
    0xBA,
    0xFC,
    0x20,
    0xE9,
    0xFC,
    0x13,
    0xA4,
    0xFC,
    0x20,
    0xEF,
    0xFC,
    0x13,
    0x26,
    0xFC,
    0x20,
    0x75,
    0xFC,
    0x92,
    0xBC,
    0xFC,
    0x94,
    0xF2,
    0xFC,
    0x97,
    0xA1,
    0xFC,
    0x61,
    0x80,
    0xFC,
    0x13,
    0x31,
    0xFC,
    0x20,
    0xE5,
    0xFC,
    0x92,
    0xB6,
    0xFC,
    0x20,
    0xE9,
    0xFC,
    0x92,
    0xB9,
    0xFC,
    0x20,
    0xEF,
    0xFC,
    0x13,
    0xB3,
    0xFC,
    0x20,
    0x75,
    0xFC,
    0x92,
    0x25,
    0xFC,
    0x20,
    0x80,
    0xFF,
    0x80,
};

uint8_t sei2[] = {
    0x06,
    0x04,
    0x35,
    0xB5,
    0x00,
    0x31,
    0x47,
    0x41,
    0x39,
    0x34,
    0x03,
    0xCE,
    0xFF,
    0xFC,
    0x94,
    0x26,
    0xFC,
    0x94,
    0xAD,
    0xFC,
    0x94,
    0xF2,
    0xFC,
    0x43,
    0xC1,
    0xFC,
    0xD0,
    0x54,
    0xFC,
    0x49,
    0x4F,
    0xFC,
    0xCE,
    0x20,
    0xFC,
    0x4C,
    0x49,
    0xFC,
    0xCE,
    0x45,
    0xFC,
    0xD3,
    0x20,
    0xFC,
    0x52,
    0x4F,
    0xFC,
    0x4C,
    0x4C,
    0xFC,
    0x20,
    0xD5,
    0xFC,
    0xD0,
    0x80,
    0xFF,
    0x80,
};

uint8_t sei3[] = {
    0x06,
    0x04,
    0x68,
    0xB5,
    0x00,
    0x31,
    0x47,
    0x41,
    0x39,
    0x34,
    0x03,
    0xDF,
    0xFF,
    0xFC,
    0xEC,
    0xE5,
    0xFC,
    0xAE,
    0x80,
    0xFC,
    0x94,
    0x52,
    0xFC,
    0x97,
    0xA1,
    0x00,
    0x00,
    0x03,
    0x00,
    0xFC,
    0xDC,
    0x20,
    0xFC,
    0x5E,
    0x20,
    0xFC,
    0xDF,
    0x20,
    0xFC,
    0xE0,
    0x20,
    0xFC,
    0x91,
    0x38,
    0xFC,
    0x20,
    0x80,
    0xFC,
    0x91,
    0xBA,
    0xFC,
    0x20,
    0xE9,
    0xFC,
    0x13,
    0xA4,
    0xFC,
    0x20,
    0xEF,
    0xFC,
    0x13,
    0x26,
    0xFC,
    0x20,
    0x75,
    0xFC,
    0x92,
    0xBC,
    0xFC,
    0x94,
    0xF2,
    0xFC,
    0x97,
    0xA1,
    0xFC,
    0x61,
    0x80,
    0xFC,
    0x13,
    0x31,
    0xFC,
    0x20,
    0xE5,
    0xFC,
    0x92,
    0xB6,
    0xFC,
    0x20,
    0xE9,
    0xFC,
    0x92,
    0xB9,
    0xFC,
    0x20,
    0xEF,
    0xFC,
    0x13,
    0xB3,
    0xFC,
    0x20,
    0x75,
    0xFC,
    0x92,
    0x25,
    0xFC,
    0x20,
    0x80,
    0xFF,

    0x04,
    0x68,
    0xB5,
    0x00,
    0x31,
    0x47,
    0x41,
    0x39,
    0x34,
    0x03,
    0xDF,
    0xFF,
    0xFC,
    0xEC,
    0xE5,
    0xFC,
    0xAE,
    0x80,
    0xFC,
    0x94,
    0x52,
    0xFC,
    0x97,
    0xA1,
    0x00,
    0x00,
    0x03,
    0x00,
    0xFC,
    0xDC,
    0x20,
    0xFC,
    0x5E,
    0x20,
    0xFC,
    0xDF,
    0x20,
    0xFC,
    0xE0,
    0x20,
    0xFC,
    0x91,
    0x38,
    0xFC,
    0x20,
    0x80,
    0xFC,
    0x91,
    0xBA,
    0xFC,
    0x20,
    0xE9,
    0xFC,
    0x13,
    0xA4,
    0xFC,
    0x20,
    0xEF,
    0xFC,
    0x13,
    0x26,
    0xFC,
    0x20,
    0x75,
    0xFC,
    0x92,
    0xBC,
    0xFC,
    0x94,
    0xF2,
    0xFC,
    0x97,
    0xA1,
    0xFC,
    0x61,
    0x80,
    0xFC,
    0x13,
    0x31,
    0xFC,
    0x20,
    0xE5,
    0xFC,
    0x92,
    0xB6,
    0xFC,
    0x20,
    0xE9,
    0xFC,
    0x92,
    0xB9,
    0xFC,
    0x20,
    0xEF,
    0xFC,
    0x13,
    0xB3,
    0xFC,
    0x20,
    0x75,
    0xFC,
    0x92,
    0x25,
    0xFC,
    0x20,
    0x80,
    0xFF,
    0x80,
};

// TODO make SEI with multiple messages
// TODO make SEI with emupation prevention

uint8_t* read_file(const char* file, size_t* size)
{
    FILE* f = fopen(file, "rb");

    if (!f) {
        return 0;
    }

    fseek(f, 0, SEEK_END);
    (*size) = ftell(f);
    fseek(f, 0, SEEK_SET);
    uint8_t* data = (uint8_t*)malloc(*size);

    for (int i = 0; i < (*size);) {
        i += fread(&data[i], 1, *size, f);
    }

    fclose(f);
    return data;
}

int test_emulation_byte()
{
    avcsei_t sei;
    avcsei_init(&sei);
    avcsei_parse(&sei, sei3, sizeof(sei3));
    avcsei_dump(&sei);
    avcsei_free(&sei);
}

int main(int argc, const char** argv)
{
    // test_emulation_byte();
    // return 0;

    size_t size;
    avcsei_t sei;
    cea708_t cea708;
    eia608_screen_t screen;
    char screen_buf[EIA608_SCREEN_DUMP_BUF_SIZE];
    char json_buf[EIA608_SCREEN_JSON_BUF_SIZE];

    // uint8_t* data =
    for (int i = 1; i < argc; ++i) {
        avcsei_init(&sei);
        eia608_screen_init(&screen);
        uint8_t* data = read_file(argv[i], &size);
        avcsei_parse(&sei, data, size);
        free(data);

        // avcsei_parse (&sei,sei1,sizeof (sei1));

        for (avcsei_message_t* msg = avcsei_message_head(&sei); msg; msg = avcsei_message_next(msg)) {
            if (sei_type_user_data_registered_itu_t_t35 == avcsei_message_type(msg)) {
                // avcsei_dump (&sei);
                avcsei_decode_cea708(msg, &cea708);
                int count = cea708_cc_count(&cea708.user_data);

                for (int i = 0; i < count; ++i) {
                    cea708_cc_type_t type;
                    int valid;
                    uint16_t cc_data = cea708_cc_data(&cea708.user_data, i, &valid, &type);

                    if (valid && (cc_type_ntsc_cc_field_1 == type || cc_type_ntsc_cc_field_2 == type)) {
                        eia608_screen_decode(&screen, cc_data);
                    }
                }

                // eia608_screen_dump (&screen, &screen_buf[0]);
                // printf ("screen:\n%s\n",&screen_buf[0]);

                eia608_screen_json(&screen, &json_buf[0]);
                printf("json:\n%s\n", &json_buf[0]);
            }
        }

        avcsei_free(&sei);
    }
}

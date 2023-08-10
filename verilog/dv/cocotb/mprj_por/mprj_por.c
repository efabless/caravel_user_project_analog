/*
 * SPDX-FileCopyrightText: 2023 Efabless Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <firmware_apis.h>

// --------------------------------------------------------

void main()
{
    ManagmentGpio_write(0);
    ManagmentGpio_outputEnable();
    GPIOs_writeLow(0x00000000);
    GPIOs_writeHigh(0x00000000);

    // Configure mprj_io 10 and 25 as analog (digital in/out = off)
    // Configure mprj_io 11, 12, 26, and 27 as digital output
    // mprj_io 14 to 24 are analog pads and cannot be configured
    GPIOs_configure(27, GPIO_MODE_USER_STD_OUTPUT);
    GPIOs_configure(26, GPIO_MODE_USER_STD_OUTPUT);
    GPIOs_configure(25, GPIO_MODE_USER_STD_ANALOG);

    GPIOs_configure(12, GPIO_MODE_USER_STD_OUTPUT);
    GPIOs_configure(11, GPIO_MODE_USER_STD_OUTPUT);
    GPIOs_configure(10, GPIO_MODE_USER_STD_ANALOG);

    GPIOs_loadConfigs();
    ManagmentGpio_write(1); // finish configuration

    /* Block until end of test */
    while (1);
}


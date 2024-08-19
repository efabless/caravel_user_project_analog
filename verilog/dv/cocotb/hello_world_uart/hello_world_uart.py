# SPDX-FileCopyrightText: 2023 Efabless Corporation

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#      http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# SPDX-License-Identifier: Apache-2.0


from caravel_cocotb.caravel_interfaces import test_configure
from caravel_cocotb.caravel_interfaces import report_test
import cocotb
from caravel_cocotb.caravel_interfaces import UART

@cocotb.test()
@report_test
async def hello_world_uart(dut):
    caravelEnv = await test_configure(dut,timeout_cycles=3346140)

    cocotb.log.info(f"[TEST] Start uart test")  
    expected_msg = "Hello World"
    uart = UART(caravelEnv)
    # wait for start of sending
    await caravelEnv.wait_mgmt_gpio(1)
    # read the msg sent
    msg = await uart.get_line()
    if msg in expected_msg :
        cocotb.log.info (f"[TEST] Pass recieve the full expected msg '{msg}'")
    else: 
        cocotb.log.error (f"[TEST] recieved wrong msg from uart msg recieved:'{msg}' expected '{expected_msg}'")
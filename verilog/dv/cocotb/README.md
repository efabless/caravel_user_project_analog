Overview
======== 
This directory contain tests to verify the example user project 16 bit counter and 2 other simple tests as examples. 

Prerequisites
==============

- ```bash pip install caravel-cocotb```
- update design_info.yaml

directory hierarchy
=====================

# mprj_por 

Example test for the PoR user project example 
 
 # hello_world 
 
 Example test with empty firmware that only power and reset caravel the print "Hello World" 
 
 # hello_world_uart 
 
 Example test That uses the firmware to send "Hello World" using UART TX 
 
# cocotb_tests.py 

Module that should import all the tests used to be seen for cocotb as a test

 
Run tests 
===========
# run mprj_por
    ```bash
    caravel_cocotb -t mprj_por -tag mprj_por_run 
    ```
# run hello_world_uart
    ```bash
    caravel_cocotb -t hello_world_uart -tag hello_world 
    ```

# run from different directory
    ```bash
    caravel_cocotb -t hello_world_uart -tag hello_world -design_info <path to design_info.yaml>
    ```      
# run with changing the results directory
    ```bash
    caravel_cocotb -t hello_world_uart -tag hello_world -sim  <path to results directory>
    ```  

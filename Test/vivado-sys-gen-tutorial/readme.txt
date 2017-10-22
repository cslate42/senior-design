*************************************************************************
   ____  ____ 
  /   /\/   / 
 /___/  \  /   
 \   \   \/    © Copyright 2013-2017 Xilinx, Inc. All rights reserved.
  \   \        This file contains confidential and proprietary 
  /   /        information of Xilinx, Inc. and is protected under U.S. 
 /___/   /\    and international copyright and other intellectual 
 \   \  /  \   property laws. 
  \___\/\___\ 
 
*************************************************************************

Vendor: Xilinx 
Current readme.txt Version: 1.8
Date Last Modified:  28APR2017
Date Created: 20MAR2013

Associated Filename: UG948-design-files.zip
Associated Document: UG948, Vivado Design Suite Tutorial: Model-Based DSP Design using System Generator

Supported Device(s): Kintex-7 FPGAs, Zynq-7000 SoC
   
*************************************************************************

Disclaimer: 

      This disclaimer is not a license and does not grant any rights to 
      the materials distributed herewith. Except as otherwise provided in 
      a valid license issued to you by Xilinx, and to the maximum extent 
      permitted by applicable law: (1) THESE MATERIALS ARE MADE AVAILABLE 
      "AS IS" AND WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL 
      WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, 
      INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
      NON-INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and 
      (2) Xilinx shall not be liable (whether in contract or tort, 
      including negligence, or under any other theory of liability) for 
      any loss or damage of any kind or nature related to, arising under 
      or in connection with these materials, including for any direct, or 
      any indirect, special, incidental, or consequential loss or damage 
      (including loss of data, profits, goodwill, or any type of loss or 
      damage suffered as a result of any action brought by a third party) 
      even if such damage or loss was reasonably foreseeable or Xilinx 
      had been advised of the possibility of the same.

Critical Applications:

      Xilinx products are not designed or intended to be fail-safe, or 
      for use in any application requiring fail-safe performance, such as 
      life-support or safety devices or systems, Class III medical 
      devices, nuclear facilities, applications related to the deployment 
      of airbags, or any other applications that could lead to death, 
      personal injury, or severe property or environmental damage 
      (individually and collectively, "Critical Applications"). Customer 
      assumes the sole risk and liability of any use of Xilinx products 
      in Critical Applications, subject only to applicable laws and 
      regulations governing limitations on product liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS 
FILE AT ALL TIMES.

*************************************************************************

This readme file contains these sections:

1. REVISION HISTORY
2. OVERVIEW
3. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS
4. DESIGN FILE HIERARCHY
5. INSTALLATION AND OPERATING INSTRUCTIONS
6. OTHER INFORMATION (OPTIONAL)
7. SUPPORT


1. REVISION HISTORY 


            Readme  
Date        Version      Revision Description
=========================================================================
20MAR2013   1.0          Initial Xilinx release.
19JUN2013   1.1          Updated for 2013.2 Release
02OCT2013   1.2          Updated for 2013.3 Release
28OCT2014   1.3          Updated for 2014.3 Release
06AUG2015   1.4          Updated for 2015.1 Release
12OCT2015   1.5          Updated for 2015.3 Release
20MAY2016   1.6          Updated for 2016.1 Release
25OCT2016   1.7          Updated for 2016.3 Release 
28APR2017   1.8          Updated for 2017.1 Release
=========================================================================



2. OVERVIEW

This readme describes how to use the files that come with UG948, the Vivado System Generator Tutorial.

In the tutorial, you will do the following:


  Lab 1: Understand how to create and validate a model using System Generator. 
	 Make use of workspace variables to easily parameterize your models.
	 Synthesize the model into FPGA hardware, and then create a more optimal hardware version of the design.  
	 Learn how fixed-point data types can be used to trade off accuracy against hardware area and performance.

  Lab 2: Learn Modeling Control System with M-Code, incorporating existing RTL designs, written in Verilog or VHDL,
         into your design and Import C/C++ source files into a System Generator model by leveraging the tool integration with HLS.

  Lab 3: Learn how to do Timing and Resource Analysis and how to overcome timing violations.

  Lab 4: Learn how to create an efficient design using multiple clock domains.

  Lab 5: Use AXI interfaces and Vivado IP integrator to easily include your model into a larger design.

  Lab 6: Integrate your design into a larger system and operate the design under CPU control.


3. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS

* Xilinx Vivado 2017.1 or higher
* MATLAB R2017a,R2016b, or R2016a

4. DESIGN FILE HIERARCHY


The directory structure underneath this top-level folder is described 
below:

\SysGen_Tutorial
 |   This folder contains a directory for the files used in each of the nine (9) labs in this Tutorial. 
 | 
 |
 +-----  \Lab1
 |       Contains the files necessary to perform Lab1.
 | 
 |           +--\solution
 |              Contains the files used or generated while performing Lab1,
 |              as they appear at the end of the lab procedure.  
 |
+-----  \Lab2
 |       Contains the files necessary to perform Lab2.
 | 
 |
 |           +--\M_code
 |           Contains the files necessary to perform lab2/M_code           
 |	     	  
 |		  +--\solution
 |                Contains the files used or generated while performing Lab2/M_code,
 |                as they appear at the end of the lab procedure. 
 |
 |           +--\HDL 
 |           Contains the files necessary to perform lab2/HDL           
 |	     	  
 |                +--\solution
 |                Contains the files used or generated while performing Lab2/HDL,
 |                as they appear at the end of the lab procedure. 
 
 |           +--\C_code      
 |           Contains the files necessary to perform lab2/C_code           
 |	     	  
 |                +--\solution
 |              	Contains the files used or generated while performing Lab2/C_code,
 |              	as they appear at the end of the lab procedure.
 |                +--\hls_project
 |                      Contains the Vivado HLS project that generates a design incorporated as a block into the Lab2_3 Matlab design.
 |
 +-----  \Lab3
 |       Contains the files necessary to perform Lab3.
 | 
 |           +--\solution
 |              Contains the files used or generated while performing Lab3, as they appear at the end of the lab procedure.  
 ||
 +-----  \Lab4
 |       Contains the files necessary to perform Lab4.
 | 
 |           +--\solution
 |              Contains the files used or generated while performing Lab4,
 |              as they appear at the end of the lab procedure.  
 ||
 +-----  \Lab5
 |       Contains the files necessary to perform Lab5.
 | 
 |           +--\solution
 |              Contains the files used or generated while performing Lab5,
 |              as they appear at the end of the lab procedure.  
 ||
 |
 +-----  \Lab6
 |       Contains the files necessary to perform Lab6.
 | 
 |           +--\solution
 |              Contains the files used or generated while performing Lab6,
 |              as they appear at the end of the lab procedure.  
 | 
 |           +--\IPI_Project
 |              Contains Tcl files used to create a Vivado project, create an IPI design based on a System Generator design,
 |              and build the implementation which is then used in Lab6.  
 

5. INSTALLATION AND OPERATING INSTRUCTIONS 


1) Install the Xilinx Vivado 2017.1 or later tools.
2) Configure MATLAB to this version of the Vivado tools.
3) Extract the tutorial design files in ug948-design-files.zip to a write-accessible location on your hard drive or network location.



6. OTHER INFORMATION 

   N/A


7. SUPPORT

To obtain technical support for this reference design, go to 
www.xilinx.com/support to locate answers to known issues in the Xilinx
Answers Database or to create a WebCase.  
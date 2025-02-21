 # 📜 Spectral_Analyzer_Zedboard_S8

Spectral_Analyzer_Zedboard_S8 is a co-design and architecture project. The project aims to design and implement a real-time spectrum analyzer using a Zedboard FPGA and Vivado for hardware development.

The system processes audio signals through an I2S interface, stores data in DDR memory, performs FFT computation, and displays the frequency spectrum on a VGA screen. The data transfer between components is managed via DMA, optimizing performance.

## 📋 The project includes:

  **+** RTL development and simulation using Xilinx tools
  **+** Bare-metal prototyping for low-level validation
  **+** Linux driver development to interface with FPGA components
  **+** Application development on an embedded Linux system using Buildroot

This project leverages hardware acceleration on FPGA to perform efficient spectral analysis, demonstrating an optimized hardware-software codesign approach.

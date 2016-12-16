#!/bin/bash
sudo apt-get install pandoc
sudo apt-get install doxygen
git clone https://github.com/pmem/nvml.git
cd nvml
make
sudo make install

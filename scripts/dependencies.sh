#!/bin/bash
sudo apt-get install pandoc
git clone https://github.com/pmem/nvml.git
cd nvml
make
sudo make install

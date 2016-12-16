#!/bin/bash
sudo apt-get install pandoc
sudo apt-get install doxygen
git clone https://github.com/pmem/nvml.git
cd nvml
make
sudo make install
cd ..
git clone https://github.com/mongodb/mongo.git
cd mongo
mkdir -p src/mongo/db/modules/
ln -sf ~/pmse src/mongo/db/modules/pmse
ls src/mongo/db/modules/pmse


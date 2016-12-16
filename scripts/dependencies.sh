#!/bin/bash
#sudo apt-get install pandoc
#sudo apt-get install doxygen
pwd
ls
#git clone https://github.com/pmem/nvml.git
#cd nvml
#make
#sudo make install
#cd ..
cd ..
git clone https://github.com/mongodb/mongo.git
cd mongo
mkdir -p src/mongo/db/modules/
#pwd
#ls
#cd src/mongo/db/modules/
#pwd
#ls
cd ..
cp -r pmse mongo/src/mongo/db/modules/
ls
cd mongo/src/mongo/db/modules/pmse
pwd
ls
cd ../../../../..



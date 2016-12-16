#!/bin/bash
#sudo apt-get install scons
wget http://mirrors.kernel.org/ubuntu/pool/main/s/scons/scons_2.3.0-2_all.deb
sudo dpkg -i scons_2.3.0-2_all.deb
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update -qq

sudo apt-get install -qq g++-5
sudo apt-get install -qq gcc-5
gcc --version
g++ --version


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



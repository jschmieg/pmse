#!/bin/bash
pwd
cd ../mongo
scons -j3 LIBPATH=/usr/local/lib core

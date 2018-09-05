#!/bin/bash

cd matrix_c
find . -type f -name '*.o' -delete
rm -rf matexp
cd ../
rm -rf matrix_c_build
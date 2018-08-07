#!/bin/sh

# Set our EMSDK Environment Variables
source ./../../emscripten/emsdk/emsdk_env.sh

PROJECT_VARIANT=$1

# COMPILE OUR ASM VARIANT OF THE CODE
# -------------------------------------------------------------------------
PROJECT="delaunay_asm"
PROJECT_BUILD=${PROJECT}"_build"

cd ${PROJECT}
yes | sudo emmake make ${PROJECT_VARIANT}
cd ../

# create our required directory if it doesn't exist
mkdir ${PROJECT_BUILD}

# copy our generated/compiled files
cp ${PROJECT}/${PROJECT_VARIANT}.html ${PROJECT_BUILD}/${PROJECT_VARIANT}.html
cp ${PROJECT}/${PROJECT_VARIANT}.html.mem ${PROJECT_BUILD}/${PROJECT_VARIANT}.html.mem
cp ${PROJECT}/${PROJECT_VARIANT}.js ${PROJECT_BUILD}/${PROJECT_VARIANT}.js

# copy our runner
cp runner.sh ${PROJECT_BUILD}/run.sh
# -------------------------------------------------------------------------

# COMPILE OUR WASM VARIANT OF THE CODE
# -------------------------------------------------------------------------
PROJECT="delaunay_wasm"
PROJECT_BUILD=${PROJECT}"_build"

cd ${PROJECT}
yes | sudo emmake make ${PROJECT_VARIANT}
cd ../

# create our required directory if it doesn't exist
mkdir ${PROJECT_BUILD}

# copy our generated/compiled files
cp ${PROJECT}/${PROJECT_VARIANT}.html ${PROJECT_BUILD}/${PROJECT_VARIANT}.html
cp ${PROJECT}/${PROJECT_VARIANT}.wasm ${PROJECT_BUILD}/${PROJECT_VARIANT}.wasm
cp ${PROJECT}/${PROJECT_VARIANT}.js ${PROJECT_BUILD}/${PROJECT_VARIANT}.js

# copy our runner
cp runner.sh ${PROJECT_BUILD}/run.sh
# -------------------------------------------------------------------------

# COMPILE OUR ORIGINAL CODE
# -------------------------------------------------------------------------
PROJECT="delaunay_original"
PROJECT_BUILD=${PROJECT}"_build"

cd ${PROJECT}
yes | sudo make ${PROJECT_VARIANT}
cd ../

# create our required directory if it doesn't exist
mkdir ${PROJECT_BUILD}
# -------------------------------------------------------------------------
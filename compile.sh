#!/bin/sh

# Set our EMSDK Environment Variables
source ./../../emscripten/emsdk/emsdk_env.sh

# perform cleanup
source ./clean.sh

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
cp -f ${PROJECT}/${PROJECT_VARIANT}.html ${PROJECT_BUILD}/${PROJECT_VARIANT}.html
cp -f ${PROJECT}/${PROJECT_VARIANT}.html.mem ${PROJECT_BUILD}/${PROJECT_VARIANT}.html.mem
cp -f ${PROJECT}/${PROJECT_VARIANT}.html.map ${PROJECT_BUILD}/${PROJECT_VARIANT}.html.map
cp -f ${PROJECT}/${PROJECT_VARIANT}.js ${PROJECT_BUILD}/${PROJECT_VARIANT}.js

# copy our runner
cp -f runner.sh ${PROJECT_BUILD}/run.sh

# perform cleanup
cd ${PROJECT}
find . -type f -name '*.o' -delete
find . -type f -name '*.html' -delete
find . -type f -name '*.wasm' -delete
find . -type f -name '*.js' -delete
find . -type f -name '*.mem' -delete
find . -type f -name '*.map' -delete
cd ../
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
cp -f ${PROJECT}/${PROJECT_VARIANT}.html ${PROJECT_BUILD}/${PROJECT_VARIANT}.html
cp -f ${PROJECT}/${PROJECT_VARIANT}.wasm ${PROJECT_BUILD}/${PROJECT_VARIANT}.wasm
cp -f ${PROJECT}/${PROJECT_VARIANT}.js ${PROJECT_BUILD}/${PROJECT_VARIANT}.js

# copy our runner
cp -f runner.sh ${PROJECT_BUILD}/run.sh

# perform cleanup
cd ${PROJECT}
find . -type f -name '*.o' -delete
find . -type f -name '*.html' -delete
find . -type f -name '*.wasm' -delete
find . -type f -name '*.js' -delete
find . -type f -name '*.mem' -delete
find . -type f -name '*.map' -delete
cd ../
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

cp -f ${PROJECT}/${PROJECT_VARIANT} ${PROJECT_BUILD}/${PROJECT_VARIANT}

cd ${PROJECT}
find . -type f -name '*.o' -delete
rm -rf dct
cd ../
# -------------------------------------------------------------------------
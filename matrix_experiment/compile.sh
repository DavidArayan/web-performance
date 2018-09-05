#!/bin/bash

# Set our EMSDK Environment Variables
source ./../emscripten/emsdk/emsdk_env.sh

# perform cleanup
source ./clean.sh
source ./copy-sources.sh

PROJECT_VARIANT="matexp"

# COMPILE OUR ORIGINAL CODE
# -------------------------------------------------------------------------
PROJECT="matrix_c"
PROJECT_BUILD=${PROJECT}"_build"

cd ${PROJECT}
make ${PROJECT_VARIANT}
cd ../

# create our required directory if it doesn't exist
mkdir ${PROJECT_BUILD}

cp -f ${PROJECT}/${PROJECT_VARIANT} ${PROJECT_BUILD}/${PROJECT_VARIANT}
# -------------------------------------------------------------------------
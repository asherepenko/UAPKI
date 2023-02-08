#!/bin/bash

if [[ "$OSTYPE" == "darwin"* ]]; then
    CORES=$((`sysctl -n hw.logicalcpu`+1))
else
    CORES=$((`nproc`+1))
fi

ANDROID_TOOLCHAIN=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake
ANDROID_PLATFORM=23

for ANDROID_ABI in "arm64-v8a" "x86_64" "x86" "armeabi-v7a"; do

  BUILD_DIR=./build/$ANDROID_ABI
  DEFINE_PARAMS="-DCMAKE_SYSTEM_NAME=Android -DCMAKE_TOOLCHAIN_FILE=$ANDROID_TOOLCHAIN -DANDROID_PLATFORM=$ANDROID_PLATFORM -DANDROID_ABI=$ANDROID_ABI"

  mkdir -p $BUILD_DIR

  cmake -S . -B $BUILD_DIR $DEFINE_PARAMS
  cmake --build $BUILD_DIR --config Release -j $CORES
done

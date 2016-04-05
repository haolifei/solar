#!/bin/bash
./build_deps.sh
echo "-->(1/3), start to install deps ..."
if [ $? -ne 0 ]; then
    echo "fail to install deps!!!"
    exit 1
fi
echo "-->(2/3) gen protobuf header ..."
thirdparty/bin/protoc --proto_path=./src/protocol/ --cpp_out=./src/protocol/ src/protocol/*.proto

echo "-->(3/3) call scons to build project"


scons


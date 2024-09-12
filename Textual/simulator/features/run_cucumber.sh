#!/bin/bash

# make sure the tag is unique
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]')
WORKDIR=/usr/software
echo "building container, please wait (the first time this may take several minutes) ..."
docker build -t $TAG .
docker run \
	--rm \
	--name cucumber_$(date +%s) \
	--volume "${PWD}/../../..":${WORKDIR} \
	--workdir ${WORKDIR}/Textual/simulator/features \
	-it $TAG \
	bash -c "cmake . && cmake --build . && (./simulator_steps >/dev/null &) && cucumber ."

#!/bin/bash
# set -x

PLATFORM=`uname -m`"_"`uname -s`

error () {
    echo "ERROR:"
    tail -n 5 build.log
    exit 1
}

# make c compiler
echo "Making CC for ${PLATFORM} .."
cd compiler || exit 1
make "ARCH=${PLATFORM}" all >> ../build.log || error
cd .. || exit 1

if test -z "${1}" ; then
    echo No file specified, exiting
    exit 0
fi

#compile
echo "Running CC, '${1}' .."
cp "./compiler/arch/${PLATFORM}/header.s"  "./program.s" || exit 1
cc -E "${1}" | grep -v '^#' | ./compiler/cc >> "./program.s" 2>> build.log || error
cat "./compiler/arch/${PLATFORM}/footer.s" >> "./program.s" || exit 1

gcc -c -o "./program.o" "./program.s" 2>> build.log || error
ld -o program.bin "./program.o" 2>> build.log || error

echo "SUCCESS"
exit 0


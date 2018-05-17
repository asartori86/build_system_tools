#!/bin/bash

# takes at lease three arguments:
# 1. the executable to run
# 2. the reference output file
# 3. all the needed arguments

_exe=$1; shift
_ref=$1; shift
_rest=$@

_generated=$(basename $_ref)

$_exe $_rest > $_generated

# test if run was successfull
if [[ $? -ne 0 ]]
then
    echo "run failed"
    exit 1
fi

diff $_ref $_generated

# test if diff was successfull
if [[ $? -ne 0 ]]
then
    echo "diff failed"
    exit 1
fi

exit 0



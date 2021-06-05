#!/bin/bash
pvs-studio-analyzer trace -- make > /dev/null
pvs-studio-analyzer analyze > /dev/null 2> /dev/null
plog-converter -a '64:1,2,3;GA:1,2,3;OP:1,2,3' -t tasklist -o report.tasks PVS-Studio.log  > /dev/null
rm -f strace_out
rm -f PVS-Studio.log
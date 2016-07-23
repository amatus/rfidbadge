#!/usr/bin/env python

import sys

for line in sys.stdin.readlines():
    if line[0] != ':':
        break
    line = line[1:]
    length = int(line[0:2], 16)
    record_type = int(line[6:8],16)
    if record_type != 0:
        break
    for x in range(length / 2):
        sys.stdout.write("0x" + line[x * 4 + 10:x * 4 + 12] + line[x * 4 + 8:x * 4 + 10] + ",")
    sys.stdout.write("\n")

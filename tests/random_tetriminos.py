#!/usr/bin/python
from __future__ import print_function
import sys, random, os

if (len(sys.argv) != 2):
    print("Please provide one argument.")
    sys.exit()
print ("Generating file with %s random tetriminos: " % sys.argv[1], end="")
os.chdir('tetriminos')
ttmns = os.listdir('.')
n_ttmns = len(ttmns)
rand_ind = [random.randrange(0, n_ttmns - 1) for _ in range(int(sys.argv[1]))]
# for i in indexes:
#     print(ttmns[i].rstrip(), end="")
rand_ttmns = [ttmns[i].rstrip() for i in rand_ind]
print(', '.join(rand_ttmns))
command = "cat "+' '.join(rand_ttmns)+" | awk '1; NR % 4 == 0 {print \"\"}' | sed '$ d' > ../ttmnfile"
# print(command)
os.system(command)

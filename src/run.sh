# Build on all cores with the Makefile & start the game

#!/bin/bash

echo -e "** Building **\n"
make -j
echo -e "\n** Starting game... **\n"
./drunkrun

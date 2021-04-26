# Build on all cores with the Makefile & start the game

#!/bin/bash

echo "** Building **\n"
make -j
echo "\n** Launching game... **\n"
./drunkrun

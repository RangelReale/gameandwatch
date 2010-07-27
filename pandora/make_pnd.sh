#!/bin/sh

rm -Rf build

mkdir -p build/gameandwatch
mkdir -p build/gameandwatch/bin
mkdir -p build/gameandwatch/doc
mkdir -p build/gameandwatch/data
mkdir -p build/gameandwatch/data/gamewatch
mkdir -p build/gameandwatch/lib

cp ../src/gameandwatch build/gameandwatch/bin
cp ../res/gameandwatch.png build/gameandwatch/data
cp ../doc/README.pandora build/gameandwatch/doc/README.pandora.txt
cp gameandwatch/PXML.xml build/gameandwatch
cp gameandwatch/bin/gameandwatch_run.sh build/gameandwatch/bin
chmod +x build/gameandwatch/bin/gameandwatch_run.sh
cp ../data/gamewatch/*.ttf build/gameandwatch/data/gamewatch
cp ../data/pancake.zip ../data/condor.zip ../data/pirate.zip ../data/defendo.zip ../data/monkey.zip ../data/rollerc.zip build/gameandwatch/data
cp $SDK_PATH_TARGET/lib/libzzip-0.so.13 build/gameandwatch/lib

pnd_make.sh -p gameandwatch_0.3-0.pnd -d build/gameandwatch -x build/gameandwatch/PXML.xml -i build/gameandwatch/data/gameandwatch.png

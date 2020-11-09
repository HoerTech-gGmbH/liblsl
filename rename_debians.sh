#!/bin/bash
SOURCES=`(cd build && echo *.deb)`
CODENAME=`lsb_release -sc`
CODEVER=`lsb_release -si``lsb_release -sr`
COMMITCNT=`git log --pretty='format:%h'|wc -l`
COMMITHASH=`git log -1 --abbrev=7 --pretty='format:%h'`
ARCH=`dpkg-architecture --query DEB_BUILD_ARCH`
for SOURCE in ${SOURCES}; do
    VERSION=`echo ${SOURCE} | sed -e 's/[^0-9]*\([0-9\.]*\).*/\1/1'`
    echo ver = $VERSION
    FULLVERSION=${VERSION}-${COMMITCNT}-${COMMITHASH}-${CODEVER}
    TARGET="build/pack/${CODENAME}/liblsl_${FULLVERSION}_${ARCH}.deb"
    mkdir -p build/pack/${CODENAME}
    (
	cd build &&
	    dpkg-deb -x "${SOURCE}" debian &&
	    dpkg-deb -e "${SOURCE}" debian/DEBIAN &&
            (cd debian/usr/lib && ln -s liblsl*.so liblsl.so) &&
	    sed -i -e "s/^Version: .*/Version: ${FULLVERSION}/1" \
		-e "s/^Maintainer: .*/Maintainer: openMHA Packaging Team <packaging@openMHA.org>/" \
		-e '/^Description: / i Replaces: liblsl, liblsl-dev\
Provides: liblsl, liblsl-dev\
Conflicts: liblsl (<< 1.13.0), liblsl-dev (<< 1.13.0)' \
		debian/DEBIAN/control &&
	    dpkg-deb -b debian "../${TARGET}"
    )
done

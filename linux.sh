#!/bin/bash
HERE="$(dirname "$(readlink -f "${0}")")"
export PATH="${HERE}/usr/bin:${PATH}"

sudo apt-get update && sudo apt-get install -y libglfw3-dev libglew-dev

cd "${HERE}/usr/share/SolarSystem"

exec SolarSystem "$@"
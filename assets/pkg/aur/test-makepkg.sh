#/usr/bin/env bash
set -e

MYSELF=$(realpath "$0")
MYDIR=$(dirname "$MYSELF")

for pkg in "$MYDIR"/*/; do
    cd "$pkg"
    printf "\x1b[1mEntering '%s'\x1b[0m\n" "$pkg"

    rm -rf *.{gz,zst} src pkg
    makepkg -f .

    echo
done

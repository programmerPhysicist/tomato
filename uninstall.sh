#!/bin/bash

echo "Uninstalling tomato..."

if [ $(id -u) -ne 0 ]
then
    rm -rf $HOME/tomato
else
    rm -f /usr/bin/tomato
    rm -rf /usr/local/share/tomato
fi

echo "Finished uninstalling."

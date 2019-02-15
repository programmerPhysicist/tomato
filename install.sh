#!/bin/bash

if [ $(id -u) -ne 0 ]
then
    echo "Installing tomato as local user $USER..."

    echo "Creating application directory..."
    mkdir -p $HOME/tomato

    echo "Copying executable to app folder..."
    if [ -e bin/tomato ]
    then
	cp bin/tomato $HOME/tomato
	echo "Copied executable."
    else
	echo "Unable to find executable. Please run make."
	exit
    fi

    echo "Installing configuration file..."
    if [ -e $HOME/.tomato ]
    then
	echo "Configuration file already exists."
    else
	cp src/resources/example.tomato $HOME/.tomato
	echo "Installed configuration file."
    fi

    echo "Copying resources to app folder..."
    cp -r src/resources/sounds/ $HOME/tomato
    echo "Done."
    echo "Please set bin path to $HOME/tomato/"

else
    echo "Installing tomato as root..."
    echo "Copying executable to bin..."
    if [ -e bin/tomato ]; then
	cp bin/tomato /usr/bin/
	echo "Copied executable to /usr/bin/"
    else
	echo "Unable to find executable. Please run make."
	exit
    fi
    
    echo "Creating config file for each user..."
    DIRS=$(find /home/* -maxdepth 0 -type d ! -path /home/lost+found)
    for DIR in $DIRS
    do
	echo "Copying to $DIR..."
	if [ -e $DIR/.tomato ] 
	then
	    cp src/resources/example.tomato $DIR/.tomato
	fi
    done
    if [ -e /root/.tomato ]
    then
	cp src/resources/example.tomato /root/.tomato
    fi

    echo "Creating application directory..."
    mkdir /usr/local/share/tomato
    echo "Copying resources to app directory..."
    cp -r src/resources/sounds/ /usr/local/share/tomato
    echo "Finished."
fi


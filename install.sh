#!/bin/bash

if [ -e bin/tomato ] 
then
    EX_PATH=bin/tomato
    RES_PATH=src/resources
elif [ -e tomato ] 
then
    EX_PATH=tomato
    RES_PATH=resources 
else
    echo "Unable to find executable. Please run make."
    exit
fi

if [ $(id -u) -ne 0 ]
then
    echo "Installing tomato as local user $USER..."

    echo "Creating application directory..."
    mkdir -p $HOME/tomato

    echo "Copying executable to app folder..."
    cp $EX_PATH $HOME/tomato
    echo "Copied executable."

    echo "Installing configuration file..."
    if [ -e $HOME/.tomato ]
    then
	echo "Configuration file already exists."
    else
	cp $RES_PATH/example.tomato $HOME/.tomato
	echo "Installed configuration file."
    fi

    echo "Copying resources to app folder..."
    cp -r $RES_PATH/sounds/ $HOME/tomato
    echo "Done."
    echo "Please set bin path to $HOME/tomato/"

else
    echo "Installing tomato as root..."
    echo "Copying executable to bin..."
    cp $EX_PATH /usr/bin/
    echo "Copied executable to /usr/bin/"
    
    echo "Creating config file for each user..."
    DIRS=$(find /home/* -maxdepth 0 -type d ! -path /home/lost+found)
    for DIR in $DIRS
    do
	echo "Copying to $DIR..."
	if [ -e $DIR/.tomato ] 
	then
	    cp $RES_PATH/example.tomato $DIR/.tomato
	fi
    done

    echo "Creating application directory..."
    mkdir /usr/local/share/tomato
    echo "Copying resources to app directory..."
    cp -r $RES_PATH/sounds/ /usr/local/share/tomato
    echo "Finished."
fi


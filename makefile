#Main makefile for project

#Get root compile directory
ROOT_TOMATO = $(shell pwd)
export ROOT_TOMATO

All:
	$(MAKE) -C src

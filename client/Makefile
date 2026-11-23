NAME		?=	client
ENV			?=	../.env


PACKAGES	=	

TARGETS		=	

SRC			=	main	\

COMMON		=	


all: build

configure:
	@cmake							\
		-B build 					\
		-DNAME="$(NAME)"			\
		-DENV="$(ENV)"				\
		-DPACKAGES="$(PACKAGES)"	\
		-DTARGETS="$(TARGETS)"		\
		-DSRC="$(SRC)"				\
		-DCOMMON="$(COMMON)"		\

build: configure
	@cmake --build build

clean:
	@rm -dfr build

re: clean build


.PHONY: all configure build clean re

#*******************************************************************************
# File name        : makefile
# File description : C
# Author           : ronyett
#*******************************************************************************

SRC_DIR			= 	.
OBJECT_DIR		= 	$(SRC_DIR)/object
MAKE_DIR_CMD		= 	mkdir $(OBJECT_DIR)

CC  			= 	gcc
LINK  			= 	gcc
AR			= 	ar
CHK   			= 	checkmk
CHECK_FOR_CHK		:= 	$(shell command -v $(CHK) 2> /dev/null)

#*******************************************************************************
# Build options
#*******************************************************************************

# gcov and gprof build options
COVPFLAGS		= 	-fprofile-arcs -ftest-coverage
PROFLAGS		= 	-pg
#PFLAGS			= 	$(COVFLAGS)

# Main CC and Link build strings
DEBUG			= 	-g
CFLAGS			= 	-c -std=c99 -Wall -pedantic $(PFLAGS)
LFLAGS			= 	$(PFLAGS) -static -L.

# -DDEBUG_TRACE	Will turn on deep trace per function
# -DEXCEPTION	Will use the real exceptions with the 'try' that's in the test harness

#
# Code checking with splint
#
CODE_CHECK       	= 	splint
CODE_CHECK_ARGS	 	= 	-showfunc -mustfreefresh -nullpass -nullret -noeffect

#
# codespell
CODE_SPELL		= 	codespell
CODE_SPELL_ARGS		= 	--skip "*.a,*.o,*.exe,./.git"
CHECK_FOR_CODESPELL	:=	$(shell command -v $(CODE_SPELL) 2> /dev/null)

#
# Libs, objs targets
# libstack library is built from trap handling and the stack implementation. 
#
OBJS  		     	=	$(OBJECT_DIR)/flicks.o		\
		       		$(OBJECT_DIR)/progress.o

LIBS  		     	= 	

TEST_STACK 	     	= 	

#*******************************************************************************
# Build targets:
# all		Creates object directory, builds executable and runs checker
# lib		Build only the list library, n
# splint-it	run the Syntax checker
# clean		Delete object and library files
#*******************************************************************************

all:	$(OBJECT_DIR) flicker.exe progress.exe spelling-bee

lib:	$(LIBS)

flicker.exe:	$(OBJECT_DIR)/flicks.o
	$(LINK) $(OBJECT_DIR)/flicks.o $(LFLAGS) -o flicker.exe
progress.exe:	$(OBJECT_DIR)/progress.o
	$(LINK) $(OBJECT_DIR)/progress.o $(LFLAGS) -o progress.exe

$(OBJECT_DIR):
	-$(MAKE_DIR_CMD)

$(OBJECT_DIR)/flicks.o:		flicks.c
	$(CC) $(CFLAGS) $(DEBUG) flicks.c -o $(OBJECT_DIR)/flicks.o
$(OBJECT_DIR)/progress.o:	progress.c
	$(CC) $(CFLAGS) $(DEBUG) progress.c -o $(OBJECT_DIR)/progress.o

#
# Code checking target
#
splint-it:
	$(CODE_CHECK) $(CODE_CHECK_ARGS) flicks.c
	$(CODE_CHECK) $(CODE_CHECK_ARGS) progress.c   

spelling-bee:
ifndef CHECK_FOR_CODESPELL
	@echo "** codespell was not found"
else
	$(CODE_SPELL) $(CODE_SPELL_ARGS)
endif

clean:
	rm -f flicker.exe
	rm -f progress..exe
	rm -f $(OBJECT_DIR)/flicks.o
	rm -f $(OBJECT_DIR)/progress.o
	rm -f *.gcno
	rm -f *.gcda
	rm -f gmon.out
	rm -f core

#
# Fin
#


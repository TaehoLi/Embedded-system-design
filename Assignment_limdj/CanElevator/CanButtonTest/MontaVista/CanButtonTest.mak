
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug=-g
CPPCompileRelease=-O
LinkDebug=-g
LinkRelease=-O

ConfigurationCPPCompileSwitches=   -I. -I. -I$(OMROOT) -I$(OMROOT)/LangCpp -I$(OMROOT)/LangCpp/oxf $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) -DUSE_IOSTREAM $(CPPCompileDebug) -c 

#########################################
###### Predefined macros ################
CPU=arm-none-linux-gnueabi
CC=arm-none-linux-gnueabi-gcc
LIB_CMD=arm-none-linux-gnueabi-ar
LIB_PREFIX=mvl
RM=rm -rf
MD=mkdir -p

INCLUDE_QUALIFIER=-I

LINK_CMD=$(CC)
LIB_FLAGS=rvu

LINK_FLAGS=-lpthread -lstdc++ $(LinkDebug)  

#########################################
####### Context macros ##################

FLAGSFILE=
RULESFILE=
OMROOT="/home/control/Rhapsody753/Share"

CPP_EXT=.cpp
H_EXT=.h
OBJ_EXT=.o
EXE_EXT=
LIB_EXT=.a

INSTRUMENTATION=None

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=CanButtonTest

all : $(TARGET_NAME)$(EXE_EXT) CanButtonTest.mak

TARGET_MAIN=MainCanButtonTest

LIBS=

INCLUDE_PATH= \
  $(INCLUDE_QUALIFIER)$(OMROOT)/LangCpp/osconfig/Linux

ADDITIONAL_OBJS=

OBJS= \
  ReceiveMessageObj.o \
  ElevatorControl.o \
  CanButton.o \
  can_interface.o




#########################################
####### Predefined macros ###############
$(OBJS) :  $(INST_LIBS) $(OXF_LIBS)

OBJ_DIR=

ifeq ($(OBJ_DIR),)
CREATE_OBJ_DIR=
CLEAN_OBJ_DIR=
else
CREATE_OBJ_DIR= $(MD) $(OBJ_DIR)
CLEAN_OBJ_DIR=  $(RM) $(OBJ_DIR)
endif


ifeq ($(INSTRUMENTATION),Animation)

INST_FLAGS=-DOMANIMATOR
INST_INCLUDES=-I$(OMROOT)/LangCpp/aom -I$(OMROOT)/LangCpp/tom
INST_LIBS= $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)aomanimarm-none-linux-gnueabi$(LIB_EXT)
OXF_LIBS=$(OMROOT)/LangCpp/lib/$(LIB_PREFIX)oxfinstarm-none-linux-gnueabi$(LIB_EXT) $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)omcomapplarm-none-linux-gnueabi$(LIB_EXT)
SOCK_LIB=

else
ifeq ($(INSTRUMENTATION),Tracing)

INST_FLAGS=-DOMTRACER
INST_INCLUDES=-I$(OMROOT)/LangCpp/aom -I$(OMROOT)/LangCpp/tom
INST_LIBS=$(OMROOT)/LangCpp/lib/$(LIB_PREFIX)tomtracearm-none-linux-gnueabi$(LIB_EXT) $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)aomtracearm-none-linux-gnueabi$(LIB_EXT)
OXF_LIBS= $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)oxfinstarm-none-linux-gnueabi$(LIB_EXT) $(OMROOT)/LangCpp/lib/$(LIB_PREFIX)omcomapplarm-none-linux-gnueabi$(LIB_EXT)
SOCK_LIB=

else
ifeq ($(INSTRUMENTATION),None)

INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
OXF_LIBS=$(OMROOT)/LangCpp/lib/$(LIB_PREFIX)oxfarm-none-linux-gnueabi$(LIB_EXT)
SOCK_LIB=

else
	@echo An invalid Instrumentation $(INSTRUMENTATION) is specified.
	exit
endif
endif
endif

.SUFFIXES: $(CPP_EXT)



#####################################################################
##################### Context dependencies and commands #############






ReceiveMessageObj.o : ReceiveMessageObj.cpp ReceiveMessageObj.h    CanButton.h ElevatorControl.h 
	@echo Compiling ReceiveMessageObj.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o ReceiveMessageObj.o ReceiveMessageObj.cpp




ElevatorControl.o : ElevatorControl.cpp ElevatorControl.h    CanButton.h ReceiveMessageObj.h 
	@echo Compiling ElevatorControl.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o ElevatorControl.o ElevatorControl.cpp




CanButton.o : CanButton.cpp CanButton.h    ReceiveMessageObj.h ElevatorControl.h 
	@echo Compiling CanButton.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o CanButton.o CanButton.cpp




can_interface.o : can_interface.cpp     
	@echo Compiling can_interface.cpp
	$(CREATE_OBJ_DIR)
	@$(CC) $(ConfigurationCPPCompileSwitches)  -o can_interface.o can_interface.cpp







$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) 
		@$(CC) $(ConfigurationCPPCompileSwitches) -o  $(TARGET_MAIN)$(OBJ_EXT) $(TARGET_MAIN)$(CPP_EXT)

####################################################################################
#                    Predefined linking instructions                               #
# INST_LIBS is included twice to solve bi-directional dependency between libraries #
####################################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) CanButtonTest.mak 
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	@$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(INST_LIBS) \
	$(SOCK_LIB) \
	$(LINK_FLAGS) -o $(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) CanButtonTest.mak
	@echo Building library $@
	@$(LIB_CMD) $(LIB_FLAGS) $(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS) $(LIBS)



clean:
	@echo Cleanup
	$(RM) ReceiveMessageObj.o
	$(RM) ElevatorControl.o
	$(RM) CanButton.o
	$(RM) can_interface.o
	$(RM) $(TARGET_MAIN)$(OBJ_EXT) $(ADDITIONAL_OBJS)
	$(RM) $(TARGET_NAME)$(LIB_EXT)
	$(RM) $(TARGET_NAME)$(EXE_EXT)
	$(CLEAN_OBJ_DIR)

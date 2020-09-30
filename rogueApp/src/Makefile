TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
# ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

LIBRARY_IOC = rogueRegister
#DBD += pgpCamlinkSupport.dbd
#DBD += pgpClSerialDev.dbd
DBD += rogueRecords.dbd
DBD += rogueSupport.dbd

# TODO: Rethink naming scheme for C++ classes
LIB_SRCS   		+= rogueDev.cpp
LIB_SRCS   		+= pgpRogueLib.cpp
LIB_SRCS		+= rogueRecords.cpp

#LIB_SRCS   		+= pgpCamlink.cpp
#LIB_SRCS		+= ClSerialMaster.cpp
#LIB_SRCS		+= ClSerialSlave.cpp
LIB_SRCS		+= ClStreamSlave.cpp
LIB_SRCS		+= ImageStream.cpp
LIB_SRCS		+= pgpClDev.cpp
#LIB_SRCS		+= pgpClSerialDev.cpp
#LIB_SRCS		+= asynPgpClSerial.cpp

#LIB_LIBS		+= asyn
#LIB_LIBS		+= $(EPICS_BASE_IOC_LIBS)
#pgpCamlink_LIBS		+= asyn
#pgpCamlink_LIBS		+= $(EPICS_BASE_IOC_LIBS)
LIB_INSTALLS_Linux += $(wildcard $(ROGUE_LIB)/lib*)

HOST_OPT = NO
USR_CPPFLAGS += -O0 -DNO_PYTHON
#USR_CPPFLAGS += -DUSE_TYPED_RSET -DUSE_TYPED_DSET -DUSE_TYPED_DRVET
#USR_CFLAGS   += -DUSE_TYPED_RSET -DUSE_TYPED_DSET -DUSE_TYPED_DRVET

PROD_SYS_LIBS += util pthread rt

rogue_core_DIR		= $(ROGUE_LIB)
SHRLIB_SEARCH_DIRS	+=$(ROGUE_LIB)

include $(ADCORE)/ADApp/commonLibraryMakefile

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
# ADD RULES AFTER THIS LINE

#$(foreach v, $(filter-out .VARIABLES, $(.VARIABLES)), $(info $(v) = $($(v))))


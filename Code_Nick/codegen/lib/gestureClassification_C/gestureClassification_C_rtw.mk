###########################################################################
## Makefile generated for component 'gestureClassification_C'. 
## 
## Makefile     : gestureClassification_C_rtw.mk
## Generated on : Wed Nov 23 16:38:04 2022
## Final product: ./gestureClassification_C.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = gestureClassification_C
MAKEFILE                  = gestureClassification_C_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2022b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2022b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/ncartocci/Documents/GitHub/MyoArmbandDataset/Code_Nick
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = gestureClassification_C_rtw_comp.rsp
CMD_FILE                  = gestureClassification_C_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = gestureClassification_C.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2022b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(notdir $(basename $(PRODUCT))).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(notdir $(basename $(PRODUCT))).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./gestureClassification_C.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__USE_MINGW_ANSI_STDIO=1
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=gestureClassification_C

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C_data.cpp $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C_initialize.cpp $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C_terminate.cpp $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C.cpp $(START_DIR)/codegen/lib/gestureClassification_C/predict.cpp $(START_DIR)/codegen/lib/gestureClassification_C/forwardExplicitLoops.cpp $(START_DIR)/codegen/lib/gestureClassification_C/postProcessOutputToReturnCategorical.cpp $(START_DIR)/codegen/lib/gestureClassification_C/strtrim.cpp $(START_DIR)/codegen/lib/gestureClassification_C/cellstr_sort.cpp $(START_DIR)/codegen/lib/gestureClassification_C/find.cpp $(START_DIR)/codegen/lib/gestureClassification_C/classifyAndUpdateState.cpp $(START_DIR)/codegen/lib/gestureClassification_C/strcmp.cpp $(START_DIR)/codegen/lib/gestureClassification_C/elementwiseOperationInPlace.cpp $(START_DIR)/codegen/lib/gestureClassification_C/introsort.cpp $(START_DIR)/codegen/lib/gestureClassification_C/insertionsort.cpp $(START_DIR)/codegen/lib/gestureClassification_C/categorical.cpp $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = gestureClassification_C_data.obj gestureClassification_C_initialize.obj gestureClassification_C_terminate.obj gestureClassification_C.obj predict.obj forwardExplicitLoops.obj postProcessOutputToReturnCategorical.obj strtrim.obj cellstr_sort.obj find.obj classifyAndUpdateState.obj strcmp.obj elementwiseOperationInPlace.obj introsort.obj insertionsort.obj categorical.obj gestureClassification_C_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -fopenmp
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -fopenmp

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -fopenmp

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -fopenmp

LDFLAGS += $(LDFLAGS_)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -fopenmp

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/gestureClassification_C/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/gestureClassification_C/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


gestureClassification_C_data.obj : $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


gestureClassification_C_initialize.obj : $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


gestureClassification_C_terminate.obj : $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


gestureClassification_C.obj : $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


predict.obj : $(START_DIR)/codegen/lib/gestureClassification_C/predict.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


forwardExplicitLoops.obj : $(START_DIR)/codegen/lib/gestureClassification_C/forwardExplicitLoops.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


postProcessOutputToReturnCategorical.obj : $(START_DIR)/codegen/lib/gestureClassification_C/postProcessOutputToReturnCategorical.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


strtrim.obj : $(START_DIR)/codegen/lib/gestureClassification_C/strtrim.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cellstr_sort.obj : $(START_DIR)/codegen/lib/gestureClassification_C/cellstr_sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.obj : $(START_DIR)/codegen/lib/gestureClassification_C/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


classifyAndUpdateState.obj : $(START_DIR)/codegen/lib/gestureClassification_C/classifyAndUpdateState.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


strcmp.obj : $(START_DIR)/codegen/lib/gestureClassification_C/strcmp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


elementwiseOperationInPlace.obj : $(START_DIR)/codegen/lib/gestureClassification_C/elementwiseOperationInPlace.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


introsort.obj : $(START_DIR)/codegen/lib/gestureClassification_C/introsort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


insertionsort.obj : $(START_DIR)/codegen/lib/gestureClassification_C/insertionsort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


categorical.obj : $(START_DIR)/codegen/lib/gestureClassification_C/categorical.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


gestureClassification_C_rtwutil.obj : $(START_DIR)/codegen/lib/gestureClassification_C/gestureClassification_C_rtwutil.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."



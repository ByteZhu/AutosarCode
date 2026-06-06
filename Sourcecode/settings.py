# Version information:
# BUILD_TYPE = PROD  : production release
# BUILD_TYPE = DEBUG : temporary debug build
# BUILD_TYPE = DEVEL : development release
BUILD_TYPE          = 'DEBUG'
PROJ_NAME           = 'ENTRY_PLATFROM'
SW_VERSION_MSB      = 0
SW_VERSION_LSB      = 0


# Compiler Type Choice 
COMPILER_CHOICE = 'TASKING'
# COMPILER_CHOICE = 'HIGHTEC'

# General configuration:--------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
	OUTPUT_DIR          = 'output'
	LOG_DIR             = 'log'
	COMPILER_TOOL       = 'Tasking'#Must match the file name located in the site_tools directory
	COMPILER_ROOT       = 'C:/TriCorev6.3r1/ctc/bin'#fill you compiler location

elif COMPILER_CHOICE == "HIGHTEC" :
	OUTPUT_DIR			= 'output'
	LOG_DIR				= 'log'
	COMPILER_TOOL		= 'Hightec'
	COMPILER_ROOT 		= 'C:/toolbase/hightec_ifx/cd_v4.9.2.0/bin'
# CPU target--------------------------------------------------------------------------------------------------------

CPU_TARGET          = 'tc36x'
CPU_USED            = 'tc36x'



# Compiler configuration:-------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
	
	COMPILER_DEFINES        = ['-D_TASKING_C_TRICORE_=1', '-D_APP_SW = DEMO_APP'] 
	COMPILER_FLAGS		= '	-Ctc36x \
							--core=tc1.6.2 \
							-t \
							-Wa-gAHLs \
							--emit-locals=-equ,-symbols \
							-Wa-Ogs \
							-Wa--error-limit=42 \
							--iso=99 \
							--integer-enumeration \
							--language=-comments,-gcc,+volatile,-strings \
							--switch=auto \
							--default-near-size=0 \
							--default-a0-size=0 \
							--default-a1-size=0 \
							-O2ROPYGKLF-predict \
							--tradeoff=4 \
							-g \
							--source '
elif COMPILER_CHOICE == 'HIGHTEC' :
	COMPILER_DEFINES  	= '-D _GNU_C_TRICORE_=1 -D DEMO_APP -D APP_SW -D TEST_APP -D _NOT_READY_FOR_TESTING_OR_DEPLOYMENT'
	COMPILER_FLAGS 		=  '-DNOT_READY_FOR_TESTING_OR_DEPLOYMENT\
							-gdwarf-2 \
							-Wall \
							-W \
							-Wundef \
							-Wpointer-arith \
							-Wbad-function-cast \
							-Wcast-qual \
							-Wcast-align \
							-Wstrict-prototypes \
							-Wmissing-prototypes \
							-Wmissing-noreturn \
							-Wredundant-decls \
							-Wnested-externs \
							-Winline \
							-fno-builtin \
							-Wno-return-type \
							-Wno-pointer-to-int-cast \
							-Wfloat-equal \
							-fno-common \
							-Og \
							-ffunction-sections \
							-fdata-sections \
							-mpragma-data-sections \
							-Wno-unused-parameter \
							-mcpu=tc33x \
							-maligned-data-sections'
# Assembler configuration:-------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
	ASSEMBLER_DEFINES      = COMPILER_DEFINES
	ASSEMBLER_FLAGS     = '    -Ctc36x \
	                            --lsl-core=vtc \
	                            -t \
	                            -Wa-H"sfr/regtc36x.def" \
	                            -Wa-gAHLs \
	                            --emit-locals=-equs,-symbols \
	                            -Wa-Ogs \
	                            -Wa--error-limit=42'
elif COMPILER_CHOICE == 'HIGHTEC':
	ASSEMBLER_DEFINES  	= COMPILER_DEFINES
	ASSEMBLER_FLAGS 	= COMPILER_FLAGS
# Libraries to include:----------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
	ADD_LIBRARIES        = ['.\os\Gen\RTAOS.a']
	LIBRARY_PATHS		 = 	[] 
elif COMPILER_CHOICE == 'HIGHTEC':
	ADD_LIBRARIES        = ['C:/toolbase/hightec_ifx/cd_v4.9.2.0/lib/gcc/tricore/4.9.4/libgcc.a',
							'os/Gen/RTAOS.a',] 
							#add library
	LIBRARY_PATHS		 = 	[] 
OBJECT_FILE         = 	[]

# Linker configuration:----------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
#No optimization		 	-OCLTXY --optimize=0 -O0
#Default optimization 		-OcLtxy --optimize=1 -O1
#All optimizations 	 		-Ocltxy --optimize=2 -O2
	LINKER_FLAGS    =   '--core=mpe:vtc \
						-OCLTXY \
						-Cmpe:vtc \
						-M         \
						-mcrfiklSmNOduQ \
						--error-limit=42 '
	LINKER_FILE       = '.\linkfile\ENTRY_PLATFORM_AUTOSAR_LSL_TASKING.lsl'
elif COMPILER_CHOICE == 'HIGHTEC':
	LINKER_FLAGS 		= 	'-Wl,--warn-orphan \
							-Wl,--warn-section-align \
							-Wl,--no-demangle \
							-Wl,--warn-once \
							-Wl,--relax \
							-nodefaultlibs \
							-nostdlib \
							-nocrt0 \
							-nostartfiles \
							-e cstart \
							-mtc162'
	LINKER_FILE       = '.\linkfile\ENTRY_PLATFORM_AUTOSAR_LD_HIGHTEC.ld'
#centralized header directory::----------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
	CEN_HEADER_DIR = '.\output\inc'
elif COMPILER_CHOICE == 'HIGHTEC':
	CEN_HEADER_DIR = '.\output\inc'


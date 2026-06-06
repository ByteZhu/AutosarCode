import scons_common

from SCons.Script import *

# SCons mandatory function for custom tools, sets up environment
def generate(env):

######## ENVIRONMENT ########

	env['CPPDEFPREFIX']     = '-D'
	env['INCPREFIX']        = '-I'
	env['INCSUFFIX']		= ''
	env['OBJSUFFIX']         = '.o'
	env['DEPFILESUFFIX']     = '.d'
	env['MAPFILESUFFIX']     = '.map'
	env['LIBSUFFIX']         = '.a'
	env['PROGSUFFIX']        = '.elf'
	env['LIBLINKPREFIX']    = '-L'
	env['LIBDIRPREFIX']        = ''
	env['HEXFILESUFFIX']     = '.hex'
	env['S19FILESUFFIX']     = '.s19'
	env['ASMSUFFIXES'] 		= ['.asm']
	env['CPPSUFFIXES']         = ['.c','.C','.h','.H']
	env['SPAWN']             = scons_common.w32api_cmdfilearg_spawn
	env['PRINT_CMD_LINE_FUNC'] = scons_common.print_cmd_line
    
######## END ENVIRONMENT ########
    
######## COMPILER ########
    
    # Implements: COR003, COR006, PLF001
	env['CC']                 = env['COMPILER_ROOT'] + os.sep + 'cctc.exe'
	env['TARGETCPUOPT']     = env['CPU_TARGET']
	env['CPPDEFINES']       = env['COMPILER_DEFINES']
	env['CCFLAGS']             = env['COMPILER_FLAGS']
    
    # Compiler command line
	
	env['CCCOM'] 			= '$CC -o $TARGET $CCFLAGS $CPPDEFINES -t -c $SOURCE -I$CEN_HEADER_DIR'
    
######## END COMPILER ########

######## ASSEMBLER ########


	# Implements: COR004, COR008, PLF002
	env['AS']				= env['COMPILER_ROOT'] + os.sep + 'cctc.exe'
	env['ASFLAGS']  		= env['ASSEMBLER_FLAGS']
	
	# Assembler command line
	env['ASCOM']			= '$AS -D__CPU__=$CPU_USED -o $TARGET -c $SOURCES $ASCFLAGS $ASFLAGS $_ASCOMCOM $_ASCPPCOMCOM'
	
	env['ASPPFLAGS'] 		= env['ASSEMBLER_FLAGS']
	env['ASCPPDEFINES']		= env['ASSEMBLER_DEFINES']
	env['_ASCPPDEFFLAGS'] 	= '${_defines(CPPDEFPREFIX, ASCPPDEFINES, \
								CPPDEFSUFFIX, __env__)}'
	env['_ASCPPCOMCOM']    	=  '$ASCPPFLAGS $_ASCPPDEFFLAGS $_ASCPPINCFLAGS \
								$_CPPINCFLAGS'
	
	# Assembler command line
	env['ASPPCOM']			= '$AS -D__CPU__=$CPU_USED -o $TARGET -c $SOURCES $ASPPFLAGS $ASCFLAGS $_ASCPPCOMCOM'

######## END ASSEMBLER ########

######## ARCHIVER ########

	env['AR']                = env['COMPILER_ROOT'] + os.sep + 'artc.exe'
	env['ARFLAGS']            = env['COMPILER_FLAGS']

	# Archiver command line
	env['ARCOM']            = '$AR rv $TARGET $SOURCES'

######## END ARCHIVER ########

######## LINKER ########

	# Implements: COR005, COR007, PLF003
	env['LINK']             = env['COMPILER_ROOT'] + os.sep + 'ltc.exe'
	env['LINKFLAGS']        = env['LINKER_FLAGS']
	env['LINKCMDFILE']         = env['LINKER_FILE']
	env['LIBS']                = env['ADD_LIBRARIES']
	env['LIBPATH']            = env['LIBRARY_PATHS']
	env['LINKERGENMAPFILE'] = '-M' + os.path.join(env.subst('$OUTPUT_DIR'), 'dbg', env.subst('$TARGET_NAME')) + env['MAPFILESUFFIX']
	env['_LIBDIRFLAGS']     = '${_concat(LIBDIRPREFIX, LIBPATH, LIBDIRSUFFIX, \
								__env__, RDirs, TARGET, SOURCE)}'
	env['_LIBFLAGS']        = '${_stripixes(LIBLINKPREFIX, LIBS, LIBLINKSUFFIX,\
								LIBPREFIXES, LIBSUFFIXES, __env__)}'

	# Linker command line
	env['LINKCOM']          = '$LINK -o$TARGET -D__CPU__=$CPU_USED $LINKFLAGS $SOURCES $_LIBDIRFLAGS $LIBS -lc -lfp -lrt -d$LINKCMDFILE $LINKERGENMAPFILE'
#-L"D:\TASKING\TriCore v4.2r2\ctc/lib/tc16x"
######## END LINKER ########
######## OBJECT BUILDER ########

	# Implements: COR003, COR004

	cs = SCons.Scanner.ClassicCPP("CScanner", "$CPPSUFFIXES", "CPPPATH", \
					'^[ \t]*#[ \t]*(?:include|import)[ \t]*(<|")([^>"]+)(>|")') 

	obj_builder = SCons.Builder.Builder(action = '$CCCOM',src_suffix = env.subst('$CPPSUFFIXES') \
													+ env.subst('$ASMSUFFIXES'),
										suffix = env.subst('$OBJSUFFIX'),
										source_scanner = cs)

	env['BUILDERS']['Object']	= obj_builder
######## HEX BUILDER ########

	# Implements: COR011
	env['HEXCMD']             = './site_scons/site_tools/objcopy.exe'

	hex_builder = SCons.Builder.Builder(action = '$HEXCMD -O ihex "$SOURCE" \
																	"$TARGET"',
										single_source = 1,
										suffix = env.subst('$HEXFILESUFFIX'))
										
	env['BUILDERS']['Hex']    = hex_builder

######## END HEX BUILDER ########

######## S19 BUILDER ########


	# Implements: COR011
	env['S19CMD']             = './site_scons/site_tools/objcopy.exe'

	s19_builder = SCons.Builder.Builder(action = '$S19CMD -O srec "$SOURCE" \
																	"$TARGET"',
										single_source = 1,
										suffix = env.subst('$S19FILESUFFIX'))
										
	env['BUILDERS']['S19']    = s19_builder

######## END S19 BUILDER ########


                                        
    
######## END OBJECT BUILDER ########

# SCons mandatory function for custom tools
def exists(env):
    return True

if __name__ == '__main__':
    main()    

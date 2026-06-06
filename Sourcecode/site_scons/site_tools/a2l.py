import scons_common

from SCons.Script import *

# SCons mandatory function for custom tools, sets up environment
# Implements: COR012
def generate(env):

######## A2L BUILDER ########
										
	a2l_builder = SCons.Builder.Builder(action = env.subst('$A2L_COMMAND') + ' $SOURCE $TARGET $COMPILER_ROOT',
										single_source = 1,
										suffix = '.a2l')
	
	env['BUILDERS']['A2L']	= a2l_builder

	# Dataset for INCA
	hexDs_builder = SCons.Builder.Builder(action = env.subst('$HEXDS_COMMAND') + ' $SOURCE $TARGET $COMPILER_ROOT',
										single_source = 1,
										suffix = env.subst('$HEXFILESUFFIX'))
										
	env['BUILDERS']['HexDs']	= hexDs_builder

######## END A2L BUILDER ########

# SCons mandatory function for custom tools
def exists(env):
    return True
	
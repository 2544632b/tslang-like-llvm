# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chan/Desktop/StaticScript-master-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chan/Desktop/StaticScript-master-2

# Include any dependencies generated for this target.
include CMakeFiles/staticscript.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/staticscript.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/staticscript.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/staticscript.dir/flags.make

# Object files for target staticscript
staticscript_OBJECTS =

# External object files for target staticscript
staticscript_EXTERNAL_OBJECTS = \
"/Users/chan/Desktop/StaticScript-master-2/CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/Entity/CMakeFiles/entity.dir/Type.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/Entity/CMakeFiles/entity.dir/Scope.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/AST/CMakeFiles/ast.dir/DeclNode.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/AST/CMakeFiles/ast.dir/StmtNode.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/AST/CMakeFiles/ast.dir/ExprNode.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/AST/CMakeFiles/ast.dir/ModuleNode.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/AST/CMakeFiles/ast.dir/ASTBuilder.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/Sema/CMakeFiles/sema.dir/ASTVisitor.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/Sema/CMakeFiles/sema.dir/ScopeScanner.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/Sema/CMakeFiles/sema.dir/ReferenceResolver.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/Sema/CMakeFiles/sema.dir/TypeChecker.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/Sema/CMakeFiles/sema.dir/SemanticValidator.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/Optimization/CMakeFiles/optimization.dir/Optimizer.cpp.o" \
"/Users/chan/Desktop/StaticScript-master-2/src/Driver/CMakeFiles/driver.dir/Driver.cpp.o"

staticscript: CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptLexer/StaticScriptLexer.cpp.o
staticscript: CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParser.cpp.o
staticscript: CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserBaseVisitor.cpp.o
staticscript: CMakeFiles/parser.dir/antlr4_generated_src/StaticScriptParser/StaticScriptParserVisitor.cpp.o
staticscript: src/Entity/CMakeFiles/entity.dir/Type.cpp.o
staticscript: src/Entity/CMakeFiles/entity.dir/Scope.cpp.o
staticscript: src/AST/CMakeFiles/ast.dir/DeclNode.cpp.o
staticscript: src/AST/CMakeFiles/ast.dir/StmtNode.cpp.o
staticscript: src/AST/CMakeFiles/ast.dir/ExprNode.cpp.o
staticscript: src/AST/CMakeFiles/ast.dir/ModuleNode.cpp.o
staticscript: src/AST/CMakeFiles/ast.dir/ASTBuilder.cpp.o
staticscript: src/Sema/CMakeFiles/sema.dir/ASTVisitor.cpp.o
staticscript: src/Sema/CMakeFiles/sema.dir/ScopeScanner.cpp.o
staticscript: src/Sema/CMakeFiles/sema.dir/ReferenceResolver.cpp.o
staticscript: src/Sema/CMakeFiles/sema.dir/TypeChecker.cpp.o
staticscript: src/Sema/CMakeFiles/sema.dir/SemanticValidator.cpp.o
staticscript: src/CodeGen/CMakeFiles/codegen.dir/Builtin.cpp.o
staticscript: src/CodeGen/CMakeFiles/codegen.dir/IRGenerator.cpp.o
staticscript: src/CodeGen/CMakeFiles/codegen.dir/DeclCodeGen.cpp.o
staticscript: src/CodeGen/CMakeFiles/codegen.dir/ExprCodeGen.cpp.o
staticscript: src/CodeGen/CMakeFiles/codegen.dir/StmtCodeGen.cpp.o
staticscript: src/CodeGen/CMakeFiles/codegen.dir/Pass.cpp.o
staticscript: src/Optimization/CMakeFiles/optimization.dir/Optimizer.cpp.o
staticscript: src/Driver/CMakeFiles/driver.dir/Driver.cpp.o
staticscript: CMakeFiles/staticscript.dir/build.make
staticscript: /usr/local/lib/libantlr4-runtime.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMSupport.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMCore.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMIRReader.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMLinker.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMCodeGen.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMX86CodeGen.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMX86Desc.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMX86Info.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMPasses.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMObjCARCOpts.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMX86CodeGen.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMX86AsmParser.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMX86Desc.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMX86Disassembler.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMX86Info.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMAsmPrinter.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMDebugInfoDWARF.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMGlobalISel.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMSelectionDAG.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMCodeGen.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMCFGuard.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMTarget.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMCoroutines.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMHelloNew.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMipo.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMIRReader.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMAsmParser.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMLinker.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMBitWriter.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMScalarOpts.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMAggressiveInstCombine.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMFrontendOpenMP.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMInstCombine.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMVectorize.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMInstrumentation.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMTransformUtils.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMAnalysis.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMObject.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMBitReader.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMTextAPI.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMProfileData.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMCore.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMRemarks.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMBitstreamReader.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMMCParser.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMMCDisassembler.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMMC.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMBinaryFormat.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMDebugInfoCodeView.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMDebugInfoMSF.a
staticscript: /usr/local/opt/llvm@12/lib/libLLVMSupport.a
staticscript: /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/usr/lib/libz.tbd
staticscript: /Library/Developer/CommandLineTools/SDKs/MacOSX13.sdk/usr/lib/libcurses.tbd
staticscript: /usr/local/opt/llvm@12/lib/libLLVMDemangle.a
staticscript: CMakeFiles/staticscript.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/chan/Desktop/StaticScript-master-2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX executable staticscript"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/staticscript.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/staticscript.dir/build: staticscript
.PHONY : CMakeFiles/staticscript.dir/build

CMakeFiles/staticscript.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/staticscript.dir/cmake_clean.cmake
.PHONY : CMakeFiles/staticscript.dir/clean

CMakeFiles/staticscript.dir/depend:
	cd /Users/chan/Desktop/StaticScript-master-2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2 /Users/chan/Desktop/StaticScript-master-2/CMakeFiles/staticscript.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/staticscript.dir/depend

set (USEDLIBS LLVMLibHSAIL.a)
set(LLVM_LINK_COMPONENTS ${LLVM_TARGETS_TO_BUILD} bitreader asmparser)

add_library(LIBHSAIL STATIC IMPORTED)
add_library(LIBHSAIL64 STATIC IMPORTED)
set_property(TARGET LIBHSAIL64 PROPERTY IMPORTED_LOCATION /home/amd/Prakash/Git/HSAIL-Tools-private/libHSAIL/build_linux_opt_m64/libhsail.a)

add_llvm_tool(llc
          llc.cpp
            )

target_link_libraries(llc LIBHSAIL64)


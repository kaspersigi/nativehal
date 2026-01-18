###########################################
#Makefile for my Android C++ programs
###########################################

TRG = nativehal
OBJ = nativehal.o
SRC = nativehal.cc
NDK = /mnt/develop/android-ndk-r27d
ARCH = $(shell uname -m)
PLATFORM = darwin
ifeq ($(ARCH), x86_64)
	PLATFORM = linux
else ifeq ($(ARCH), aarch64)
	PLATFORM = windows
endif
TOOLCHAIN = $(NDK)/toolchains/llvm/prebuilt/$(PLATFORM)-x86_64
TARGET = aarch64-linux-android
API = 35
LLVM = -21
CC = $(TOOLCHAIN)/bin/$(TARGET)$(API)-clang
CXX = $(TOOLCHAIN)/bin/$(TARGET)$(API)-clang++
SCAN = scan-build$(LLVM) --use-cc=$(CC) --use-c++=$(CXX)
TIDY = /usr/bin/clang-tidy$(LLVM) -quiet
FORMAT = /usr/bin/clang-format$(LLVM)
C_FLAGS = -std=c23 -Wall -Wno-unused --sysroot=$(TOOLCHAIN)/sysroot --target=$(TARGET)
CXX_FLAGS = -std=c++26 -Wall -Wno-unused --sysroot=$(TOOLCHAIN)/sysroot --target=$(TARGET)
DEBUG = -g -O0
RELEASE = -flto -O3
LIBS = -L $(TOOLCHAIN)/sysroot/usr/lib/$(TARGET)/$(API)/ -landroid -llog
LLVMLIBC = /usr/lib/llvm$(LLVM)/lib/
CLANG_FLAGS = -nostdlib
CLANG_LINK_FLAGS = /usr/lib/llvm$(LLVM)/lib/libllvmlibc.a -static
CLANGXX_FLAGS = -stdlib=libc++
CLANGXX_LINK_FLAGS = -static-libstdc++
TIDY_FLAGS = -- $(CXX_FLAGS) $(CLANGXX_FLAGS) $(DEBUG)

.PHONY : all
all : nativehal
nativehal : nativehal.o module.o device.o
	$(CXX) nativehal.o ./module/CameraModule.o ./device/Camera3Device.o -o nativehal $(CLANGXX_LINK_FLAGS) $(LIBS)
	rm -v nativehal.o
	$(MAKE) -C module clean
	$(MAKE) -C device clean
nativehal.o : nativehal.cc
	$(CXX) nativehal.cc -c $(CXX_FLAGS) $(CLANGXX_FLAGS) $(DEBUG)
module.o :
	$(MAKE) -C module
device.o :
	$(MAKE) -C device
format :
	$(FORMAT) nativehal.cc -style=file -i
	$(FORMAT) include/camera_common.h -style=file -i
	$(FORMAT) include/camera_metadata_tags.h -style=file -i
	$(FORMAT) include/camera_metadata.h -style=file -i
	$(FORMAT) include/camera_vendor_tags.h -style=file -i
	$(FORMAT) include/camera3.h -style=file -i
	$(FORMAT) include/graphics.h -style=file -i
	$(FORMAT) include/hardware.h -style=file -i
	$(FORMAT) include/log.h -style=file -i
	$(FORMAT) include/native_handle.h -style=file -i
	$(MAKE) -C module format
	$(MAKE) -C device format
clean :
	rm -v nativehal
scan :
	$(SCAN) make
tidy :
	$(TIDY) nativehal.cc $(TIDY_FLAGS)
	$(MAKE) -C module tidy
	$(MAKE) -C device tidy
check :
	valgrind --tool=memcheck --leak-check=full --show-reachable=yes --error-limit=no ./$(TRG)
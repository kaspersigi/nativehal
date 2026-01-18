###########################################
#Makefile for my Android programs
###########################################

TRG = main
OBJ = main.o
SRC = main.c
VPATH = /mnt/develop/linux/nativetest
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
TIDY_FLAGS = -- $(C_FLAGS) $(DEBUG)

.PHONY : all
all : template android_nativehal
template :
	$(MAKE) -C 00.template
android_nativehal :
	$(MAKE) -C 01.android_nativehal

format :
	$(MAKE) -C 00.template format
	$(MAKE) -C 01.android_nativehal format

clean :
	$(MAKE) -C 00.template clean
	$(MAKE) -C 01.android_nativehal clean

scan :
	$(MAKE) -C 00.template scan
	$(MAKE) -C 01.android_nativehal scan

tidy :
	$(MAKE) -C 00.template tidy
	$(MAKE) -C 01.android_nativehal tidy

style :
	clang-format -style=webkit -dump-config > .clang-format

bak :
	git archive --format=tar.gz --prefix=nativehal/ --output ../nativehal.tar.gz master
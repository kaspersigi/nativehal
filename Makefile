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
all : template android_c android_cpp
template :
	$(MAKE) -C 00.template
android_c :
	$(MAKE) -C 01.android_c
android_cpp :
	$(MAKE) -C 02.android_cpp

format :
	$(MAKE) -C 00.template format
	$(MAKE) -C 01.android_c format
	$(MAKE) -C 02.android_cpp format

clean :
	$(MAKE) -C 00.template clean
	$(MAKE) -C 01.android_c clean
	$(MAKE) -C 02.android_cpp clean

scan :
	$(MAKE) -C 00.template scan
	$(MAKE) -C 01.android_c scan
	$(MAKE) -C 02.android_cpp scan

tidy :
	$(MAKE) -C 00.template tidy
	$(MAKE) -C 01.android_c tidy
	$(MAKE) -C 02.android_cpp tidy

style :
	clang-format -style=webkit -dump-config > .clang-format

bak :
	git archive --format=tar.gz --prefix=nativetest/ --output ../nativetest.tar.gz master
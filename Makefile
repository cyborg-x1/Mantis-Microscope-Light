#############################################################################
# Makefile for building: RL_Microscope_Light_Control
# Generated by qmake (2.01a) (Qt 4.7.4) on: So. Dez 4 15:02:50 2011
# Project:  RL_Microscope_Light_Control.pro
# Template: app
# Command: /opt/Qt/Desktop/Qt/474/gcc/bin/qmake CONFIG+=debug_and_release -o Makefile RL_Microscope_Light_Control.pro
#############################################################################

first: release
install: release-install
uninstall: release-uninstall
MAKEFILE      = Makefile
QMAKE         = /opt/Qt/Desktop/Qt/474/gcc/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		release \
		debug

release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: RL_Microscope_Light_Control.pro  /opt/Qt/Desktop/Qt/474/gcc/mkspecs/default/qmake.conf /opt/Qt/Desktop/Qt/474/gcc/mkspecs/common/g++.conf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/common/unix.conf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/common/linux.conf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/qconfig.pri \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/modules/qt_webkit_version.pri \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/qt_functions.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/qt_config.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/exclusive_builds.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/default_pre.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/release.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/debug_and_release.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/default_post.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/warn_on.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/qt.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/unix/thread.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/moc.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/resources.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/uic.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/yacc.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/lex.prf \
		/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/include_source_dir.prf
	$(QMAKE) CONFIG+=debug_and_release -o Makefile RL_Microscope_Light_Control.pro
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/common/g++.conf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/common/unix.conf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/common/linux.conf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/qconfig.pri:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/modules/qt_webkit_version.pri:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/qt_functions.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/qt_config.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/exclusive_builds.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/default_pre.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/release.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/debug_and_release.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/default_post.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/warn_on.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/qt.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/unix/thread.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/moc.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/resources.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/uic.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/yacc.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/lex.prf:
/opt/Qt/Desktop/Qt/474/gcc/mkspecs/features/include_source_dir.prf:
qmake: qmake_all FORCE
	@$(QMAKE) CONFIG+=debug_and_release -o Makefile RL_Microscope_Light_Control.pro

qmake_all: FORCE

make_default: release-make_default debug-make_default FORCE
make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile

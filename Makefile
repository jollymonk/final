#############################################################################
# Makefile for building: CS123
# Generated by qmake (2.01a) (Qt 4.7.0) on: Tue Dec 20 13:52:08 2011
# Project:  CS123.pro
# Template: app
# Command: /course/cs123/lib/qt/qt/bin/qmake -o Makefile CS123.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DTIXML_USE_STL -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O3 -W -Waddress -Warray-bounds -Wc++0x-compat -Wchar-subscripts -Wformat -Wmain -Wmissing-braces -Wparentheses -Wreorder -Wreturn-type -Wsequence-point -Wsign-compare -Wstrict-aliasing -Wstrict-overflow=1 -Wswitch -Wtrigraphs -Wuninitialized -Wunused-label -Wunused-variable -Wvolatile-register-var -Wno-extra -D_REENTRANT $(DEFINES)
INCPATH       = -I/course/cs123/lib/qt/qt-4.7.0/mkspecs/default -I. -I/course/cs123/lib/qt/qt-4.7.0/include/QtCore -I/course/cs123/lib/qt/qt-4.7.0/include/QtGui -I/course/cs123/lib/qt/qt-4.7.0/include/QtOpenGL -I/course/cs123/lib/qt/qt-4.7.0/include -Ibrush -Icamera -Ilib -Imath -Iscenegraph -Iui -I/usr/X11R6/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/course/cs123/lib/qt/qt-4.7.0/lib
LIBS          = $(SUBLIBS)  -L/course/cs123/lib/qt/qt-4.7.0//lib -L/usr/X11R6/lib -lQtOpenGL -L/course/cs123/lib/qt/qt-4.7.0//lib -L/usr/X11R6/lib -lQtGui -lQtCore -lGLU -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /course/cs123/lib/qt/qt/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = brush/SmudgeBrush.cpp \
		brush/QuadraticBrush.cpp \
		brush/LinearBrush.cpp \
		brush/ConstantBrush.cpp \
		brush/Brush.cpp \
		camera/OrbitingCamera.cpp \
		camera/CamtransCamera.cpp \
		lib/tinyxmlparser.cpp \
		lib/tinyxmlerror.cpp \
		lib/tinyxml.cpp \
		lib/tinystr.cpp \
		lib/CS123XmlSceneParser.cpp \
		math/CS123Matrix.cpp \
		scenegraph/ShapesScene.cpp \
		scenegraph/SceneviewScene.cpp \
		scenegraph/Scene.cpp \
		scenegraph/RayScene.cpp \
		scenegraph/OpenGLScene.cpp \
		ui/SupportCanvas3D.cpp \
		ui/SupportCanvas2D.cpp \
		ui/Settings.cpp \
		ui/mainwindow.cpp \
		ui/Databinding.cpp \
		ui/Canvas3D.cpp \
		ui/Canvas2D.cpp \
		shape/Cone.cpp \
		shape/Cube.cpp \
		shape/Cylinder.cpp \
		shape/Shape.cpp \
		shape/Sphere.cpp \
		main.cpp \
		filter/Filter.cpp \
		filter/Invert.cpp \
		filter/Grayscale.cpp \
		filter/EdgeDetect.cpp \
		filter/Blur.cpp \
		filter/Scale.cpp \
		filter/Lichtenstein.cpp \
		filter/Sharpen.cpp \
		scenegraph/RayThread.cpp moc_SupportCanvas3D.cpp \
		moc_SupportCanvas2D.cpp \
		moc_mainwindow.cpp \
		moc_Databinding.cpp \
		moc_Canvas3D.cpp \
		moc_Canvas2D.cpp
OBJECTS       = SmudgeBrush.o \
		QuadraticBrush.o \
		LinearBrush.o \
		ConstantBrush.o \
		Brush.o \
		OrbitingCamera.o \
		CamtransCamera.o \
		tinyxmlparser.o \
		tinyxmlerror.o \
		tinyxml.o \
		tinystr.o \
		CS123XmlSceneParser.o \
		CS123Matrix.o \
		ShapesScene.o \
		SceneviewScene.o \
		Scene.o \
		RayScene.o \
		OpenGLScene.o \
		SupportCanvas3D.o \
		SupportCanvas2D.o \
		Settings.o \
		mainwindow.o \
		Databinding.o \
		Canvas3D.o \
		Canvas2D.o \
		Cone.o \
		Cube.o \
		Cylinder.o \
		Shape.o \
		Sphere.o \
		main.o \
		Filter.o \
		Invert.o \
		Grayscale.o \
		EdgeDetect.o \
		Blur.o \
		Scale.o \
		Lichtenstein.o \
		Sharpen.o \
		RayThread.o \
		moc_SupportCanvas3D.o \
		moc_SupportCanvas2D.o \
		moc_mainwindow.o \
		moc_Databinding.o \
		moc_Canvas3D.o \
		moc_Canvas2D.o
DIST          = /gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/common/g++.conf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/common/unix.conf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/common/linux.conf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/qconfig.pri \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/qt_functions.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/qt_config.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/exclusive_builds.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/default_pre.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/release.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/default_post.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/warn_on.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/qt.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/unix/opengl.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/unix/thread.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/moc.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/resources.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/uic.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/yacc.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/lex.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/include_source_dir.prf \
		CS123.pro
QMAKE_TARGET  = CS123
DESTDIR       = 
TARGET        = CS123

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: CS123.pro  /course/cs123/lib/qt/qt-4.7.0/mkspecs/default/qmake.conf /gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/common/g++.conf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/common/unix.conf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/common/linux.conf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/qconfig.pri \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/qt_functions.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/qt_config.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/exclusive_builds.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/default_pre.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/release.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/default_post.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/warn_on.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/qt.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/unix/opengl.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/unix/thread.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/moc.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/resources.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/uic.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/yacc.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/lex.prf \
		/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/include_source_dir.prf \
		/course/cs123/lib/qt/qt-4.7.0/lib/libQtOpenGL.prl \
		/course/cs123/lib/qt/qt-4.7.0/lib/libQtGui.prl \
		/course/cs123/lib/qt/qt-4.7.0/lib/libQtCore.prl
	$(QMAKE) -o Makefile CS123.pro
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/common/g++.conf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/common/unix.conf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/common/linux.conf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/qconfig.pri:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/qt_functions.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/qt_config.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/exclusive_builds.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/default_pre.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/release.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/default_post.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/warn_on.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/qt.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/unix/opengl.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/unix/thread.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/moc.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/resources.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/uic.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/yacc.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/lex.prf:
/gpfs/main/sys/shared/psfu/contrib/projects/qt/qt-4.7.0/mkspecs/features/include_source_dir.prf:
/course/cs123/lib/qt/qt-4.7.0/lib/libQtOpenGL.prl:
/course/cs123/lib/qt/qt-4.7.0/lib/libQtGui.prl:
/course/cs123/lib/qt/qt-4.7.0/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile CS123.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/CS1231.0.0 || $(MKDIR) .tmp/CS1231.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/CS1231.0.0/ && $(COPY_FILE) --parents brush/SmudgeBrush.h brush/QuadraticBrush.h brush/LinearBrush.h brush/ConstantBrush.h brush/Brush.h camera/OrbitingCamera.h camera/CamtransCamera.h camera/Camera.h lib/tinyxml.h lib/tinystr.h lib/CS123XmlSceneParser.h lib/CS123SceneData.h lib/CS123ISceneParser.h lib/CS123Common.h math/CS123Algebra.h math/CS123Matrix.h math/CS123Matrix.inl math/CS123Vector.h math/CS123Vector.inl math/TA_Tester.h scenegraph/ShapesScene.h scenegraph/SceneviewScene.h scenegraph/Scene.h scenegraph/RayScene.h scenegraph/OpenGLScene.h ui/SupportCanvas3D.h ui/SupportCanvas2D.h ui/Settings.h ui/mainwindow.h ui/Databinding.h ui/Canvas3D.h ui/Canvas2D.h shape/Cone.h shape/Cube.h shape/Cylinder.h shape/Shape.h shape/Sphere.h ui_mainwindow.h filter/Filter.h filter/Invert.h filter/Grayscale.h filter/EdgeDetect.h filter/Blur.h filter/Scale.h filter/Lichtenstein.h filter/Sharpen.h scenegraph/RayThread.h .tmp/CS1231.0.0/ && $(COPY_FILE) --parents brush/SmudgeBrush.cpp brush/QuadraticBrush.cpp brush/LinearBrush.cpp brush/ConstantBrush.cpp brush/Brush.cpp camera/OrbitingCamera.cpp camera/CamtransCamera.cpp lib/tinyxmlparser.cpp lib/tinyxmlerror.cpp lib/tinyxml.cpp lib/tinystr.cpp lib/CS123XmlSceneParser.cpp math/CS123Matrix.cpp scenegraph/ShapesScene.cpp scenegraph/SceneviewScene.cpp scenegraph/Scene.cpp scenegraph/RayScene.cpp scenegraph/OpenGLScene.cpp ui/SupportCanvas3D.cpp ui/SupportCanvas2D.cpp ui/Settings.cpp ui/mainwindow.cpp ui/Databinding.cpp ui/Canvas3D.cpp ui/Canvas2D.cpp shape/Cone.cpp shape/Cube.cpp shape/Cylinder.cpp shape/Shape.cpp shape/Sphere.cpp main.cpp filter/Filter.cpp filter/Invert.cpp filter/Grayscale.cpp filter/EdgeDetect.cpp filter/Blur.cpp filter/Scale.cpp filter/Lichtenstein.cpp filter/Sharpen.cpp scenegraph/RayThread.cpp .tmp/CS1231.0.0/ && $(COPY_FILE) --parents ui/mainwindow.ui .tmp/CS1231.0.0/ && (cd `dirname .tmp/CS1231.0.0` && $(TAR) CS1231.0.0.tar CS1231.0.0 && $(COMPRESS) CS1231.0.0.tar) && $(MOVE) `dirname .tmp/CS1231.0.0`/CS1231.0.0.tar.gz . && $(DEL_FILE) -r .tmp/CS1231.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check:

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_SupportCanvas3D.cpp moc_SupportCanvas2D.cpp moc_mainwindow.cpp moc_Databinding.cpp moc_Canvas3D.cpp moc_Canvas2D.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_SupportCanvas3D.cpp moc_SupportCanvas2D.cpp moc_mainwindow.cpp moc_Databinding.cpp moc_Canvas3D.cpp moc_Canvas2D.cpp
moc_SupportCanvas3D.cpp: math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/SupportCanvas3D.h
	/course/cs123/lib/qt/qt-4.7.0//bin/moc $(DEFINES) $(INCPATH) ui/SupportCanvas3D.h -o moc_SupportCanvas3D.cpp

moc_SupportCanvas2D.cpp: lib/CS123Common.h \
		ui/SupportCanvas2D.h
	/course/cs123/lib/qt/qt-4.7.0//bin/moc $(DEFINES) $(INCPATH) ui/SupportCanvas2D.h -o moc_SupportCanvas2D.cpp

moc_mainwindow.cpp: ui/Settings.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/mainwindow.h
	/course/cs123/lib/qt/qt-4.7.0//bin/moc $(DEFINES) $(INCPATH) ui/mainwindow.h -o moc_mainwindow.cpp

moc_Databinding.cpp: math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Databinding.h
	/course/cs123/lib/qt/qt-4.7.0//bin/moc $(DEFINES) $(INCPATH) ui/Databinding.h -o moc_Databinding.cpp

moc_Canvas3D.cpp: ui/SupportCanvas3D.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas3D.h
	/course/cs123/lib/qt/qt-4.7.0//bin/moc $(DEFINES) $(INCPATH) ui/Canvas3D.h -o moc_Canvas3D.cpp

moc_Canvas2D.cpp: ui/SupportCanvas2D.h \
		lib/CS123Common.h \
		ui/Canvas2D.h
	/course/cs123/lib/qt/qt-4.7.0//bin/moc $(DEFINES) $(INCPATH) ui/Canvas2D.h -o moc_Canvas2D.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: ui/mainwindow.ui \
		ui/Canvas2D.h \
		ui/Canvas3D.h \
		ui/SupportCanvas2D.h \
		lib/CS123Common.h \
		ui/SupportCanvas3D.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl
	/course/cs123/lib/qt/qt-4.7.0/bin/uic ui/mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

SmudgeBrush.o: brush/SmudgeBrush.cpp brush/SmudgeBrush.h \
		brush/QuadraticBrush.h \
		brush/Brush.h \
		lib/CS123Common.h \
		ui/Settings.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SmudgeBrush.o brush/SmudgeBrush.cpp

QuadraticBrush.o: brush/QuadraticBrush.cpp brush/QuadraticBrush.h \
		brush/Brush.h \
		lib/CS123Common.h \
		ui/Settings.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o QuadraticBrush.o brush/QuadraticBrush.cpp

LinearBrush.o: brush/LinearBrush.cpp brush/LinearBrush.h \
		brush/Brush.h \
		lib/CS123Common.h \
		ui/Settings.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o LinearBrush.o brush/LinearBrush.cpp

ConstantBrush.o: brush/ConstantBrush.cpp brush/ConstantBrush.h \
		brush/Brush.h \
		lib/CS123Common.h \
		ui/Settings.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ConstantBrush.o brush/ConstantBrush.cpp

Brush.o: brush/Brush.cpp brush/Brush.h \
		lib/CS123Common.h \
		ui/Settings.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Brush.o brush/Brush.cpp

OrbitingCamera.o: camera/OrbitingCamera.cpp camera/OrbitingCamera.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		camera/Camera.h \
		ui/Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OrbitingCamera.o camera/OrbitingCamera.cpp

CamtransCamera.o: camera/CamtransCamera.cpp camera/CamtransCamera.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		camera/Camera.h \
		ui/Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CamtransCamera.o camera/CamtransCamera.cpp

tinyxmlparser.o: lib/tinyxmlparser.cpp lib/tinyxml.h \
		lib/tinystr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tinyxmlparser.o lib/tinyxmlparser.cpp

tinyxmlerror.o: lib/tinyxmlerror.cpp lib/tinyxml.h \
		lib/tinystr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tinyxmlerror.o lib/tinyxmlerror.cpp

tinyxml.o: lib/tinyxml.cpp lib/tinyxml.h \
		lib/tinystr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tinyxml.o lib/tinyxml.cpp

tinystr.o: lib/tinystr.cpp lib/tinystr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tinystr.o lib/tinystr.cpp

CS123XmlSceneParser.o: lib/CS123XmlSceneParser.cpp lib/CS123XmlSceneParser.h \
		lib/CS123ISceneParser.h \
		lib/CS123SceneData.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		lib/tinyxml.h \
		lib/tinystr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CS123XmlSceneParser.o lib/CS123XmlSceneParser.cpp

CS123Matrix.o: math/CS123Matrix.cpp math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Algebra.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CS123Matrix.o math/CS123Matrix.cpp

ShapesScene.o: scenegraph/ShapesScene.cpp scenegraph/ShapesScene.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		lib/CS123SceneData.h \
		shape/Shape.h \
		ui/Settings.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		camera/Camera.h \
		ui/SupportCanvas3D.h \
		ui/Canvas3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ShapesScene.o scenegraph/ShapesScene.cpp

SceneviewScene.o: scenegraph/SceneviewScene.cpp scenegraph/SceneviewScene.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		lib/CS123SceneData.h \
		shape/Shape.h \
		ui/Settings.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		camera/Camera.h \
		ui/Canvas3D.h \
		ui/SupportCanvas3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SceneviewScene.o scenegraph/SceneviewScene.cpp

Scene.o: scenegraph/Scene.cpp scenegraph/Scene.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		lib/CS123SceneData.h \
		shape/Shape.h \
		ui/Settings.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		camera/Camera.h \
		lib/CS123ISceneParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Scene.o scenegraph/Scene.cpp

RayScene.o: scenegraph/RayScene.cpp scenegraph/RayScene.h \
		scenegraph/Scene.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		lib/CS123SceneData.h \
		shape/Shape.h \
		ui/Settings.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		camera/Camera.h \
		scenegraph/RayThread.h \
		camera/CamtransCamera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RayScene.o scenegraph/RayScene.cpp

OpenGLScene.o: scenegraph/OpenGLScene.cpp scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		lib/CS123SceneData.h \
		shape/Shape.h \
		ui/Settings.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		camera/Camera.h \
		ui/SupportCanvas3D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OpenGLScene.o scenegraph/OpenGLScene.cpp

SupportCanvas3D.o: ui/SupportCanvas3D.cpp ui/SupportCanvas3D.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		scenegraph/ShapesScene.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h \
		shape/Shape.h \
		ui/Settings.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		scenegraph/SceneviewScene.h \
		camera/OrbitingCamera.h \
		camera/Camera.h \
		camera/CamtransCamera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SupportCanvas3D.o ui/SupportCanvas3D.cpp

SupportCanvas2D.o: ui/SupportCanvas2D.cpp ui/SupportCanvas2D.h \
		lib/CS123Common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SupportCanvas2D.o ui/SupportCanvas2D.cpp

Settings.o: ui/Settings.cpp ui/Settings.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Settings.o ui/Settings.cpp

mainwindow.o: ui/mainwindow.cpp ui/mainwindow.h \
		ui/Settings.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui_mainwindow.h \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		ui/Canvas3D.h \
		ui/SupportCanvas3D.h \
		ui/Databinding.h \
		scenegraph/RayScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h \
		shape/Shape.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		camera/Camera.h \
		scenegraph/ShapesScene.h \
		scenegraph/OpenGLScene.h \
		scenegraph/SceneviewScene.h \
		camera/CamtransCamera.h \
		lib/CS123XmlSceneParser.h \
		lib/CS123ISceneParser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o ui/mainwindow.cpp

Databinding.o: ui/Databinding.cpp ui/Databinding.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Databinding.o ui/Databinding.cpp

Canvas3D.o: ui/Canvas3D.cpp ui/Canvas3D.h \
		ui/SupportCanvas3D.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		shape/Shape.h \
		ui/Settings.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		camera/Camera.h \
		camera/OrbitingCamera.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Canvas3D.o ui/Canvas3D.cpp

Canvas2D.o: ui/Canvas2D.cpp ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		lib/CS123Common.h \
		ui/Canvas3D.h \
		ui/SupportCanvas3D.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Settings.h \
		scenegraph/RayScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h \
		shape/Shape.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		camera/Camera.h \
		brush/Brush.h \
		brush/ConstantBrush.h \
		brush/LinearBrush.h \
		brush/QuadraticBrush.h \
		brush/SmudgeBrush.h \
		filter/Filter.h \
		filter/Blur.h \
		filter/EdgeDetect.h \
		filter/Grayscale.h \
		filter/Invert.h \
		filter/Scale.h \
		filter/Sharpen.h \
		filter/Lichtenstein.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Canvas2D.o ui/Canvas2D.cpp

Cone.o: shape/Cone.cpp shape/Cone.h \
		shape/Shape.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Settings.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Cone.o shape/Cone.cpp

Cube.o: shape/Cube.cpp shape/Cube.h \
		shape/Shape.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Settings.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h \
		shape/Cone.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		scenegraph/RayScene.h \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		camera/Camera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Cube.o shape/Cube.cpp

Cylinder.o: shape/Cylinder.cpp shape/Cylinder.h \
		shape/Shape.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Settings.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Sphere.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Cylinder.o shape/Cylinder.cpp

Shape.o: shape/Shape.cpp shape/Shape.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Settings.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Shape.o shape/Shape.cpp

Sphere.o: shape/Sphere.cpp shape/Sphere.h \
		shape/Shape.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Settings.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Sphere.o shape/Sphere.cpp

main.o: main.cpp math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/mainwindow.h \
		ui/Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

Filter.o: filter/Filter.cpp filter/Filter.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		scenegraph/OpenGLScene.h \
		scenegraph/Scene.h \
		lib/CS123SceneData.h \
		shape/Shape.h \
		ui/Settings.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Filter.o filter/Filter.cpp

Invert.o: filter/Invert.cpp filter/Invert.h \
		filter/Filter.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Invert.o filter/Invert.cpp

Grayscale.o: filter/Grayscale.cpp filter/Grayscale.h \
		filter/Filter.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Grayscale.o filter/Grayscale.cpp

EdgeDetect.o: filter/EdgeDetect.cpp filter/EdgeDetect.h \
		filter/Filter.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		ui/Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o EdgeDetect.o filter/EdgeDetect.cpp

Blur.o: filter/Blur.cpp filter/Blur.h \
		filter/Filter.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		ui/Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Blur.o filter/Blur.cpp

Scale.o: filter/Scale.cpp filter/Scale.h \
		filter/Filter.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		ui/Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Scale.o filter/Scale.cpp

Lichtenstein.o: filter/Lichtenstein.cpp filter/Lichtenstein.h \
		filter/Filter.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		ui/Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Lichtenstein.o filter/Lichtenstein.cpp

Sharpen.o: filter/Sharpen.cpp filter/Sharpen.h \
		filter/Filter.h \
		lib/CS123Common.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		ui/Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Sharpen.o filter/Sharpen.cpp

RayThread.o: scenegraph/RayThread.cpp scenegraph/RayThread.h \
		scenegraph/RayScene.h \
		scenegraph/Scene.h \
		math/CS123Algebra.h \
		math/CS123Matrix.h \
		math/CS123Vector.h \
		lib/CS123Common.h \
		math/CS123Vector.inl \
		math/CS123Matrix.inl \
		lib/CS123SceneData.h \
		shape/Shape.h \
		ui/Settings.h \
		shape/Cone.h \
		shape/Cube.h \
		shape/Cylinder.h \
		shape/Sphere.h \
		ui/Canvas2D.h \
		ui/SupportCanvas2D.h \
		camera/Camera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RayThread.o scenegraph/RayThread.cpp

moc_SupportCanvas3D.o: moc_SupportCanvas3D.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_SupportCanvas3D.o moc_SupportCanvas3D.cpp

moc_SupportCanvas2D.o: moc_SupportCanvas2D.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_SupportCanvas2D.o moc_SupportCanvas2D.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_Databinding.o: moc_Databinding.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Databinding.o moc_Databinding.cpp

moc_Canvas3D.o: moc_Canvas3D.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Canvas3D.o moc_Canvas3D.cpp

moc_Canvas2D.o: moc_Canvas2D.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Canvas2D.o moc_Canvas2D.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


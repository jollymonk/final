# -------------------------------------------------
# Project created by QtCreator 2010-08-22T14:12:19
# -------------------------------------------------
QT += opengl
TARGET = CS123
TEMPLATE = app
SOURCES += \
    camera/OrbitingCamera.cpp \
    camera/CamtransCamera.cpp \
    lib/tinyxmlparser.cpp \
    lib/tinyxmlerror.cpp \
    lib/tinyxml.cpp \
    lib/tinystr.cpp \
    lib/CS123XmlSceneParser.cpp \
    math/CS123Matrix.cpp \
    ui/SupportCanvas3D.cpp \
    ui/SupportCanvas2D.cpp \
    ui/Settings.cpp \
    ui/mainwindow.cpp \
    ui/Databinding.cpp \
    ui/Canvas3D.cpp \
    main.cpp \
    fountain/Emitter.cpp \
    shape/Sphere.cpp \
    shape/Shape.cpp \
    lib/targa.cpp \
    lib/resourceloader.cpp \
    lib/glm.cpp

HEADERS += \
    camera/OrbitingCamera.h \
    camera/CamtransCamera.h \
    camera/Camera.h \
    lib/tinyxml.h \
    lib/tinystr.h \
    lib/CS123XmlSceneParser.h \
    lib/CS123SceneData.h \
    lib/CS123ISceneParser.h \
    lib/CS123Common.h \
    math/CS123Algebra.h \
    math/CS123Matrix.h \
    math/CS123Matrix.inl \
    math/CS123Vector.h \
    math/CS123Vector.inl \
    math/TA_Tester.h \
    ui/SupportCanvas3D.h \
    ui/SupportCanvas2D.h \
    ui/Settings.h \
    ui/mainwindow.h \
    ui/Databinding.h \
    ui/Canvas3D.h \
    ui_mainwindow.h \
    fountain/Emitter.h \
    shape/Sphere.h \
    shape/Shape.h \
    lib/targa.h \
    lib/resourceloader.h \
    lib/camera.h \
    lib/glm.h
FORMS += ui/mainwindow.ui
INCLUDEPATH += camera lib math scenegraph ui fountain
DEPENDPATH += camera lib math scenegraph ui fountain
DEFINES += TIXML_USE_STL
OTHER_FILES +=

# Don't add the -pg flag unless you know what you are doing. It makes QThreadPool freeze on Mac OS X
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_WARN_ON -= -Wall
QMAKE_CXXFLAGS_WARN_ON += -Waddress -Warray-bounds -Wc++0x-compat -Wchar-subscripts -Wformat\
                          -Wmain -Wmissing-braces -Wparentheses -Wreorder -Wreturn-type \
                          -Wsequence-point -Wsign-compare -Wstrict-aliasing -Wstrict-overflow=1 -Wswitch \
                          -Wtrigraphs -Wuninitialized -Wunused-label -Wunused-variable \
                          -Wvolatile-register-var -Wno-extra
# QMAKE_CXX_FLAGS_WARN_ON += -Wunknown-pragmas -Wunused-function -Wmain

macx {
    QMAKE_CXXFLAGS_WARN_ON -= -Warray-bounds -Wc++0x-compat
}

#-------------------------------------------------
#
# Project created by QtCreator 2015-12-12T16:01:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Image_Dehazing
TEMPLATE = app


SOURCES += main.cpp \
    lib_qc/img_rgb_to_QImage.cpp \
    lib_qc/QImage_to_img_rgb.cpp \
    lib_c/img_rgb_create.c \
    lib_c/img_rgb_destruct.c \
    lib_c/img_to_map_rgb.c \
    lib_c/Malloc2D_dbl.c \
    lib_c/Malloc2D_uchr.c \
    lib_c/map_create.c \
    lib_c/map_destruct.c \
    lib_c/map_rgb_create.c \
    lib_c/map_rgb_destruct.c \
    lib_c/map_to_img_rgb.c \
    lib_c/img_rgb_to_yuv.c \
    lib_c/img_yuv_create.c \
    lib_c/img_yuv_destruct.c \
    lib_c/img_create.c \
    lib_c/img_destruct.c \
    lib_c/arry_pix_create.c \
    lib_c/arry_pix_destruct.c \
    lib_c/Dehaze.c

HEADERS  += \
    include/image.h \
    include/image_qt.h

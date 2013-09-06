project (KSerial)
find_package(KDE4 REQUIRED)
include (KDE4Defaults)
include_directories(${KDE4_INCLUDES})

set(KSerial_SRCS main.cpp mainwindow.cpp)
kde4_add_ui_files(KSerial_SRCS mainwindow.ui)

kde4_add_executable(KSerial ${KSerial_SRCS})
target_link_libraries(KSerial ${KDE4_KDEUI_LIBS})
install(TARGETS KSerial ${INSTALL_TARGETS_DEFAULT_ARGS})

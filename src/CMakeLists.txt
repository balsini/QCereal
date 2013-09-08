project (KSerial)
find_package(KDE4 REQUIRED)
include (KDE4Defaults)
include_directories(${KDE4_INCLUDES})
set(KSerial_SRCS
  main.cpp
  mainwindow.cpp
  aboutwindow.cpp
)
qt4_add_resources(KSerial_SRCS
  resources.qrc
)
kde4_add_ui_files(KSerial_SRCS
  mainwindow.ui
  aboutwindow.ui
)
kde4_add_executable(KSerial ${KSerial_SRCS})
target_link_libraries(KSerial ${KDE4_KDEUI_LIBS} ${KDE4_SOLID_LIBS})
install(TARGETS KSerial ${INSTALL_TARGETS_DEFAULT_ARGS})

# Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT). All rights reserved.
# This software may be modified and distributed under the terms of the
# GNU Lesser General Public License v2.1 or any later version.

yarp_prepare_plugin(xsens_suit
    TYPE wearable::devices::XsensSuit
    INCLUDE XsensSuit.h
    CATEGORY device
    ADVANCED
    DEFAULT ON)

yarp_add_plugin(XsensSuit
    src/XsensSuit.cpp
    include/XsensSuit.h)

target_include_directories(XsensSuit PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(XsensSuit PUBLIC
    Wearable::IWear IXsensMVNControl XSensMVN YARP::YARP_dev)

yarp_install(
    TARGETS XsensSuit
    COMPONENT runtime
    LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
    ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR})

yarp_install(
    FILES "${CMAKE_CURRENT_SOURCE_DIR}/xsens_suit.ini"
    DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})

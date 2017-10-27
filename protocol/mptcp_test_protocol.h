// Copyright (c) 2017 Agora.io, Inc.
// jiqi@agora.io
//
// Test Protocol For MPTCP

#pragma once

#include "base/packet_helper.h"

enum MptcpTestUriType {
  kPingUri = 1,
  kPongUri = 2,
  kTestDataUri = 3,
};

NEW_DECLARE_PACKET_0(Ping, kPingUri);
NEW_DECLARE_PACKET_0(Pong, kPongUri);

NEW_DECLARE_PACKET_1(TestData, kTestDataUri,
                     std::string, data);

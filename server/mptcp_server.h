// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP Server

#pragma once  // NOLINT(build/header_guard)

#include <iostream>
#include <string>

#include "base/event_loop.h"
#include "protocol/mptcp_test_protocol.h"
#include "network/address_utility.h"
#include "network/tcp_server.h"

using std::cout;
using std::endl;
using std::string;
using namespace agora::base;  // NOLINT
using namespace agora::network;  // NOLINT

class MptcpServer :
  private TcpServerCallback {
 public:
  explicit MptcpServer(event_base *base, uint16_t port) :
    server_(base, this) {
    server_.ListenOn(port);
  }

  ~MptcpServer() {}

 protected:
  virtual void OnConnectionAccepted(TcpConnection *conn);

 private:
  TcpServer server_;
};

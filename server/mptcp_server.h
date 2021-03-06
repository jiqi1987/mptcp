// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP Server

#pragma once  // NOLINT(build/header_guard)

#include <iostream>
#include <string>

#include "base/event_loop.h"
#include "protocol/mptcp_test_protocol.h"
#include "network/address_utility.h"
#include "network/tcp_connection.h"
#include "network/tcp_server.h"

using std::cout;
using std::endl;
using std::string;
using namespace agora::base;  // NOLINT
using namespace agora::network;  // NOLINT

class MptcpServer :
  private TcpServerCallback,
  private TcpConnectionCallback {
 public:
  explicit MptcpServer(event_base *base, uint16_t port) :
    server_(base, this) {
    server_.ListenOn(port);
  }

  ~MptcpServer() {}

 protected:
  virtual void OnConnectionAccepted(TcpConnection *conn);

  virtual void OnError(TcpConnection *conn, int events);
  virtual void OnPacketReceived(TcpConnection *conn, Unpacker *p,
                                uint16_t service_type, uint16_t uri);

 private:
  TcpServer server_;
  TcpConnection *conn_;
};

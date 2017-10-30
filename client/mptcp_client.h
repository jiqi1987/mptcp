// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP Client

#pragma once  // NOLINT(build/header_guard)

#include <iostream>
#include <string>

#include "base/event_loop.h"
#include "base/timer.h"
#include "protocol/mptcp_test_protocol.h"
#include "network/address_utility.h"
#include "network/tcp_client.h"

using std::cout;
using std::endl;
using std::string;
using namespace agora::base;  // NOLINT
using namespace agora::network;  // NOLINT

class MptcpClient :
  private TcpClientCallback {
 public:
  explicit MptcpClient(event_base *base, uint32_t ip, uint16_t port)
    : client_(base, ip, port, this) {
    timer_ = RepeatedTimer(base, 1000,
                           &MptcpClient::OnTimer, this);
    client_.Connect();
  }

  ~MptcpClient() {}

 protected:
  virtual void OnConnect(TcpClient *conn, bool connected);
  virtual void OnPacketReceived(TcpClient *conn, Unpacker *pkr,
                                uint16_t service_type, uint16_t uri);
  virtual void OnSocketError(TcpClient *conn);
  virtual void TimeToPing(TcpClient *conn);

 private:
  void OnTimer();

 private:
  TcpClient client_;
  RepeatedTimer timer_;
};

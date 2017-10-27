// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP Server

#include <gtest/gtest.h>
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
  private TcpServerCallback,
  public testing::Test {
 public:
  MptcpServer() :
    server_(loop_.GetEventBase(), this) {
  }

  ~MptcpServer() { }

  virtual void SetUp() {
    server_.ListenOn(10913);
    loop_.Run();
  }

  virtual void TearDown() {
    loop_.Stop();
  }

 protected:
  virtual void OnConnectionAccepted(TcpConnection *conn);

 private:
  // static const string server_ip = "10.10.114.52";
  // static const uint16_t server_port = 10913;

 private:
  EventLoop loop_;
  TcpServer server_;
};

void MptcpServer::OnConnectionAccepted(TcpConnection *conn) {
  cout << "OnConnectionAccpeted" << endl;
}

TEST_F(MptcpServer, server) {
}

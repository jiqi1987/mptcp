// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP Client

#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "base/event_loop.h"
#include "protocol/mptcp_test_protocol.h"
#include "network/address_utility.h"
#include "network/tcp_client.h"

using std::cout;
using std::endl;
using std::string;
using namespace agora::base;  // NOLINT
using namespace agora::network;  // NOLINT

class MptcpClient :
  private TcpClientCallback,
  public testing::Test {
 public:
  MptcpClient() :
    client_(loop_.GetEventBase(),
            IpToInt("10.10.114.52"), 10913,
            this) {
  }

  ~MptcpClient() { }

  virtual void SetUp() {
    loop_.Run();
  }

  virtual void TearDown() {
    loop_.Stop();
  }

 protected:
  virtual void OnConnect(TcpClient *conn, bool connected);
  virtual void OnPacketReceived(TcpClient *conn, Unpacker *pkr,
                                uint16_t service_type, uint16_t uri);

  virtual void OnSocketError(TcpClient *conn);
  virtual void TimeToPing(TcpClient *conn);

 private:
  // static const string server_ip = "10.10.114.52";
  // static const uint16_t server_port = 10913;

 private:
  EventLoop loop_;
  TcpClient client_;
};

void MptcpClient::OnConnect(TcpClient *conn, bool connected) {
  cout << "OnConnect" << endl;
}

void MptcpClient::OnPacketReceived(TcpClient *conn, Unpacker *pkr,
                      uint16_t service_type, uint16_t uri) {
  cout << "OnPacketReceived" << endl;
}

void MptcpClient::OnSocketError(TcpClient *conn) {
}

void MptcpClient::TimeToPing(TcpClient *conn) {
  Ping pkt(1);
  conn->SendPacket(pkt);
}

TEST_F(MptcpClient, client) {
}

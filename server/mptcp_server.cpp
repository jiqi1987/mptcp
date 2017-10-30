// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP Server

#include <gtest/gtest.h>
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
  private TcpConnectionCallback,
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

  virtual void OnError(TcpConnection *conn, int events);

  virtual void OnPacketReceived(TcpConnection *conn, Unpacker *p,
                                uint16_t service_type, uint16_t uri);

 private:
  // static const string server_ip = "10.10.114.52";
  // static const uint16_t server_port = 10913;

 private:
  EventLoop loop_;
  TcpConnection *conn_;
  TcpServer server_;
};

void MptcpServer::OnConnectionAccepted(TcpConnection *conn) {
  cout << "OnConnectionAccpeted" << endl;
  conn_ = conn;
  conn_->RegisterCallback(this);
}

void MptcpServer::OnError(TcpConnection *conn, int events) {
}

void MptcpServer::OnPacketReceived(TcpConnection *conn, Unpacker *pkr,
                                   uint16_t service_type, uint16_t uri) {
  if (uri == 3) {
    TestData data(1);
    data.Unmarshall(pkr);
    cout << ".";
  }
  if (uri == 1) {
    cout << "|";
    Pong pong(1);
    conn_->SendPacket(pong);
  }
}

TEST_F(MptcpServer, server) {
}

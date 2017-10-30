// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP Server

#include "server/mptcp_server.h"

using std::cout;
using std::endl;
using std::string;

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

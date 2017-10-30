// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP Client

#include "client/mptcp_client.h"

using std::cout;
using std::endl;
using std::string;

void MptcpClient::OnConnect(TcpClient *conn, bool connected) {
  if (connected) {
    cout << "OnConnect" << endl;
  }
}

void MptcpClient::OnTimer() {
  if (!client_.IsConnected()) return;
  cout << "Sending data" << endl;
  for (int i = 0; i < 20000; ++i) {
    TestData data(1);
    data.data = "KNOCK KNOCK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    client_.SendPacket(data);
  }
}

void MptcpClient::OnPacketReceived(TcpClient *conn, Unpacker *pkr,
                      uint16_t service_type, uint16_t uri) {
  if (uri == 2) {
    cout << "OnPong" << endl;
  }
}

void MptcpClient::OnSocketError(TcpClient *conn) {
}

void MptcpClient::TimeToPing(TcpClient *conn) {
  Ping pkt(1);
  conn->SendPacket(pkt);
}

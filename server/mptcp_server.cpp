// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP Server

#include "server/mptcp_server.h"

using std::cout;
using std::endl;
using std::string;

void MptcpServer::OnConnectionAccepted(TcpConnection *conn) {
  cout << "OnConnectionAccpeted" << endl;
}

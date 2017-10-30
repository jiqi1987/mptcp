// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP test

#include <cstdlib>
#include <iostream>

#include "server/mptcp_server.h"

int main(int argc, char *argv[]) {
  EventLoop loop;
  uint16_t port = (argc < 2 ? 10913 : atoi(argv[1]));
  MptcpServer server(loop.GetEventBase(), port);
  loop.Run();
}

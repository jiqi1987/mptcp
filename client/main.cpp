// Copyright (c) 2017 Agora.io, Inc.
// Author: jiqi@agora.io (Qi Ji) OCT 2017
// MPTCP test

#include <cstdlib>
#include <iostream>

#include "client/mptcp_client.h"

int main(int argc, char *argv[]) {
  EventLoop loop;
  uint32_t ip = IpToInt("127.0.0.1");
  uint16_t port = 10913;
  if (argc == 3) {
    ip = IpToInt(argv[1]);
    port = atoi(argv[2]);
  }
  MptcpClient client(loop.GetEventBase(), ip, port);
  loop.Run();
}

#include "Sender.h"

Sender::Sender(MsgServiceEsp *msgEsp)
{
    this->msgEsp = msgEsp;
}

void Sender::notifyMsg(String msg)
{
    msgEsp->sendMsg(msg);
}

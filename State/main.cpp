#include <iostream>

using namespace std;


class ClientState;
class ClientConnection
{
public:
    void Online();
    void Offline();

private:
    friend class ClientState;
    void ChangeState(ClientState * state);

private:
    ClientState * state_;
};

class ClientState
{
public:
    virtual void Online(ClientConnection * connection){}
    virtual void Offline(ClientConnection * connection) {}
protected:
    void ChangeState(ClientConnection * connection,ClientState * state)
    {
        connection->ChangeState(state);
    }
};


void ClientConnection::ChangeState(ClientState * state)
{
    state_ = state;
}


class OnlineClientState : public ClientState
{
public:
    static OnlineClientState & Instance()
    {
        static OnlineClientState inst;
        return inst;
    }
    virtual void Offline(ClientConnection * connection);
};

class OfflineClientState: public ClientState
{
public:
    static OfflineClientState & Instance()
    {
        static OfflineClientState inst;
        return inst;
    }
    virtual void Online(ClientConnection * connection);
};

void OnlineClientState::Offline(ClientConnection * connection)
{
    // do some thing and wait offline
    ChangeState(connection,& OfflineClientState::Instance());
}
void OfflineClientState::Online(ClientConnection * connection)
{
    // do some thing and wait online
    ChangeState(connection,& OnlineClientState::Instance());
}
int main()
{

    return 0;
}

#ifndef ZEUS_NET_ACCEPTOR_H_
#define ZEUS_NET_ACCEPTOR_H_

#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <thread>
#include "inet_address.hpp"
#include "tcp_connection.hpp"
#include "zeus_net_def.h"

using namespace boost::asio;
using namespace boost::asio::ip;

class Acceptor : private boost::noncopyable
{
public:
    Acceptor(const InetAddress& listenAddress, boost::asio::io_service& io_service, uint32 threadNums)
        : _io_service(io_service),
        _strand(io_service),
        _listenAddr(listenAddress),
        _listenning(false),
        _acceptor(io_service),
        _threadNums(threadNums)
    {
        //�󶨵�ַ
        boost::asio::ip::address address;
        address.from_string(_listenAddr.host());
        tcp::endpoint endpoint(address, _listenAddr.port());
        _acceptor.open(tcp::v4());
        _acceptor.bind(endpoint);
    }

public:
    inline std::string host() const
    {
        return _listenAddr.host();
    }

    inline uint16 port() const
    {
        return _listenAddr.port();
    }

    void listen(int32 backlog = socket_base::max_connections)
    {
        _acceptor.listen(backlog);
        _listenning = true;
    }

    void startAccept()
    {
        assert(_threadNums != 0);

        //Ͷ��һ�������¼�
        postAcceptEvent();

        //ΪIO���д����߳�
        std::vector<ThreadPtr> threads;
        for (std::size_t i = 0; i < _threadNums; ++i)
        {
            ThreadPtr t(new std::thread(boost::bind(&boost::asio::io_service::run, &_io_service)));
            threads.push_back(t);
        }

        for(auto& thread : threads)
        {
            thread->join();
        }
    }

    void stopAccept()
    {
        std::cout << "stopAccept." << std::endl;
        _io_service.stop();
        _acceptor.close();
    }

    bool listenning() const { return _listenning; }

public:
    void setNewConnectCallback(const NewConnectionCallback& cb)
    {
        _newConnectionCallback = cb;
    }

private:
    void acceptHandler(const TcpConnectionPtr& connection)
    {
        std::cout << "thread id = " << std::this_thread::get_id() << std::endl;

        postAcceptEvent();

        if (connection->isOpen())
        {
            if (!_newConnectionCallback._Empty())
            {
                //����ͨ�ŵ�ַ�ṹ
                tcp::socket& socket = connection->socket();
                std::string remote_address = socket.remote_endpoint().address().to_string();
                uint16 remote_port = socket.remote_endpoint().port();
                InetAddress peerAddress(remote_address, remote_port);

                //�ص��������Ӵ�����
                _newConnectionCallback(connection, peerAddress);
            }
            else
            {
                connection->close();
            }
        }
    }

    void postAcceptEvent()
    {
        //����һ���µ����ӣ��º��������ӳأ����⿪���ڴ�Ŀ�����
        TcpConnectionPtr new_connection(new TcpConnection(_io_service)); 

        //Ͷ��һ��accept����io���У����ص���acceptHandler
        _acceptor.async_accept(new_connection->socket(),
            std::bind(&Acceptor::acceptHandler, this, new_connection));
    }

private:
    boost::asio::io_service& _io_service;
    boost::asio::strand _strand;
    bool _listenning;
    uint32 _threadNums;
    InetAddress _listenAddr;
    tcp::acceptor _acceptor;
    NewConnectionCallback _newConnectionCallback;
};

#endif
#include "StdAfx.h"

#if 0
#if defined (LINUX)

int  CEpollReactor::runRector(int port,int address)
{
	int listenq = 1024;
	int listenfd =  createListenSocket(servPort,listenq);
	static char buf[10240];
	struct epoll_event ev;
	struct epoll_event events[MAXEPOLLSIZE];
	// 创建 epoll 句柄，把监听 socket 加入到 epoll 集合里
	int kdpfd = epoll_create(MAXEPOLLSIZE);
	ev.events = EPOLLIN | EPOLLET;
	ev.data.fd = listenfd;
	if (epoll_ctl(kdpfd, EPOLL_CTL_ADD, listenfd, &ev) < 0)
	{
		fprintf(stderr, "epoll set insertion error: fd=%d\n", listenfd);
		return -1;
	}

	printf("epollserver startup,port %d, max connection is %d, backlog is %d\n",\
		servPort, MAXEPOLLSIZE, listenq);
	int nfds,n,connfd;
	int acceptCount = 0;
	static int curfds = 1;
	struct sockaddr_in cliaddr;
	socklen_t socklen = sizeof(struct sockaddr_in);
	while(1)
	{
		// 等待有事件发生
		nfds = epoll_wait(kdpfd, events, curfds, -1);
		if (nfds == -1)
		{
			perror("epoll_wait");
			continue;
		}
		// 处理所有事件
		for (n = 0; n < nfds; ++n)
		{
			struct epoll_event event = events[n];
			if (event.data.fd == listenfd)
			{
				connfd = accept(listenfd, (struct sockaddr *)&cliaddr,&socklen);
				if (connfd < 0)
				{
					perror("accept error");
					continue;
				}

				sprintf(buf, "accept form %s:%d\n", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port);
				printf("%d:%s", ++acceptCount, buf);

				if (curfds >= MAXEPOLLSIZE)
				{
					fprintf(stderr, "too many connection, more than %d\n", MAXEPOLLSIZE);
					close(connfd);
					continue;
				}
				if (setnonblocking(connfd) < 0)
				{
					perror("setnonblocking error");
					continue;
				}
				//投递事件
				ev.events = EPOLLIN | EPOLLET;
				ev.data.fd = connfd;
				if (epoll_ctl(kdpfd, EPOLL_CTL_ADD, connfd, &ev) < 0)
				{
					fprintf(stderr, "add socket '%d' to epoll failed: %s\n", connfd, strerror(errno));
					continue;
				}
				curfds++;
				continue;
			}

			// 处理客户端请求
			if (event_handle(event) < 0)
			{
				epoll_ctl(kdpfd, EPOLL_CTL_DEL, event.data.fd,&ev);
				curfds--;
			}
		}
	}
	close(listenfd);
	return 0;
}


int CEpollReactor::event_handle(epoll_event event)
{

	int nread;
	int connfd = event.data.fd;
	if(event.events&EPOLLIN)
	{
		nread = read(connfd, m_buf, MAX_BUFFER);//读取客户端socket流
		if (nread == 0)
		{
			printf("client close the connection\n");
			close(connfd);
			return -1;
		}
		else if (nread < 0)
		{
			perror("read error");
			close(connfd);
			return -1;
		}
		m_pos += nread;
		printf("buf %s\n",m_buf);
	}

	return 0;
}


#endif

#endif

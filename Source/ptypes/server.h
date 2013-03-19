
#ifndef SERVER_H
#define SERVER_H

USING_PTYPES


#define QUEUEDEPTH (200)
#define UDPBUFSZ (4096)


typedef struct ApmData {
	float a;
	float b;
	float c;
} ApmData;

/**
 * @class ServerThread
 * Receives UDP data blocks, which are stored using the segragated memory
 * manager. For each received block a message consisting of a buffer pointer
 * and byte count are inserted into the server's helper thread's job queue.
 *
 * @param jobqueue *p_jq  - A "message" holds a data pointer and byte count.
 * @param struct SMT_ITEMS *p_smt - SMT board information structure.
 */
class ServerThread : public thread {
protected:
	char		m_udpbuf[UDPBUFSZ];
	ipmsgserver	m_server;
	char*		m_pbuf;
	int		m_hMsgSvr;
	int		m_cnt;
	int 		m_port;
	jobqueue*	m_outjq;
public:
	ServerThread(pt::jobqueue* ojq, int port) : thread(true), m_port(port), m_outjq(ojq) {}
	~ServerThread() {}
	void execute();
};


class ProcessThread : public thread {
protected:
	ApmData*	m_data;
    	char*		m_buf;
        int		m_cnt;

public:
        jobqueue*	m_injq;
        jobqueue*	m_outjq;

        ProcessThread(pt::jobqueue* ijq, pt::jobqueue* ojq) : thread(true), m_injq(ijq), m_outjq(ojq)  {}
        ~ProcessThread() {}
        void execute();
};

/**
 * @class myjob2
 * Inherits from PTypes message class. A queue item consists of a pointer to a
 * dynamically allocated data buffer as well as the buffer's byte count.
 *
 * @param char* buf - Pointer.
 * @param int amt - Byte count.
 */
class job1 : public message {
    public:
        int	cnt;
        char*	buf;

        job1(int c, char* p) : message(1), cnt(c), buf(p)  {}
        ~job1()  { if (buf) delete buf; }
};

/**
 * @class myjob2
 * Inherits from PTypes message class. A queue item consists of a pointer to a
 * dynamically allocated structure.
 *
 * @param
 */
class job2 : public pt::message {
    public:
        ApmData* data;

        job2(ApmData* d) : message(1), data(d) {}
        ~job2()  { if (data) delete data; }
};


#ifdef __cplusplus
extern "C" {
#endif

    extern int volatile gThreadsRun;

#ifdef __cplusplus
}
#endif

#endif

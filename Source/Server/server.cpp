
#include "ptypes.h"
#include "pasync.h"
#include "pinet.h"
#include "ptime.h"
#include "server.h"

USING_PTYPES

int volatile gThreadsRun;


/**
 *
 *
 *
 */
void ServerThread::execute() {
	try {
		m_hMsgSvr = m_server.bindall(m_port);
	} catch(estream* e) {
		perr.putf("FATAL: %s\n", pconst(e->get_message()));
		delete e;
	}

	while(gThreadsRun) {
		m_server.poll(m_hMsgSvr, -1);
		m_cnt = m_server.receive((char*)&m_udpbuf, UDPBUFSZ);

		m_pbuf = new char[m_cnt];
		memcpy(m_pbuf, m_udpbuf, m_cnt);
		m_outjq->post(new job1(m_cnt, m_pbuf));
	}
}

/**
 *
 *
 *
 */
void ProcessThread::execute() {
	while(gThreadsRun) {
		message* msg = m_injq->getmessage();
		m_cnt = ((job1 *) msg)->cnt;
		m_buf = ((job1 *) msg)->buf;

		// TODO: proccess
		m_data = new ApmData;
		m_outjq->post(new job2(m_data));

		delete msg;
	}
}

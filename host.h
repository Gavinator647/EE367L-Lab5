/* 
 * host.h 
 */

enum host_job_type {
	JOB_SEND_PKT_ALL_PORTS,
	JOB_PING_SEND_REQ,	
	JOB_PING_SEND_REPLY,
	JOB_PING_WAIT_FOR_REPLY,
	JOB_FILE_DOWNLOAD_SEND,			//------add download enum
	JOB_FILE_DOWNLOAD_RECV_START,
	JOB_FILE_DOWNLOAD_RECV_END,
	JOB_FILE_UPLOAD_SEND,
	JOB_SWITCH, 
	JOB_REGISTER_DOMAIN_NAME,
	JOB_REQ_ID_BY_NAME,
	JOB_SEND_ID_BACK,
	JOB_FILE_DOWNLOAD_RECV_MID,//--------for Switch
	JOB_FILE_UPLOAD_RECV_START,
	JOB_FILE_UPLOAD_RECV_END,
	JOB_TREE_SEND,
	JOB_TREE_RECV
};

struct host_job {
	enum host_job_type type;
	struct packet *packet;
	int in_port_index;
	int out_port_index;
	char fname_download[100];
	char fname_upload[100];
	int ping_timer;
	int file_upload_dst;
	struct host_job *next;
};


struct job_queue {
	struct host_job *head;
	struct host_job *tail;
	int occ;
};

void host_main(int host_id);



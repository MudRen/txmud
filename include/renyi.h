// renyi.h

#define ENYI_ROOM		"/d/renyi/access_room"

#define MAX_KILLER_NUM		300	// �������˵������Ŀ
#define MIN_XIAKE_EXP		1000000	// �������˵���;���Ҫ��
#define MAX_XIAKE_NUM		5	// ���ͬʱֻ���ŵ�������
#define QUEST_LAST_TIME		86400

#define SUCCESS_ACCEPT		1	// �ɹ������ͽ�
#define FAIL_ACCEPT		0	// �������
#define NO_XIAKE		-1	// �޴���
#define NO_THIS_KILLER		-2	// û�������͹�����
#define DATABASE_NO_READY	-3	// ���ݿ��޷�����
#define GET_MAX_KILLER_NUM	-4	// �ﵽ�����ɱ�հ������������ټ��뱻��������
#define AWARD_GET_MAX		-5	// �ͽ�ﵽ�������Ŀ21�ڣ������ټ��ͽ���
#define HAVE_KQUEST		-6	// �����͵�ǰ����������
#define NO_THIS_USER		-7	// �����������ҵ���
#define IN_PROTECTED		-8	// ���ڱ������䣬����������
#define QUEST_BEEN_USE		-9	// �Ѿ�������ִ��׷ɱ���˵�����
#define GET_MAX_XIAKE_NUM	-10	// �Ѵﵽ��������������Ŀ
#define SAME_XID_KID		-11	// kid & xid ��ͬ
#define HAVE_NO_KQUEST		-12	// ����Ŀǰû���κ�����

class bang	// һ����¼����������
{
	string id;		// �������˵� ID
	string name;		// �������˵�������
	string shimen;		// �������˵�ʦ��
	int last_time;		// ���һ�μ����ͽ��ʱ��
	int shangjin;		// ��ǰ�ͽ�����
	string xid;		// �������˵� ID
	string xname;		// �������˵�������
	int accept_time;	// �������ʱ��
}

class kdetail	// �������˵�����
{
	string id;		// �������˵� ID
	string name;		// �������˵�������
	string shimen;		// �������˵�ʦ��
	int shangjin;		// ��ǰ�ͽ�����
}

class xdetail	// ��������
{
	string xid;		// �������˵� ID
	string xname;		// �������˵�������
	int accept_time;	// �������ʱ��
}

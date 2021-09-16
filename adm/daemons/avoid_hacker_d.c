// /adm/daemons/avoid_hacker_d.c
// by Find.
// ��ֹ������. ���˺Ź���Ҳ�ڴ�ʵ��.
// �˹���Ҳ�бײ�������ֻ����ʦ�˺Ų�ȡ���±�����

#include <origin.h>
inherit F_DBASE;
inherit F_SAVE;

#define TIME_SEC	300
#define MAX_MISTAKE	3
#define LIST_FILE	"/adm/etc/blocklist"

mapping being_hacking = ([]);
nosave string *blocked_account = ({});

int block_account(string id);
int unblock_account(string id);

protected void check_same_ip_number(string ip);

void init_blocklist()
{
	if(previous_object() && (geteuid(previous_object()) != ROOT_UID))
		return;

	blocked_account =  filter_array(explode(read_file(LIST_FILE), "\n") - ({ "" }), (: $1[0] != '#' :));
}

private void write_list()
{
	write_file(LIST_FILE,implode(blocked_account,"\n"),1);
}

void create()
{
	seteuid(getuid());
	set("channel_id","פ�ؾ���");
	restore();
	init_blocklist();
}

string query_save_file() { return DATA_DIR+"ahacker"; }

void passwd_mistake(string id,string ip)
{
	string *hacking;

	if(previous_object() && (geteuid(previous_object()) != ROOT_UID))
		return;
	if(!id || !stringp(id))
		return;

	hacking = keys(being_hacking);
	if(!sizeof(hacking) || member_array(id,hacking) == -1)
	{
		being_hacking += ([ id : 1 ]);
		log_file("hacking",sprintf("�˺�:%s �������벻��ȷ.ʱ��:%s ����:%s\n",
			id,ctime(time()),ip));
		save();
		check_same_ip_number(ip);
		return;
	}

	else if( (being_hacking[id] + 1) >= MAX_MISTAKE )
	{
		block_account(id);
		map_delete(being_hacking,id);
		save();
		CHANNEL_D->do_channel(this_object(),"sys",sprintf("�˺� %s������5������������󣬴��˺ű��������Ա�����\n",
			capitalize(id)));
		log_file("hacking",sprintf("***�˺�:%s ����"+MAX_MISTAKE+"���������벻��ȷ�������ܵ�����.\n"
			+"   �� %s ����ʱ�������Ա���.���һ�ι�������%s.\n",id,ctime(time()),ip));
		check_same_ip_number(ip);
		return;
	}

	else
	{
		being_hacking[id] += 1;
		save();
		log_file("hacking",sprintf("�˺�:%s �������벻��ȷ.ʱ��:%s ����:%s\n",
			id,ctime(time()),ip));
		save();
		check_same_ip_number(ip);
	}
}

void success_login(string id)
{
	string *hacking;

	if(previous_object() && (geteuid(previous_object()) != ROOT_UID))
		return;
	if(!id || !stringp(id))
		return;

	if(!mapp(being_hacking) || being_hacking == ([]))
		return;

	hacking = keys(being_hacking);
	if(!sizeof(hacking))
		return;
	if(member_array(id,hacking) != -1)
	{
		map_delete(being_hacking,id);
		save();
	}
	return;
}

// return 0:�Ѿ������� 1:�ɹ�����.
int block_account(string id)
{
	string file;
	if(!id || !stringp(id))
		return 0;

	if(!previous_object())
		return 0;
	file = file_name(previous_object());
	if( (origin() == ORIGIN_CALL_OTHER) &&(file != "/cmds/arch/block") )
		return 0;

	if(member_array(id,blocked_account) != -1)
		return 0;
	else
	{
		blocked_account += ({ id });
		write_list();
		return 1;
	}
}

// return 0:����δ������ 1: �ɹ��������.
int unblock_account(string id)
{
	string file;

	if(!id || !stringp(id))
		return 0;

	if(!previous_object())
		return 0;
	file = file_name(previous_object());
	if( (origin() == ORIGIN_CALL_OTHER) && (file != "/cmds/arch/block") )
		return 0;

	if(member_array(id,blocked_account) == -1)
		return 0;
	else
	{
		blocked_account -= ({ id });
		write_list();
		return 1;
	}
}

int query_block(string id)
{
	if(!pointerp(blocked_account) || blocked_account == ({}))
		return 0;
	else return member_array(id,blocked_account) !=-1;
}

string blocked_list()
{
	int i;
	string list = "";

	if(geteuid(previous_object()) != ROOT_UID)
		return "";

	if(!sizeof(blocked_account))
		return "Ŀǰ"+MUD_NAME+"û���κ��˺ű�������\n";
	else
	{
		for(i=0; i<sizeof(blocked_account); i++)
		{
			list += sprintf("%-15s%c",
			blocked_account[i],((i%5==4) ? '\n' : ' '));
		}
               	list += "\n";
		return list;
	}
}

protected void check_same_ip_number(string ip)
{
	object *objs;
	string *ids = ({});

	objs = filter_array(children(USER_OB),(: clonep :));

	for(int i=0;i<sizeof(objs);i++)
	{
		if(query_ip_number(objs[i]) == ip)
			ids += ({ geteuid(objs[i]) });
	}

	if(!sizeof(ids))
		return;
	else
		log_file("hacking",sprintf("\t��������IP���������� %s ��IP��ַ��ͬ\n",
			implode(ids,"��")));
}

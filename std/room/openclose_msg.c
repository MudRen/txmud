// openclose_msg.c

#include <ansi.h>

private string m_id,
	open_msg = CYN"%sЦӯӯ�Ķ���˵����%s��ʼӪҵ�ˣ�%s�����⡣\n"NOR,
	close_msg = CYN"%sǫ��˵������λ%s�Բ���%s�����ˣ��������������ɡ�\n"NOR;

private int dn_flag = 0;

void set_dn_open(int flag) { dn_flag = flag; }

void set_master(string id) { m_id = id; }

void open_close_door(string msg,object user)
{
	object ob;

	if(stringp(m_id) && (m_id != ""))
		ob = present(m_id,this_object());

	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
		{
			if(dn_flag)
				tell_object(user,sprintf(close_msg,
					ob->name(),
					RANK_D->query_respect(user),
					this_object()->query("short")
					));
			else
				tell_object(user,sprintf(open_msg,
					ob->name(),
					this_object()->query("short"),
					RANK_D->query_respect(user)
					));
		}
		else
			tell_object(user,sprintf(CYN"%s%s�ˡ�\n"NOR,
				this_object()->query("short"),dn_flag?"����":"��ʼӪҵ"));
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
		{
			if(dn_flag)
				tell_object(user,sprintf(open_msg,
					ob->name(),
					this_object()->query("short"),
					RANK_D->query_respect(user)
					));
			else
				tell_object(user,sprintf(close_msg,
					ob->name(),
					RANK_D->query_respect(user),
					this_object()->query("short")
					));
		}
		else
			tell_object(user,sprintf(CYN"%s%s�ˡ�\n"NOR,
				this_object()->query("short"),dn_flag?"��ʼӪҵ":"����"));
		return;
	}
}

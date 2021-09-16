// ��ҷ��������level one.
// by ���ֺ�(Find).

// �ȼ� 1�� é����.

#define HOME_DIR	"/d/phome/"
#define CAN_SAVE_OBJECT	5	// �˷��ݿ��Ա������Ʒ������
#define MAX_FUR		3
#define WORN_TIME	525600	/* MUD ��һ�꣬������ʱ�䷿�ݱ�� */
#define BREAKDOWN_TIME	1051200 /* MUD �����꣬������ʱ�䷿�ݵ��� */

#include <room.h>
inherit ROOM;
inherit F_SAVE;

class s_ob
{
	string file;
	mixed arg;
}

protected class s_ob *save_objs;

void get_long(string str, string text);
int home_level() { return 1; }	//���ݵȼ���
int is_player_home() { return 1; }
string home_master() { return query("master_name"); }

class s_ob *query_save_objs()
{
	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return 0;

	return save_objs;
}

void create()
{
	if(!restore())
	{
	set("short", "���ߵ�é����");
	set("long", @LONG
������һ���é�ݷ���
��������� changelong ����ı���ļҵ�������
��<<֣�����ѣ����뷿����������ã������κ��˾�������
  ������ķ���������ı�����Ʒ������Կ���벻Ҫ���׽�
  ������>>��
��Ҫ��Կ�׿���ȥ������ (pei key) ��
���˷���������ղ� 5 ����Ʒ��
  ���� baocun �����
  list ������г��㷿�����ѱ������Ʒ
  quzou ����������߱������Ʒ��
��check ������鷿��״̬����
�����ķ���Ҫ���ڽ������ɣ���ʱ�䲻���ɷ��ݻᵹ����
���������ɹ黧���Ĺ��̶ӹ�������һ��ʱ���޷�������
  ����ȥ����Ԥ��(pay)���ɷѣ����̶ӻᰴʱ������ά����
  �ݡ�
������һʱ��ת���飬���԰����ķ��������С�Ǯׯ��Ѻ��
  �ڵ�Ѻ�ڼ���һ������ʹ��ά���������ڲ��꽫��û�ա�
�����üҾ߿���ȥ�Ҿ��̵꿴��������˼Ҿ߿��Է���
  (fangzhi)����ļ���Ҿ��Ժ�����㲻��Ҫ��Ҳ����
  ��������(banzou)��

ף��������죡��
LONG
);
}

	set(SAFE_ENV,1);
	set("valid_startroom", 1);
	set("master_id","blackedge");	// ������ ID��
	set("master_name","����"); // ��������������
	set("exits",([
	"north" : "/d/path1/cc_tch17",
	]));

	call_out("check_room",1);
	setup();
        create_door("north", "����", "south", DOOR_CLOSED,LOCKED,__DIR__"blackedge_key");

}

string query_save_file()
{
	return HOME_DIR+"path1/blackedge_home_data";
}

void check_room()
{
	if(!query("built_time"))
	{
		set("built_time", time());
		return;
	}
	PLAYERHOME_D->check_player_room(this_object());
}

void init()
{
	add_action("do_changelong","changelong");
	add_action("do_baocun","baocun");
	add_action("do_list","list");
	add_action("do_quzou","quzou");
	add_action("do_save","save");
	add_action("do_fangzhi","fangzhi");
	add_action("do_banzou","banzou");
	add_action("do_check", "check");
}

int do_check(string arg)
{
	object me = this_player();
	int time, btime,des, tmp;
	string out;
	mapping bank;

	if( (me->query("id") != query("master_id"))
	&& !wizardp(me) )
		return 0;

	time = time();
	out = "����״̬��\n";

	if(!(btime = query("built_time")) || (btime < 0))
	{
		set("built_time", time);
		btime = time;
	}

	des = time - btime;

	if(des >= 0)
	{
		out += "������Ҫȥ���ɷ������ɷ���\n";
		if(des <= WORN_TIME)
		{
			tmp = (WORN_TIME - des)/1440;
			if(!tmp)
				out += "������Ҫȥ���ɷ������ɷ���\n  ��������ܿ�����ưܲ���\n";
			else
				out += sprintf("  �����Լ���� %d ������ͻ����ưܲ���\n", tmp);
		}
		else if(time <= BREAKDOWN_TIME)
		{
			tmp = (BREAKDOWN_TIME - des)/1440;
			if(!tmp)
				out += "������Ҫȥ�Ͽ���ɷ������ɷ���\n  �����������ϻᵹ����\n";
			else
				out += sprintf("  �����Լ���� %d ��������ܻᵹ����\n", tmp);

		}
		else
			out += "����Ҫ����ȥ���ɷ������ɷѣ���\n  �ܲ������ü�ֻ������֪����\n";
	}
	else
	{
		tmp = abs(des/1440);
		if(!tmp)
			out += "����ķ������ɷ����Ͼ�Ҫ������\n";
		else
			out += sprintf("����ķ������ɷѻ���֧�� %d ��\n", tmp);
	}

	if(mapp(bank = query("bank")))
	{
		des = bank["time"] - time;

		if(des >= 0)
		{
			tmp = des/1440;
			if(!tmp)
				out += "����ķ��������н����˵�Ѻ\n  �Ͻ�ȥ����ɣ��ܲ������ü�������˵��\n";
			else
				out += sprintf("����ķ��������н����˵�Ѻ\n  ��Լ���� %d ���Ҫ������\n", tmp);
		}
		else
			out += "����ķ��������н����˵�Ѻ\n  �����������շ��Ӱ�\n";
	}

	write(out);
	return 1;
}

int do_save(string arg)
{
	object link_ob,me = this_player();

	if(me->query("id") != query("master_id"))
	{
		if( !objectp(link_ob = me->query_temp("link_ob")) )
		{
                	write("�㲻�Ǿ����������߽��룬���ܴ��档\n");
			return 1;
		}
		if( (int)link_ob->save() && (int)me->save() )
		{
			write("����������ϡ�\n");
			return 1;
		}
		else
		{
			write("����ʧ�ܡ�\n");
			return 1;
		}
	}
	return 0;
}

int do_changelong(string arg)
{
	string str;
	object me = this_player();

	if(me->query("id") != query("master_id"))
		return notify_fail("��������Ƿ���ר�����\n");

	write("Ϊ������������ۣ�ÿһ���벻Ҫ������ʮ��������֡�\n");
	write("��һ�е����ݳ��ȱ������еĳ��������������ֿ���ܶ��롣\n");
	this_player()->edit( (: get_long , str :) );
	return 1;
}

void get_long(string str, string text)
{
	if( sizeof( explode(text, "\n") ) > 8 )
	{
		write("�뽫���ļ�ͥ���������ڲ��������С�\n");
		return ;
	}	

	set("long",text);
	save();
	write("ok.\n");
	return;
}

int do_list(string arg)
{
	string out;

	if(!arrayp(save_objs) || !sizeof(save_objs))
		return notify_fail("����û�б����κ���Ʒ��\n");

	out = "���ﱣ�����Ʒ�У�\n";

	foreach(class s_ob tmp in save_objs)
	{
		object ob;

		if(tmp->file->is_self_object())
		{
			ob = new(tmp->file, tmp->arg);
			out += sprintf("%s(%s)\n", ob->name(), ob->query("id"));
			destruct(ob);
		}
		else
			out += sprintf( "%s(%s)\n", tmp->file->name(), tmp->file->query("id"));
	}
	write(out);
	return 1;
}

int do_baocun(string arg)
{
	object obj,me = this_player();
	class s_ob tmp;

	if(!arg || arg == "")
		return notify_fail("��Ҫ����ʲô��\n");

	if(!obj = present(arg,me))
		obj = present(arg,this_object());
	if(!obj)
		return notify_fail("��Ҫ����ʲô��\n");

	if(obj->is_character())
		return notify_fail("��Ҫ����ʲô��\n");

#ifdef WIZARD_FLAG
	if(obj->query_wiz_flag())
	{
		sys_log("wiz_ob",sprintf("%s��ͼ��%s�ļ�լ˽����ʦ��Ʒ %s ��û��.%s\n",
			geteuid(me),query("master_id"),base_name(obj),ctime(time())));
		write(obj->name()+"����ʦ��Ʒ��û���ˣ�����������������������,�������Ը�.\n");
		destruct(obj);
		return 1;
	}
#endif

	if(sizeof(save_objs) >= CAN_SAVE_OBJECT)
		return notify_fail("��䷿������Ҳ���治�¸������Ʒ�ˡ�\n");

	if(obj->is_food() || obj->is_liquid())
		return notify_fail("�ԺȵĶ������Ǳ���ڼ���ĺá�\n");

	if(obj->query("money_id"))
		return notify_fail("Ǯ���Ǵ���������Ƚ��׵���\n");

	if(obj->query_credit_point_flag() || obj->no_save_in_home())
		return notify_fail("����������ܱ��档\n");

	if(obj->is_weapon() && obj->query("weapon_mangle"))
		return notify_fail("��������Ѿ����ˣ���ȥ�޺����ڱ���ɡ�\n");

	if(obj->is_armor() && obj->query("armor_mangle"))
		return notify_fail("��������Ѿ����ˣ���ȥ�޺����ڱ���ɡ�\n");

	if(obj->query_amount() && (obj->query_amount() > 1))
		return notify_fail("��һ��ֻ�ܱ���һ����Ʒ��\n");

	if(obj->is_container() && sizeof(all_inventory(obj)))
		return notify_fail(sprintf("��һ��ֻ�ܱ���һ����Ʒ�����Ƚ�%s�����Ʒȡ����\n",obj->name()));

	tmp = new(class s_ob);
	tmp->file = base_name(obj);
	tmp->arg = obj->query_save_args();

	if(!arrayp(save_objs) || !sizeof(save_objs))
		save_objs = ({ tmp });
	else
		save_objs += ({ tmp });

	if(obj->is_ctl_ob())
		CTLOB_D->save_to_mud(base_name(obj));

	destruct(obj);
	save();
	write("ok.\n");
	return 1;
}

int do_quzou(string arg)
{
	class s_ob *tt = ({});
	object ob;

	if(!arrayp(save_objs) || !sizeof(save_objs))
		return notify_fail("����û�б����κ���Ʒ��\n");

	if(!stringp(arg) || !sizeof(arg))
		return notify_fail("��Ҫȡ��ʲô��Ʒ��\n");

	foreach(class s_ob tmp in save_objs)
	{
		object idob;

		if(!objectp(ob))
		{
			if(tmp->file->is_self_object())
			{
				idob = new(tmp->file, tmp->arg);
				if(idob->id(arg))
					ob = idob;
				else
				{
					destruct(idob);
					tt += ({ tmp });
				}
			}
			else if(tmp->file->id(arg))
				ob = new(tmp->file, tmp->arg);
			else
				tt += ({ tmp });
		}
		else
			tt += ({ tmp });
	}

	if(!objectp(ob))
		return notify_fail("�������Ʒ��û�������Ʒ��\n");

	if(ob->is_ctl_ob())
		CTLOB_D->delete_from_mud(base_name(ob));

	if(!ob->move(this_player()))
		ob->move(this_object());

	save_objs = tt;
	save();

	write(sprintf("�㽫%sȡ�˳�����\n", ob->name()));
	return 1;
}

int do_fangzhi(string arg)
{
	object me = this_player();
	string f;
	mapping obs,t_obs;
	int *sum,n;

	if(me->query("id") != query("master_id"))
		return 0;

	if( !(f = me->query_temp("furniture")) )
		return notify_fail("�����û�������üҾ�ѽ��\n");

	me->delete_temp("furniture");
	obs = query("objects");
	if(!obs || !sizeof(obs))
		set("objects",([f:1]));
	else
	{
		sum = values(obs);
		for(int i=0;i<sizeof(sum);i++)
			n += sum[i];
		if(n >= MAX_FUR)
			return notify_fail("�����������Ҳ���ò��¸���ļҾ��ˡ�\n");

		else if(!undefinedp(obs[f]))
			obs[f]++;
		else
			obs += ([f:1]);
		set("objects",obs);
	}

	if(mapp(t_obs = query_temp("objects")))
	{
		foreach(string file,mixed ob in t_obs)
		{
			if(objectp(ob))
				destruct(ob);
			if(arrayp(ob))
			{
				for(int i=0;i<sizeof(ob);i++)
					if(objectp(ob[i]))
						destruct(ob[i]);
			}
		}

	}
	delete_temp("objects");
	
	save();
	setup();
	write(sprintf("С��ư�%s�͵�����ڷźã�һת���ֲ����ˡ�\n",f->name()));
	return 1;
}

int do_banzou(string arg)
{
	object ob,me=this_player();
	string f;
	mapping obs,t_obs;

	if(me->query("id") != query("master_id"))
		return 0;

	if(!stringp(arg))
		return notify_fail("��Ҫ����ʲô�Ҿߣ�\n");

	ob = present(arg,this_object());
	if(!ob)
		return notify_fail("��Ҫ����ʲô�Ҿߣ�\n");

	f = base_name(ob);

	obs = query("objects");

	if(undefinedp(obs[f]) || !obs[f])
		return notify_fail("��Ҫ����ʲô�Ҿߣ�\n");

	obs[f]--;
	if(!obs[f])
		map_delete(obs,f);
	message_vision("���߰�$n�����������˳�ȥ��\n",me,ob);
	destruct(ob);
	set("objects",obs);

	if(mapp(t_obs = query_temp("objects")))
	{
		foreach(string file,mixed obj in t_obs)
		{
			if(objectp(obj))
				destruct(obj);
			if(arrayp(obj))
			{
				for(int i=0;i<sizeof(ob);i++)
					if(objectp(obj[i]))
						destruct(obj[i]);
			}
		}

	}
	delete_temp("objects");

	save();
	setup();
	return 1;
}

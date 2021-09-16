// team.c
// by Find.

#include <ansi.h>
#include <command.h>
#include <dbase.h>
#include <origin.h>

/*
object can_guard()	// �Ƿ���������˵���
void release_array()	// ��ɢ��
int refresh_array()	// ˢ����Ա: 1 ������ 0 �󷨱���ɢ
*/
class zhenfa
{
	object *memb;		// �󷨳�Ա
	string type;		// �󷨵��书����
	int num;		// �󷨵�Ҫ������
	object master;		// ����
	string name;		// ������
	string menpai;		// ����������
	int ready;		// �������
	int array_level;	// �󷨵�������Чֵ
	int level;		// ���󷨵���Ч�ȼ�
	string zhen_fn;		// ���ļ���
}

/* ��������
1����ԱΪͬһ����
2�����Ტ�� enable ͬһ��
3����ǰ��ʹ�ñ���Ϊ��Ҫ��ı���
4���ﵽ��Ҫ������
5��������ͬ

�ƶ���Ա����������
����ˢ����״̬
������״̬�仯Ҫ��ѯ�� enable zhuang xie
����ս���е�������
	�����ߵֵ������� busy���������١�����ڵ͡����˵ֵ�һ���Լ�ͣһ��
	�󷨳�Ա����ս��״̬����Ա��ȫԱ���롢�󷨿�ʼ������
	�󷨵��ع� �ջõ����ǵ��˵��������

*/

class team
{
	object *memb;
	object leader;
}

nosave class zhenfa zhen;
nosave object leader;
nosave class team oteam;

//protected 
void init_zhen()
{
	zhen = new(class zhenfa);
	zhen->memb = ({});
}

// ����Ϊ��ѯ����
int in_array()
{
	if(!classp(zhen))
		return 0;

	if(!arrayp(zhen->memb))
		return 0;

	zhen->memb -= ({0});
	return sizeof(zhen->memb);
}

object query_array_obstructor()
{
	if(!in_array() || !zhen->ready)
		return 0;

	foreach(object ob in zhen->memb)
	{
		mapping db;

		if(!ob
		|| (ob == this_object())
		|| ob->is_busy())
			continue;

		db = ob->query_entire_dbase();
		if( (db["kee"] > db["max_kee"]*3/5)
		&& (db["sen"] > db["max_sen"]*3/5) )
			return ob;
	}

	return 0;
}

int query_array_level()
{
	if(!in_array() || !zhen->ready)
		return 0;

	return zhen->array_level>4000?4000:zhen->array_level;
}

void check_array_status()
{
	int i,n;
	string ski;

	if(!in_array())
		return;

	if((n=sizeof(zhen->memb)) < zhen->num)
	{
		if(zhen->ready)
			zhen->ready = 0;
		return;
	}

	ski = zhen->zhen_fn->query_array_id();
	zhen->array_level = 0;

	for(i=0;i<n;i++)
	{
		if(!living(zhen->memb[i]))
			break;

		if(zhen->memb[i]->query_temp("on_rided"))
			break;

		if(zhen->memb[i]->query_current_skill() != zhen->type)
			break;

		if(environment(zhen->memb[i]) != environment(zhen->master))
			break;

		zhen->array_level += zhen->memb[i]->query_skill(ski,1);

		if(zhen->memb[i] == zhen->master)
			continue;
	}

	if(i<n)
	{
		if(zhen->ready)
			zhen->ready = 0;
		return;
	}

	zhen->array_level = (zhen->array_level)*(zhen->level)/(zhen->num);

	if(!zhen->ready)
	{
		zhen->ready = 1;
		message_vision((zhen->zhen_fn)->success_msg(),zhen->master);
	}
}

string query_array_name()
{
	if(!classp(zhen))
		return 0;

	return zhen->name;
}

object query_array_master()
{
	if(!classp(zhen))
		return 0;

	return zhen->master;
}

object *query_array_member()
{
	if(!classp(zhen))
		return 0;

	return zhen->memb;
}

string query_array_fn()
{ return zhen->zhen_fn; }

int query_array_status()
{ return classp(zhen) && zhen->ready && (sizeof(zhen->memb - ({0})) >= zhen->num); }

// ����Ϊ�жϺ���
int can_become_member(object who)
{
	if(!who)
		return 0;

	if(environment(who) != environment())
		return notify_fail("û������ˡ�\n");

	if(!in_array())
		return notify_fail("��û�����κ�����֮�С�\n");

	if(zhen->master != this_object())
		return notify_fail("�㲢����������\n");

	if(sizeof(zhen->memb) >= zhen->num)
		return notify_fail(sprintf("��%s���������Ѿ���%s�����ˡ�\n",
			zhen->name,
			chinese_number(zhen->num)));

	if(!living(who))
		return notify_fail(who->name()+"Ŀǰ�޷�������˵�����Ȼ����˵�ɡ�\n");

	if(!zhen->zhen_fn)
	{
		init_zhen();
		return 0;
	}

	if(!zhen->zhen_fn->valid_member(who))
		return 0;

	return 1;
}

int is_array_member(object who)
{
	if(!who || !in_array())
		return 0;
	return member_array(who,zhen->memb) != -1;
}

int is_array_master()
{
	return in_array() && (zhen->master == this_object());
}

// ����Ϊ״̬�������
int set_array(class zhenfa z)
{
	if(!classp(z))
		return 0;

	if( !z->master
	|| !previous_object()
	|| (previous_object() != z->master) )
		return 0;

	zhen = z;
	return 1;
}

int add_array_member(object who)
{
	if(!can_become_member(who))
		return 0;

	foreach(object ob in zhen->memb)
		if(who->is_fighting(ob))
			return notify_fail(sprintf("�����ں͡�%s���ĳ�Ա%s����أ�\n",
				zhen->name,ob->name()));

	zhen->memb += ({ who });

	if(!who->set_array(zhen))
	{
		zhen->memb -= ({ who });
		return notify_fail("�����󷨳�Աʧ�ܡ�\n");
	}

	tell_object(this_object(),sprintf("%sӦ�����������ֵġ�%s����\n",
		who->name(),zhen->name));
	message("tell_object",sprintf("��%s����%sӦ�����롺%s����\n",
		zhen->name,who->name(),zhen->name),(zhen->memb - ({who})) );

	check_array_status();

	return 1;
}

int build_up_array(string f_name)
{
	if(in_array())
	{
		tell_object(this_object(),sprintf("�����ڡ�%s���У��޷������������󷨡�\n",
			zhen->name));
		return 0;
	}

	if(!f_name || (file_size(f_name+".c") <= 0))
	{
		tell_object(this_object(),"�󷨴���\n");
		return 0;
	}

	init_zhen();

	zhen->memb += ({ this_object() });
	zhen->master = this_object();
	zhen->num = f_name->query_member_num();
	zhen->name = f_name->query_name();
	zhen->menpai = f_name->query_menpai();
	zhen->zhen_fn = f_name;
	zhen->type = f_name->query_array_skill();
	zhen->level = f_name->query_effective_level();

	if(!zhen->num || !zhen->name || !zhen->type || !zhen->level)
	{
		init_zhen();
		tell_object(this_object(),"�󷨲�������\n");
		return 0;
	}

	return 1;
}

varargs int release_array(int flag)
{
	object me = this_object();

	if(!in_array())
		return notify_fail("�㲢û�����κ���֮�С�\n");

	if(zhen->master != me)
		return notify_fail(sprintf("ֻ���������ܽ�ɢ��%s����\n",zhen->name));

	zhen->memb -= ({ me });

	switch (flag)
	{
		case 0: // array ����������ɢ
			if(sizeof(zhen->memb))
				message("tell_object",sprintf("��%s����%s����%s����ɢ�ˡ�\n",
					zhen->name,me->name(),zhen->name),zhen->memb );
			tell_object(me,sprintf("�㽫��%s����ɢ�ˡ�\n",zhen->name));
			break;

		case 1: // ��������
			if(sizeof(zhen->memb))
				message("tell_object",sprintf("��%s������������%s��������%s����ɢ�ˡ�\n",
					zhen->name,me->name(),zhen->name),zhen->memb );
			break;

		case 2: // �����뿪��Ϸ
			if(sizeof(zhen->memb))
				message("tell_object",sprintf("��%s������������%s�뿪��Ϸ����%s����ɢ�ˡ�\n",
					zhen->name,me->name(),zhen->name),zhen->memb );
			break;

		case 3: // ʧɢ
			//if(sizeof(zhen->memb))
			//	message("tell_object",sprintf("��%s�������ں�����%sʧɢ����%s����ɢ�ˡ�\n",
			//		zhen->name,me->name(),zhen->name),zhen->memb );
			tell_object(me,sprintf("����û��������Ա����%s���Զ���ɢ�ˡ�\n",zhen->name));
			break;
		case 4: // ���Բ���
			if(sizeof(zhen->memb))
				message("tell_object",sprintf("��%s������������%s���Բ��ѣ���%s����ɢ�ˡ�\n",
					zhen->name,me->name(),zhen->name),zhen->memb );
			break;
		case 5:
			if(sizeof(zhen->memb))
				message("tell_object",sprintf("��%s���������ڲ���Ա������ڧ����%s����ɢ�ˡ�\n",
					zhen->name,zhen->name),zhen->memb );
			break;
	}

	if(sizeof(zhen->memb))
		(zhen->memb)->init_zhen();

	init_zhen();
	return 1;
}

// ����Ϊ״̬�ı�֪ͨ
varargs void dismiss_array_member(object who,int flag) // ��Ա���
{
// flag = 4 ���Բ���
// flag = 3 ��ʧ
// flag = 2 quit
// flag = 1 dead
	string out;

	if(!objectp(who)
	|| !in_array()
	|| (who == zhen->master)
	|| (zhen->master != this_object())
	|| (member_array(who,zhen->memb) == -1) )
		return;

	zhen->memb -= ({ who });
	who->init_zhen();
	tell_object(who,sprintf("\n�������ˡ�%s����\n\n",zhen->name));

	if(sizeof(zhen->memb) <= 1)// ���ں�������Աʧɢ
	{
		tell_object(zhen->master,sprintf("\n%s�����ˡ�%s����\n\n",who->name(),zhen->name));
		release_array(3);
		return;
	}

	switch (flag)
	{
		case 4:
			out = "���Բ���";
			break;
		case 2:
			out = "�뿪��Ϸ";
			break;
		case 1:
			out = "����";
			break;
		default:
			out = "��������";
			break;
	}

	if(zhen->ready)
	{
		message("tell_object",sprintf("��%s��������%s%s����%s����������ʧ�ˡ�\n",
			zhen->name,who->name(),out,zhen->name),zhen->memb );
		zhen->ready = 0;
	}
	else
		message("tell_object",sprintf("��%s��������%s%s����%s��ʧȥ��һ����Ա��\n",
			zhen->name,who->name(),out,zhen->name),zhen->memb );

}

void test_array()
{
	object me = this_object(),*lv = ({}),env = environment();
	int i,n;

	if( !(n = in_array()) || (n == 1))
		return;

	if(zhen->master == me)
	{
		for( i=0;i<n;i++ )
			if(environment(zhen->memb[i]) != env)
				lv +=({  zhen->memb[i] });
		if(n = sizeof(lv))
		{
			string out = "";

			zhen->memb -= lv;

			message("tell_object",sprintf("�������ˡ�%s����\n",zhen->name),lv);
			lv->init_zhen();

			switch (n)
			{
				case 1:
					out = lv[0]->name();
					break;
				case 2:
					out = sprintf("%s��%s",lv[0]->name(),lv[1]->name());
					break;
				default:
					for(i=0;i<n;i++)
						out += i==0?lv[i]->name():
							( (i==n-1)?sprintf("��%s",lv[i]->name()):
								sprintf("��%s",lv[i]->name()) );
			}

			if(sizeof(zhen->memb) <= 1)
			{
				tell_object(me,sprintf("��%s����%s�������󷨡�\n",
					zhen->name,out));
				release_array(3);
				return;
			}

			else if(zhen->ready)
			{
				message("tell_object",sprintf("��%s��������%s�������󷨣���%s����������ʧ�ˡ�\n",
					zhen->name,out,zhen->name),zhen->memb);
				zhen->ready = 0;
			}
			else
				message("tell_object",sprintf("��%s����%s�����ˡ�%s����\n",
					zhen->name,out,zhen->name),zhen->memb);
		}
		return;
	}

	else if(env != environment(zhen->master))
	{
		(zhen->master)->dismiss_array_member(me);
		return;
	}
}

void change_skill_status(string arg)
{
	if(!in_array())
		return;

	if( !stringp(arg)
	|| (file_size(SKILL_D(arg)+".c") <= 0) )
		return;

	if( (arg != zhen->type) && zhen->ready)
	{
		message("tell_object",sprintf("��%s��������%sû��ʹ��%s����%s����������ʧ�ˡ�\n",
			zhen->name,
			this_object()->name(),
			to_chinese(zhen->type),
			zhen->name),
				zhen->memb);
		zhen->ready = 0;
		return;
	}

	if( (arg == zhen->type) && !zhen->ready)
		check_array_status();
}
// ***************************************


// ���鲿��
// ��ѯ�Ƿ���һ��������
int in_team()
{
	if(classp(oteam))
	{
		oteam->memb -= ({0});
		if(sizeof(oteam->memb) <= 1)
			oteam = 0;
	}

	return classp(oteam) && sizeof(oteam->memb);
}

object query_team_leader()
{
	if(!classp(oteam) || !oteam->leader)
		return 0;
	else
		return oteam->leader;
}

// ��ѯ��������г�Ա
object *query_team_member()
{
	if(!classp(oteam) || !oteam->leader)
		return 0;

	oteam->memb -= ({0});
	return oteam->memb;
}

// ��ѯ�Ƿ�Ϊ�����Ա
int is_team_member(object who)
{
	if(!who || !in_team())
		return 0;

	return (member_array(who, oteam->memb) != -1);
}

// �Ƿ�Ϊ��������
int is_team_leader()
{
	if(!in_team())
		return 0;

	return (oteam->leader == this_object());
}

varargs void dismiss_team(object who)
{
	if(!in_team())
		return;

	if(!who)
	{
		if(is_team_leader())
		{
			oteam->memb -= ({ this_object() });
			(oteam->memb)->set_team_data(0);
			message("team", HIW "�����顿�����ɢ�ˡ�\n", oteam->memb);
			oteam = 0;
			return;
		}
		else
			return (oteam->leader)->dismiss_team(this_object());
	}
	else
	{
		if(!is_team_leader())
			return;

		tell_object(who, "����������ˡ�\n");
		oteam->memb -= ({ who });
		who->set_team_data(0);
		if(sizeof(oteam->memb) <= 1)
		{
			tell_object(this_object(), sprintf("����%s�뿪���飬�����ɢ�ˡ�\n",who->name()));
			oteam = 0;
			return;
		}

		else
		{
			message("team", sprintf(HIW "�����顿%s�����˶��顣\n" NOR,who->name(1)), oteam->memb);
			(oteam->memb)->set_team_data(oteam);
			return;
		}
	}
}

void check_team()
{
	object env, *ob = ({});

	if(!in_team())
		return;

	env = environment();

	if(!is_team_leader())
	{
		if(environment(oteam->leader) != env)
			(oteam->leader)->dismiss_team(this_object());
	}

	else
	{
		foreach(object tmp in oteam->memb)
		{
			if(tmp == this_object())
				continue;
			if(environment(tmp) != env)
				ob += ({tmp});
		}

		if(sizeof(ob))
			foreach(object tmp in ob)
				dismiss_team(tmp);
	}
}

void set_team_data(class team temp)
{
	if(in_team() && is_team_leader())
		return;
	oteam = temp;
}

// ��������Աֻ�������촦��
int add_team_member(object who)
{
	if(!who)
		return 0;

	if(in_team() && !is_team_leader())
		return 0;

	if(!in_team())
	{
		oteam = new(class team);
		oteam->leader = this_object();
		oteam->memb = ({ this_object(), who });

		who->set_team_data(oteam);
		tell_object(this_object(), sprintf("%sӦ��������Ķ��顣\n", who->name()));
		return 1;
	}
	else
	{
		oteam->memb -= ({0});
		message("team", sprintf(HIW "�����顿%sӦ��������顣\n" NOR,who->name(1)), oteam->memb);
		oteam->memb += ({who});
		(oteam->memb)->set_team_data(oteam);
		return 1;
	}
}
//////////////////////////

int set_leader(object ob)
{
	if( ob==this_object() )
		//error("set_leader: Cannot set this_object() as leader.\n");
		return 0;
	leader = ob;
	return 1;
}

object query_leader() { return leader; }

int follow_path(string dir)
{
	if( (origin()==ORIGIN_LOCAL) || (origin()==ORIGIN_CALL_OUT) )
	{
		this_object()->remove_all_enemy();
		return GO_CMD->main(this_object(), dir);
	}
}

int follow_me(object ob, string dir)
{
	if( !living(this_object()) || ob==this_object() ) return 0;

	if( ( (ob==leader) && !ob->in_array() && !in_array() && !in_team() )	// array ���ܺͱ��˷��� follow ��ϵ
	|| (in_array() && zhen->master == ob )
	|| (in_team() && ob == oteam->leader)
	|| (query("pursuer") && this_object()->is_killing(ob->query("id")))) 
	{

		if(this_object()->query_temp("have_been_rided")
		&& ob->query_temp("on_rided") 
		&& ob->query_temp("on_rided") == this_object())
		{
			if(!environment(this_object())->valid_leave(this_object(),dir))
			{
				ob->delete_temp("on_rided");
				if(ob->query_temp("add/dodge"))
				{
					ob->add_temp("apply/dodge",-(int)ob->query_temp("add/dodge"));
					ob->delete_temp("add/dodge");
				}
				this_object()->delete_temp("have_been_rided");
				this_object()->set_leader(0);
				tell_object(ob,"�������û�ܺ���һ�������\n");
				return 1;
			}
			else
			{
				tell_object(ob,"������"+this_object()->name()+"���˹�����\n");
				return follow_path(dir);
			}
		}

		else if(ob->query("ride"))
		{
			if(this_object()->query_temp("on_rided"))
			{
				if( (int)(this_object()->query_temp("on_rided"))->query("ride/dodge")
				< (int)ob->query("ride/dodge") )
				{
				tell_object(this_object(),ob->name()+"�Ľ���̫�죬�������׷�����ˡ�\n");
				return 1;
				}
			}
			else if((int)this_object()->query_skill("dodge",1)
			< ((ob->query("ride/dodge")) ? (int)(ob->query("ride/dodge"))*50 : 50) )
			{
				tell_object(this_object(),ob->name()+"�Ľ���̫�죬��׷�����ˡ�\n");
				return 1;
			}
		}

		else if(ob->query_temp("on_rided"))
		{
			if( this_object()->query_temp("on_rided"))
			{
				if ( (int)(this_object()->query_temp("on_rided"))->query("ride/dodge")
				< (int)(ob->query_temp("on_rided"))->query("ride/dodge") )
				{
				tell_object(this_object(),ob->name()+"���������̫�죬�������׷�����ˡ�\n");
				return 1;
				}
			}
			else if((int)this_object()->query_skill("dodge",1)
			< ((ob->query_temp("on_rided"))->query("ride/dodge") ? 
			 (int)((ob->query_temp("on_rided"))->query("ride/dodge"))*50 : 50) )
			{
				tell_object(this_object(),ob->name()+"���������̫�죬��׷�����ˡ�\n");
				return 1;
			}
		}
		return follow_path(dir);
	}
}

// renyi_d.c
// by Find.

/*
 �ͽ�λΪ gold

// ����������Ӧ��ʾ�˴�
// ��ɱ������Ӧ��ʾ�˴�
// ��ȡ����ʱ�� 24 Сʱ��һСʱ��ѯһ��ʱ���Ƿ�


��ȡ�����ڼ䲻��ɱ�������
��������

�쵽������˻�ױ�����ǹ㲥Ƶ����tell whisper ���ֲ�������

�������ׯ��ױ

���ܷɵ�����ׯ

ע�� id here ������

��ȡ������˲�������ɱĿ����������ˣ�������ҡ�npc��

���� 100 ����˲���������

�����ͽ�ǰʮ��

���͵�Ҫ�󣬱�һ����ɱ�˲������������

����������ˣ�Ҫ�����������

�����ɱ�ļ�¼Ҫ���棬�����Ƿ�ɱһ��ֻ������һ�Σ�
*/

#include <renyi.h>

protected class bang eybang;

protected void create()
{
	seteuid(getuid());
}

protected int check_legal_id(string id)
{
	if( !stringp(id) || (strlen(id) < 3) || (strlen(id) > 10) )
		return 0;
	return 1;
}

protected int check_legal_caller(object ob)
{
	object ey = find_object(ENYI_ROOM);

	if(!ob)
		return 0;

	if( (geteuid(ob) == ROOT_UID) || (objectp(ey) && (ob == ey)) )
		return 1;

	return 0;
}

varargs mixed *query_killer_detail(string killer)
{
	if(!check_legal_caller(previous_object()))
		return 0;

	return DATABASE_D->db_query_killer_detail(killer);
}

// ��ѯ����ִ��׷ɱ killer �����͵� ID
string query_xiake_id(string killer)
{
	if(!check_legal_id(killer)
	|| !check_legal_caller(previous_object()) )
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return DATABASE_D->db_query_xiake_id(killer);
}

// ��ѯ��������׷ɱ�������˵� ID
string query_killer_id(string xiake)
{
	if(!check_legal_id(xiake)
	|| !check_legal_caller(previous_object()) )
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return DATABASE_D->db_query_killer_id(xiake);
}

// ��ѯ��� id ��ǰ��û������
int query_have_killer_quest(string id)
{
	if(!check_legal_id(id) || !check_legal_caller(previous_object()))
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return sizeof(DATABASE_D->db_query_killer_id(id));
}

// ��ѯ�Ƿ��д��˵����ͼ�¼
int query_have_killer(string id)
{
	if(!check_legal_id(id) || !check_legal_caller(previous_object()))
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return sizeof(DATABASE_D->db_query_killer_detail(id));
}


// ��������������
int accept_xiake_quest(string killer, object me)
{
	string xid;

	if(!check_legal_caller(previous_object())
	|| !me
	|| (!xid = geteuid(me))
	|| !check_legal_id(killer)
	|| !check_legal_id(xid))
		return 0;

	if(killer == xid)
		return SAME_XID_KID;

	if(!find_object(DATABASE_D))
		return 0;

	return DATABASE_D->db_accept_xiake_quest(killer, xid, me->name(1));
}

// ������������
int return_xiake_quest(string xiake)
{
	if(!check_legal_caller(previous_object())
	|| !check_legal_id(xiake) )
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return DATABASE_D->db_return_xiake_quest(xiake);
}

// �������˸�����������
void killer_change_cname(string killer, string cname)
{
	object ob;

	if(!check_legal_id(killer) && (strlen(cname) < 2))
		return;

	if(!objectp(ob = previous_object()) || (geteuid(previous_object()) != "Object") )
		return;

	return DATABASE_D->db_killer_change_cname(killer,cname);
}

// ����������ɱ
void killer_suicided(string killer)
{
	if(!check_legal_id(killer) || !check_legal_caller(previous_object()))
		return;

	return DATABASE_D->db_killer_suicided(killer);
}

// ������ɱ
void xiake_suicided(string xiake)
{
	if(!check_legal_id(xiake) || !check_legal_caller(previous_object()))
		return;

	return_xiake_quest(xiake);
}

// һСʱ����һ�ε�ǰ�����������(һ������24Сʱ����ɾ��Զ�ȡ��)
void update_killer_table()
{
	object ob;
	string *xks, kid;

	if(!objectp(ob = previous_object())
	|| (geteuid(ob) != ROOT_UID) )
		return;

	xks = DATABASE_D->db_update_killer_table();

	if(sizeof(xks))
		foreach(string id in xks)
		{
			object login, user;

			if( (file_size(sprintf(DATA_DIR"login/%c/%s.o",id[0],id)) <= 0)
			|| (file_size(sprintf(DATA_DIR"user/%c/%s.o",id[0],id)) <= 0) )
				continue;

			if(!objectp(user = find_player(id)))
			{
				login = new(LOGIN_OB);
				login->set("id", id);
				if( !login->restore() )
				{
					destruct(login);
					continue;
				}
				if( objectp(user = LOGIN_D->make_body(login)) )
					user->restore();
				else
				{
					destruct(login);
					continue;
				}
				destruct(login);
				if( stringp(kid = user->query("enyi_class/finish"))
				&& (user->query("enyi_class/id") == kid) )	// ���������
					DATABASE_D->db_killer_suicided(kid);
				else
					DATABASE_D->db_return_xiake_quest(id);

				user->delete("enyi_class");
				user->save();
				destruct(user);
			}
			else
			{
				if( stringp(kid = user->query("enyi_class/finish"))
				&& (user->query("enyi_class/id") == kid) )	// ���������
				{
					DATABASE_D->db_killer_suicided(kid);
					tell_object(user, "\n\n���Ѿ��������ׯ����������񵫾ܲ����ͣ����������ׯ�����ˡ�\n��Ļ�ױ��ʧЧ�ˡ�\n\n\n");
				}
				else
				{
					DATABASE_D->db_return_xiake_quest(id);
					tell_object(user, "\n\n��û�������������ׯ�����������\n��Ļ�ױ��ʧЧ�ˡ�\n\n\n");
				}

				user->delete("enyi_class");
				user->remove_mask_name();
				user->remove_mask_id();
				user->save();
			}
		}
}

// ��鱻������
int check_valid_killer(string id)
{
	object login,user;

	if(!check_legal_caller(previous_object()))
		return 0;

	if( !stringp(id) || (strlen(id) < 3) )
		return 0;

	if( (file_size(sprintf(DATA_DIR"login/%c/%s.o",id[0],id)) <= 0)
	|| (file_size(sprintf(DATA_DIR"user/%c/%s.o",id[0],id)) <= 0) )
		return NO_THIS_USER;

	if(!objectp(user = find_player(id)))
	{
		login = new(LOGIN_OB);
		login->set("id", id);
		if( !login->restore() )
		{
			destruct(login);
			return NO_THIS_USER;
		}
		if( objectp(user = LOGIN_D->make_body(login)) )
			user->restore();
		else
		{
			destruct(login);
			return NO_THIS_USER;
		}
		destruct(login);
		if(user->query("age") <= PROTECT_AGE)
		{
			destruct(user);
			return IN_PROTECTED;
		}
		destruct(user);
	}
	else if(user->query("age") <= PROTECT_AGE)
		return IN_PROTECTED;

	return 1;
}

// �����ͽ�
// ���ܡ��ͽ��Ѵﵽ���ߡ����������Ѵﵽ���� *
int accept_award_gold(string id, int gold)
{
	object login,user;
	string name, shimen;
	mapping family;

	if( (gold <= 0)
	|| !check_legal_id(id)
	|| !check_legal_caller(previous_object()) )
		return 0;

	if( (file_size(sprintf(DATA_DIR"login/%c/%s.o",id[0],id)) <= 0)
	|| (file_size(sprintf(DATA_DIR"user/%c/%s.o",id[0],id)) <= 0) )
		return NO_THIS_USER;

	if(!objectp(user = find_player(id)))
	{
		login = new(LOGIN_OB);
		login->set("id", id);
		if( !login->restore() )
		{
			destruct(login);
			return NO_THIS_USER;
		}
		if( objectp(user = LOGIN_D->make_body(login)) )
			user->restore();
		else
		{
			destruct(login);
			return NO_THIS_USER;
		}
		destruct(login);
		if(user->query("age") <= PROTECT_AGE)
		{
			destruct(user);
			return IN_PROTECTED;
		}
		if(mapp(family = user->query("family")))
			shimen = family["family_name"];
		name = user->name(1);
		destruct(user);
	}
	else
	{
		if(user->query("age") <= PROTECT_AGE)
			return IN_PROTECTED;
		else if(mapp(family = user->query("family")))
			shimen = family["family_name"];
		name = user->name(1);
	}

	if(!find_object(DATABASE_D))
		return DATABASE_NO_READY;

	return DATABASE_D->db_accept_killer_award(gold, id, name, shimen);
}

// �����������
int finish_renyi_quest(string xid, string kid)
{
	if( !check_legal_id(kid)
	|| !check_legal_id(xid)
	|| !check_legal_caller(previous_object()) )
		return 0;

	return DATABASE_D->db_finish_renyi_quest(xid,kid);
}

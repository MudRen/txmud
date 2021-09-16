// renyi_d.c
// by Find.

/*
 赏金单位为 gold

// 改名部分相应提示此处
// 自杀部分相应提示此处
// 领取任务时间 24 小时，一小时查询一次时间是否到


领取任务期间不能杀其它玩家
退任务功能

领到任务的人化妆，但是广播频道，tell whisper 部分不受限制

进入恩义庄化妆

不能飞到恩义庄

注意 id here 的问题

领取任务的人不能主动杀目标人以外的人（包括玩家、npc）

低于 100 万的人不能领任务

产生赏金前十名

悬赏的要求，被一个人杀了才能悬赏这个人

如果侠客死了，要解除侠客任务

被玩家杀的纪录要保存，考虑是否被杀一次只能悬赏一次？
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

// 查询正在执行追杀 killer 的侠客的 ID
string query_xiake_id(string killer)
{
	if(!check_legal_id(killer)
	|| !check_legal_caller(previous_object()) )
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return DATABASE_D->db_query_xiake_id(killer);
}

// 查询侠客正在追杀的悬赏人的 ID
string query_killer_id(string xiake)
{
	if(!check_legal_id(xiake)
	|| !check_legal_caller(previous_object()) )
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return DATABASE_D->db_query_killer_id(xiake);
}

// 查询这个 id 当前有没有任务
int query_have_killer_quest(string id)
{
	if(!check_legal_id(id) || !check_legal_caller(previous_object()))
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return sizeof(DATABASE_D->db_query_killer_id(id));
}

// 查询是否有此人的悬赏纪录
int query_have_killer(string id)
{
	if(!check_legal_id(id) || !check_legal_caller(previous_object()))
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return sizeof(DATABASE_D->db_query_killer_detail(id));
}


// 侠客来接受任务
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

// 侠客来退任务
int return_xiake_quest(string xiake)
{
	if(!check_legal_caller(previous_object())
	|| !check_legal_id(xiake) )
		return 0;

	if(!find_object(DATABASE_D))
		return 0;

	return DATABASE_D->db_return_xiake_quest(xiake);
}

// 被悬赏人更改了中文名
void killer_change_cname(string killer, string cname)
{
	object ob;

	if(!check_legal_id(killer) && (strlen(cname) < 2))
		return;

	if(!objectp(ob = previous_object()) || (geteuid(previous_object()) != "Object") )
		return;

	return DATABASE_D->db_killer_change_cname(killer,cname);
}

// 被悬赏人自杀
void killer_suicided(string killer)
{
	if(!check_legal_id(killer) || !check_legal_caller(previous_object()))
		return;

	return DATABASE_D->db_killer_suicided(killer);
}

// 侠客自杀
void xiake_suicided(string xiake)
{
	if(!check_legal_id(xiake) || !check_legal_caller(previous_object()))
		return;

	return_xiake_quest(xiake);
}

// 一小时更新一次当前有任务的侠客(一次任务24小时不完成就自动取消)
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
				&& (user->query("enyi_class/id") == kid) )	// 任务已完成
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
				&& (user->query("enyi_class/id") == kid) )	// 任务已完成
				{
					DATABASE_D->db_killer_suicided(kid);
					tell_object(user, "\n\n你已经完成仁义庄交给你的任务但拒不领赏，奖金归仁义庄所有了。\n你的化妆都失效了。\n\n\n");
				}
				else
				{
					DATABASE_D->db_return_xiake_quest(id);
					tell_object(user, "\n\n你没能如期完成仁义庄交给你的任务。\n你的化妆都失效了。\n\n\n");
				}

				user->delete("enyi_class");
				user->remove_mask_name();
				user->remove_mask_id();
				user->save();
			}
		}
}

// 检查被悬赏人
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

// 接受赏金
// 接受、赏金已达到上线、悬赏人数已达到上限 *
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

// 侠客完成任务
int finish_renyi_quest(string xid, string kid)
{
	if( !check_legal_id(kid)
	|| !check_legal_id(xid)
	|| !check_legal_caller(previous_object()) )
		return 0;

	return DATABASE_D->db_finish_renyi_quest(xid,kid);
}

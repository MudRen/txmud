// databased.c
// by Find.

#include <renyi.h>
#include <station.h>
#include "/adm/etc/database.h"

class target
{
	string host;
	string user;
	mapping quest;
}

#ifdef STATIC_LINK
protected int db_handle = 0;
#endif

protected mixed *all_target = ({});
protected int max_repeat = 3;
protected void broadcast(string sql);

protected void init_target()
{
	if(!sizeof(all_others_db))
		return;

	foreach(string h,string u in all_others_db)
	{
		class target one;

		one = new(class target);
		one->host = h;
		one->user = u;
		one->quest = ([]);
		all_target += ({ one });
	}
}


protected void log_error(string func,mixed err)
{
	log_file("database",sprintf("%s ERROR ** %s\n%O\n",func,ctime(time()),err));
}

#ifdef STATIC_LINK
protected void connect_to_database()
#else
protected int connect_to_database()
#endif
{
	mixed n;

	n = db_connect(DB_HOST, DATABASE, DB_USER);

	if(intp(n) && (n > 0))	// ���ӳɹ�
#ifdef STATIC_LINK
	{
		db_handle = n;
		return;
	}
#else
		return n;
#endif

	else
	{
		log_error("db_connect",n);
#ifdef STATIC_LINK
		call_out("connect_to_database",30);
		return;
#endif
		return 0;
	}
}

protected void close_database(int db)
{
	mixed ret;

	if(!intp(db) || (db < 1))
		return 0;

	ret = db_close(db);

	if(intp(ret) && (ret == 1))
		return;

	else
		log_error("db_close",ret);
}

protected void create()
{
	seteuid(ROOT_UID);
#ifdef STATIC_LINK
	connect_to_database();
#endif
	init_target();
}

protected int valid_caller()
{
	if( !previous_object()
	|| (previous_object() != find_object(SIMUL_EFUN_OB)) )
		return 0;

	else
		return 1;
}

// ��ѯ�������Ƿ����
int db_permit_add_cname(string name)
{
	int db;
	mixed ret;
	string sql;

	if(!valid_caller())
		return 0;

	if( !stringp(name) || (name == "") )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT id FROM %s WHERE name = \"%s\"",REGISTERED_TABLE,name);
	ret = db_exec(db,sql);
	if(!intp(ret) || ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		if(!intp(ret))
			log_error("permit_add_cname.db_exec",ret);
		return 0;
	}

	sql = sprintf("SELECT id FROM %s WHERE name = \"%s\"",TEMP_TABLE,name);
	ret = db_exec(db,sql);
#ifndef STATIC_LINK
	close_database(db);
#endif
	if(!intp(ret))
	{
		log_error("permit_add_cname.db_exec",ret);
		return 0;
	}

	return !(ret);
}

// ������ʼ���ַ�ܷ�ע��
int db_permit_reg_email(string email)
{
	int db;
	mixed ret;
	string sql;

	if(!valid_caller())
		return 0;

	if( !stringp(email) || (email == "") )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT id FROM %s WHERE email = \"%s\"",REGISTERED_TABLE,email);
	ret = db_exec(db,sql);
	if(!intp(ret) || ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		if(!intp(ret))
			log_error("permit_reg_email.db_exec",ret);
		return 0;
	}

	sql = sprintf("SELECT id FROM %s WHERE email = \"%s\"",TEMP_TABLE,email);
	ret = db_exec(db,sql);
#ifndef STATIC_LINK
	close_database(db);
#endif
	if(!intp(ret))
	{
		log_error("permit_reg_email.db_exec",ret);
		return 0;
	}

	return !(ret);
}

// ��ѯָ��ʱ��δ�ɹ�ע������
string *db_query_exceed_reg_time()
{
	int db,i,n;
	string sql,*player;
	mixed ret;

	if(!valid_caller())
		return 0;
#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT id FROM %s WHERE station = \"%s\" AND (UNIX_TIMESTAMP() - UNIX_TIMESTAMP(dtime)) > %d",
		TEMP_TABLE, local_station, reg_time);
	ret = db_exec(db,sql);
	if(!intp(ret) || !ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		if(!intp(ret))
			log_error("query_exceed_reg_time.db_exec",ret);
		return 0;
	}

	player = allocate(ret);
	for(i=1; i <= ret; i++)
		player[i-1] = db_fetch(db,i)[0];

	foreach(string id in player)
	{
		sql = sprintf("DELETE FROM %s WHERE id = \"%s\"", TEMP_TABLE, id);
		ret = db_exec(db,sql);
		if(!intp(ret))
		{
			log_error("query_exceed_reg_time.db_exec(DEL)",ret);
			log_file("database",sprintf("%O\n\n",player));
		}

		n = db_affected(db);
		if( n < 1 )
			log_error("query_exceed_reg_time.db_exec(DEL)",sprintf("Can not del (%s)",id));

		broadcast(sql);
	}

#ifndef STATIC_LINK
	close_database(db);
#endif

	return player;
}

// ɾ��һ��δע�����
int db_del_temp_user(string id)
{
	int db,n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",TEMP_TABLE, id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("del_temp_user(%s).db_exec",id),ret);
		return 0;
	}

	n = db_affected(db);
	if(n < 1)
		log_error(sprintf("del_temp_user(%s).db_exec",id),"Fail to del.\n");

#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

// ɾ��һ����ʽע�����
int db_del_reg_user(string id)
{
	int db,n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",REGISTERED_TABLE, id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("del_reg_user(%s).db_exec",id),ret);
		return 0;
	}
	n = db_affected(db);
	if(n < 1)
		log_error(sprintf("del_reg_user(%s).db_exec",id),"Fail to del.\n");

// ����񲿷�
	sql = sprintf("DELETE FROM %s WHERE kid = \"%s\"",RENYI_BANG, id);
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
		log_error(sprintf("del_reg_user(%s).renyi",id),ret);
		return 0;
	}

#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

// ɾ�����״̬δ֪
int db_del_unknow_user(string id)
{
	int db,n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	// �Ȳ�ѯ TEMP_TABLE
	sql = sprintf("SELECT id FROM %s WHERE id = \"%s\"",TEMP_TABLE,id);
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("select (%s) from tmp_table.db_exec",id),ret);
		return 0;
	}

	if(ret) // �ҵ�
	{
		sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",TEMP_TABLE, id);
		ret = db_exec(db,sql);
		if(!intp(ret))
		{
			log_error(sprintf("del_temp_user(%s).db_exec",id),ret);
			return 0;
		}

		broadcast(sql);

		n = db_affected(db);
		if(n < 1)
			log_error(sprintf("del_temp_user(%s).db_exec",id),"Fail to del.\n");
#ifndef STATIC_LINK
		close_database(db);
#endif
		return n;
	}

	else
	{
		sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",REGISTERED_TABLE, id);
		ret = db_exec(db,sql);
		if(!intp(ret))
		{
			log_error(sprintf("del_reg_user(%s).db_exec",id),ret);
			return 0;
		}
		n = db_affected(db);
		if(n < 1)
			log_error(sprintf("del_reg_user(%s).db_exec",id),"Fail to del.\n");

		broadcast(sql);

#ifndef STATIC_LINK
		close_database(db);
#endif
		return n;
	}
}


/************************
 *  ����ҵ���������
 ***********************/

int db_newbie_buildup(string id,string name)
{
	int db, n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == "")
	|| !stringp(name) || (name == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT id FROM %s WHERE id = \"%s\"",TEMP_TABLE,id);
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("newbie_buildup(%s).db_exec",id),ret);
		return 0;
	}

	if(ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return 0;
	}

	sql = sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\",NULL,NOW(),\"%s\")",TEMP_TABLE,id,name,local_station);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("newbie_buildup(%s).db_exec",id),ret);
		return 0;
	}

	n = db_affected(db);
#ifndef STATIC_LINK
	close_database(db);
#endif

	return n;
}

int db_newbie_reg(string id, string email)
{
	int db, n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == "")
	|| !stringp(email) || (email == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("UPDATE %s SET email = \"%s\" WHERE id = \"%s\"",TEMP_TABLE,email,id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("newbie_reg(%s).db_exec",id),ret);
		return 0;
	}

	n = db_affected(db);

#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

int db_newbie_success_reg(string id)
{
	int db,n;
	string sql,*res;
	mixed ret;

	if(!valid_caller())
		return 0;

	if(!stringp(id) || (id == ""))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT name,email FROM %s WHERE id = \"%s\"",TEMP_TABLE,id);
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("newbie_success(select %s).db_exec",id),ret);
		return 0;
	}

	if(!ret)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error("newbie_success.db_exec",sprintf("can not find (%s) from tmp_table",id));
		return 0;
	}

	res = db_fetch(db,1);

	sql = sprintf("DELETE FROM %s WHERE id = \"%s\"",TEMP_TABLE,id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error("newbie_success.db_exec",sprintf("can not delete (%s) from tmp_table",id));
		return 0;
	}
	n = db_affected(db);
	if(n < 1)
		log_error("newbie_success.db_exec",sprintf("did not delete (%s) from tmp_table",id));

	sql = sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\",\"%s\",\"%s\",NULL,NULL)",REGISTERED_TABLE,id,res[0],res[1],local_station);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("newbie_success(insert %s).db_exec",id),ret);
		return 0;
	}

	n = db_affected(db);
#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

/************************
 *  newbie_buildup, newbie_reg, newbie_success
 ***********************/

// ����
int db_change_chinese_name(string id,string to)
{
	int db,n;
	string sql;
	mixed ret;

	if(!valid_caller())
		return 0;

	if( !stringp(id) || (id == "")
	|| !stringp(to) || (to == "") )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("UPDATE %s SET name = \"%s\" WHERE id = \"%s\"",
		REGISTERED_TABLE, to, id);
	ret = db_exec(db,sql);

	broadcast(sql);

	if(!intp(ret))
	{
		log_error(sprintf("change_chinese_name(%s.to%s).db_exec",id,to),ret);
		return 0;
	}

	n = db_affected(db);

#ifndef STATIC_LINK
	close_database(db);
#endif
	return n;
}

// �������е���ʽע���������
int db_count_reg_user()
{
	int db;
	mixed ret,*res;

	if(!valid_caller())
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	ret = db_exec(db,sprintf("SELECT COUNT(*) FROM %s",REGISTERED_TABLE));
	if(!intp(ret) || (ret < 1))
	{
		log_error("count_reg_user",ret);
		return 0;
	}

	res = db_fetch(db,1);
#ifndef STATIC_LINK
	close_database(db);
#endif

	return res[0];
}

// ��ѯ������ڵķ�վ
string db_query_register_station(string id)
{
	int db;
	mixed ret,*res;

	if(!valid_caller())
		return 0;

	if( !stringp(id) || (id == "") )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	ret = db_exec(db,sprintf("SELECT station FROM %s WHERE id = \"%s\"",TEMP_TABLE,id));

	if(!intp(ret))
	{
		log_error("query_register_station",ret);
		return 0;
	}

	if(ret > 0)
	{
		res = db_fetch(db,1);
		return res[0];
	}

	ret = db_exec(db,sprintf("SELECT station FROM %s WHERE id = \"%s\"",REGISTERED_TABLE,id));

	if(!intp(ret))
	{
		log_error("query_register_station",ret);
		return 0;
	}

	if(ret > 0)
	{
		res = db_fetch(db,1);
		return res[0];
	}

	else
		return 0;
}

/******************
 * �䵱���ֵĲ�ѯ *
 ******************/

//������ĳһ�ض�����������ģ�δ���ڵ�������Ʒ��
mixed *query_user_all_pob(string id)
{
	int db,time;
	mixed ret, *res;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)
	|| !id
	|| !stringp(id) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	time = time();
	ret = db_exec(db, sprintf("SELECT * FROM %s WHERE id = \"%s\" AND ptime > %d",PAWN_TABLE,id,time));
	if(!intp(ret))
	{
		log_error("query_user_all_pob",ret);
		return 0;
	}

	if(ret < 1)
		return 0;

	res = allocate(ret);
	for(int i=1;i<=ret;i++)
		res[i-1] = db_fetch(db,i);

#ifndef STATIC_LINK
	close_database(db);
#endif
	return res;
}

// ����һ������ѵ䵱��Ʒ��������
int query_count_user_pob(string id)
{
	int db,n;
	mixed ret;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)
	|| !id
	|| !stringp(id) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	ret = db_exec(db, sprintf("SELECT COUNT(*) FROM %s WHERE id = \"%s\"",PAWN_TABLE,id));
	if(!intp(ret))
	{
		log_error("query_user_all_pob",ret);
		return 0;
	}

	if(ret < 1)
		return 0;

	n = db_fetch(db,1)[0];
#ifndef STATIC_LINK
	close_database(db);
#endif

	return n;
}

// �䵱һ����Ʒ
int pawn_one_object(mixed *pob)
{
	int db,n;
	string sql;
	mixed ret;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)
	|| !pob
	|| !sizeof(pob) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

//                                            master, pob,time, shop, long
	sql = sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\",%d,\"%s\",\"%s\")",
		PAWN_TABLE,
		pob[0],pob[1],pob[2],pob[3],pob[4]);
	ret = db_exec(db,sql);
	if(!intp(ret))
	{
		log_error("pawn_one_object",ret);
		return 0;
	}

	n = db_affected(db);

#ifndef STATIC_LINK
	close_database(db);
#endif
	return (n > 0);
}

// ���һ����Ʒ
int retrieve_one_object(string id,int time)
{
	int db,n;
	mixed ret;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)
	|| !stringp(id)
	|| (id == "")
	|| (time <= 0) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	ret = db_exec(db,sprintf("SELECT id FROM %s WHERE id = \"%s\" AND ptime = %d",PAWN_TABLE,id,time));
	if(!intp(ret))
	{
		log_error(sprintf("retrieve_one_object(%s,%d)",id,time),ret);
		return 0;
	}

	if(ret < 1)
		return -1;

	ret = db_exec(db,sprintf("DELETE FROM %s WHERE id = \"%s\" AND ptime = %d",PAWN_TABLE,id,time));
	if(!intp(ret))
	{
		log_error(sprintf("retrieve_one_object(%s,%d)",id,time),ret);
		return 0;
	}

	n = db_affected(db);

#ifndef STATIC_LINK
	close_database(db);
#endif

	return (n > 0);
}

// ���һ��������еĵ䵱Ʒ
void del_user_all_pob(string id)
{
	int db;
	mixed ret;

	if(!valid_caller())
		return;

	if(!stringp(id) || (id == ""))
		return;

#ifdef STATIC_LINK
	if(!db_handle)
		return;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return;
#endif

	ret = db_exec(db,sprintf("DELETE FROM %s WHERE id = \"%s\"",PAWN_TABLE,id));
#ifndef STATIC_LINK
	close_database(db);
#endif
	if(!intp(ret))
	{
		log_error(sprintf("del_user_all_pob(%s)",id),ret);
		return;
	}
}

// ������е���δ��ص���Ʒ
string *query_all_exceed_pob()
{
	int db,time,all,n;
	mixed ret,*res;

	if( !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	time = time();
	ret = db_exec(db,sprintf("SELECT obj FROM %s WHERE ptime <= %d",PAWN_TABLE,time));
	if(!intp(ret))
	{
		log_error("query_all_exceed_pob",ret);
		return 0;
	}

	if(ret < 1)
		return 0;

	res = allocate(ret);
	for(int i=1; i<= ret; i++)
		res[i-1] = db_fetch(db,i)[0];

	all = ret;

	// ����д������ûЧ��
	ret = db_exec(db,sprintf("DELETE FROM %s WHERE ptime <= %d",PAWN_TABLE,(time+2)));
	if(!intp(ret))
		log_error(sprintf("del_all_exceed_pob(%d)",(time+2)),ret);

	n = db_affected(db);

	if(n < all)
		log_error(sprintf("del_all_exceed_pob(%d)",(time+2)),sprintf("except %d, get %d.\n",all,n));

	return res;
}

#ifdef STATIC_LINK
void remove(string id)
{
	if(!valid_caller())
		return;

	close_database(db_handle);
}
#endif

protected void broadcast(string sql)
{
	if(!all_target || !sizeof(all_target))
		return;

	foreach(class target one in all_target)
		one->quest += ([ sql : 0 ]);

	if(find_call_out("do_broadcast") == -1)
		call_out("do_broadcast",3);
}

protected void do_broadcast()
{
	mixed n;
	int flag = 0;

	if(!sizeof(all_others_db) || !sizeof(all_target))
		return;

	foreach(class target one in all_target)
	{
		if(sizeof(one->quest))
		{
			n = db_connect(one->host, DATABASE, one->user);
			if(intp(n) && (n > 0))	// ���ӳɹ�
			{
				foreach(string sql,int num in one->quest)
				{
					mixed ret;
					ret = db_exec(n,sql);
					if( intp(ret) && (db_affected(n) > 0) )
					{
						map_delete(one->quest,sql);
						continue;
					}
					else if( ++one->quest[sql] >= max_repeat )
					{
#ifdef STATIC_LINK
						if(!db_handle)
							log_error(sprintf("Fail add fail cmd to: %s",one->host),sql);
						else
							db_exec(db_handle,sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\")",
								FAIL_CMD_TABLE, one->host, sql));
							
#else
						int db;

						if(!(db = connect_to_database()))
							log_error(sprintf("Fail add fail cmd to: %s",one->host),sql);
						else
							db_exec(db,sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\")",
								FAIL_CMD_TABLE, one->host, sql));
#endif
						map_delete(one->quest,sql);
					}
				}
				db_close(n);
			}
			if(sizeof(one->quest))
				flag++;
		}
	}

	if(flag)
		call_out("do_broadcast",10);
}

// ����Ϊ����񲿷�
// �����ͽ�
int db_accept_killer_award(int gold, string id, string name, string shimen)
{
	object ob;
	string sql;
	mixed ret;
	int db, n;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return 0;

	if( (gold <= 0) || !id || !name)
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	// �ּ����û�����͹������
	sql = sprintf("SELECT shangjin FROM %s WHERE kid = \"%s\"", RENYI_BANG, id);

	ret = db_exec(db, sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
	close_database(db);
#endif
		log_error(sprintf("db_accept_killer_award(%s,%d)",id,gold),ret);
		return 0;
	}

	if(ret < 1)	// û�����͹�����
	{
		sql = sprintf("SELECT COUNT(*) FROM %s ", RENYI_BANG);

		ret = db_exec(db, sql);

		if(!intp(ret))
		{
#ifndef STATIC_LINK
	close_database(db);
#endif
			log_error(sprintf("db_accept_killer_award(%s,%d)",id,gold),ret);
			return 0;
		}
		n = db_fetch(db,1)[0];

		if(n >= MAX_KILLER_NUM)
		{
#ifndef STATIC_LINK
	close_database(db);
#endif
			return GET_MAX_KILLER_NUM;
		}

		sql = sprintf("INSERT INTO %s VALUES (\"%s\",\"%s\",%s,NOW(),%d,NULL,NULL,NULL)",
			RENYI_BANG, id, name, 
			shimen?sprintf("\"%s\"",shimen):"NULL", gold);

		ret = db_exec(db, sql);

#ifndef STATIC_LINK
		close_database(db);
#endif
		if(!intp(ret))
		{
			log_error(sprintf("db_accept_killer_award insert (%s,%d)",id,gold),ret);
			return 0;
		}
		return SUCCESS_ACCEPT;
	}

	else
	{
		n = db_fetch(db,1)[0];

		if(2000000000 - n < gold)	// �����������ͽ���
		{
#ifndef STATIC_LINK
			close_database(db);
#endif
			return AWARD_GET_MAX;
		}

		sql = sprintf("UPDATE %s SET shangjin=shangjin+%d WHERE kid = \"%s\"",
			RENYI_BANG, gold, id);

		ret = db_exec(db, sql);

#ifndef STATIC_LINK
		close_database(db);
#endif
		if(!intp(ret))
		{
			log_error(sprintf("db_accept_killer_award add (%s,%d)",id,gold),ret);
			return 0;
		}
		return SUCCESS_ACCEPT;
	}
}

// ��������������
int db_accept_xiake_quest(string kid, string xid, string xname)
{
	mixed ret, *data;
	int db, n;
	string sql;
	object ob;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return 0;

	if(!kid || !xid || !xname)
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT kid,xid FROM %s where kid = \"%s\"", RENYI_BANG, kid);

	ret = db_exec(db, sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("db_accept_xiake_quest (kid: %s)",kid),ret);
		return 0;
	}

	if(ret < 1)	// û����˵����ͼ�¼
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return NO_THIS_KILLER;
	}

	data = db_fetch(db, 1);

	if(sizeof(data[1]))	// �Ѿ������������������
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return QUEST_BEEN_USE;
	}

	sql = sprintf("SELECT xid FROM %s where xid = \"%s\"", RENYI_BANG, xid);
	ret = db_exec(db, sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("db_accept_xiake_quest (xid: %s)",xid),ret);
		return 0;
	}

	if(ret > 0)	// �����Ѿ��������
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return HAVE_KQUEST;
	}

	sql = sprintf("SELECT COUNT(*) FROM %s WHERE xid IS NOT NULL", RENYI_BANG);
	ret = db_exec(db, sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("db_accept_xiake_quest (xid: %s)",xid),ret);
		return 0;
	}

	n = db_fetch(db, 1)[0];

	if(n >= MAX_XIAKE_NUM)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return GET_MAX_XIAKE_NUM;
	}

	sql = sprintf("UPDATE %s SET xid=\"%s\",xname=\"%s\",accept_time=NOW() WHERE kid = \"%s\"",
		RENYI_BANG, xid, xname, kid);
	ret = db_exec(db, sql);

#ifndef STATIC_LINK
	close_database(db);
#endif

	if(!intp(ret))
	{
		log_error(sprintf("db_accept_xiake_quest (xid: %s)",xid),ret);
		return 0;
	}

	return 1;
}

// ������
int db_return_xiake_quest(string xid)
{
	string sql;
	object ob;
	int db;
	mixed ret;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return 0;

	if(!xid)
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT kid FROM %s WHERE xid = \"%s\"", RENYI_BANG, xid);
	ret = db_exec(db, sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("db_return_xiake_quest (xid: %s)",xid),ret);
		return 0;
	}

	if(ret <= 0)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return HAVE_NO_KQUEST;
	}

	sql = sprintf("UPDATE %s SET xid=NULL,xname=NULL,accept_time=NULL WHERE xid = \"%s\"",RENYI_BANG,xid);
	ret = db_exec(db, sql);

#ifndef STATIC_LINK
	close_database(db);
#endif

	if(!intp(ret))
	{
		log_error(sprintf("db_return_xiake_quest (xid: %s)",xid),ret);
		return 0;
	}

	return 1;
}

// ��ѯĳ���������б������˵�����
varargs mixed *db_query_killer_detail(string kid)
{
	string sql;
	object ob;
	int db;
	mixed ret, *data;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	if(kid)
		sql = sprintf("SELECT kid,kname,shimen,shangjin,xid FROM %s WHERE kid = \"%s\"", RENYI_BANG, kid);
	else
		sql = sprintf("SELECT kid,kname,shimen,shangjin,xid FROM %s", RENYI_BANG);
	ret = db_exec(db, sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("db_query_killer_detail (kid: %s)",kid),ret);
		return 0;
	}

	if(ret <= 0)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return 0;
	}

	if(ret == 1)
		data = ({ db_fetch(db, 1) });
	else
	{
		data = allocate(ret);
		for(int i=0;i<ret;i++)
			data[i] = db_fetch(db, i+1);
	}

#ifndef STATIC_LINK
	close_database(db);
#endif

	return data;
}

//һЩС�Ĳ�ѯ����

// ��ѯ����ִ��׷ɱ kid �����͵� xid
string query_xiake_id(string kid)
{
	string sql, xid;
	object ob;
	int db;
	mixed ret;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return 0;

	if(!kid)
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT xid FROM %s WHERE kid = \"%s\"", RENYI_BANG, kid);
	ret = db_exec(db, sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("query_xiake_id (kid: %s)",kid),ret);
		return 0;
	}

	if(ret <= 0)	// �����޴���
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return 0;
	}

	xid = db_fetch(db, 1)[0];

#ifndef STATIC_LINK
	close_database(db);
#endif

	if(!sizeof(xid))
		return 0;

	return xid;
}

// ��ѯ���� xid ����׷ɱ�������˵� kid
string query_killer_id(string xid)
{
	string sql, kid;
	object ob;
	int db;
	mixed ret;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return 0;

	if(!xid)
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT kid FROM %s WHERE xid = \"%s\"", RENYI_BANG, xid);
	ret = db_exec(db, sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("query_xiake_id (kid: %s)",kid),ret);
		return 0;
	}

	if(ret <= 0)	// xid û����׷ɱ�κ���
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return 0;
	}

	kid = db_fetch(db, 1)[0];

#ifndef STATIC_LINK
	close_database(db);
#endif
	return kid;
}

// �������˸�����������
void db_killer_change_cname(string kid, string kname)
{
	string sql;
	object ob;
	int db;
	mixed ret;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return;

	if(!kid || !kname)
		return;

#ifdef STATIC_LINK
	if(!db_handle)
		return;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return;
#endif

	sql = sprintf("UPDATE %s SET kname=\"%s\" WHERE kid = \"%s\"", RENYI_BANG, kname, kid);

	ret = db_exec(db, sql);

#ifndef STATIC_LINK
	close_database(db);
#endif

	if(!intp(ret))
		log_error(sprintf("db_killer_change_cname (kid: %s, kname: %s)",kid, kname),ret);
}

// ����������ɱ
void db_killer_suicided(string kid)
{
	string sql;
	object ob;
	int db;
	mixed ret;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return;

	if(!kid)
		return;

#ifdef STATIC_LINK
	if(!db_handle)
		return;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return;
#endif

	sql = sprintf("DELETE FROM %s WHERE kid = \"%s\"",RENYI_BANG, kid);
	ret = db_exec(db,sql);

#ifndef STATIC_LINK
	close_database(db);
#endif

	if(!intp(ret))
		log_error(sprintf("db_killer_suicided (kid: %s)",kid),ret);
}

// ˢ�����Ͱ񣬷����ѵ��ڵ� xid
string *db_update_killer_table()
{
	string sql, *xid;
	object ob;
	int db;
	mixed ret;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT xid FROM %s WHERE xid IS NOT NULL AND (UNIX_TIMESTAMP() - UNIX_TIMESTAMP(accept_time)) >= %d",
		RENYI_BANG, QUEST_LAST_TIME);
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error("db_update_killer_table",ret);
		return 0;
	}

	if(ret <= 0)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return 0;
	}

	xid = allocate(ret);

	for(int i=0;i<ret;i++)
		xid[i] = db_fetch(db, i+1)[0];

#ifndef STATIC_LINK
	close_database(db);
#endif

	return xid;
}

// ������񣬷��� <= 0 ���� >0 Ϊ�������Ŀ
int db_finish_renyi_quest(string xid, string kid)
{
	string sql;
	object ob;
	int db;
	mixed ret, *tmp;

	if( !objectp(ob = previous_object()) || (ob != find_object(RENYI_D)) )
		return 0;

	if(!xid || !kid)
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT xid,shangjin FROM %s WHERE kid = \"%s\"", RENYI_BANG, kid);
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error(sprintf("db_finish_renyi_quest(xid: %s, kid:%s)",xid,kid),ret);
		return 0;
	}

	if(ret <= 0)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return NO_THIS_KILLER;
	}

	tmp = db_fetch(db, 1);
	if(!sizeof(tmp[0]) || (tmp[0] != xid))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return QUEST_BEEN_USE;
	}

	sql = sprintf("DELETE FROM %s WHERE kid = \"%s\"",RENYI_BANG, kid);
	ret = db_exec(db,sql);

#ifndef STATIC_LINK
	close_database(db);
#endif

	if(!intp(ret))
	{
		log_error(sprintf("db_killer_suicided (kid: %s)",kid),ret);
		return 0;
	}

	return tmp[1];
}

mixed *db_query_bang_top_ten()
{
	string sql;
	mixed ret, *data;
	int db;
	object ob;


	if( !objectp(ob = previous_object()) || (geteuid(ob) != ROOT_UID) )
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT kid,kname,shimen,shangjin FROM %s ORDER BY shangjin DESC LIMIT 10", RENYI_BANG);
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error("db_query_bang_top_ten",ret);
		return 0;
	}

	if(ret <= 0)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return 0;
	}

	if(ret == 1)
		data = ({ db_fetch(db, 1) });
	else
	{
		data = allocate(ret);
		for(int i=0;i<ret;i++)
			data[i] = db_fetch(db, i+1);
	}

#ifndef STATIC_LINK
	close_database(db);
#endif

	return data;
}

string db_query_killer_id(string xiake)
{
	string sql, kid;
	mixed ret;
	int db;
	object ob;

	if( !objectp(ob = previous_object()) || (geteuid(ob) != ROOT_UID) )
		return 0;

	if(!stringp(xiake) || !strlen(xiake))
		return 0;

#ifdef STATIC_LINK
	if(!db_handle)
		return 0;
	db = db_handle;
#else
	if(!(db = connect_to_database()))
		return 0;
#endif

	sql = sprintf("SELECT kid FROM %s WHERE xid = \"%s\"", RENYI_BANG, xiake);
	ret = db_exec(db,sql);

	if(!intp(ret))
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		log_error("db_query_bang_top_ten",ret);
		return 0;
	}

	if(ret <= 0)
	{
#ifndef STATIC_LINK
		close_database(db);
#endif
		return 0;
	}

	kid = db_fetch(db, 1)[0];

#ifndef STATIC_LINK
	close_database(db);
#endif

	return kid;
}

// playerhomed.c
// by ���ֺţ�find����

// ����,Կ��,��Կ��,����,�ܴ洢�Ķ�������,����ʱ��û����ɾ��,Կ�׵Ĵ������.
// �������÷�������: 1.��Ƥ�� 2.���ݷ�

// ��Ҹ������ݡ�Կ���Զ�������
// �� outdoors ���ܽ�
// û�г��ڵĵط����ܽ�
// set("cannot_build_home",1)�ķ��䲻�ܽ�
// ֻ�ܽ��� e,w,n,s �ĸ�����,����ռ�����ܽ�(��·��).
// GATE_ROOM ���ܽ�.
// ��� 18����ǰ���ܽ�.
// ��ʦ�Ͻ�����.
// �����������ڲ��ܽ���.
// player home ���ĸ��ȼ�: 1.é�ݷ� 2.�߷� 3.Ժ��(1Ժ1��) 4.��լ(1Ժ1���㷿)
// home ���ܴ�ŵ���Ʒ: 1. 3�� 2. 5�� 3. 7 �� 4.10 ��
// ���ڷ��������üҾߣ�ľ������������ľ�Ρ�̫ʦ�Ρ�ľ����˫��ͭ������ʱ��ô�ࣩ
// ���üҾ��ڼҾߵꡣ

// �����й����ס���Ĳ��־��ɴ�פ���������
// ���������ı��й����ס����״̬�������
// ��פ��������ĺ�����ʵ�֡�

#undef TEST_RUNNING	// �����ڼ�ȡ��һЩ���ơ�

#define	DIRS		({"north","south","west","east"})
#define ORIGIN_OBJ_DIR	PHOME_DIR+"origin_objs/"	// ��ҷ���,Կ�׵�ԭʼ������Ŀ¼.
#define WORN_TIME	525600	/* MUD ��һ�꣬������ʱ�䷿�ݱ�� */
#define BREAKDOWN_TIME	1051200 /* MUD �����꣬������ʱ�䷿�ݵ��� */
#define STARTROOM	"/d/changan/jiulou"
	/*�˷���Ϊ��ҷ��ݱ�ɾ�������ڵ���ұ��ƶ����˷��䣬�˷���Ӧ���� 'no_fight' */

inherit F_SAVE;
#include <domain_cost.h>	//���ɽ�������ĵ�Ƥ�ѡ�
#include <ansi.h>

class s_ob
{
	string file;
	mixed arg;
}

static mapping back_dir = ([
	"north" : "south",
	"south" : "north",
	"west"  : "east",
	"east"  : "west",
]);

mapping have_built = ([]);

#define head "\n/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/\n"
#define end "\n/*�����Զ��������.*/\n"

private int reduce_room_file(string file); /*�������ݻ�ԭ������ɾ����ҷ��ݡ�*/
private string replace_home_file(string file,object user,string env_file,string dir);
private int make_exit(object env,string dir,string phomefile,string key_file,string door,int msg_flag);
string *user_have_home(string id); /*�˺����ж�����Ƿ����Լ���ס��*/
private int key_change_name(string key_file,string old_name,string new_name);
private void do_delete_phome(string id,string domain);

// Ϊ���� security hole,�����¼����������С�
private int build_one(object user,object env,string dir);
private int build_two(object user,object env,string dir);
private int build_three(object user,object env,string dir);
private int build_four(object user,object env,string dir);
private static int *home_level_cost = ({ 1000000,2000000,4000000,6000000});

void create()
{
	seteuid(getuid());
	restore();
}

string query_save_file() { return DATA_DIR+"domain_built";}

mixed query_this_domain_cost(string domain)
{
	mapping costs;

	if(!stringp(domain))
		return 0;
	if(undefinedp(domain_cost[domain]))
		return 0;
	costs = copy(domain_cost)[domain];
	costs["origin_max"] = costs["max"];
	if(have_built[domain] && costs["max"] != -1)
		costs["max"] -= (int)have_built[domain];
	return costs;
}

int home_value(int level)
{
	if(!intp(level) || level < 1 || level >4)
		return 0;
	else
		return home_level_cost[level-1];
}

int can_make_home(object user/*Ҫ�󽨷���������*/,string dir/*Ҫ�󽨷��ķ���*/)
{
	object env;
	string domain;
	mapping exits,build;
	int cost,up = 0;

	if(!user || !userp(user))
		return 0;

#ifndef TEST_RUNNING
	if(wizardp(user))
	{
		write("��ʦ���������Լ��ķ���.\n");
		return 0;
	}
#endif

	if(user->query("age") < 18)
	{
		write("ʮ�˳����Ժ���ܽ���.\n");
		return 0;
	}

	if(!mapp(build = user->query("can_build_home")))
	{
		write("��ȥ���������������ɡ�\n");
		return 0;
	}

	if(undefinedp(build["level"]))
	{
		write("�㻹û�н��������ء�\n");
		return 0;
	}

	if(undefinedp(build["cost_domain"]))
	{
		write("�㻹û�н���Ƥ���ء�\n");
		return 0;
	}

	/* ��ҿɽ�����ǡ�û���� temp �����Ϊ��ֹ���ⶪʧ��
	 * can_build_home/level 1,2,3,4 �ĸ����ݵȼ�.
	 **************************************************
	 * can_build_home/where ������ʱ���뱻��׼�Ľ����ص㡣
	 * ����ǣ�浽 outdoors ��д�����������Ŀ¼�Ĺ������⣬
	 * ���������������ͳһ�涨��
	 * ��׼�����ڷ���(��ǡ��򡢴塢���ɵȺʹ�Ƭͬ�������
	 * ��ɭ�֡���ɽ�����������������ͳ���30������)��Ҫ�󵥷�Ŀ¼��
	 * ������������������ҪΨһ�����������ڵ�Ŀ¼�������������������
	 * �糤������������Ϊ changan,����������Ϊ�������ǣ�
	 * ���������ڵ�Ŀ¼Ϊ��changan.
	 * ��·���򣨼��������׼����֮��ĵ�·����������Ϊ
	 * �á�-�������·���˵����������ڱ��ֵ�·������Ψһ��ǰ
	 * ���µ�·���˵���������һ��д���˵�·�����Ŀ¼����Ϊ��
	 * ��·�������������
	 * �糤��������ĵ�·������Ϊ: cha-ft�������ڵ�Ŀ¼��Ϊcha-ft.
	 * ��������outdoors��Ǽ�Ϊ���������������Ҳ���Ǵ���������
	 * ��Ŀ¼�������е��������������������Ķ�Ӧ��Ҫ����
	 * �ֵ����ͨ�� to_chinese(������) �ɵõ���������������
	 * ����������ҲҪע�ⲻҪ����Ϸ���п����õ�������Ӣ��
	 * ������ͻ��������Խ����Խ��ȷԽ�á�
	 *****************************************************
	 * can_build_home/time  ����������ʱ�� time()��
	 * ��Ұ��������� mud_time 30��(43200��)�ڽ�����Ч������30�죬
	 * �۳�5%�������ѣ����ཨ�����˻���ҡ�
	 * �˿�ֳ����� logind �� autosave ���� daemon ��.
	 * ������һ�ֲ��ˣ��Ժ���˵��
	 ******************************************************
	 * can_build_home/cost_home ����Ѹ��Ľ������ݷ��ã����飩.
	 ******************************************************
	 * can_build_home/cost_domain ����Ѹ��Ľ�����Ƥ��.
	 ****************************************************/
	 
	if(!stringp(dir))	return 0;
	env = environment(user);
	if(!env)	return 0;

	if(!sscanf(file_name(env), "/d/%*s"))
	{
		write("����������ѽ����\n");
		return 0;
	}

	if( !stringp(domain = domain_file(file_name(env)))
	|| undefinedp(domain_cost) )
	{
		write("���ﲻ�ܽ�����\n");
		return 0;
	}

	if(dir == "w")
		dir = "west";
	else if(dir == "e")
		dir = "east";
	else if(dir == "s")
		dir = "south";
	else if(dir == "n")
		dir = "north";

	if(member_array(dir,DIRS) == -1)
	{
		write("��Ӷ����ϡ��������ĸ�������ѡ����Ľ���λ�á�\n");
		return 0;
	}

	// ��������Ϊ��һЩ�ڿɽ��������ڵ����ⷿ���õģ�
	// ��ĳ��լԺ���Ժ�ӡ�ɭ�֡�����ɽ���������ȣ�
	// ��outdoors��Ҳ�г��ڣ��������ֵط������ǲ�����ģ�
	// ����ڴ������ⷿ����Ҫ�� set��"cannot_build_home",1��,
	// ������ QC ʱҪע���ϸ�����෿��������ǡ�
	if(env->query("cannot_build_home") || virtualp(env))
	{
		write("���ﲻ�ܽ�����\n");
		return 0;
	}
	if(env->query("GATE_ROOM"))
	{
		write("���ﲻ�ܽ�����\n");
		return 0;
	}

	exits = env->query("exits");
	if(!mapp(exits))
	{
		write("���ﲻ�ܽ�����\n");
		return 0;		
	}

	if(sizeof(exits) >= 4)
		return notify_fail("�����Ѿ�û�еط������ˡ�\n");

	if(!undefinedp(exits["north"])
	&& !undefinedp(exits["south"])
	&& !undefinedp(exits["west"])
	&& !undefinedp(exits["east"]))
	{
		write("�����Ѿ�û�������ڽ����ĳ����ˡ�\n");
		return 0;
	}

	if(!(env->query("outdoors")))
	{
		write("���ﲻ�ܽ�����\n");
		return 0;
	}

	if( file_size(sprintf("%s%s/%s_home.c",PHOME_DIR,domain,user->query("id"))) > 0 )
	{
		write(sprintf("����%s�ѽ����Լ���סլ����������������ٽ����ˡ�\n",
			to_chinese(domain)));
		return 0;
	}

	if( (have_built[domain] && domain_cost[domain]["max"] != -1)
	&& (domain_cost[domain]["max"] <= (int)have_built[domain]) )
	{
		write("�����Ѿ�û�н�����ָ���ˡ�\n");
		return 0;
	}

/*
	if(member_array(user->query("can_build_home/where"),domains) == -1)
	{
		write("BUG!! ��׼�Ľ��������ڿɽ��������б��ڣ�������ʦ���档\n");
		return 0;
	}
*/
	cost = domain_cost[domain]["cost"];
	if(have_built[domain])
		up = to_int(have_built[domain]*100/domain_cost[domain]["max"]*cost/10000/100)*10000;
	cost += up;

	if(build["cost_domain"] < cost)
	{
		write("�������ĵ�Ƥ�Ѳ����������ｨ����\n");
		return 0;
	}

	if( !undefinedp(domain_cost[domain]["min_level"])
	&& (build["level"] < domain_cost[domain]["min_level"]) )
	{
		if(domain_cost[domain]["min_level"] == 2)
		{
			write("�����ｨ������ҲҪ��һ���߷���\n");
			return 0;
		}
		else if(domain_cost[domain]["min_level"] == 3)
		{
			write("�����ｨ������ҲҪ��һ��լԺ��\n");
			return 0;
		}
		else if(domain_cost[domain]["min_level"] == 4)
		{
			write("����ֻ�ܽ��������լԺ��\n");
			return 0;
		}
	}

	if( !undefinedp(domain_cost[domain]["max_level"])
	&& (build["level"] > domain_cost[domain]["max_level"]) )
	{
		if(domain_cost[domain]["max_level"] == 1)
		{
			write("����ֻ�ܽ���é�ݷ���\n");
			return 0;

		}
		if(domain_cost[domain]["max_level"] == 2)
		{
			write("�����ﶥ��ֻ�ܽ�һ���߷���\n");
			return 0;
		}
		else if(domain_cost[domain]["max_level"] == 3)
		{
			write("�����ﶥ��ֻ�ܽ�һ��լԺ��\n");
			return 0;
		}
	}

	if(!undefinedp(exits[dir]))
	{
		write("��������Ѿ���������������ʩ��������ѡ��һ����������\n");
		return 0;
	}

	return 1;
}

int buildup_home(object user,string dir)
{
	object env = environment(user);
	string *valid_dirs,news;

	if(!user) return 0;
	if(!can_make_home(user,dir))
		return 0;

	valid_dirs = keys(back_dir);
	if(member_array(dir,valid_dirs) == -1)
		return 0;

	/*building_home �ڼ䲻������,�� quit.c ������.*/
	user->set("building_home",1);
	user->start_busy(1);
	switch( user->query("can_build_home/level") )
	{
		case 1:
			log_file("phome",sprintf("%s(%s)�� %s ������һ�� %d ��סլ.%s\n",
				user->name(),user->query("id"),
				domain_file(file_name(env)),1,ctime(time())));
			news = sprintf(HIG+"%s��%s������һ��é���ݰ����ڴˡ�\n"+NOR,user->name(),
				to_chinese(domain_file(file_name(env))));
			NEWS_D->add_news_item( news , "p", 1);
			return build_one(user,env,dir);
			break;
		case 2:
			log_file("phome",sprintf("%s(%s)�� %s ������һ�� %d ��סլ.%s\n",
				user->name(),user->query("id"),
				domain_file(file_name(env)),2,ctime(time())));
			news = sprintf(HIG+"%s��%s������һ����߷������ڴˡ�\n"+NOR,user->name(),
				to_chinese(domain_file(file_name(env))));
			NEWS_D->add_news_item( news , "p", 1);
			return build_two(user,env,dir);
			break;
		case 3:
			log_file("phome",sprintf("%s(%s)�� %s ������һ�� %d ��סլ.%s\n",
				user->name(),user->query("id"),
				domain_file(file_name(env)),3,ctime(time())));
			news = sprintf(HIG+"%s��%s������һ��լԺ�����ڴˡ�\n"+NOR,user->name(),
				to_chinese(domain_file(file_name(env))));
			NEWS_D->add_news_item( news , "p", 1);
			return build_three(user,env,dir);
			break;
		case 4:
			log_file("phome",sprintf("%s(%s)�� %s ������һ�� %d ��סլ.%s\n",
				user->name(),user->query("id"),
				domain_file(file_name(env)),4,ctime(time())));
			news = sprintf(HIG+"%s��%s������һ��������լԺ�����ڴˡ�\n"+NOR,user->name(),
				to_chinese(domain_file(file_name(env))));
			NEWS_D->add_news_item( news , "p", 1);
			return build_four(user,env,dir);
			break;
		
		write("��׼�������ʹ���\n");
		return 0;
	}
}

/* $KEYN ��Ҽ���Կ�׵���������.
 * $N ��ҵ���������. $DIR ��ҷ��ݵĳ��ڷ���.
 * $EXITOBJ ��ҷ��ݳ�������������ļ���.
 * $KEYOBJ  ��ҷ��ݵ�Կ��������ļ���.
 * $ID ��ҵ�Ӣ��id. $SAVEFILE ��ҷ��ݵ� save_file.
 * $TWOSAVEFILE ��ҵļҵĵڶ�������� save_file.
 * $THREESAVEFILE ��ҵļҵĵ���������� save_file.
 * $BDIR ��ҷ��ݵĳ��ڷ���ķ�����.
 */

// �˴�Ҫע�� config �������ִ����ȵĶ���.
private string replace_home_file(string file,object user,string env_file,string dir)
{
	string id = user->query("id");
	string domain = domain_file(env_file);

	file = replace_string(file,"$KEYN",sprintf("%s��%s",
		user->query("name"),to_chinese(domain)));
	file = replace_string(file,"$N",user->query("name"));
	file = replace_string(file,"$DIR",back_dir[dir]);
	file = replace_string(file,"$EXITOBJ",env_file);
	file = replace_string(file,"$KEYOBJ",id+"_key");
	file = replace_string(file,"$ID",id);
	file = replace_string(file,"$SAVEFILE",domain+"/"+id+"_home_data");
	file = replace_string(file,"$TWOSAVEFILE",domain+"/"+id+"_home_data2");
	file = replace_string(file,"$THREESAVEFILE",domain+"/"+id+"_home_data3");
	file = replace_string(file,"$BDIR",dir);
	return file;
}

// Ϊ���򷿼俪���ڡ�
// �˴����ǵ���һЩ����д����̫�淶�������
private int make_exit(object env,string dir,string phomefile,string key_file,string door,int msg_flag)
{
	string file,fsubfile,esubfile;
	int n,i;
	object *inv;
	string err;

	if(!file = read_file(file_name(env)+".c"))
		return 0;

	/*�ж��Ƿ�include room.h*/
	if(strsrch(file,"#include <room.h>") == -1)
		file = head+"#include <room.h>"+end+file;

	/*������*/
	n = strsrch(file,"void create()");	/*ֻ���� create() �����ڵ� exits*/
	if( n == -1)
	{
		log_file("playerhomed_log","Can't find create() function in "+
		file_name(env)+".c\n");
		return 0;
	}

	i = strsrch(file[n..],"set(\"exits\",");
	if( i == -1)
	{
		log_file("playerhomed_log","Can't find exits in "+
		file_name(env)+".c\n");
		return 0;
	}

	n = n+i+11;	/*��,��ʼ����,��д������Դ����Ŀո���������*/
	i = strsrch(file[n..],"([");
	if( i == -1)
	{
		log_file("playerhomed_log","Can't find begain of exits mapping in "+
		file_name(env)+".c\n");
		return 0;
	}

	n = n+i+1;
	fsubfile = file[0..n];
	esubfile = file[n+1..];

	file = fsubfile+head+"\t\""+dir+"\" : \""+phomefile+"\","+end+esubfile;

	/* ������ */
	i = strsrch(file[n..],"setup()");	/*��n�����ܱ�֤��create()������*/
	if(i == -1)
	{
		log_file("playerhomed_log","Can't find setup() function in create() in "+
		file_name(env)+".c\n");
		return 0;
	}

	n = n+i+6;
	i = strsrch(file[n..],";");
	if(i == -1)
	{
		log_file("playerhomed_log","Can't find end of setup() line in "+
		file_name(env)+".c\n");
		return 0;
	}

	n = n+i;	/*��д������Դ����Ŀո���������*/
	fsubfile = file[0..n];
	esubfile = file[n+1..];

	file = fsubfile+head+
	"\tcreate_door(\""+dir+"\", \""+door+"\", \""+back_dir[dir]+
	"\", DOOR_CLOSED,LOCKED,\""+key_file+"\");"+
	end+esubfile;

	write_file(file_name(env)+".c",file,1);

	/* reload env obj */
	file = file_name(env);
	if(env)
	{
		inv = all_inventory(env);
		i = sizeof(inv);
		while(i--)
		{
			if(inv[i]->is_character())
				inv[i]->move(VOID_OB, 1);
			else
				inv[i] = 0;
		}
		destruct(env);
	}

	if(env)
	{
		log_file("playerhomed_log","�޷���� "+
		file+".c �ľɳ�ʽ�롣\n");
		return 1;
	}

	err = catch( call_other(file, "???") );
	if(err)
	{
		log_file("playerhomed_log",err+"\n");
		return 1;
	}

	if((i=sizeof(inv)) && (env = find_object(file)))
	{
		while(i--)
		{
			if(inv[i] && inv[i]->is_character()) 
				inv[i]->move(env, 1);
		}
	}

	if(msg_flag && env)
	{
		switch(msg_flag)
		{
			case 1:
			tell_object(env,"ֻ��"+to_chinese(dir)+"�潨����һ��é�ݷ���\n");
			break;
			case 2:
			tell_object(env,"ֻ��"+to_chinese(dir)+"�潨����һ����߷���\n");
			break;
			case 3:
			tell_object(env,"ֻ��"+to_chinese(dir)+"�潨����һ��լԺ��\n");
			break;
			case 4:
			tell_object(env,"ֻ��"+to_chinese(dir)+"�潨����һ��������լԺ��\n");
			break;
		}
	}
	return 1;
}

private int build_one(object user,object env,string dir)
/* ����˵ķ���,�ȼ� 1. é�ݷ�*/
{
	string file,key_file,env_file;
	string id,phome,pkey,domain;
	object key_ob,phome_ob;

	if(!user || !env)
		return 0;
	env_file = file_name(env);
	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_one.c"),
	user,env_file,dir);
	if(!stringp(file))
		return 0;
	key_file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"player_key.c"),
	user,env_file,dir);
	if(!stringp(key_file))
		return 0;

	id = user->query("id");
	phome = PHOME_DIR+domain_file(env_file)+"/"+id+"_home";
	pkey  = PHOME_DIR+domain_file(env_file)+"/"+id+"_key";

	assure_file(phome);
	write_file(phome+".c",file,1);
	write_file(pkey+".c",key_file,1);

	make_exit(env,dir,phome,pkey,"����",1);

	key_ob = new(pkey);
	key_ob->move(user);

	if( !phome_ob = find_object(phome) )
		phome_ob = load_object(phome);

	phome_ob->set("built_time",time());
	phome_ob->save();

	tell_object(user,"��ķ����Ѿ�������,Կ�׽�����,ǧ�򱣹ܺ�.\n");
	user->delete("building_home");
	user->delete("can_build_home");	
	user->save();

	domain = environment(user)->query("outdoors");
	if(undefinedp(have_built[domain]))
		have_built += ([ domain : 1 ]);
	else
		have_built[domain] += 1;
	save();

	return 1;
}

private int build_two(object user,object env,string dir)
/* ����,�ȼ� 2. �߷�*/
{
	string file,key_file,env_file;
	string id,phome,pkey,domain;
	object key_ob,phome_ob;

	if(!user || !env)
		return 0;
	env_file = file_name(env);
	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_two.c"),
	user,env_file,dir);
	if(!stringp(file))
		return 0;
	key_file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"player_key.c"),
	user,env_file,dir);
	if(!stringp(key_file))
		return 0;

	id = user->query("id");
	phome = PHOME_DIR+domain_file(env_file)+"/"+id+"_home";
	pkey  = PHOME_DIR+domain_file(env_file)+"/"+id+"_key";

	assure_file(phome);
	write_file(phome+".c",file,1);
	write_file(pkey+".c",key_file,1);

	make_exit(env,dir,phome,pkey,"ľ��",2);

	key_ob = new(pkey);
	key_ob->move(user);

	if( !phome_ob = find_object(phome) )
		phome_ob = load_object(phome);

	phome_ob->set("built_time",time());
	phome_ob->save();

	tell_object(user,"��ķ����Ѿ�������,Կ�׽�����,ǧ�򱣹ܺ�.\n");
	user->delete("building_home");
	user->delete("can_build_home");	
	user->save();

	domain = environment(user)->query("outdoors");
	if(undefinedp(have_built[domain]))
		have_built += ([ domain : 1 ]);
	else
		have_built[domain] += 1;
	save();

	return 1;
}

private int build_three(object user,object env,string dir)
/* ����,�ȼ� 3. ����һ��СԺ��һ���߷�*/
{
	string file,key_file,env_file;
	string id,phome,pkey,domain;
	object key_ob,phome_ob;

	if(!user || !env)
		return 0;
	env_file = file_name(env);
	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_three.c"),
	user,env_file,dir);	/* Ժ�� */
	if(!stringp(file))
		return 0;
	key_file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"player_key.c"),
	user,env_file,dir);
	if(!stringp(key_file))
		return 0;

	id = user->query("id");
	phome = PHOME_DIR+domain_file(env_file)+"/"+id+"_home";
	pkey  = PHOME_DIR+domain_file(env_file)+"/"+id+"_key";

	assure_file(phome);
	write_file(phome+".c",file,1);
	write_file(pkey+".c",key_file,1);

	make_exit(env,dir,phome,pkey,"��ľ��",3);

	if( !phome_ob = find_object(phome) )
		phome_ob = load_object(phome);

	phome_ob->set("built_time",time());
	phome_ob->save();

	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_three2.c"),
	user,env_file,dir);	/* ���� */
	if(!stringp(file))
		return 0;
	write_file(phome+"2.c",file,1);
	if( !phome_ob = find_object(phome+"2") )
		phome_ob = load_object(phome+"2");
	phome_ob->set("built_time",time());
	phome_ob->save();

	key_ob = new(pkey);
	key_ob->move(user);

	tell_object(user,"��ķ����Ѿ�������,Կ�׽�����,ǧ�򱣹ܺ�.\n");
	user->delete("building_home");
	user->delete("can_build_home");	
	user->save();

	domain = environment(user)->query("outdoors");
	if(undefinedp(have_built[domain]))
		have_built += ([ domain : 1 ]);
	else
		have_built[domain] += 1;
	save();

	return 1;
}

private int build_four(object user,object env,string dir)
/* ����,�ȼ� 4. ����һ��СԺ��һ������¥*/
{
	string file,key_file,env_file;
	string id,phome,pkey,domain;
	object key_ob,phome_ob;

	if(!user || !env)
		return 0;
	env_file = file_name(env);
	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_four.c"),
	user,env_file,dir);	/* Ժ�� */
	if(!stringp(file))
		return 0;
	key_file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"player_key.c"),
	user,env_file,dir);
	if(!stringp(key_file))
		return 0;

	id = user->query("id");
	phome = PHOME_DIR+domain_file(env_file)+"/"+id+"_home";
	pkey  = PHOME_DIR+domain_file(env_file)+"/"+id+"_key";

	assure_file(phome);
	write_file(phome+".c",file,1);
	write_file(pkey+".c",key_file,1);

	make_exit(env,dir,phome,pkey,"�������",4);

	if( !phome_ob = find_object(phome) )
		phome_ob = load_object(phome);

	phome_ob->set("built_time",time());
	phome_ob->save();

	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_four2.c"),
	user,env_file,dir);	/* ���� */
	if(!stringp(file))
		return 0;
	write_file(phome+"2.c",file,1);
	if( !phome_ob = find_object(phome+"2") )
		phome_ob = load_object(phome+"2");
	phome_ob->set("built_time",time());
	phome_ob->save();

	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_four3.c"),
	user,env_file,dir);	/* ��¥ */
	if(!stringp(file))
		return 0;
	write_file(phome+"3.c",file,1);
	if( !phome_ob = find_object(phome+"3") )
		phome_ob = load_object(phome+"3");
	phome_ob->set("built_time",time());
	phome_ob->save();

	key_ob = new(pkey);
	key_ob->move(user);

	tell_object(user,"��ķ����Ѿ�������,Կ�׽�����,ǧ�򱣹ܺ�.\n");
	user->delete("building_home");
	user->delete("can_build_home");	
	user->save();

	domain = domain_file(file_name(environment(user)));
	if(undefinedp(have_built[domain]))
		have_built += ([ domain : 1 ]);
	else
		have_built[domain] += 1;
	save();

	return 1;
}

string *user_have_home(string id)
{
	string *files = ({}),*dirs;
	int n,i;

	if(!id || !stringp(id))
		return 0;

	dirs = get_dir(PHOME_DIR)- ({"origin_objs"});

	if( !(n = sizeof(dirs)) )
		return 0;

	for(i=0;i<n;i++)
	{
		string file;
		if( file_size((file = sprintf("%s%s/%s_home",
			PHOME_DIR,dirs[i],id))+".c") > 0 )
				files += ({ file });
	}

	if(!sizeof(files))
		return 0;
	else
		return files;
}

// �����ı���������
int home_master_change_cname(object user,string old_name,string new_name)
{
	string pkey,short,id,*homes;
	object home;
	int i,n;

	if(!user) return 0;
	if(!(homes = user_have_home(id = user->query("id"))))
		return 0;

	for(i=0;i<sizeof(homes);i++)
	{
		reset_eval_cost();

		if(!home = find_object(homes[i]))
			home = load_object(homes[i]);
		if(!home)
			continue;
		n = home->home_level();
		pkey = replace_string(homes[i],"_home","_key");

		switch(n)
		{
			case 1:	/* é�ݷ� */
				home->set("master_name",new_name);
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!key_change_name(pkey,old_name,new_name))
					log_file("playerhomed_log","Can't change "+
					pkey+" name.\n");
				break;
			case 2:	/* �߷� */
				home->set("master_name",new_name);
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!key_change_name(pkey,old_name,new_name))
					log_file("playerhomed_log","Can't change "+
					pkey+" name.\n");
				break;
			case 3:	/* һԺһ�� */
				home->set("master_name",new_name); /* Ժ */
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!home = find_object(homes[i]+"2")) /* �� */
					home = load_object(homes[i]+"2");
				if(!home)
					log_file("playerhomed_log","Can't load "+
					homes[i]+"2 name.\n");
				home->set("master_name",new_name);
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!key_change_name(pkey,old_name,new_name))
					log_file("playerhomed_log","Can't change "+
					pkey+" name.\n");
				break;
			case 4:	/* һԺһ����¥ */
				home->set("master_name",new_name); /* Ժ */
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!home = find_object(homes[i]+"2")) /* һ�㷿 */
					home = load_object(homes[i]+"2");
				if(!home)
					log_file("playerhomed_log","Can't load "+
					homes[i]+"2 name.\n");
				home->set("master_name",new_name);
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!home = find_object(homes[i]+"3")) /* ���㷿 */
					home = load_object(homes[i]+"3");
				if(!home)
					log_file("playerhomed_log","Can't load "+
					homes[i]+"3 name.\n");
				home->set("master_name",new_name);
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!key_change_name(pkey,old_name,new_name))
					log_file("playerhomed_log","Can't change "+
					pkey+" name.\n");
				break;
			log_file("playerhomed_log",id+" 's home level mistake.\n");
			//return 0;
		}
	}
	return 1;
}

// �����ı�������������Կ�׵�������Ҳ��֮�ı䡣
private int key_change_name(string key_file,string old_name,string new_name)
{
	string file;
	object *ob,org_ob,env,key;
	int i;

	if(!file = read_file(key_file+".c"))
		return 0;
	file = replace_string(file,old_name,new_name);
	write_file(key_file+".c",file,1);

	if(org_ob = find_object(key_file))
		destruct(org_ob);

	ob = children(key_file);
	if(!sizeof(ob))
		return 1;

	for(i=0;i<sizeof(ob);i++)
	{
		if(!env = environment(ob[i]))
			continue;
		key = new(key_file);
		destruct(ob[i]);
		key->move(env);
	}
	return 1;
}

private int reduce_room_file(string file /*Ҫ��ԭ���ļ���*/)
{
	string room_file,f_file,e_file,err,domain;
	int b,e,l,i;
	object ob,*inv;

	if(!file)
		return 0;
	room_file = read_file(file+".c");
	if(!stringp(room_file))
		return 0;

	l = strlen(end);
	b = strsrch(room_file,head);
	while(b != -1)
	{
		if(b == 0)
			f_file = "";
		else
			f_file = room_file[0..b-1];
		e = strsrch(room_file,end);
		e_file = room_file[e+l..];
		room_file = f_file + e_file;
		b = strsrch(room_file,head);
	}

	write_file(file+".c",room_file,1);

	if(!ob = find_object(file))
	{
		ob = load_object(file);
		if(!ob)
			return 1;
		domain = domain_file(file_name(ob));
		if(!undefinedp(have_built[domain]))
		{
			have_built[domain] -= 1;
			save();
		}
		return 1;
	}

	/* reload this room. */
	inv = all_inventory(ob);
	i = sizeof(inv);
	while(i--)
	{
		if(inv[i]->is_character())
			inv[i]->move(VOID_OB, 1);
		else
			inv[i] = 0;
	}
	destruct(ob);

	if(ob)
	{
		log_file("playerhomed_log","�޷���� "+
		file+".c �ľɳ�ʽ�롣\n");
		return 1;
	}

	err = catch( call_other(file, "???") );
	if(err)
	{
		log_file("playerhomed_log",err+"\n");
		return 1;
	}

	if((i=sizeof(inv)) && (ob = find_object(file)))
	{
		while(i--)
		{
			if(inv[i] && inv[i]->is_character()) 
				inv[i]->move(ob, 1);
		}
	}

	if(!ob)
		ob = load_object(file);
	if(!ob)
		return 1;

	tell_object(ob,"ֻ��������¡��һ�����죬���ϵķ��ݵ����ˡ�\n");

	domain = ob->query("outdoors");
	if(!undefinedp(have_built[domain]))
	{
		have_built[domain] -= 1;
		save();
	}

	return 1;
}

/* ɾ����ҷ��� */
varargs void delete_player_home(string id,int flag,string domain)
{
	mapping mail;
	string news,*homes,d;
	int i;
	object mbox;

	if(flag < 2)
	mail = ([
		"from": "�����ù� §����(Lou ashu)",
		"title": "��Ҫ֪ͨ����",
               	"to": id,
		"time": time(),
		"text": ""
	]);

	switch (flag)
	{
		case 0: /* ���� */
			mail["text"] = "���ļ�լ�������ʧ�޵����ˡ�";
			mbox = new(MAILBOX_OB);
			mbox->send_mail(id,mail);
			destruct(mbox);
			log_file("phome",sprintf("%s �� %s �ļ�լ�������ʧ�޵����ˡ�%s\n",
				capitalize(id),domain,ctime(time())));
			news = sprintf(HIM+"%s ��%s�ļ�լ�������ʧ�޵����ˡ�\n"+NOR,
				capitalize(id),to_chinese(domain));
			do_delete_phome(id,domain);
			break;

		case 1: /* ��Ѻ���� */
			mail["text"] = "���ļ�լ���ڵ�Ѻ����δ��ر�û�ա�";
			mbox = new(MAILBOX_OB);
			mbox->send_mail(id,mail);
			destruct(mbox);
			log_file("phome",sprintf("%s �� %s �ļ�լ���ڵ�Ѻ����δ��ر�û�ա�%s\n",
				capitalize(id),domain,ctime(time())));
			news = sprintf(HIM+"%s ��%s�ļ�լ���ڵ�Ѻ����δ����ر���͢û���ˡ�\n"+NOR,
					capitalize(id),to_chinese(domain));
			do_delete_phome(id,domain);
			break;

		case 2:
		case 3:
			if( !(homes = user_have_home(id)) )
				return;

			if(flag == 2) /* �����ɱ */
				log_file("phome",sprintf("%s ��ȫ����լ���ڱ�����ɱ���ջء�%s\n",
					capitalize(id),ctime(time())));

			else if(flag == 3) /* ��ұ� purge */
				log_file("phome",sprintf("%s ��ȫ����լ���ڱ��˵�����ɾ�����ջء�%s\n",
					capitalize(id),ctime(time())));
			
			for(i=0;i<sizeof(homes);i++)
			{
				reset_eval_cost();
				sscanf(homes[i],PHOME_DIR+"%s/%*s",d);
				do_delete_phome(id,d);
			}
			news = sprintf(HIM+"���� %s ��Զ���뿪��������磬�����м�լ����͢ȫ�������\n"+NOR,
					capitalize(id));
	}

	NEWS_D->add_news_item( news , "p", 1);
}

private void do_delete_phome(string id,string domain)
{
	string phome,*home_files,file,door_dir;
	object room,*pkeys;
	mapping exits,doors;
	int i,f;

	if(!stringp(id) || id == "")
		return;

	if( file_size((phome = sprintf("%s%s/%s_home",
			PHOME_DIR,domain,id))+".c") < 0 )
		return;

	if(!room = find_object(phome))
		room = load_object(phome);

	if(!room)
		return;
	exits = room->query("exits");
	doors = room->query_doors();

	if(!mapp(exits) || !mapp(doors))
	{
		log_file("playerhomed_log","error "+id+
		"'s home 's exit or door,can't delete home.\n");
		return;
	}

	if(sizeof(keys(doors)) != 1)
	{
		log_file("playerhomed_log","err: "+id+
		"'s home 's door_out != 1,can't delete home.\n");
		return;
	}

	door_dir = keys(doors)[0];
	if(undefinedp(exits[door_dir]))
	{
		log_file("playerhomed_log",id+
		"'s home 's door exit err,can't delete home.\n");
		return;
	}

	file = exits[door_dir];
	if(!reduce_room_file(file)) /* ��ԭ���򵵰� */
	{
		log_file("playerhomed_log",
		"Can't reduce "+file+",can't delete "+id+"'s home.\n");
		return;
	}

	/* ɾ��������ڴ���������е� home ������*/
	home_files = get_dir(PHOME_DIR+domain+"/");

	pkeys = children(PHOME_DIR+domain+"/"+id+"_key"); /*ɾ��Կ�����*/
	for(i=0;i<sizeof(pkeys);i++)
		destruct(pkeys[i]);

	for(i=0;i<sizeof(home_files);i++)
	{
		if(home_files[i][0..strlen(id)-1] == id)
		{
			string rfile;

			room = find_object(rfile = PHOME_DIR+domain+"/"+home_files[i]);
			if(!room)
				room = load_object(rfile);
			if(objectp(room))
			{
				class s_ob *ctlobs;
				object *inv = filter_array(all_inventory(room),(: userp :));

				for(f=0;f<sizeof(inv);f++)
				{
					tell_object(inv[f],"ͻȻ��ؿ�ʼ���������ߴ�������ž���ľ��죬����������Ҫ�����ˣ�\n");
					inv[f]->unconcious();
					inv[f]->move(STARTROOM);
					tell_room(STARTROOM,"ͻȻ"+inv[f]->name()+"�����汻���˽�����\n");
				}

				if(arrayp(ctlobs = room->query_save_objs()) && sizeof(ctlobs))
					foreach(class s_ob one_ob in ctlobs)
						CTLOB_D->delete_from_mud(one_ob->file);

				destruct(room);
			}
			rm(rfile);
		}
	}

	return;
}

void check_player_room(object room)
{
	int built_time,time;
	string room_short,master,domain;
	mapping bank;

	if( !room || (previous_object() != room) )
		return;

	sscanf(base_name(room),"/d/phome/%s/%*s",domain);

	if(mapp(bank = room->query("bank")))
	{
		time = bank["time"];
		if(time() > time)
		{
			delete_player_home(room->query("master_id"),1,domain);
			return;
		}
	}

	built_time = (int)room->query("built_time");

	if(!built_time)
		return;

	time = time() - built_time;
	room_short = room->query("short");
	master = room->query("master_name");
	if(!sscanf(room_short,master+"%s",room_short))
		return;

	if(time <= WORN_TIME)
	{
		if(strsrch(room_short,"���ƾ�") >= 0)
		{
			room_short = replace_string(room_short,"���ƾ�","��");
			room->set("short",master+room_short);
			room->save();
		}
		return;
	}

	else if(time <= BREAKDOWN_TIME)
	{
		if(strsrch(room_short,"���ƾ�") == -1)
		{
			room_short = replace_string(room_short,"��","���ƾ�");
			room->set("short",master+room_short);
			room->save();
		}
		return;
	}

	else
	{
		if(!sscanf(file_name(room),PHOME_DIR+"%s/%*s",domain))
			return;
		delete_player_home(room->query("master_id"),0,domain);
		return;
	}
}

object *player_homes(object me,object room)
{
	object *homes = ({});
	object room2,room3;
	int level;
	string file;

	if(!me || !userp(me) || !objectp(room))
		return 0;

	file = base_name(room);

	homes += ({ room });
	level = room->home_level();
	if(level<=2)
		return homes;

	room2 = find_object(sprintf(file+"%d",2));
	if(!room2)
		room2 = load_object(sprintf(file+"%d",2));
	if(!room2)
		return 0;

	else
		homes += ({ room2 });

	if(level == 4)
	{
		room3 = find_object(sprintf(file+"%d",3));
		if(!room3)
			room3 = load_object(sprintf(file+"%d",3));
		if(!room3)
			return 0;
		else
			homes += ({ room3 });
	}

	return homes;
}

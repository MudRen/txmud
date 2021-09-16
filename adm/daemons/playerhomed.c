// playerhomed.c
// by 发现号（find）。

// 建房,钥匙,配钥匙,修缮,能存储的东西数量,多少时间没上线删除,钥匙的存放问题.
// 建房费用分两部分: 1.地皮费 2.房屋费

// 玩家改名后房屋、钥匙自动更名。
// 非 outdoors 不能建
// 没有出口的地方不能建
// set("cannot_build_home",1)的房间不能建
// 只能建于 e,w,n,s 四个方向,如已占满不能建(如路口).
// GATE_ROOM 不能建.
// 玩家 18岁以前不能建.
// 巫师严禁建房.
// 各门派区域内不能建房.
// player home 分四个等级: 1.茅草房 2.瓦房 3.院落(1院1房) 4.豪宅(1院1二层房)
// home 内能存放的物品: 1. 3件 2. 5件 3. 7 件 4.10 件
// 可在房间里添置家具：木桌、八仙桌、木椅、太师椅、木床、双人铜床（暂时这么多）
// 购置家具在家具店。

// 所有有关玩家住房的部分均由此驻留程序管理。
// 其他物件需改变有关玩家住房的状态均须调用
// 此驻留程序里的函数来实现。

#undef TEST_RUNNING	// 测试期间取消一些限制。

#define	DIRS		({"north","south","west","east"})
#define ORIGIN_OBJ_DIR	PHOME_DIR+"origin_objs/"	// 玩家房屋,钥匙等原始物件存放目录.
#define WORN_TIME	525600	/* MUD 中一年，超过此时间房屋变旧 */
#define BREAKDOWN_TIME	1051200 /* MUD 中两年，超过此时间房屋倒塌 */
#define STARTROOM	"/d/changan/jiulou"
	/*此房间为玩家房屋被删除房屋内的玩家被移动到此房间，此房间应当是 'no_fight' */

inherit F_SAVE;
#include <domain_cost.h>	//各可建房区域的地皮费。
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

#define head "\n/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/\n"
#define end "\n/*代码自动生成完毕.*/\n"

private int reduce_room_file(string file); /*将区域房屋还原，用于删除玩家房屋。*/
private string replace_home_file(string file,object user,string env_file,string dir);
private int make_exit(object env,string dir,string phomefile,string key_file,string door,int msg_flag);
string *user_have_home(string id); /*此函数判断玩家是否有自己的住房*/
private int key_change_name(string key_file,string old_name,string new_name);
private void do_delete_phome(string id,string domain);

// 为避免 security hole,将以下几个函数单列。
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

int can_make_home(object user/*要求建房的玩家物件*/,string dir/*要求建房的方向*/)
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
		write("巫师不允许建造自己的房屋.\n");
		return 0;
	}
#endif

	if(user->query("age") < 18)
	{
		write("十八成年以后才能建房.\n");
		return 0;
	}

	if(!mapp(build = user->query("can_build_home")))
	{
		write("先去工部办理建房手续吧。\n");
		return 0;
	}

	if(undefinedp(build["level"]))
	{
		write("你还没有交建房款呢。\n");
		return 0;
	}

	if(undefinedp(build["cost_domain"]))
	{
		write("你还没有交地皮费呢。\n");
		return 0;
	}

	/* 玩家可建房标记。没有用 temp 标记是为防止意外丢失。
	 * can_build_home/level 1,2,3,4 四个房屋等级.
	 **************************************************
	 * can_build_home/where 办手续时申请被批准的建房地点。
	 * 这里牵涉到 outdoors 的写法、各区域分目录的规则问题，
	 * 因此在这里作如下统一规定：
	 * 标准区域内房间(如城、镇、村、门派等和大片同类地形如
	 * 大森林、大山脉等明暗房间数量和超过30的区域)均要求单分目录，
	 * 区域名、区域中文名要唯一，此区域所在的目录名即此区域的区域名。
	 * 如长安城其区域名为 changan,区域中文名为：长安城，
	 * 此区域所在的目录为：changan.
	 * 道路区域（即连结各标准区域之间的道路）的区域名为
	 * 用“-”连结道路两端的区域名，在保持道路区域名唯一的前
	 * 提下道路两端的区域铭刻一简写，此道路区域的目录名即为此
	 * 道路区域的区域名。
	 * 如长安至奉天的道路区域名为: cha-ft，其所在的目录名为cha-ft.
	 * 各区域内outdoors标记即为此区域的区域名，也就是此区域所在
	 * 的目录名。所有的区域名与区域中文名的对应都要放在
	 * 字典里。即通过 to_chinese(区域名) 可得到此区域中文名，
	 * 所以区域名也要注意不要和游戏里有可能用到的其他英文
	 * 发生冲突，区域名越复杂越精确越好。
	 *****************************************************
	 * can_build_home/time  办理手续的时间 time()。
	 * 玩家办完手续后 mud_time 30天(43200秒)内建房有效，超过30天，
	 * 扣除5%的手续费，其余建房款退还玩家。
	 * 退款部分程序在 logind 和 autosave 两个 daemon 里.
	 * 现在是一分不退，以后再说。
	 ******************************************************
	 * can_build_home/cost_home 玩家已付的建房房屋费用（备查）.
	 ******************************************************
	 * can_build_home/cost_domain 玩家已付的建房地皮费.
	 ****************************************************/
	 
	if(!stringp(dir))	return 0;
	env = environment(user);
	if(!env)	return 0;

	if(!sscanf(file_name(env), "/d/%*s"))
	{
		write("你现在在哪呀！！\n");
		return 0;
	}

	if( !stringp(domain = domain_file(file_name(env)))
	|| undefinedp(domain_cost) )
	{
		write("这里不能建房。\n");
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
		write("请从东、南、西、北四个方向里选择你的建房位置。\n");
		return 0;
	}

	// 这个标记是为了一些在可建房区域内的特殊房间用的，
	// 如某个宅院里的院子、森林、沼泽、山脉、湖泊等，
	// 是outdoors，也有出口，但在这种地方建房是不合理的，
	// 因此在此类特殊房间里要求 set（"cannot_build_home",1）,
	// 在区域 QC 时要注意严格检查此类房间的这个标记。
	if(env->query("cannot_build_home") || virtualp(env))
	{
		write("这里不能建房。\n");
		return 0;
	}
	if(env->query("GATE_ROOM"))
	{
		write("这里不能建房。\n");
		return 0;
	}

	exits = env->query("exits");
	if(!mapp(exits))
	{
		write("这里不能建房。\n");
		return 0;		
	}

	if(sizeof(exits) >= 4)
		return notify_fail("这里已经没有地方建房了。\n");

	if(!undefinedp(exits["north"])
	&& !undefinedp(exits["south"])
	&& !undefinedp(exits["west"])
	&& !undefinedp(exits["east"]))
	{
		write("这里已经没有能用于建房的出口了。\n");
		return 0;
	}

	if(!(env->query("outdoors")))
	{
		write("这里不能建房。\n");
		return 0;
	}

	if( file_size(sprintf("%s%s/%s_home.c",PHOME_DIR,domain,user->query("id"))) > 0 )
	{
		write(sprintf("你在%s已建有自己的住宅，不能在这个地区再建造了。\n",
			to_chinese(domain)));
		return 0;
	}

	if( (have_built[domain] && domain_cost[domain]["max"] != -1)
	&& (domain_cost[domain]["max"] <= (int)have_built[domain]) )
	{
		write("这里已经没有建房的指标了。\n");
		return 0;
	}

/*
	if(member_array(user->query("can_build_home/where"),domains) == -1)
	{
		write("BUG!! 批准的建房区域不在可建房区域列表内，请向巫师报告。\n");
		return 0;
	}
*/
	cost = domain_cost[domain]["cost"];
	if(have_built[domain])
		up = to_int(have_built[domain]*100/domain_cost[domain]["max"]*cost/10000/100)*10000;
	cost += up;

	if(build["cost_domain"] < cost)
	{
		write("你所付的地皮费不足以在这里建房。\n");
		return 0;
	}

	if( !undefinedp(domain_cost[domain]["min_level"])
	&& (build["level"] < domain_cost[domain]["min_level"]) )
	{
		if(domain_cost[domain]["min_level"] == 2)
		{
			write("在这里建房至少也要是一间瓦房。\n");
			return 0;
		}
		else if(domain_cost[domain]["min_level"] == 3)
		{
			write("在这里建房至少也要是一所宅院。\n");
			return 0;
		}
		else if(domain_cost[domain]["min_level"] == 4)
		{
			write("这里只能建造豪华大宅院。\n");
			return 0;
		}
	}

	if( !undefinedp(domain_cost[domain]["max_level"])
	&& (build["level"] > domain_cost[domain]["max_level"]) )
	{
		if(domain_cost[domain]["max_level"] == 1)
		{
			write("这里只能建造茅草房。\n");
			return 0;

		}
		if(domain_cost[domain]["max_level"] == 2)
		{
			write("在这里顶多只能建一间瓦房。\n");
			return 0;
		}
		else if(domain_cost[domain]["max_level"] == 3)
		{
			write("在这里顶多只能建一所宅院。\n");
			return 0;
		}
	}

	if(!undefinedp(exits[dir]))
	{
		write("这个方向已经建造了其他的设施，请另外选择一个建房方向。\n");
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

	/*building_home 期间不能退线,在 quit.c 里限制.*/
	user->set("building_home",1);
	user->start_busy(1);
	switch( user->query("can_build_home/level") )
	{
		case 1:
			log_file("phome",sprintf("%s(%s)在 %s 建起了一所 %d 级住宅.%s\n",
				user->name(),user->query("id"),
				domain_file(file_name(env)),1,ctime(time())));
			news = sprintf(HIG+"%s在%s建造了一间茅草屋安家于此。\n"+NOR,user->name(),
				to_chinese(domain_file(file_name(env))));
			NEWS_D->add_news_item( news , "p", 1);
			return build_one(user,env,dir);
			break;
		case 2:
			log_file("phome",sprintf("%s(%s)在 %s 建起了一所 %d 级住宅.%s\n",
				user->name(),user->query("id"),
				domain_file(file_name(env)),2,ctime(time())));
			news = sprintf(HIG+"%s在%s建造了一间大瓦房安家于此。\n"+NOR,user->name(),
				to_chinese(domain_file(file_name(env))));
			NEWS_D->add_news_item( news , "p", 1);
			return build_two(user,env,dir);
			break;
		case 3:
			log_file("phome",sprintf("%s(%s)在 %s 建起了一所 %d 级住宅.%s\n",
				user->name(),user->query("id"),
				domain_file(file_name(env)),3,ctime(time())));
			news = sprintf(HIG+"%s在%s建造了一所宅院安家于此。\n"+NOR,user->name(),
				to_chinese(domain_file(file_name(env))));
			NEWS_D->add_news_item( news , "p", 1);
			return build_three(user,env,dir);
			break;
		case 4:
			log_file("phome",sprintf("%s(%s)在 %s 建起了一所 %d 级住宅.%s\n",
				user->name(),user->query("id"),
				domain_file(file_name(env)),4,ctime(time())));
			news = sprintf(HIG+"%s在%s建造了一所豪华大宅院安家于此。\n"+NOR,user->name(),
				to_chinese(domain_file(file_name(env))));
			NEWS_D->add_news_item( news , "p", 1);
			return build_four(user,env,dir);
			break;
		
		write("批准建房类型错误！\n");
		return 0;
	}
}

/* $KEYN 玩家家门钥匙的中文名字.
 * $N 玩家的中文名字. $DIR 玩家房屋的出口方向.
 * $EXITOBJ 玩家房屋出口连结物件的文件名.
 * $KEYOBJ  玩家房屋的钥匙物件的文件名.
 * $ID 玩家的英文id. $SAVEFILE 玩家房屋的 save_file.
 * $TWOSAVEFILE 玩家的家的第二个房间的 save_file.
 * $THREESAVEFILE 玩家的家的第三个房间的 save_file.
 * $BDIR 玩家房屋的出口方向的反方向.
 */

// 此处要注意 config 里的最大字串长度的定义.
private string replace_home_file(string file,object user,string env_file,string dir)
{
	string id = user->query("id");
	string domain = domain_file(env_file);

	file = replace_string(file,"$KEYN",sprintf("%s在%s",
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

// 为区域房间开出口。
// 此处考虑到了一些程序写作不太规范的情况。
private int make_exit(object env,string dir,string phomefile,string key_file,string door,int msg_flag)
{
	string file,fsubfile,esubfile;
	int n,i;
	object *inv;
	string err;

	if(!file = read_file(file_name(env)+".c"))
		return 0;

	/*判断是否include room.h*/
	if(strsrch(file,"#include <room.h>") == -1)
		file = head+"#include <room.h>"+end+file;

	/*开出口*/
	n = strsrch(file,"void create()");	/*只查找 create() 函数内的 exits*/
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

	n = n+i+11;	/*从,开始查找,此写法避免源程序的空格数量问题*/
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

	/* 加上门 */
	i = strsrch(file[n..],"setup()");	/*用n查找能保证在create()函数内*/
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

	n = n+i;	/*此写法避免源程序的空格数量问题*/
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
		log_file("playerhomed_log","无法清除 "+
		file+".c 的旧程式码。\n");
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
			tell_object(env,"只见"+to_chinese(dir)+"面建起了一间茅草房。\n");
			break;
			case 2:
			tell_object(env,"只见"+to_chinese(dir)+"面建起了一间大瓦房。\n");
			break;
			case 3:
			tell_object(env,"只见"+to_chinese(dir)+"面建起了一所宅院。\n");
			break;
			case 4:
			tell_object(env,"只见"+to_chinese(dir)+"面建起了一所豪华大宅院。\n");
			break;
		}
	}
	return 1;
}

private int build_one(object user,object env,string dir)
/* 最便宜的房屋,等级 1. 茅草房*/
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

	make_exit(env,dir,phome,pkey,"竹门",1);

	key_ob = new(pkey);
	key_ob->move(user);

	if( !phome_ob = find_object(phome) )
		phome_ob = load_object(phome);

	phome_ob->set("built_time",time());
	phome_ob->save();

	tell_object(user,"你的房屋已经建好了,钥匙交给你,千万保管好.\n");
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
/* 房屋,等级 2. 瓦房*/
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

	make_exit(env,dir,phome,pkey,"木门",2);

	key_ob = new(pkey);
	key_ob->move(user);

	if( !phome_ob = find_object(phome) )
		phome_ob = load_object(phome);

	phome_ob->set("built_time",time());
	phome_ob->save();

	tell_object(user,"你的房屋已经建好了,钥匙交给你,千万保管好.\n");
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
/* 房屋,等级 3. 包括一个小院、一间瓦房*/
{
	string file,key_file,env_file;
	string id,phome,pkey,domain;
	object key_ob,phome_ob;

	if(!user || !env)
		return 0;
	env_file = file_name(env);
	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_three.c"),
	user,env_file,dir);	/* 院子 */
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

	make_exit(env,dir,phome,pkey,"柳木门",3);

	if( !phome_ob = find_object(phome) )
		phome_ob = load_object(phome);

	phome_ob->set("built_time",time());
	phome_ob->save();

	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_three2.c"),
	user,env_file,dir);	/* 正房 */
	if(!stringp(file))
		return 0;
	write_file(phome+"2.c",file,1);
	if( !phome_ob = find_object(phome+"2") )
		phome_ob = load_object(phome+"2");
	phome_ob->set("built_time",time());
	phome_ob->save();

	key_ob = new(pkey);
	key_ob->move(user);

	tell_object(user,"你的房屋已经建好了,钥匙交给你,千万保管好.\n");
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
/* 房屋,等级 4. 包括一个小院、一个二层楼*/
{
	string file,key_file,env_file;
	string id,phome,pkey,domain;
	object key_ob,phome_ob;

	if(!user || !env)
		return 0;
	env_file = file_name(env);
	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_four.c"),
	user,env_file,dir);	/* 院子 */
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

	make_exit(env,dir,phome,pkey,"红漆大门",4);

	if( !phome_ob = find_object(phome) )
		phome_ob = load_object(phome);

	phome_ob->set("built_time",time());
	phome_ob->save();

	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_four2.c"),
	user,env_file,dir);	/* 正房 */
	if(!stringp(file))
		return 0;
	write_file(phome+"2.c",file,1);
	if( !phome_ob = find_object(phome+"2") )
		phome_ob = load_object(phome+"2");
	phome_ob->set("built_time",time());
	phome_ob->save();

	file = replace_home_file(read_file(ORIGIN_OBJ_DIR+"phome_four3.c"),
	user,env_file,dir);	/* 二楼 */
	if(!stringp(file))
		return 0;
	write_file(phome+"3.c",file,1);
	if( !phome_ob = find_object(phome+"3") )
		phome_ob = load_object(phome+"3");
	phome_ob->set("built_time",time());
	phome_ob->save();

	key_ob = new(pkey);
	key_ob->move(user);

	tell_object(user,"你的房屋已经建好了,钥匙交给你,千万保管好.\n");
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

// 房主改变中文名。
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
			case 1:	/* 茅草房 */
				home->set("master_name",new_name);
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!key_change_name(pkey,old_name,new_name))
					log_file("playerhomed_log","Can't change "+
					pkey+" name.\n");
				break;
			case 2:	/* 瓦房 */
				home->set("master_name",new_name);
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!key_change_name(pkey,old_name,new_name))
					log_file("playerhomed_log","Can't change "+
					pkey+" name.\n");
				break;
			case 3:	/* 一院一房 */
				home->set("master_name",new_name); /* 院 */
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!home = find_object(homes[i]+"2")) /* 房 */
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
			case 4:	/* 一院一二层楼 */
				home->set("master_name",new_name); /* 院 */
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!home = find_object(homes[i]+"2")) /* 一层房 */
					home = load_object(homes[i]+"2");
				if(!home)
					log_file("playerhomed_log","Can't load "+
					homes[i]+"2 name.\n");
				home->set("master_name",new_name);
				short = replace_string(home->query("short"),
					old_name,new_name);
				home->set("short",short);
				home->save();
				if(!home = find_object(homes[i]+"3")) /* 二层房 */
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

// 房主改变中文名，家门钥匙的中文名也随之改变。
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

private int reduce_room_file(string file /*要还原的文件名*/)
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
		log_file("playerhomed_log","无法清除 "+
		file+".c 的旧程式码。\n");
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

	tell_object(ob,"只听到“轰隆”一声巨响，边上的房屋倒塌了。\n");

	domain = ob->query("outdoors");
	if(!undefinedp(have_built[domain]))
	{
		have_built[domain] -= 1;
		save();
	}

	return 1;
}

/* 删除玩家房间 */
varargs void delete_player_home(string id,int flag,string domain)
{
	mapping mail;
	string news,*homes,d;
	int i;
	object mbox;

	if(flag < 2)
	mail = ([
		"from": "工部堂官 搂阿叔(Lou ashu)",
		"title": "重要通知！！",
               	"to": id,
		"time": time(),
		"text": ""
	]);

	switch (flag)
	{
		case 0: /* 倒塌 */
			mail["text"] = "您的家宅由于年久失修倒塌了。";
			mbox = new(MAILBOX_OB);
			mbox->send_mail(id,mail);
			destruct(mbox);
			log_file("phome",sprintf("%s 在 %s 的家宅由于年久失修倒塌了。%s\n",
				capitalize(id),domain,ctime(time())));
			news = sprintf(HIM+"%s 在%s的家宅由于年久失修倒塌了。\n"+NOR,
				capitalize(id),to_chinese(domain));
			do_delete_phome(id,domain);
			break;

		case 1: /* 抵押到期 */
			mail["text"] = "您的家宅由于抵押到期未赎回被没收。";
			mbox = new(MAILBOX_OB);
			mbox->send_mail(id,mail);
			destruct(mbox);
			log_file("phome",sprintf("%s 在 %s 的家宅由于抵押到期未赎回被没收。%s\n",
				capitalize(id),domain,ctime(time())));
			news = sprintf(HIM+"%s 在%s的家宅由于抵押到期未能赎回被朝廷没收了。\n"+NOR,
					capitalize(id),to_chinese(domain));
			do_delete_phome(id,domain);
			break;

		case 2:
		case 3:
			if( !(homes = user_have_home(id)) )
				return;

			if(flag == 2) /* 玩家自杀 */
				log_file("phome",sprintf("%s 的全部家宅由于本人自杀被收回。%s\n",
					capitalize(id),ctime(time())));

			else if(flag == 3) /* 玩家被 purge */
				log_file("phome",sprintf("%s 的全部家宅由于本人档案被删除而收回。%s\n",
					capitalize(id),ctime(time())));
			
			for(i=0;i<sizeof(homes);i++)
			{
				reset_eval_cost();
				sscanf(homes[i],PHOME_DIR+"%s/%*s",d);
				do_delete_phome(id,d);
			}
			news = sprintf(HIM+"由于 %s 永远的离开了这个世界，其所有家宅被朝廷全部拆除。\n"+NOR,
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
	if(!reduce_room_file(file)) /* 还原区域档案 */
	{
		log_file("playerhomed_log",
		"Can't reduce "+file+",can't delete "+id+"'s home.\n");
		return;
	}

	/* 删除此玩家在此区域的所有的 home 档案。*/
	home_files = get_dir(PHOME_DIR+domain+"/");

	pkeys = children(PHOME_DIR+domain+"/"+id+"_key"); /*删除钥匙物件*/
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
					tell_object(inv[f],"突然大地开始颤动，耳边传来“噼啪”的巨响，看样子这里要倒塌了！\n");
					inv[f]->unconcious();
					inv[f]->move(STARTROOM);
					tell_room(STARTROOM,"突然"+inv[f]->name()+"从外面被扔了进来。\n");
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
		if(strsrch(room_short,"的破旧") >= 0)
		{
			room_short = replace_string(room_short,"的破旧","的");
			room->set("short",master+room_short);
			room->save();
		}
		return;
	}

	else if(time <= BREAKDOWN_TIME)
	{
		if(strsrch(room_short,"的破旧") == -1)
		{
			room_short = replace_string(room_short,"的","的破旧");
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

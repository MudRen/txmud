// 玩家房屋物件。level three.
// by 发现号(Find).

// 等级 3，宅院,共两间，这是第一间，与公共区域相连。
// 此房间为院子，只能改变描述，不能保存物品。

#define HOME_DIR	"/d/phome/"
#define MAX_FUR		3

#include <room.h>
inherit ROOM;
inherit F_SAVE;

void get_long(string str, string text);
int home_level() { return 3; }	//房屋等级。
int is_player_home() { return 1; }
string home_master() { return query("master_name"); }

void create()
{
	if(!restore())
	{
	set("short", "飞天狐狸家的院子");
	set("long", @LONG
这里是一个宁静的小院。
·你可以用 changelong 命令改变你的家的描述。
·<<郑重提醒：出入房屋请把门锁好，否则任何人均可随意
  出入你的房屋拿走你的保存物品，您的钥匙请不要轻易交
  给别人>>。
·要配钥匙可以去铁匠铺 (pei key) 。
·您的房屋要定期进行修缮，长时间不修缮房屋会倒塌。
·房屋修缮归户部的工程队管理。如您一段时间无法来修缮
  可以去户部预交(pay)修缮费，工程队会按时给您来维护房
  屋。
·如您一时周转不灵，可以把您的房屋向银行、钱庄抵押，
  在抵押期间您一样可以使用维护，但过期不赎将被没收。
·添置家具可以去家具商店看看。买好了家具可以放置
  (fangzhi)在你的家里。家具以后如果你不想要了也可以
  把它搬走(banzou)。

祝您生活愉快！！
LONG
);
	}

	set(SAFE_ENV,1);
	set("master_id","feitian");	// 房主的 ID。
	set("master_name","飞天狐狸"); // 房主的中文名。
	set("exits",([
	"north" : __DIR__"feitian_home2",
	"south" : "/d/tianshui/ekou",
	]));

	set("outdoors","playerhome");
	call_out("check_room",1);

	setup();
        create_door("south", "柳木门", "north", DOOR_CLOSED,LOCKED,__DIR__"feitian_key");

}

string query_save_file()
{
	return HOME_DIR+"tianshui/feitian_home_data";
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
	add_action("do_fangzhi","fangzhi");
	add_action("do_banzou","banzou");
}

int do_changelong(string arg)
{
	string str;
	object me = this_player();

	if(me->query("id") != query("master_id"))
		return notify_fail("这个命令是房主专用命令。\n");

	write("为了您房间的美观，每一行请不要超过二十五个中文字。\n");
	write("第一行的内容长度比其它行的长度少两个中文字宽才能对齐。\n");
	this_player()->edit( (: get_long , str :) );
	return 1;
}

void get_long(string str, string text)
{
	if( sizeof( explode(text, "\n") ) > 8 )
	{
		write("请将您的家庭描述控制在不超过八行。\n");
		return ;
	}	

	set("long",text);
	save();
	write("ok.\n");
	return;
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
		return notify_fail("你好像没有新添置家具呀。\n");

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
			return notify_fail("这间屋子里再也放置不下更多的家具了。\n");

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
	write(sprintf("小伙计把%s送到这里摆放好，一转眼又不见了。\n",f->name()));
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
		return notify_fail("你要搬走什么家具？\n");

	ob = present(arg,this_object());
	if(!ob)
		return notify_fail("你要搬走什么家具？\n");

	f = base_name(ob);

	obs = query("objects");

	if(undefinedp(obs[f]) || !obs[f])
		return notify_fail("你要搬走什么家具？\n");

	obs[f]--;
	if(!obs[f])
		map_delete(obs,f);
	message_vision("飞天狐狸把$n从屋子里扔了出去。\n",me,ob);
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
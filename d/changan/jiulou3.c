// Room: /d/changan/jiulou3.c
// by Find.

#undef DEBUG

#include <ansi.h>

inherit ROOM;
inherit F_SAVE;

class top
{
	string cname;
	string id;
	int gold;
}

protected class top *my_top = ({});
protected nosave string now;
protected nosave int fd;

string query_save_file() { return __DIR__"jiulou3"; }
protected int sort_topten(class top t1, class top t2);
string pai_msg();

int query_max_items() { return 100; }

protected nosave int open,time;
protected nosave string *colour = ({ HIY, HIG, HIM });

protected void do_refresh()
{
	set("short", "谪仙楼三层");
	now = 0;
	fd = 0;
	open = 0;
}

protected int have_food()
{
	mapping obj;
	int j,k;
	object *tables, *inv;

	if( !mapp(obj = query_temp("objects"))
	|| !sizeof(obj)
	|| !sizeof(tables = obj[__DIR__"obj/table"]) )
		return -1;

	for(int i=sizeof(tables)-1; i>=0; i--)
		if(tables[i]->is_sxg()
		/*
		&& sizeof(filter_array(all_inventory(tables[i]),
			(: $1->is_food() || $1->is_liquid() :) )))
		*/
		&& (k = sizeof(inv = all_inventory(tables[i]))) )
			for(j=0;i<k;j++)
				if(inv[j]->is_food() || inv[j]->is_liquid())
					return 1;
	return 0;
}

protected void begin_play()
{
	if(find_call_out("lasting"))
		remove_call_out("lasting");

	tell_room(this_object(),"\n一队手拿各式各样乐器的姑娘款款的走上舞台。
耳边响起了悠扬的曲子《高山流水》。。。。。。\n\n");
	call_out("lasting",20);
}

protected void lasting()
{
	string *melody = ({
"舞台上传来了优美的曲子《广陵散》",
"耳边响起了悠扬的曲子《碧霄吟》",
"台上奏起了优美的曲子《喜洋洋》"
 });

	if(((time() - time) > 360) || !have_food())
	{
		object *tables, *inv;
		int i,n,j,k;
		mapping obj;

		if( mapp(obj = query_temp("objects"))
		&& sizeof(obj)
		&& (n = sizeof(tables = obj[__DIR__"obj/table"])) )
			for(i=0; i<n; i++)
				if(tables[i]->is_sxg()
				&& (k = sizeof(inv = all_inventory(tables[i]))) )
					for(j=0;j<k;j++)
						if(inv[j]->is_food() || inv[j]->is_liquid())
							destruct(inv[j]);

		tell_room(this_object(),"\n管事指挥着小伙计将桌子上的残羹剩饭撤了下去。
舞台上的姑娘们抱着乐器走了。\n\n");
		do_refresh();
		return;
	}

	tell_room(this_object(),sprintf("\n%s%s ~ ~ ~ ~ ~ ~\n\n"NOR,
		colour[random(sizeof(colour))],melody[random(sizeof(melody))]));

	call_out("lasting",20);
}

void create()
{
	restore();

	set("short", "谪仙楼三层");
	set("long", @LONG
这是一所宽阔的厅堂，厅堂中央摆放着三张大长条红木桌子，
正前方有一个戏台，大概可以一边欢宴一边欣赏戏曲，门口贴着
一张红纸(paper)，左侧的墙上挂着一块红木牌(pai)。
LONG
	);

	set("item_desc",([
	"pai" : (: pai_msg :),
	"paper" : "
本酒楼专门承办(order)喜庆酒席
       每场十两黄金。

  生日宴席	order sr
  朋友聚饮	order fd

",
]));

	set(SAFE_ENV,1);
	set("NONPC",1);

	set("exits", ([
  "down" : __DIR__"jiulou2",
]));

	set("objects",([
	__DIR__"obj/table" : 3,
]));

	setup();
	if(my_top && (sizeof(my_top) > 1))
		my_top = sort_array(my_top, (: sort_topten :));
}

void init()
{
	add_action("do_order","order");
}

int do_order(string arg)
{
	object me = this_player();

	if((arg != "fd") && (arg != "sr"))
		return notify_fail("管事说道：对不起，这里只供「生日宴会」和「朋友聚会」。\n");

	if(now && (me->query("id") != now))
		return notify_fail(sprintf("管事说道：您先等一会儿吧，别人正在这里举办%s呢。\n",fd?"朋友聚会":"生日宴会"));

	if(open)
		return notify_fail("管事说道：稍等一会儿，别着急，马上就来。\n");

	if(have_food())
		return notify_fail("管事说道：瞧瞧桌上还这么多东西没吃完呢，等吃完了再说吧。\n");

	if(player_pay(me,100000) != 1)
		return notify_fail(sprintf("管事摇摇头说道：%s每场十两黄金。\n",arg=="fd"?"朋友聚会":"生日宴会"));


	now = me->query("id");
	me->add("pai_in_dxl",10);
	call_out("add_to_top",1,me);

	if(arg == "fd")
	{
		set("short", "悦朋轩");
		fd = 1;
	}
	else
		set("short", "福寿堂");
	open = 1;
	write("管事说道：好，您稍等一会儿。\n");

	if(find_call_out("do_open") > 0)
		remove_call_out("do_open");
	call_out("do_open",3,me);
	return 1;
}

protected void do_open(object me)
{
	string *all;
	int i,n,j,k;
	object *tables;

	if(!objectp(me))
	{
		do_refresh();
		return;
	}

	tables = filter_array(query_temp("objects")[__DIR__"obj/table"] - ({0}),
		(: $1->is_sxg() && (environment($1) == this_object()) :));

	if(!(k = sizeof(tables)))
	{
		if(objectp(me))
			tell_object(me,"\n管事说道：桌子怎么让人搬跑啦！快找巫师吧！！\n\n");
		do_refresh();
		return;
	}

	all = get_dir(__DIR__"foods/");

	if( !(n = sizeof(all)) )
	{
		if(objectp(me))
			tell_object(me,"\n管事说道：原料都没了！！快找巫师处理吧！！\n\n");
		return;
	}

	tell_room(this_object(),"\n管事往门口一站，高声喊道：开。。。席。。。喽。。。。。。\n\n
只见布菜的小伙计们川流不息，不一会儿桌子上就布满了山珍海味。\n\n");

	if(environment(me) == this_object())
	{
		string ey;

		if(me->query("gender") == "男性")
			ey = me->query("age")<=25?"大公子":"大爷";
		else
			ey = me->query("age")<=25?"大小姐":"大奶奶";
		tell_room(__FILE__,sprintf("\n管事走到%s面前一打拱说道：\n\t恭祝%s%s%s！！\n\n",
			me->name(),
			me->name()[0..1],
			ey,
			fd?"亲朋好友常聚，年年有今日，岁岁有今朝":"福如东海，寿比南山"));
	}

	for(i=0;i<n;i++)
	{
		string file;

		if(file_size(file = sprintf(__DIR__"foods/%s",all[i])) > 0)
		{
			for(j=0;j<k;j++)
			{
				object ob = new(file);
				ob->move(tables[j]);
			}
		}
	}

	if(!fd)
	{
		all = get_dir(__DIR__"shou/");
		if(n = sizeof(all))
			for(i=0;i<n;i++)
			{
				string file;
		
				if(file_size(file = sprintf(__DIR__"shou/%s",all[i])) > 0)
				{
					for(j=0;j<k;j++)
					{
						object ob = new(file);
						ob->move(tables[j]);
					}
				}
			}
	}

	shout(sprintf(HIR BWHT"\n【%s在京城谪仙楼%s请大家参加】\n\n" NOR,me->name(),
		fd?"设宴招待各方朋友":"举行生日宴会"));

#ifdef __THIS_PLAYER_IN_CALL_OUT__
	tell_object(me,sprintf(HIR BWHT"\n【%s在京城谪仙楼%s请大家参加】\n\n" NOR,me->name(),
		fd?"设宴招待各方朋友":"举行生日宴会"));
#endif

	begin_play();
	open = 0; time = time();
}

string pai_msg()
{
	string out;
	int n;

	out = HIY"\n  『谪仙楼十大财东』\n"NOR;

	if(!(n = sizeof(my_top)))
	{
		out += "  (目前还未曾有人光临)\n\n";
		return out;
	}

	if(n < 10)
		out += sprintf("  [只有%s人曾经光临]\n\n",chinese_number(n));

	foreach(class top tmp in my_top)
		out += sprintf("%s(%s)\n\t共在此花费 %d 两黄金\n",
			tmp->cname,capitalize(tmp->id),tmp->gold);

	return (out + "\n");
}

protected int sort_topten(class top t1, class top t2)
{
	if(t1->gold > t2->gold)
		return -1;
	return 1;
}

protected void add_to_top(object me)
{
	int i,n;
	class top nt;

	if(!me)
		return;

	nt = new(class top);
	nt->cname = me->name();
	nt->id = me->query("id");
	nt->gold = me->query("pai_in_dxl");

	if(!my_top || !(n = sizeof(my_top)))
	{
		my_top = ({ nt });
		save();
		return;
	}

	if(n < 10)
	{
		for(i=0;i<n;i++)
			if(my_top[i]->id == nt->id)
			{
				my_top[i]->gold = nt->gold;
				if(my_top[i]->cname != nt->cname)
					my_top[i]->cname = nt->cname;
				if(n > 1)
					my_top = sort_array(my_top, (: sort_topten :));
				save();
				return;
			}
		my_top += ({ nt });
		my_top = sort_array(my_top, (: sort_topten :));
		save();
		return;
	}

	if(nt->gold <= my_top[9]->gold)
		return;

	for(i=0;i<n;i++)
	{
		if(my_top[i]->id == nt->id)
		{
			my_top[i]->gold = nt->gold;
			if(my_top[i]->cname != nt->cname)
				my_top[i]->cname = nt->cname;
			my_top = sort_array(my_top, (: sort_topten :));
			save();
			return;
		}
	}

	my_top[9] = nt;
	my_top = sort_array(my_top, (: sort_topten :));
	save();
}

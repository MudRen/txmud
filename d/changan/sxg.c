// Room: /d/changan/sxg.c
// by Find.

#undef DEBUG

#include <ansi.h>
#include <room.h>

inherit ROOM;

int query_max_items() { return 100; }

protected int open,time;
protected string *colour = ({ HIY, HIG, HIM });

protected int have_food()
{
	mapping obj;
	object *tables;

	if( !mapp(obj = query_temp("objects"))
	|| !sizeof(obj)
	|| !sizeof(tables = obj[__DIR__"obj/table"]) )
		return -1;

	for(int i=sizeof(tables)-1; i>=0; i--)
		if(tables[i]->is_sxg()
		&& sizeof(filter_array(all_inventory(tables[i]),
			(: $1->is_food() || $1->is_liquid() :) )))
					return 1;
	return 0;
}

protected void begin_play()
{
	if(find_call_out("lasting"))
		remove_call_out("lasting");

	tell_room(this_object(),"\n一队手拿各式各样乐器的姑娘款款的走上舞台。
耳边响起了悠扬的《凤求凰》曲子。。。。。。\n\n");
	call_out("lasting",20);
}

protected void lasting()
{
	string *melody = ({
"舞台上传来了优美的《有所思》曲子",
"耳边响起了悠扬的《凤求凰》曲子",
"台上奏起了优美的《柳庭缘》曲子"
 });

	if((time() - time) > 300 || !have_food())
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

		tell_room(this_object(),"\n跑堂指挥着小伙计将桌子上的残羹剩饭撤了下去。
舞台上的姑娘们抱着乐器走了。\n\n");
		return;
	}

	tell_room(this_object(),sprintf("\n%s%s ~ ~ ~ ~ ~ ~\n\n"NOR,
		colour[random(sizeof(colour))],melody[random(sizeof(melody))]));

	call_out("lasting",20);
}

void create()
{
	set("short", BWHT HIR"双喜阁"NOR);
	set("long", @LONG
这是一所宽阔的厅堂，厅堂中央摆放着两张大长条红木桌子，
正前方有一个戏台，大概可以一边欢宴一边欣赏戏曲，门口的红
漆柱子上嵌着一块象牙牌子(pai)。
LONG
	);

	set("item_desc",([
	"pai" : "本酒楼专门承办(order)婚庆酒席，每场五两黄金。
"
]));

	set(SAFE_ENV,1);
	set("NONPC",1);

	set("exits", ([
  "westdown" : __DIR__"baoxiang",
]));

	set("objects",([
	__DIR__"obj/table" : 2,
]));

	setup();
	create_door("westdown", "红木门", "eastup", DOOR_CLOSED);
}

void init()
{
	add_action("do_order","order");
}

int do_order()
{
	object me = this_player();

	if(!me->query_temp("marry_bai")
#ifndef DEBUG
	|| wizardp(me)
#endif
	)
		return notify_fail("跑堂说道：只有新婚夫妇才能在这里举行婚庆酒席。\n");

	if(open)
		return notify_fail("跑堂说道：稍等一会儿，别着急。\n");

	if(have_food())
		return notify_fail("跑堂说道：瞧瞧桌上还这么多东西没吃完呢，等吃完了再说吧。\n");

	if(player_pay(me,50000) != 1)
		return notify_fail("跑堂摇摇头说道：婚庆喜宴每场五两黄金。\n");

	write("跑堂说道：好，您稍等一会儿。\n");
	open = 1;
	call_out("do_open",3,me);
	return 1;
}

protected void do_open(object me)
{
	string *all;
	int i,n,j,k;
	object *tables;

	tables = filter_array(query_temp("objects")[__DIR__"obj/table"] - ({0}),
		(: $1->is_sxg() && (environment($1) == this_object()) :));

	if(!(k = sizeof(tables)))
	{
		if(objectp(me))
			tell_object(me,"\n跑堂说道：桌子怎么让人搬跑啦！快找巫师吧！！\n\n");
		return;
	}

	all = get_dir(sprintf("%shunyan/",NPC_DIR));

	if( !(n = sizeof(all)) )
	{
		if(objectp(me))
			tell_object(me,"\n跑堂说道：原料都没了！！快找巫师处理吧！！\n\n");
		return;
	}

	tell_room(this_object(),"\n跑堂往门口一站，高声喊道：开。。。席。。。喽。。。。。。\n\n
只见布菜的小伙计们川流不息，不一会儿桌子上就布满了山珍海味。\n\n");

	for(i=0;i<n;i++)
	{
		string file;

		if(file_size(file = sprintf("%shunyan/%s",NPC_DIR,all[i])) > 0)
		{
			for(j=0;j<k;j++)
			{
				object ob = new(file);
				ob->move(tables[j]);
			}
		}
	}

	shout(sprintf(HIR BWHT"\n【%s在京城双喜阁举行新婚喜筵请大家参加】\n\n" NOR,me->name()));

#ifdef __THIS_PLAYER_IN_CALL_OUT__
	tell_object(me,sprintf(HIR BWHT"\n【%s在京城双喜阁举行新婚喜筵请大家参加】\n\n" NOR,me->name()));
#endif

	begin_play();
	open = 0; time = time();
}

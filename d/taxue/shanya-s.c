// shanya-s.c
// by dicky 2002-12-9

#include <ansi.h>
inherit ROOM;
string look_down();

void create()
{
        set("short","山崖");
        set("long", @LONG
此处已是绝路，光秃秃的石壁，突然在对面传来几声狼嗥，甚是凄厉可
怖。下边是一条深不见底的深崖(cliff)，云雾深锁其间，飞鸟难渡。看起来
你必须小必翼翼，一不小心可能掉下深崖。近悬崖边有棵摩天大树(tree)，
枝叶极盛，如大伞一张遮掩住方圆之地。
LONG);
	set("outdoors", "taxue");

        set(SAFE_ENV,1);

	set("exits", ([
		"south" : __DIR__"milin2",
	]));

	set("item_desc",([
		"cliff" : (: look_down :),
		"tree" : "这是一棵棵摩天大树，树上鸟虫聚集，枝叶极盛。\n", 
		"down" : "下面白茫茫一片，什么都看不见！\n", 
	]));

        setup();
}

void init()
{
        add_action("do_jump",({ "tiao", "jump" }));
}

int do_jump(string arg)
{
	object me;

        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("你要往哪跳？\n");
        message_vision("$N把大风筝紧紧缚在背后，朝山谷奋力跳了下去。\n"NOR, me);

        if (! present("da fengzheng", me) || me->query_skill("dodge", 1) < 300)
          { 
            message_vision("$N象一铁秤砣般迅速下落，瞬间就到了松树边，连忙深手去抓，却发现差了几寸。\n\n"NOR, me);
            message_vision(RED"啊---，$N一声惨叫，直往万丈深谷落去。\n\n"NOR, me);
            me->receive_damage("kee",9999,"trip");
            me->die();
            return 1;
          }

        message_vision(HIY"$N人在空中，大风筝像一对翅膀般轻轻的托着你，慢慢地朝谷底飘落去。\n\n\n"NOR, me);
	message_vision(HIB"$N由于不适应这种状态，感觉有点头晕，渐渐$N适应了这种状态。。。\n\n\n"NOR, me);
	me->start_busy(10);
	call_out("success", 10, me);
	return 1;
}

string look_down()
{
	return "下面(down)深不可测，根本看不到底，如果你要自杀，这到是个好地方。\n";
}

int success(object me)
{
	object ob1;
	message_vision(HIB"$N悬在半空中，两耳生风，感觉到一种从未有过的刺激。。。\n\n\n"NOR, me);
        me->move(__DIR__"gudi");
	tell_room(environment(me), me->name() + "飞了过来。\n", ({ me }));
	ob1 = present("da fengzheng", me);
	destruct(ob1);
	write(HIY"你终于安全着陆到一谷底的一块石头上面。\n"NOR);
	return 1;
}
// xiaopu.c

#include <ansi.h>

inherit ITEM;

int is_feiyu_xiaopu() { return 1; }

void create()
{
        set_name(HIM"清懿幽箫谱"NOR, ({ "xiao pu","pu" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本很旧的乐谱，上面的符号很怪，看
样子很难看(kan)懂。\n");
        }
}

void init()
{
        add_action("do_du","kan");
}

int do_du(string arg)
{
        object me = this_player();

	if (!arg || (!id(arg) && (arg != "清懿幽箫谱") && (arg != "箫谱")) )
		return notify_fail("你要读什么？\n");

	if (me->query("sen") < 25 )
		return notify_fail("你太累了，还是休息一下吧。\n");

	if (me->query_temp("mark/louth_xiao") > 8)
		return notify_fail("你对这本谱子已经看的很熟了，还不赶快吹奏一曲？\n");

	message_vision("$N开始钻研清懿幽箫谱。。。。。\n\n\n",me);
	me->start_busy(10);
	call_out("greeting",8,me);
	return 1;
}

void greeting(object me)
{
	if(!me)
		return;

	message_vision("$N看完一遍乐谱，对这首乐曲有了一定的了解。\n",me);
        me->receive_damage("sen",25,"tire");
	me->add_temp("mark/louth_xiao",1);
	me->stop_busy();
}       

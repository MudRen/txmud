// se.c

#include <ansi.h>
inherit ITEM;

private int xian = 3;
private int have = 0;

string get_long_desc();

void create()
{
	set_name("古琴", ({ "gu qin","qin"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
        else
	{
		set("no_get", 1);
		set("unit", "把");
		set("long", (: get_long_desc :));
		set("value", 1);
	}
}

string get_long_desc()
{
	return sprintf("这把古琴被牢牢的镶在了桌子上。\n%s",
		xian?sprintf("边上放着%s根琴弦。\n",chinese_number(xian)):"");
}
/*
void init()
{
	add_action("do_play","play");
	add_action("do_shang","shang");
}
*/
int do_shang(string arg)
{
	object me = this_player();

	if (arg != "琴弦" && arg !="qin xian")
		return notify_fail("你要上什么？\n");

	if(have)
		return notify_fail("琴弦已经上好了。\n");

	if(!xian)
		return notify_fail("桌子上的琴弦都被人拿走了。\n");

	if(me->query_temp("louth_playqin"))
		return notify_fail("你都已经弹断过一根琴弦了，别再浪费了。\n");

	message_vision("$N拿起桌子上的琴弦，仔细的上到了琴上。\n",me);
	have = 1;
        xian--;
        return 1;
}

int do_play(string arg)
{
        object me = this_player();

	if( !id(arg) && (arg != "古琴") )
		return notify_fail("你要弹什么？\n");

	if(!have)
		return notify_fail("你伸手想拨弄拨弄古琴，才发现琴上没有琴弦。\n");

        message_vision(HIM"$N轻拂琴弦滩了一首古从军行，琴音铿锵好象万马奔腾。\n"NOR,me);
	me->start_busy(7);
	call_out("qin1",6,me);
	return 1;
}

void qin1(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,HIB"时而琴声低转让人想起古战场凄凉的场面。\n\n");
        call_out("qin2",4,me);
}

void qin2(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,HIB"时而琴声高仰，让人豪气冲天。\n\n"NOR);
        call_out("qin3",4,me);
}

void qin3(object me)
{
        object ob;

	if(!objectp(me) || (environment(me) != this_object()))
		return;

        tell_object(me,HIR"
突然琴声一转变的十分的哀怨，你仿佛看见战场上尸横
遍野，无数的人含着泪在寻找自己的亲人，你的心好象
被什么扎了一下，你的手指一颤，只听见一声“蹦”的
一声琴弦断了，琴声为一停你也收回了杂乱的思绪心中
泛起了一丝的莫名的伤感。\n\n\n"NOR);

	have = 0;
	me->set_temp("louth_playqin",1);
	me->stop_busy();

        ob = new("../npc/yman");
        ob->move(environment());
}

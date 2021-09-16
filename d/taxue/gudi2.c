// gudi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山谷底");
        set("long",@LONG
这里是峭壁下面的谷底，这里阳光稀少。四周看上去高不可攀，怪石
嶙峋。一条清泉(quan)缓缓的从峭壁的缝隙中流淌下来，发出"叮咚叮咚"
的响声，几只猴子(houzi)在山藤上面跳跃，偶尔停下来，一边吃着山果，
一边上下打量着你这不速之客。
LONG);

	set("outdoors","taxue");

	set("item_desc", ([
		"quan" : "一洌清泉晶莹透亮，你忍不住想去喝(he)几口。\n",
		"houzi" : "几只山猴正一边吃着野果，一边打量着你这不速之客。\n",
	]));

	set("exits",([
                "west" : __DIR__"gudi",
                "enter" : __DIR__"gudi3",
	]));

	setup();
}

void init()
{
	if (!this_player()->query_temp("taxue/gudi_za"))
	        this_player()->set_temp("taxue/gudi_za",1);

	add_action("do_he", "he");
	add_action("do_za", "za");
}

int do_he(string arg)
{
	object me = this_player();

	if (arg == "quan") {
		if (me->query("water") < me->query("str")*10+100) {
		message_vision(HIC"$N捧起一汪清泉，美美地喝了一口。\n"NOR, me);
		me->add("water", 50, me);
		return 1;
		}
	return notify_fail("你喝太多了，不怕撑死？\n");  
	} 
      return notify_fail("你要喝什么？\n");
}

int do_za(string arg)
{
	object me = this_player();

	if (present("ye guo", me))
		return notify_fail("你身上不是有野果么？还去骗猴子的东西吃呀？\n"); 

	if (arg == "houzi"){
	message_vision(HIC"$N拿起地上的石块，向猴子轻轻的砸过去。\n\n"NOR, me);
	message_vision(HIC"猴子马上对$N啮龇牙咧嘴，并用手上的" HIR "野果" HIC "向$P砸过来，\n$P一式“仙人问路”，顺手把它接在手中。\n\n"NOR,me);
	me->add_temp("taxue/gudi_za",1);
	new(__DIR__"obj/yeguo")->move(me);
	return 1;
	} 
	return notify_fail("你要砸谁？\n");
}
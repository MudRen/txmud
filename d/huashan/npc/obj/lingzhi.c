// lingzhi.c 九转灵芝草   by pian huashan
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(WHT"九转灵芝草"NOR, ({"jiu zhuan lingzhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枝");
		set("long", WHT"    一枝九转灵芝草，这可是难得一见的武林至宝，不吃等什么呢。\n"NOR);
		set("value", 500);
	}
	setup();
}

int do_eat(string arg)
{
      object me;
      me=this_player();
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

      me->set("kee", me->query("max_kee"));  
      me->set("gin", me->query("max_gin"));
      me->set("sen", me->query("max_sen"));
      me->set("eff_kee", me->query("max_kee"));
      me->set("eff_gin", me->query("max_gin"));
      me->set("eff_sen", me->query("max_sen"));
      me->set("max_force",me->query("max_force")+100);

	message_vision("$N闭上双眼一口吞下九转灵芝草，\n
      顿时间$N眼睛一亮，只觉得全身充满了活力 !\n", this_player());
	destruct(this_object());
	return 1;
}


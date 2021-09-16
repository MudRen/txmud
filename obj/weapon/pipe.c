// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("玉箫", ({ "pipe" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "一根约两□多长的玉箫，晶莹透亮，这里隐藏武林中的一大秘密!\n");
		set("material", "stone");
		set("wield_msg", "只见白光一闪而过，$N手中突然多了一把玉箫。\n");
		set("unwield_msg", "$N若无其事的站着，手中的玉箫却已不见。\n");
	}

	init_sword(25);
	setup();
}

void init()
{
	add_action("do_play", ({ "play", "blow" }) );
}

int do_play(string arg)
{
	if( !id(arg) )
		return 0;

	message_vision("$N拿起一只玉箫,轻轻的吹了起来,悠扬的笛声飘过每颗浪子的心，飘到遥远的故乡。\n",
		this_player() );
	environment(this_player())->pipe_notify();
        return 1;
}
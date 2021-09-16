// yxiao.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"白玉箫"NOR, ({ "white flute","flute" }) );
        set_weight(200);
        if( clonep() )
	set_default_object(__FILE__);
	else
	{
                set("unit", "根");
		set("long", "这根玉箫入手有种冰凉的感觉，是用上等寒玉制成的。
你可以试着吹(chui)首曲子。\n");
		set("value", 1);
        }
}

void init()
{
	add_action("do_chui",({ "chui","吹" }));
}

int do_chui(string arg)
{
        object me = this_player(),ob;

        if ( !arg || (!id(arg) && (arg != "白玉箫")) )
		return notify_fail("你要吹什么？\n");

	if (me->query("sen") < 60)
		return notify_fail("你精神不好，歇一会再吹吧。\n");

	if(me->query_temp("mark/louth_xiao") < 8 )
        {
		message_vision("$N拿起白玉箫放在嘴边使劲的吹了吹，但是乱七八糟的不成个曲调。\n\n",me);
		me->receive_damage("sen",60,"tire");
		return 1;
        }

	if(objectp(ob=present("xiao pu",me)) && ob->is_feiyu_xiaopu())
	{
        	message_vision(WHT"$N拿起玉萧放在唇边轻轻的吹奏了起来，一曲『清懿幽』让
听者黯然神伤，想起了自己的心上人，在$N的心里他乎近乎
远，明明触手可及却又无法真正的抓住他，$N的思绪不禁乱
了，萧声也乱了。。。\n\n"NOR,me);

		me->receive_damage("sen",60,"tire");   
		call_out("greeting",10,me);
		me->start_busy(20);
	}

	else
	{
		message_vision("$N拿起白玉箫放在嘴边想吹一曲『清懿幽』，但是总是吹不好。\n\n",me);
		me->receive_damage("sen",60,"tire");
	}

        return 1;
}

void greeting(object me)
{
	object ob,pu;

	if(!me || !environment(me))
		return;

        message_vision (HIM"\n慢慢的萧声停了，屋子静的让人感到害怕，你能听见你自己
的心跳声和呼吸声，$N的眼里流下了一行泪，多年的江湖飘
荡你也想家了。。。\n\n"NOR,me);

	if( objectp(ob = present("huan er",environment(me)))
	&& ob->query_is_feiyu_huaner()
	&& objectp(pu=present("xiao pu",me))
	&& pu->is_feiyu_xiaopu() )
	{
		message_vision("$N颤声对$n说到：谢谢你了！我好久没听到这么动听的曲子了。
萧谱和萧我就收起来了，以后你来再请你给我吹，我在读书识
字方面还下过几天功夫，以后你有这方面的问题就来找我。\n",ob,me);
		this_object()->move(ob);
		pu->move(ob);
		ob->start_call();
		me->set("mark/louth_huaner",1);
	}
        me->stop_busy();
}

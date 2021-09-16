// yanluo.c

#define DROP_CMD	"/cmds/std/drop" 
#include <ansi.h>

inherit NPC;

string *death_msg = ({
	HIW "阎罗王用阴冷的目光扫了你一眼。。。。。。\n\n" NOR,
	HIW "阎罗王“哼”的一声，从桌案上拿起一本『阴阳册』翻看着。。。。。。\n\n" NOR,
	HIW "阎罗王合上『阴阳册』，说道：你阳寿未尽，本王不能收留。\n\n" NOR,
	HIW "阎罗王长袖一挥说道：你回去吧。\n\n"
		"一股阴冷的浓雾突然出现，很快地包围了你。。。。。。\n\n" NOR,
});
string *revive_loc= ({
        "/d/changan/badroom",
});

void create()
{
	set_name("阎罗王", ({ "yan wang" }) );
	set("long","阎罗王瞪著你，惨绿的脸上看不出任何喜怒哀乐。\n");
	set("attitude", "peaceful");
	set("chat_chance", 5);
	set("chat_msg", ({
		"阎罗王用阴冷的目光扫视着周围。\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("max_gin", 900);
	set("max_kee", 900);
	set("max_sen", 200);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	setup();
}

void init()
{
	::init();
	add_action("do_huan","huanyang");
	if( !previous_object()
	||	!userp(previous_object())
	||	wizardp(previous_object()) ) return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

int do_huan(string arg)
{
	object me;

	if(!wizardp(me=this_player()))
		return 0;

	message_vision(HIY"$N单手一划，一团瑞光从地而起，托着$N"NOR,me);
	tell_object(me,HIY "走了。\n" NOR);
	tell_room(environment(me),HIY "不见了。\n" NOR,({me}));
	me->reincarnate();
	me->move(revive_loc[random(sizeof(revive_loc))]);
	return 1;
}

void death_stage(object ob, int stage)
{
	if( !ob || !present(ob) )
		return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) )
	{
		call_out( "death_stage", 5, ob, stage );
		return;
	}

	else
	{
		ob->delete_temp("chengxf_killer");
		DROP_CMD->main(ob,"all");
		ob->reincarnate();
	}

	ob->move(revive_loc[random(sizeof(revive_loc))]);
	ob->set_status_xuruo(30);

	message("vision",
		"\n你突然觉一阵透骨的阴风从身边一掠而过，虽然瞬间就恢复
了正常，但总觉得身后好像来了一个人。。。。。。\n\n", environment(ob), ob);
}

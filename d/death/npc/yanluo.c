// yanluo.c

#define DROP_CMD	"/cmds/std/drop" 
#include <ansi.h>

inherit NPC;

string *death_msg = ({
	HIW "�������������Ŀ��ɨ����һ�ۡ�����������\n\n" NOR,
	HIW "���������ߡ���һ����������������һ���������᡻�����š�����������\n\n" NOR,
	HIW "���������ϡ������᡻��˵����������δ������������������\n\n" NOR,
	HIW "����������һ��˵�������ȥ�ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣����������\n\n" NOR,
});
string *revive_loc= ({
        "/d/changan/badroom",
});

void create()
{
	set_name("������", ({ "yan wang" }) );
	set("long","�����������㣬���̵����Ͽ������κ�ϲŭ���֡�\n");
	set("attitude", "peaceful");
	set("chat_chance", 5);
	set("chat_msg", ({
		"�������������Ŀ��ɨ������Χ��\n"
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

	message_vision(HIY"$N����һ����һ�����ӵض�������$N"NOR,me);
	tell_object(me,HIY "���ˡ�\n" NOR);
	tell_room(environment(me),HIY "�����ˡ�\n" NOR,({me}));
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
		"\n��ͻȻ��һ��͸�ǵ���������һ�Ӷ�������Ȼ˲��ͻָ�
�����������ܾ�������������һ���ˡ�����������\n\n", environment(ob), ob);
}

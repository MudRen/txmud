// laohan.c

#include <ansi.h>
inherit NPC;

mixed ask_quest(object me);

void create()
{
        set_name("������", ({ "xin jin cai" }) );
	set("title","ˮ�������ƹ�");
        set("gender", "����" );
        set("age", 23);

	set(NO_KILL, 1);
        set("long", "������ˮ�������ϰ�Ķ��ӡ�\n");

	set("inquiry",([
	"������" : (: ask_quest :),
]));

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

mixed ask_quest(object me)
{
	mapping q;

	if(!mapp(q = me->query("quest/tangmen_quest"))
	|| (q["name"] != "������") || q["get_nut"] )
		return 0;

	me->set_temp("asked_xinjincai",1);
	return "�������ӡ����⵹����һ�ţ��ⶫ���ɲ����ң�2��������һ��Ҳ���С�";
}

int accept_object(object who, object ob)
{
	mapping q;

	if(!is_money(ob))
		return 0;

	if(!mapp(q = who->query("quest/tangmen_quest"))
	|| (q["name"] != "������") || q["get_nut"] )
		return 0;

	if(!who->query_temp("asked_xinjincai"))
	{
		command("say ���������׸�Ǯ�����鶼�У�лл����");
		return 1;
	}

	if(ob->value() < 200)
	{
		write(sprintf("%s˵������2������һ�ţ���һ��ͭ�Ӷ�Ҳ���У���\n",name()));
		return 0;
	}

	who->delete_temp("asked_xinjincai");
	call_out("give_guan",1,who);
	return 1;
}

protected void give_guan(object me)
{
	object nut;
	mapping q;

	if(!mapp(q = me->query("quest/tangmen_quest"))
	|| (q["name"] != "������") || q["get_nut"] )
		return 0;

	nut = new("/d/tangmen/obj/nut");
	if(!nut->move(me))
	{
		destruct(nut);
		tell_object(me, "������ʲô������װ�����ˣ���\n");
		return;
	}

	q["get_nut"] = 1;

	tell_object(me,sprintf("%s˵������ȥ�ɡ���˵�����ζ���ܺã���ô���˾��������ˡ�\n",name()));
}

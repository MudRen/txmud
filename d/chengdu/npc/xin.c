// laohan.c

#include <ansi.h>
inherit NPC;

mixed ask_quest(object me);

void create()
{
        set_name("辛进财", ({ "xin jin cai" }) );
	set("title","水果店少掌柜");
        set("gender", "男性" );
        set("age", 23);

	set(NO_KILL, 1);
        set("long", "他就是水果店辛老板的儿子。\n");

	set("inquiry",([
	"海松子" : (: ask_quest :),
]));

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

mixed ask_quest(object me)
{
	mapping q;

	if(!mapp(q = me->query("quest/tangmen_quest"))
	|| (q["name"] != "海松子") || q["get_nut"] )
		return 0;

	me->set_temp("asked_xinjincai",1);
	return "『海松子』我这倒真有一颗，这东西可不好找，2两银子少一分也不行。";
}

int accept_object(object who, object ob)
{
	mapping q;

	if(!is_money(ob))
		return 0;

	if(!mapp(q = who->query("quest/tangmen_quest"))
	|| (q["name"] != "海松子") || q["get_nut"] )
		return 0;

	if(!who->query_temp("asked_xinjincai"))
	{
		command("say 这世道连白给钱的事情都有，谢谢啦。");
		return 1;
	}

	if(ob->value() < 200)
	{
		write(sprintf("%s说道：“2两银子一颗，少一个铜子儿也不行！”\n",name()));
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
	|| (q["name"] != "海松子") || q["get_nut"] )
		return 0;

	nut = new("/d/tangmen/obj/nut");
	if(!nut->move(me))
	{
		destruct(nut);
		tell_object(me, "你身上什么东西都装不下了！！\n");
		return;
	}

	q["get_nut"] = 1;

	tell_object(me,sprintf("%s说道：拿去吧。听说这果子味道很好，这么便宜就卖给你了。\n",name()));
}

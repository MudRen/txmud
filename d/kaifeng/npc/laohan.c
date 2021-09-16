// laohan.c

#include <ansi.h>
inherit NPC;

int ask_quest(object me);

void create()
{
        set_name("张老汉", ({ "lao han" }) );
	set("title","养鸡专业户");
        set("gender", "男性" );
        set("age", 63);

	set(NO_KILL, 1);
        set("long", "张老汉专门养鸡为生，由于买卖公道，
整个开封城的鸡差不过都从这里供应。\n");

	set("inquiry",([
	"公鸡冠" : (: ask_quest :),
	"鸡冠" : (: ask_quest :),
]));

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_quest(object me)
{
	if( (me->query("quest/shaolin_quest/name") != "公鸡冠")
	|| me->query("quest/shaolin_quest/have_jiguan") )
	{
		write(sprintf(CYN"%s翻了翻眼睛说道：天下养鸡的哪有切了鸡冠卖的，别和我捣乱！\n"NOR,name()));
		return 1;
	}

	command(sprintf("say %s","公鸡我这有呀,不过你把鸡冠割走了,我还怎么卖呀,
\t要不你把公鸡买下来一只吧.每只 1 两银子."));
	me->set_temp("asked_zhanglaohan",1);
	return 1;
}

int accept_object(object who, object ob)
{
	if(!is_money(ob))
		return 0;

	if(!who->query_temp("asked_zhanglaohan"))
	{
		command("say 这世道连白给钱的事情都有，谢谢啦。");
		return 1;
	}

	if(ob->value() < 100)
	{
		write(sprintf("%s说道：“1两银子一只，少一个铜子儿也不行！”\n",name()));
		return 0;
	}

	who->delete_temp("asked_zhanglaohan");
	call_out("give_guan",1,who);
	return 1;
}

protected void give_guan(object me)
{
	object guan;

	if(!me || (environment(me) != environment())
	|| me->query("quest/shaolin_quest/have_jiguan") )
		return;

	guan = new(__DIR__"obj/jiguan");
	guan->move(this_object());
	me->set("quest/shaolin_quest/have_jiguan",1);
	tell_object(me,sprintf("%s点点头说道：好，您等一下。\n",name()));
	tell_object(me,sprintf("%s进后屋等了一会儿出来说道：这是您要的，赶紧拿去吧。\n",name()));
	command(sprintf("give ji guan to %s",me->query("id")));
}

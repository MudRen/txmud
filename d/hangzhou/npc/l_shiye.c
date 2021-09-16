// cooker.c
// by Find.

#include <ansi.h>
inherit NPC;

string ask_me(object who);

void create()
{
	set_name("刘一手", ({ "liu yishou" }) );
	set("gender", "男性" );
	set("age", 45);
	set("long", "这是一位中年男人，长的扣眉缩眼一看就不是一
个好人，从打扮上看大概是一个师爷。\n");
	set("combat_exp", 100);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	setup();
	set("chat_chance", 2);
	set("chat_msg", ({
		CYN+"刘一手说道：“从京城过来要途经黑风山，有土匪劫道。”\n" +NOR,
		CYN+"刘一手说道：“黑风山上的黑风寨。。。”\n"+NOR,
	}) );
	set("inquiry",([
	"黑风山" : (: ask_me :),
	"黑风寨" : (: ask_me :),
]));
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object who)
{
	if(who->query_temp("hangzhou_shiye"))
		return "光和我动嘴！你让我吃吐沫过日子呀！\n";

	who->set_temp("hangzhou_shiye",1);

	return "黑风寨的大寨主早年和我倒是有点交情，有我一句话路过那里
           就和自己家一样安全。不过，当师爷的日子很清苦，要是能有
           个 100 两银子，这时就好办了。";
}

int accept_object(object me,object ob)
{
	string pass, *l = ({ "小的","鄙人","在下","我要" }),
		*m = ({ "晋见","拜见","参见","拜望","看望" }),
		*n = ({ "寨主","老大","大寨主","二寨主","头领" });

	if(!is_money(ob))
		return 0;

	if(!me->query_temp("hangzhou_shiye"))
	{
		command("say 这世道连白给钱的事情都有，谢谢啦。");
                return 1;
	}

	if(ob->value() < 10000)
	{
		command("say 这几个钱够干什么的！不过看你一片孝心就收下了。也就买盘花生豆。。。\n");
                return 1;
	}

	me->delete_temp("hangzhou_shiye");

	pass = sprintf("%s%s%s",l[random(sizeof(l))],m[random(sizeof(m))],n[random(sizeof(n))]);

	command(sprintf("tell %s 你到山寨门口喊一声 %s 就可以了。切记！\n",
		me->query("id"),pass));

	me->set_temp("enter_heifeng",pass);
	return 1;
}

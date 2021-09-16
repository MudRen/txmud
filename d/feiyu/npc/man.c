// man.c

#include <ansi.h>
inherit NPC;

string ask_hoe(object who);
string ask_tong(object who);

void create()
{
        set_name("漫雨儿", ({ "manyu er","er","manyu"}) );
        set("title",RED"天真真"NOR);
        set("gender", "女性" );
        set("age", 19);
        set("long", "她整天笑嘻嘻的，一副无忧无虑的样子。\n");
        set("combat_exp", 2000);
        set("per", 30);

	set(NO_KILL, 1);
	set("inquiry",([
	"药锄" : (: ask_hoe :),
	"水桶" : (: ask_tong :),
]));

        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_hoe(object who)
{
	object ob;

	if(!who)
		return 0;

	if(who->query("quest/rain_quest/quest") != "药苗圃")
		return "没事要这个做什么。\n";

	if(objectp(present("medicine hoe",who)))
		return "你不是已经有药锄了？快去干活吧。\n";

	ob = new(__DIR__"obj/hoe");
	ob->move(this_object());

	command(sprintf("give medicine hoe to %s",who->query("id")));

	return "不知道苗圃里的草药苗长得怎么样了。\n";
}

string ask_tong(object who)
{
	object ob;

	if(!who)
		return 0;

	if(who->query("quest/rain_quest/quest") != "药苗圃")
		return "没事要这个做什么。\n";

	if(objectp(present("water bucket",who)))
		return "你不是已经有水桶了？快去干活吧。\n";

	ob = new(__DIR__"obj/tong");
	ob->move(this_object());

	command(sprintf("give water bucket to %s",who->query("id")));

	return "不知道苗圃里的草药苗长得怎么样了。\n";
}

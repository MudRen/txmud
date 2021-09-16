// han.c

#include <ansi.h>
inherit NPC;

string ask_me(object who);

void create()
{
	set_name("涵雨儿", ({ "hanyu er","er","hanyu"}) );
	set("title",HIG"笑嘻嘻"NOR);
	set("gender", "女性" );
	set("age", 20);

	set(NO_KILL, 1);
	set("inquiry",([
	"莲子" : (: ask_me :),
]));

	set("long", "她整天笑嘻嘻的，一副无忧无虑的样子。\n");
	set("combat_exp", 4000);
	set("per", 30);
	set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object who)
{
	string *get;
	object ob;

	if( (who->query("quest/rain_quest/name") == "百云汤")
	&& ( !(get = who->query("quest/rain_quest/geted"))
	|| !sizeof(get)
	|| (member_array("莲子",get) == -1) ) )
	{
		ob = new(__DIR__"obj/lian_zi");
		ob->move(this_object());
		command(sprintf("give lian zi to %s",who->query("id")));

		if(!arrayp(get))
			get = ({"莲子"});
		else
			get += ({"莲子"});
		who->set("quest/rain_quest/geted",get);
		who->add("quest/rain_quest/hint",sprintf("      %s\n",
			"你已经得到了莲子。"));
		if(sizeof(get) >= 4)
		who->add("quest/rain_quest/hint",sprintf("      %s\n",
			"百云汤的原料你已经找齐，可以去煎药了。"));

		return "我这正好还有一颗，既然你急需就送给你啦。\n";
	}

	return "我这也没了，你另外去找找吧。\n";
}

// huichi.c
// 藏经阁首座
// by Find.

#include <ansi.h>

inherit NPC;

string ask_me(object who);
int ask_yijin(object me);
int ask_book(object who,string topic);
int ask_all(object who);

protected string *books = ({
"changquan",
"damo-sword",
"ganchan",
"jingang",
"weituo-gun",
"cibei-blade",
});

protected string all_msg;

protected void make_book_msg()
{
	if( !all_msg )
		all_msg = "";

	foreach(string tmp in books)
		all_msg += sprintf("    %s(%s)\n", to_chinese(tmp), tmp);
}

void create()
{
	set_name("晦痴", ({ "hui chi" }) );

	set("class","shaolin");
	create_family("少林寺", 36, "弟子");
	set("title","藏经阁首座");

	set_auto_recover(1);

	set("gender", "男性" );
	set("age", 53);
	set("long", "这位高僧就是少林寺藏经阁首座。\n");
	set("attitude", "peaceful");
	set("inquiry",([
	"经书" : (: ask_me :),
	"jing shu" : (: ask_me :),
	"易筋经" : (: ask_yijin :),
	"book" : (: ask_all :),
	WILDCARD : (: ask_book :),
]));

	set("combat_exp", 3000000);
	set("str", 67);
	set("max_kee",2500);
	set("kee",2500);
	set("max_gin",2500);
	set("gin",2500);
	set("max_sen",2500);
	set("sen",2500);
	set("force", 2000);
	set("max_force", 2000);
	set("atman", 2000);
	set("max_atman", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 300);

	set_skill("unarmed",260);
	set_skill("dodge",260);
	set_skill("parry",250);
	set_skill("force",200);
	set_skill("stick",200);
	set_skill("iron-cloth",260);
	set_skill("perception",260);
	set_skill("yiqi-force",200);
	set_skill("ganchan",250);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");

	make_book_msg();
	setup();

	carry_object(__DIR__"obj/cangjing_key");
	carry_object(__DIR__"obj/seng_pao")->wear();
}

int ask_yijin(object me)
{
	if(me->query("class") != "shaolin")
		return 0;

	if(!me->query("family/can_study_yijin"))
	{
		write(CYN"晦痴说道：未得方丈许可，不可参悟《易筋经》以免自误！\n"NOR);
		return 1;
	}

	write(CYN"晦痴说道：既然方丈许可你可以进去了，就在东面的小屋。\n"NOR);
	call_out("do_open",2);
	return 1;
}

void want_out()
{
	call_out("do_open",2);
}

void do_open()
{
	command("unlock door");
	command("open door");
	call_out("do_close",5);
}

void do_close()
{
	command("close door");
	command("lock door");
}

string ask_me(object who)
{
	if(!who || who->query("class") != "shaolin")
		return 0;

	return "一些佛家经典都在书架上，你自己可以拿，我这还有一些武学典籍，不知你要哪本？\n";
}

int ask_book(object who,string topic)
{
	int n;
	string file;
	object book_ob;

	if(!who || !stringp(topic))
		return 0;

	if( ((n = member_array(topic,books)) == -1)
	&& ( (n = member_array(topic,map_array(books,(: to_chinese :)))) == -1))
		return 0;

	file = sprintf(__DIR__"obj/%s_book",books[n]);
	if(file_size(file+".c") <= 0 || !book_ob = new(file))
		return 0;

	message_vision(sprintf("$N从身后拿出一本%s交给了$n。\n",book_ob->name()),
		this_object(),who);
	book_ob->move(who);

	command("say 奉方丈法谕，武学典籍不可携出藏经阁。\n");
	return 1;
}

int accept_object(object who,object ob)
{
	if(!who || !ob)
		return 0;

	if(ob->is_shaolin_book())
	{
		call_out("destruct_book",1);
		return 1;
	}
	else
		return 0;
}

void destruct_book()
{
	int i,n;
	object *inv;

	inv = all_inventory(this_object());
	if(!n = sizeof(inv))
		return;

	for(i=0;i<n;i++)
		if(inv[i]->is_shaolin_book())
			destruct(inv[i]);
}

int ask_all(object who)
{
	if(who->query("family/family_name") != "少林寺")
		return 0;

	tell_object(who, sprintf("\n晦痴说道：我这只有这些武功的入门书籍：\n%s\n", all_msg));
	return 1;
}

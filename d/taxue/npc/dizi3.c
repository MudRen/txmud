// dizi4
// by dicky

#include <ansi.h>
inherit NPC;

string ask_book();

void create()
{
	set_name("踏雪莫匆", ({ "taxue mocong","mocong", "man" }));
	set("class","taxue");
        create_family("踏雪山庄", 2, "弟子");
	set("gender", "男性");
	set("age", 36);  
	set("long", "他是庄主踏雪靖远第三个弟子，长身玉立，脸型微见瘦削，俊美潇洒。\n");
	set("book1_count",3);
	set("book2_count",3);
	set("book3_count",3);
	
	set("combat_exp", 400000);

        set("max_kee",2200);
        set("max_gin",2200);
        set("max_sen",2200);
        set("max_force", 2800);
        set("max_atman", 2800);
        set("max_mana", 2800);
        set("force_factor", 100);

        set_skill("literate",150);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",150);
        set_skill("sword",150);	     
 
	set("inquiry",([
           "学习" : (: ask_book :),
           "读书" : (: ask_book :),
	]));

	setup();

        carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_book()
{
	object me;
	me=this_player();

	if(me->query("class") != "taxue")
		 return "书只能给本门弟子，你还是另想其他的办法吧！";

	if(me->query_skill("literate", 1) > 120 )
		 return "你的学识已经够高的了，你用不着那本书。\n";

	if(me->query_skill("literate", 1) < 30 )
	{

	if(me->query_temp("taxue/askbook"))
		 return "你刚才不是拿过了么，怎么又跑来了？";

	if (query("book1_count") < 1) 
		return "目前书籍已经被拿光了，等会再来吧！";

	command("smile");
	me->set_temp("taxue/askbook",1);
        add("book1_count", -1);

	message_vision(
                HIW"\n踏雪莫匆给$N一本三字经。\n"NOR,
                this_player(), this_object() );
	new("/d/taxue/obj/lite-book")->move(me);
	return "书给你了，记得一定要努力学习呀!\n";
	}

	if(me->query_skill("literate", 1) < 70 )
	{
	if(me->query_temp("taxue/askbook1"))
		 return "你刚才不是拿过了么，怎么又跑来了？";

	if (query("book2_count") < 1) 
		return "目前书籍已经被拿光了，等会再来吧！";

	command("smile");
	me->set_temp("taxue/askbook1",1);
        add("book2_count", -1);

	message_vision(
                HIG"\n踏雪莫匆给$N一本天下论语。\n"NOR,
                this_player(), this_object() );
	new("/d/taxue/obj/lite-book2")->move(me);
	return "书给你了，记得一定要努力学习呀!\n";
	}

	if(me->query_temp("taxue/askbook2"))
		 return "你刚才不是拿过了么，怎么又跑来了？";

	if (query("book3_count") < 1) 
		return "目前书籍已经被拿光了，等会再来吧！";

	command("smile");
	me->set_temp("taxue/askbook2",1);
        add("book3_count", -1);

	message_vision(
                HIW"\n踏雪莫匆给$N一本孙子兵法。\n"NOR,
                this_player(), this_object() );
	new("/d/taxue/obj/lite-book3")->move(me);
	return "书给你了，记得一定要努力学习呀!\n";
}
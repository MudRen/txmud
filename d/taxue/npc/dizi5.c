// dizi4
// by dicky

#include <ansi.h>
inherit NPC;

string ask_huju();

void create()
{
	set_name("踏雪飞虎", ({ "taxue feihu","feihu", "man" }));
	set("class","taxue");
        create_family("踏雪山庄", 2, "弟子");
	set("gender", "男性");
	set("age", 36);  
	set("long", "他是庄主踏雪靖远第五个弟子，长得虎背熊腰，非常结实。\n");
	set("combat_exp", 400000);
	set("huju_count",6);

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
           "护具" : (: ask_huju :),
           "huju" : (: ask_huju :),
	]));

	setup();

        carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_huju()
{
	object me;
	me=this_player();

	if(me->query("class") != "taxue")
		 return "护具只能给本门弟子，你还是另想其他的办法吧！";
	if(me->query_temp("taxue/askhuju"))
		 return "你刚才不是拿过了么，怎么又跑来了？";
	if(me->query_skill("force", 1) < 50 )
		 return "你的功夫还不够娴熟，护具给你也是浪费，还是留给其他的弟子用吧。\n";
	if (query("huju_count") < 1) return "目前护具已经被拿光了，等会吧";

	command("smile");

	me->set_temp("taxue/askhuju",1);

        new(__DIR__"obj/shoes")->move(me);
        new(__DIR__"obj/armor")->move(me);
        new(__DIR__"obj/hands")->move(me);
        new(__DIR__"obj/head")->move(me);
        new(__DIR__"obj/pifeng")->move(me);
        new(__DIR__"obj/waist")->move(me);
        new(__DIR__"obj/wrists")->move(me);

        add("huju_count", -1);

        message_vision("$N获得一套踏雪山庄护具。\n",this_player());
        return "我这里有一套护具，功效显著，你拿去护身吧。";
}
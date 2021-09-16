// guan6.c

inherit NPC;

int ask_wuming(object who);
int ask_taohua(object who);

void create()
{
        set_name("老管事", ({ "guan shi","guan" }) );

        set("class","jinghai");
        set("title","朱雀堂");

        set("gender", "男性" );
        set("age", 63);
	set(NO_KILL, 1);

        set("long", "这是一位瘦弱得老头子。\n");
        set("attitude", "peaceful");
        set("inquiry",([
        "无名岛" : (: ask_wuming :),
        "wuming" : (: ask_wuming :),
        "桃花岛" : (: ask_taohua :),
        "taohua" : (: ask_taohua :),
]));
 
        set("combat_exp", 10000);
        set("str", 17);
        
        set_skill("unarmed",60);
        set_skill("dodge",60);
        set_skill("parry",50);
        set_skill("force",10);

        setup();
 
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_wuming(object who)
{
        object ob;

        if(!who)
                return 0;

        if(who->query("class") != "jinghai")
		return 0;
	if(who->query_temp("jinghai_have_ling/bai"))
	{
		command("say 无名岛的令牌不是已经给过你了。\n");
		return 1;
	}

        ob = new(__DIR__"obj/bailing");

	ob->move(this_object());
	command("give bai ling to "+who->query("id"));

	if(environment(ob) == this_object())
	{
		command("say 你身上已经装不了更多的东西了。");
		destruct(ob);
		return 1;
	}

        ob->set("master",who->query("id"));
	who->set_temp("jinghai_have_ling/bai",1);

        command("say 无名岛？");
        command("fear");
        command("say 好吧！我给你这个令牌。你要好自为之啊。");
        return 1;
}

int ask_taohua(object who)
{
        object ob;

        if(!who)
        return 0;

        if(who->query("class") != "jinghai")
		return 0;

	if(who->query_temp("jinghai_have_ling/zhu"))
	{
		command("say 桃花岛的令牌不是已经给过你了。\n");
		return 1;
	}

        ob = new(__DIR__"obj/zhuling");
        ob->move(this_object());
        command("give zhu ling to "+who->query("id"));

	if(environment(ob) == this_object())
	{
		command("say 你身上已经装不了更多的东西了。");
		destruct(ob);
		return 1;
	}

        ob->set("master",who->query("id"));
	who->set_temp("jinghai_have_ling/zhu",1);

        command("say 桃花岛那个地方可是人间天堂啊。");
        command("think");
        return 1;
}


// jiang.c

inherit NPC;

void create()
{
        set_name("姜龄超", ({ "jiang ling chao" }) );

	set("title","当铺老板");
        set("gender", "男性" );
        set("age", 68);
        set("long","岁月的沧桑在他脸上留下了深深的痕迹。\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = previous_object()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;

	if(!random(3))
		command("say 本号全天营业，信誉卓著，欢迎惠顾。\n");
}


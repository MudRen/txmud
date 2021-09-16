inherit F_DEALER;

void create()
{
        set_name("铁老板", ({ "tie laoban", "tie" ,"laoban" }) );
        set("gender", "男性" );
        set("age", 47);

        set("long", "铁老板一脸凶像，有点不像好人。。\n");

        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("max_force",800);
	set("force",800);
        set("force_factor",10);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("parry", 120);

        set("sell_all_day",1);

        set("inquiry", ([
                "兵器店" : "本店专卖各种长短兵器", 
]) );

        set("vendor_goods", ([
                WEAPON_DIR"sword" : 10,
                WEAPON_DIR"whip": 10,
                WEAPON_DIR"dart": 10,
                WEAPON_DIR"sixhammer":10,
                WEAPON_DIR"thin_sword":10,
                WEAPON_DIR"dagger":10,
                WEAPON_DIR"stick":10,
                WEAPON_DIR"blade":10,
]) );

        setup();
        add_money("silver", 1);
        carry_object(WEAPON_DIR"sword")->wield();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;

        switch( random(4) )
        {
                case 0:
                        command(sprintf("say 这位%s挑一件称手的兵器吧。", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}

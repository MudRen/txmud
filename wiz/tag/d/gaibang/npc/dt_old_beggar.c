// dt_old_beggar.c

inherit NPC;

string ask_master();

void create()
{
        set_name("老乞丐", ({"old beggar"}));
        set("class", "gaibang");
	set("title", "丐帮七袋弟子");
        create_family("丐帮", 5, "七袋弟子");

        set("gender", "男性");
        set("age", 62);
        set("long","老乞丐已是满头白发，人却精神得很。\n");
        set("attitude", "peaceful");
        set("str", 40);
        set("cor", 40);
        set("int", 20);
        set("con", 40);
        set("kar", 20);
        set("per", 20);

        set("kee", 1500);
        set("max_kee", 1500);
        set("gin", 500);
        set("max_gin", 500);
        set("sen", 500);
        set("max_sen", 500);
        set("force", 2000);
        set("max_force", 2000);
        set("atman", 0);
        set("max_atman", 0);
        set("mana", 0);
        set("max_mana", 0);
        set("force_factor", 50);
        set("combat_exp", 400000);

        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("stick", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);

        set("inquiry", ([
                "舵主" : (: ask_master :),
        ]));

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/budai_7")->wear();
}

string ask_master()
{
        if (this_player()->query("class") == "gaibang")
                return "从天井爬过围墙就可以找到赵舵主啦。";
        else
                return;
}


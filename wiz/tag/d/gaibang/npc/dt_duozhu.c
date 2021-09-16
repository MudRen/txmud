// dt_duozhu.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("赵二毛", ({"master zhao"}));
        set("class", "gaibang");
        set("title", "丐帮大同分舵舵主");
        create_family("丐帮", 5, "八袋弟子");

        set("gender", "男性");
        set("age", 38);
        set("long","赵舵主年轻有为，深得全舵乞丐的爱戴。\n");
        set("attitude", "peaceful");
        set("str", 60);
        set("cor", 50);
        set("int", 20);
        set("con", 60);
        set("kar", 20);
        set("per", 20);

        set("kee", 2500);
        set("max_kee", 2500);
        set("gin", 800);
        set("max_gin", 800);
        set("sen", 800);
        set("max_sen", 800);
        set("force", 2500);
        set("max_force", 2500);
        set("atman", 0);
        set("max_atman", 0);
        set("mana", 0);
        set("max_mana", 0);
        set("force_factor", 120);
        set("combat_exp", 1500000);

        set_skill("begging", 250);
        set_skill("unarmed", 180);
        set_skill("force", 180);
        set_skill("stick", 200);
        set_skill("dodge", 180);
        set_skill("parry", 180);

        set("inquiry", ([
        ]));
        setup();
        carry_object(__DIR__"obj/bainayi")->wear();
        carry_object(__DIR__"obj/budai_8")->wear();
        carry_object(__DIR__"obj/long_stick")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query("class") != "gaibang") 
        {
                command("shake");
                command("say 想入丐帮应该先去长安分舵找俞舵主。");
                return;
        }

        if((int)ob->query("gb_bags")< 6)
        {
                command("say 等" + RANK_D->query_respect(ob) + "有六个布袋在身再来找我吧。");
                command("hehe "+ ob->query("id"));
                return;
        }

        command("say 好，" + RANK_D->query_respect(ob) +
        "我就收你为徒，但你要时刻记着本大同分舵的宗旨才是。");

        command("recruit " + ob->query("id"));
        ob->set("title",sprintf("丐帮%s袋弟子",
                chinese_number(ob->query("gb_bags"))) );
}


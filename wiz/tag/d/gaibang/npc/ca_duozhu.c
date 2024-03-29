// ca_duozhu.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("俞载粮", ({"master yu"}));
        set("class", "gaibang");
        set("title", "丐帮长安分舵舵主");
        create_family("丐帮", 5, "八袋弟子");

        set("gender", "男性");
        set("age", 55);
        set("long","俞舵主武艺杂而不精，却也是丐帮中少有的几个念过书的之一。\n");
        set("attitude", "peaceful");
        set("str", 40);
        set("cor", 40);
        set("int", 20);
        set("con", 40);
        set("kar", 20);
        set("per", 20);
 
        set("kee", 2000);
        set("max_kee", 2000);
        set("gin", 500);
        set("max_gin", 500);
        set("sen", 500);
        set("max_sen", 500);
        set("force", 2500);
        set("max_force", 2500);
        set("atman", 0);
        set("max_atman", 0);
        set("mana", 0);
        set("max_mana", 0);
        set("force_factor", 120);
        set("combat_exp", 1500000);

        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("stick", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("blade", 150);
        set_skill("sword", 150);
        set_skill("staff", 150);
        set_skill("hammer", 150);
        set_skill("whip", 150);
        set_skill("literate", 100);
        set_skill("begging", 250);

        set("inquiry", ([
        ]));

        setup();
        carry_object(__DIR__"obj/bainayi")->wear();
        carry_object(__DIR__"obj/budai_8")->wear();
}

void attempt_apprentice(object ob)
{
        if ( (int)ob->query("gb_bags") >= 2 && ob->query("class") != "gaibang" ) 
        {
                command("say 丐帮可容不下你这种背信弃义的小人！");
                command("heng");
                return;
        }

        if((ob->query("str") < 25) || ob->query("con") < 25)
        {
                command("say 我派武功需要极好的身体，否则难有所成。\n" +
                RANK_D->query_respect(ob) + "身体这么弱，恐怕难以承受得了。");
                command("shake "+ ob->query("id"));
                return;
        }

        command("say 好吧，希望" + RANK_D->query_respect(ob) +
        "能好好学习本门武功，将来在江湖中闯出一番作为。");

        if (ob->query("class") != "gaibang")
                ob->set("gb_bags", 1);

        command("recruit " + ob->query("id"));

        ob->set("class", "gaibang");
        ob->set("title",sprintf("丐帮%s袋弟子",
                chinese_number(ob->query("gb_bags"))) );
}

// kf_duozhu.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Ф��ƽ", ({"master xiao"}));
        set("class", "gaibang");
        set("title", "ؤ�￪��ֶ����");
        create_family("ؤ��", 5, "�˴�����");

        set("gender", "����");
        set("age", 57);
        set("long","Ф�������굣�ο������һְ�����ľ���\n");
        set("attitude", "peaceful");
        set("str", 50);
        set("cor", 40);
        set("int", 20);
        set("con", 60);
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

        set_skill("begging", 250);
        set_skill("unarmed", 180);
        set_skill("force", 180);
        set_skill("staff", 200);
        set_skill("dodge", 180);
        set_skill("parry", 180);

        set("inquiry", ([
        ]));

        setup();
        carry_object(__DIR__"obj/bainayi")->wear();
        carry_object(__DIR__"obj/budai_8")->wear();
}

void attempt_apprentice(object ob)
{
        if (ob->query("class") != "gaibang") 
        {
                command("shake");
                command("say ����ؤ��Ӧ����ȥ�����ֶ����������");
                return;
        }

        if((int)ob->query("gb_bags")< 4)
        {
                command("say ��" + RANK_D->query_respect(ob) + "���ĸ����������������Ұɡ�");
                command("hehe "+ ob->query("id"));
                return;
        }

        command("say �ã�" + RANK_D->query_respect(ob) +
        "�Ҿ�����Ϊͽ������Ҫʱ�̼��ű�����ֶ����ּ���ǡ�");

        command("recruit " + ob->query("id"));
        ob->set("title",sprintf("ؤ��%s������",
                chinese_number(ob->query("gb_bags"))) );
}

// ft_duozhu.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����ȭ", ({"master guo"}));
        set("class", "gaibang");
        set("title", "ؤ�����ֶ����");
        create_family("ؤ��", 5, "�˴�����");

        set("gender", "����");
        set("age", 45);
        set("long","������ȭ�ŷ������ֲ������ڷ����Ҳ�����˽�֪��\n");
        set("attitude", "peaceful");
        set("str", 70);
        set("cor", 40);
        set("int", 20);
        set("con", 40);
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
        set_skill("unarmed", 200);
        set_skill("force", 180);
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

        if((int)ob->query("gb_bags")< 6)
        {
                command("say ��" + RANK_D->query_respect(ob) + "���������������������Ұɡ�");
                command("hehe "+ ob->query("id"));
                return;
        }

        command("say �ã�" + RANK_D->query_respect(ob) +
        "�Ҿ�����Ϊͽ������Ҫʱ�̼��ű�����ֶ����ּ���ǡ�");

        command("recruit " + ob->query("id"));
        ob->set("title",sprintf("ؤ��%s������",
                chinese_number(ob->query("gb_bags"))) );
}


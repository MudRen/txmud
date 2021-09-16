// ca_duozhu.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({"master yu"}));
        set("class", "gaibang");
        set("title", "ؤ�ﳤ���ֶ����");
        create_family("ؤ��", 5, "�˴�����");

        set("gender", "����");
        set("age", 55);
        set("long","����������Ӷ�������ȴҲ��ؤ�������еļ���������֮һ��\n");
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
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                command("heng");
                return;
        }

        if((ob->query("str") < 25) || ob->query("con") < 25)
        {
                command("say �����书��Ҫ���õ����壬�����������ɡ�\n" +
                RANK_D->query_respect(ob) + "������ô�����������Գ��ܵ��ˡ�");
                command("shake "+ ob->query("id"));
                return;
        }

        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");

        if (ob->query("class") != "gaibang")
                ob->set("gb_bags", 1);

        command("recruit " + ob->query("id"));

        ob->set("class", "gaibang");
        ob->set("title",sprintf("ؤ��%s������",
                chinese_number(ob->query("gb_bags"))) );
}

// dt_old_beggar.c

inherit NPC;

string ask_master();

void create()
{
        set_name("����ؤ", ({"old beggar"}));
        set("class", "gaibang");
	set("title", "ؤ���ߴ�����");
        create_family("ؤ��", 5, "�ߴ�����");

        set("gender", "����");
        set("age", 62);
        set("long","����ؤ������ͷ�׷�����ȴ����úܡ�\n");
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
                "����" : (: ask_master :),
        ]));

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/budai_7")->wear();
}

string ask_master()
{
        if (this_player()->query("class") == "gaibang")
                return "���쾮����Χǽ�Ϳ����ҵ��Զ�������";
        else
                return;
}


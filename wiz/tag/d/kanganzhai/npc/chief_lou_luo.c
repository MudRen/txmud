// chief_lou_luo.c


inherit NPC;

void create()
{
        set_name("СͷĿ", ({"chief louluo"}));
        set("title", "����կ Ѳկ");

        set("gender", "����");
        set("age", 35 + random(10));
        set("long", "����һλ����կ��СͷĿ���������ݡ�\n");
        set("str", 100);
        set("cor", 50);
        set("int", 20);
        set("con", 50);
        set("kar", 20);
        set("per", 20);
 
        set("kee", 2500);
        set("max_kee", 2500);
        set("gin", 500);
        set("max_gin", 500);
        set("sen", 500);
        set("max_sen", 500);
        set("force", 4000);
        set("max_force", 4000);
        set("atman", 0);
        set("max_atman", 0);
        set("mana", 0);
        set("max_mana", 0);
        set("force_factor", 150);
        set("combat_exp", 3000000);

        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("hammer", 280);

        set("inquiry", ([
        ]));

        setup();
        carry_object(__DIR__"obj/huge_hammer")->wield();
        carry_object(__DIR__"obj/leather_armor")->wear();
}

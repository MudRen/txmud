//hunter.c ��֥������ˡ�
inherit NPC;
void create()
{
        set_name("�Ի�", ({"lie hu", "hunter"}));
        set("long", "����һλ�뺷�Ĳ����Ի������ڸ���Χ����̸�۴��Ե����顣\n");
        set("gender","����");
        set("age",35);
        set("con",20);
        set("str",70);
        set("max_kee",2000);
        set("max_gin",700);
        set("max_sen",700);
        set("max_force",2500);
        set("force",2500);
        set("force_factor",30);

        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("unarmed",150);
        set_skill("force",150);
        set_skill("fork",150);

        set("combat_exp",70000);

        setup();
        carry_object(__DIR__"obj/hunt-fork")->wield();
        carry_object(__DIR__"obj/teng-armor")->wear();
}

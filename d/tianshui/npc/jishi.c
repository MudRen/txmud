// jishi.c

inherit DOCTOR;

void create()
{
        set_name("������", ({ "wang jishi","wang" }) );
        set("title", "ҩ���ϰ�");
        set("gender", "����" );
        set("age", 55);
        set("long", "������ҩ�̵��ϰ���������һλ�Һ��ߡ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);

        set("inquiry", ([
                "ץҩ" : "�����Ǹ�����õ�ҩ�꣬��Ҫʲô��",
        ]) );

        setup();
        add_money("silver", 1);
        carry_object(ARMOR_DIR"cloth")->wear();
}

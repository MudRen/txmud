// butterfly.c

inherit NPC;

void create()
{
        set_name("����", ({ "hu die", "butterfly" }) );
        set("race", "Ұ��");
        set("age", 3);
	set("max_kee", 300);
        set("long", "һֻ�������ĺ�����\n");

        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 300);

        setup();
}

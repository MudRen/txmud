// maque.c

inherit NPC;

void create()
{
        set_name("С��ȸ", ({ "ma que", "sparrow" }) );
        set("race", "Ұ��");
        set("age", 3);
	set("max_kee", 300);
        set("long", "һֻߴߴ�����е�С��ȸ��\n");

	set("chat_chance",5);
	set("chat_msg",({
	"��ȸߴߴ�����Ľ��š�\n",
}));

        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);

        setup();
}

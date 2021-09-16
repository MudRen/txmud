// yetu.c Ұ��

inherit NPC;

void create()
{
        set_name("Ұ��", ({ "ye tu" }) );
	set("race", "Ұ��");

	set("age", 5);
	set("long", "һֻ�ÿɰ���СҰ�á�\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);

        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :),
		"Ұ����ǰ�����ۺ��ӣ�С�ĵ������ܿ����� \n",
		"Ұ�õ���ͷ���˼��ڲݣ���̧ͷ�����ܿ�����\n",
		"Ұ��ͻȻͣ������������������ע������ʲô��",
        }) );
	
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 10);

	setup();
}

void die()
{
	object ob;

	message_vision("$N���ˡ�\n", this_object());

	ob = new(__DIR__"obj/turou");
	ob->move(environment(this_object()));
	destruct(this_object());
}

inherit NPC;

void create()
{
	set_name("ɽȸ", ({ "shan que" }) );
        set("race", "Ұ��");
        set("age", 1);

        set("gender", "����");
        set("long", "һֻ������Сɽȸ�����������и���ͣ! \n");

	set("str", 20);

	set("combat_exp", 1000);
        set("attitude","peaceful");

	set("limbs", ({ "ͷ��", "����","���" }) );
	set("verbs", ({ "bite","claw" }) );

	set_temp("apply/dodge", 100);

	set("chat_chance", 2);
	set("chat_msg", ({
		(: random_move :),
		"ɽȸ����������ë�� \n",
		"ɽȸ�������˾�չ�������ˡ� \n",
	}) );

        setup();
}
/*

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
	ob = new(__DIR__"obj/shanjirou");
	ob->move(environment());
	destruct(this_object());
} */


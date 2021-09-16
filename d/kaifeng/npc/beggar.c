// beggar.c

inherit NPC;

void create()
{
	set_name("��ؤ", ({ "beggar" }) );
	set("gender", "����" );
	set("age", 53);
	set("long", "һ��������˪֮ɫ������ؤ��\n");
	set("combat_exp", 500);
	set("str", 20);

	set("is_beggar",1);
	setup();

	set("chat_chance", 15);
	set("chat_msg", ({
		"��ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
		"��ؤ������ش��˸���Ƿ��\n",
		"��ؤ����׽ס�����ϵ�ʭ�ӣ��������������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
		(: random_move :)
	}) );
        if(random(2))
                carry_object(BOOK_DIR"old_book");
	carry_object(ARMOR_DIR"cloth")->wear();
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say ��л��λ" + RANK_D->query_respect(me) + "��������һ�����кñ��ģ�");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}

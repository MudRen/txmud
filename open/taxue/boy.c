// beggar.c

inherit NPC;

void create()
{
    set_name("�к�", ({ "boy" }) );
	set("gender", "����" );
    set("age", 17);
   set("attitude","friendly");
   set("long", "һ�������緢���к���\n");
   set("combat_exp", 20000);
	set("str", 20);
	set("force", 200);
	set("is_beggar",1);
    set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );

	setup();

	if(random(2))
		carry_object(BOOK_DIR"old_book");
	carry_object(ARMOR_DIR"cloth")->wear();
 carry_object("/d/feiyu/obj/killersword.c")->wield();
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say ��л��λ" + RANK_D->query_respect(me) + "��������һ�����кñ��ģ�");
	return 1;
}


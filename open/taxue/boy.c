// beggar.c

inherit NPC;

void create()
{
    set_name("男孩", ({ "boy" }) );
	set("gender", "男性" );
    set("age", 17);
   set("attitude","friendly");
   set("long", "一个意气风发的男孩。\n");
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
	command("say 多谢这位" + RANK_D->query_respect(me) + "，您好心一定会有好报的！");
	return 1;
}


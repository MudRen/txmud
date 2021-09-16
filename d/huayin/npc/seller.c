// seller.c

inherit F_DEALER;

void create()
{
        set_name("�ӻ�����", ({ "zahuo fanzi" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "���ӻ����Ǹ����Ẻ�ӣ����΢
Ц���ݻ��������˵����ǰҲ��һλ�����ˡ�\n");
        set("combat_exp", 100);

	set("sell_all_day",1);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);

        set("vendor_goods", ([
                BOOK_DIR"s_force_book":2,
                MISC_DIR"bag":10,
		MISC_DIR"torch":20,
        ]) );

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && is_day())
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	if( !random(4) )
		say( "�ӻ�����Ц����ӭ��������λ"
			+ RANK_D->query_respect(ob)
			+ "��Ҫ��ʲô��\n");
}

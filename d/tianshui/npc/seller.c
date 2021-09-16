// seller.c

inherit F_DEALER;

void create()
{
        set_name("�ӻ���", ({ "seller" }) );
        set("title", "�ӻ���");
        set("gender", "����" );
        set("age", 32);
        set("long", "���ӻ����Ǹ����Ẻ�ӣ����΢Ц��\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("throwing", 30);

        set("vendor_goods", ([
                __DIR__"obj/rope":10,
                MISC_DIR"bag":10,
                DRUG_DIR"dust":5,
		MISC_DIR"torch":20,
		"/obj/mine/sz_gao" : 50,
		__DIR__"obj/dodge_book":2,
		__DIR__"obj/unarmed_book":3,
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

        if(random(10)<5)
                carry_object(WEAPON_DIR"dart")->wield();

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "�ӻ���Ц����ӭ��������λ"
                                + RANK_D->query_respect(ob)
                                + "��Ҫ��ʲô��\n");
                        break;
                case 1:
                        say( "�ӻ�����æ���������\n");
                        break;
        }
}

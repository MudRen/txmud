// fruit_seller.c

inherit F_DEALER;

void create()
{
	set_name("ˮ������", ({ "fruit seller","seller" }) );
	set("gender", "����" );
	set("age", 28);
	set("long", "һ����ˮ����С���������𾢵������˶���ˮ����\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 100);
	set_skill("throwing", 30);

	set("vendor_goods", ([
		__DIR__"obj/apple":5,
		__DIR__"obj/pear":5,
		__DIR__"obj/strawberry":5,
		__DIR__"obj/grape":5,
		__DIR__"obj/melon":5,
	]) );

	setup();
	add_money("silver", 1);
	add_money("coin", 100);
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "ˮ�����Ӹߺ�����ˮ���������������ˮ����\n");
                        break;
                case 1:
                        say( "ˮ�����Ӹߺ����ֽ���ֳ伢����\n");
                        break;
        }
}
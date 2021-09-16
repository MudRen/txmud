// seller.c
// by dicky

inherit F_DEALER;

void create()
{
        set_name("С��", ({ "xiao fan","seller" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
        set("combat_exp", 300);
        set("str", 17);
        set("per", 20);
        set("con", 17);
        set("int", 22);
	set("sell_all_day",1);
        set("attitude", "friendly");

        set("vendor_goods", ([
                __DIR__"obj/fire" : 4,
                __DIR__"obj/tanghulu" : -1,
		__DIR__"obj/erhu" : 5,
		__DIR__"obj/shuinang" : 10,
        ]) );

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
	object ob;
        ::init();

        if (interactive(ob = this_player()) && !is_fighting()){
               remove_call_out("greeting");
               call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "С����ͻȻ��ס�㣬���ص�˵������λ" + RANK_D->query_respect(ob)
				+ "���ѵ����뿴����ʲô��Ҫ��ô��\n");
			break;
		case 1:
			say( "С����̧ͷ�����죬����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ߵ���ô��æ��\n��ǧ��Ҫ�����������ྫ��ϸ�ڡ�\n");
			break;
	}
}
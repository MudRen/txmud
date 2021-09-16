// paotang.c

inherit F_DEALER;

void create()
{
        set_name("����", ({ "waiter" }) );
	set("title","���ɸ�");
        set("gender", "����" );
        set("age", 22);
        set("long","С��������æ�ţ�����ʱҪ�ͽ����Ŀ��˴��к���\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/noodles":-1,
                FOOD_DIR"chicken_leg":-1,
                LIQUID_DIR"wineskin":-1,
		MISC_DIR"top" : 20,
        ]) );
        setup();
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
                        say( "С����Ц�����˵�������ɸ�ķ���Զ��������\n");
                        break;
                case 1:
                        say( "С����һ����˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}

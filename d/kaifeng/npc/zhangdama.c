inherit F_DEALER;

void create()
{
        set_name("�Ŵ���", ({ "zhang da ma"}) );
        set("gender", "Ů��" );
        set("age", 59);

        set("long", "�Ŵ����ֶնյ�,����һ��Ц�����ſ��ˡ�\n");

        set("combat_exp", 1);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/guapimao" : -1,
                __DIR__"obj/laotouxie" : -1,
                __DIR__"obj/zicloth" : -1,
        ]) );


        setup();
        add_money("coin", 10);
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;

        switch( random(4) )
        {
                case 0:
                        command(sprintf("say ��λ%s���򼸼��·���", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}

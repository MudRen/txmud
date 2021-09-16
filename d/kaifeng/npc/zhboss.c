inherit F_DEALER;

void create()
{
        set_name("�ӻ����ϰ�", ({ "lao ban", "boss"}) );
        set("gender", "����");
        set("age", 56);
        set("long", "�ӻ����ϰ�������,���޵�ͷ���Ѿ�����.\n");

        set("combat_exp", 200);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                MISC_DIR"bag" : -1,
                MISC_DIR"lamp" : 30,
		__DIR__"obj/she_cha" : 20,
		"/obj/mine/sz_gao" : -1,
        ]) );


        setup();
        add_money("silver", 1);
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
                        command(sprintf("say ��λ%s�����ʲô?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}


inherit F_DEALER;

void create()
{
        set_name("������ϰ�", ({ "lao ban", "boss" }) );
        set("gender", "����" );
        set("age", 52);

        set("long", "������ϰ��Ǹ��Ͱ������ˡ�\n");

        set("combat_exp", 10);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/kaoyangrou" : -1,
                __DIR__"obj/kaoniurou" : -1,
        ]) );


        setup();
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
                        command(sprintf("say ��λ%s���������ǵ�Ŀ��⡣", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}

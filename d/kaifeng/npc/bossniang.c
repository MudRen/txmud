inherit F_DEALER;

void create()
{
        set_name("�ϰ���", ({ "nv laoban", "laoban" , "boss" }) );
        set("gender", "Ů��");
        set("age", 32);

        set("long", "�ϰ���һ������,������������....\n");

        set("combat_exp", 100);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/yanzhi" : 10,
        ]) );


        setup();
        add_money("silver", 30);
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
                        command(sprintf("say ��λ%s��������ϵ���֬��?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}


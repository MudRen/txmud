inherit F_DEALER;

void create()
{
        set_name("���ϰ�", ({ "chen laoban", "chen" ,"laoban" }) );
        set("gender", "����" );
        set("age", 45);

        set("long", "���ϰ����ҩζ,����һ����������ҩ����.\n");

        set("combat_exp", 100);
        set("attitude", "friendly");

        set("sell_all_day",1);
        set("vendor_goods", ([
                DRUG_DIR"medicine_ganmao":-1,
                DRUG_DIR"huandan":50,
        ]) );

        setup();
        add_money("silver", 1);
        carry_object(WEAPON_DIR"sword")->wield();
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
                        command(sprintf("say ��λ%s�����ʲôҩ��?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}

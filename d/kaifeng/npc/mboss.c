inherit F_DEALER;

void create()
{
        set_name("ľ�ĵ��ϰ�", ({ "lao ban", "boss"}) );
        set("gender", "����");
        set("age", 62);
        set("long", "ľ�ĵ��ϰ忴��������ϴ��\n");

        set("combat_exp", 120);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/mutou" : -1,
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
                        command(sprintf("say ��λ%s���ľ����?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}

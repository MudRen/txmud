inherit F_DEALER;

void create()
{
        set_name("������", ({ "li yutang", "li" , "yutang"}) );
        set("gender", "����" );
        set("age", 42);

        set("long", "���ϰ�һ�����Ǹ������ˣ����Ÿ�С�۾���\n");

        set("combat_exp", 1000);
        set("attitude", "friendly");

        set("sell_all_day",1);
        set("vendor_goods", ([
                __DIR__"obj/xianglian":-1,
                __DIR__"obj/shouzhuo":-1,
                __DIR__"obj/erhuan":-1,
                __DIR__"obj/jiezhi":-1,
        ]) );

        setup();
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
                        command(sprintf("say ��λ%s�����������?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}

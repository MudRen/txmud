inherit F_DEALER;

void create()
{
        set_name("���ϰ�", ({ "gao laoban", "gao" ,"laoban" }) );
        set("gender", "����" );
        set("age", 36);

        set("long", "��˵���ϰ��Ƕ���������..\n");

        set("combat_exp", 50000);
        set("attitude", "friendly");

        set_skill("unarmed", 150);
        set_skill("dodge", 100);
        set_skill("parry", 30);

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/dpcloth":-1,
                __DIR__"obj/ypcloth":-1,
]) );

        setup();
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
                        command(sprintf("say ��λ%s��һ��Ƥ���ɡ�", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}

inherit F_DEALER;

void create()
{
        set_name("С����", ({ "xiao sanzi", "waiter" ,"sanzi" }) );
        set("gender", "����" );
        set("age", 23);
set("title","��������¥");

        set("long", "С�����Ǹ���ͷС���ӡ�\n");

        set("combat_exp", 100);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                FOOD_DIR"chicken_leg" : -1,
                LIQUID_DIR"bowl" : -1,
                "/d/changan/npc/obj/yuxiang":-1,
                "/d/changan/npc/obj/tuofeng":-1,
                "/d/changan/npc/obj/yuchi":-1,
                "/d/changan/npc/obj/yinyu":-1,
                "/d/changan/npc/obj/shizi_tou":-1,
                "/d/changan/npc/obj/taxue":-1,
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
                        command(sprintf("say ��λ%s��Ե�ʲô?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}

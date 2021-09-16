#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("��������", ({ "liu ma zi" }) );
	set("gender", "����" );
	set("age", 48);
        set("sell_all_day",1);
        set("long","�����������ֵ�,�Ͱ����ס�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/buxie":20,
                __DIR__"obj/qcd":20,
        ]) );
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( living(ob = previous_object()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;
 
        switch( random(2) )
        {
                case 0:
                        say( CYN"��������˵������λ" + RANK_D->query_respect(ob)
                                + "���������\n"NOR);
                        break;
                case 1:
                        say( CYN"��������˵������λ" + RANK_D->query_respect(ob)
                                + "Ҫ���ʲô��\n"NOR);
                        break;
        }
}


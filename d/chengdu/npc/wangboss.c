// wangboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("�����", ({ "wang wanjin" }) );
        set("title","Ѽ����");
        set("gender", "����" );
        set("age", 41);
        set("sell_all_day",1);
        set("long","һ��������һλ���̣�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/yazi":10,
                __DIR__"obj/wangya":10,

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
                        say( CYN"�����Ц���е�����λ" + RANK_D->query_respect(ob)
                                + "���������\n"NOR);
                        break;
                case 1:
                        say( CYN"�����˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫ��ֻѼ����\n"NOR);
                        break;
        }
}

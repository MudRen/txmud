//shopper.c ��֥����ӻ��̡�
#include <ansi.h>
inherit F_DEALER;
void create()
{
        set_name("��������", ({ "yixi danba","boss" }) );
        set("title","�ӻ����ϰ�");
        set("gender", "����" );
        set("sell_all_day",1);
        set("age", 35);
        set("long","����һλ���ݿݺڵ������ˡ�\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("vendor_goods", ([
                MISC_DIR"bag":20,
                MISC_DIR"lamp":5,
                "/d/tianshui/npc/obj/xiang" : 80,
        ]) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
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
                        say( CYN"�������ʹ���˵������λ" + RANK_D->query_respect(ob)+ "����������\n"NOR);
                        break;
                case 1:
                        say( CYN"�������ʹ���˵������λ" + RANK_D->query_respect(ob)+ "Ҫ���ʲô��\n"NOR);
                        break;
        }
}

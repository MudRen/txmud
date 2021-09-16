#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("ľ��", ({ "mu jiang","waiter" }) );
        set("gender", "����" );
        set("age", 42);
        set("long","���ľ����˵��ǰ��һλ���͡�\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/wood_stick" : -1,
                __DIR__"obj/wood_staff" : -1,
                __DIR__"obj/wood_sword" : -1,
                __DIR__"obj/wood_blade" : -1,
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
        string day_night;
        int time;

        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;

        if(!is_day())
        {
                sscanf( day_night(),"%s %d",day_night,time);
                say( (time > 480) ? CYN"С���Ѿ������ˣ�"+RANK_D->query_respect(ob)+
                        "���������ɡ�\n"NOR
                        : ( (time <= 60) ? CYN"ľ������һ��Ϳ����ˣ���λ�͹����һ�°ɡ�\n"NOR
                        : CYN"ľ���������۾�˵�����컹û�����������ڲ�Ӫҵ��\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"ľ��Ц�Ǻ�˵������λ" + RANK_D->query_respect(ob)
                                + "����룬�����ʲô���ֵı�����\n"NOR);
                        break;
                case 1:
                        say( CYN"ľ��˵������λ" + RANK_D->query_respect(ob)
                                + "�������ľ���ڿ���ǿ���������Ŷ��\n"NOR);
                        break;
                }
        }
}

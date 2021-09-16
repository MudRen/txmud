#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("���ϰ�", ({ "lao ban","boss"}) );
        set("gender", "����" );
        set("age", 35);
        set("long","���ϰ��Ǹ��в�ס����,�����ҵ��ɡ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"dabaicai" : -1,
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
                say( (time > 480) ? CYN"��ô����죬�˳�һ���˶�û���ˣ�"+RANK_D->query_respect(ob)+
                        "�������������ɡ�\n"NOR
                        : ( (time <= 60) ? CYN"���ϰ�������Ͼ�ҪӪҵ�ˣ���λ�͹����һ�°ɡ�\n"NOR
                        : CYN"���ϰ���˸�����˵�����˳�û���ţ������������˵��\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"���ϰ庰�����������ײ�ѽ!\n"NOR);
                        break;
                case 1:
                        say( CYN"���ϰ������λ" + RANK_D->query_respect(ob)
                                + "��������ײ�?\n"NOR);
                        break;
                }
        }
}

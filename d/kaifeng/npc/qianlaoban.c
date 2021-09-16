#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("Ǯ�ϰ�", ({ "qiao laoban","qian","laoban" }) );
        set("gender", "����" );
        set("title",HIR"��Ǯ�ۿ�"NOR);
        set("age", 46);
        set("long","Ǯ�ϰ��������Ÿ����̺���һ�����̵����ӡ�\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/huangjinxianglian" : -1,
                __DIR__"obj/manaoshouzhuo" : -1,
                __DIR__"obj/feicuijiezhi" : -1,
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
                        : ( (time <= 60) ? CYN"Ǯ�ϰ����һ��Ϳ����ˣ���λ�͹����һ�°ɡ�\n"NOR
                        : CYN"Ǯ�ϰ��������۾�˵�����컹û�����������ڲ�Ӫҵ��\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"Ǯ�ϰ������������λ" + RANK_D->query_respect(ob)
                                + "�����������\n"NOR);
                        break;
                case 1:
                        say( CYN"Ǯ�ϰ�˵������λ" + RANK_D->query_respect(ob)
                                + "������ɱ�������\n"NOR);
                        break;
                }
        }
}
